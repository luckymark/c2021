#include <conio.h>
#include <windows.h>

#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//字符为空则更换字体。建议使用黑体
//人--"♀"
#define WALL '1'   //墙--"■"
#define BLANK '0'  //空--"  "
#define BOX '2'    //箱子--"※"
#define GOAL '3'   //目标点--"□"
#define REACH '4'  //箱子推到目标点--"★"
#define up 6       //上
#define down 7     //下
#define left 8     //左
#define right 9    //右

class pos {  //位置类
   public:
    pos(int x = 1, int y = 1, int direction = 0) {
        X = x, Y = y;
        D = direction;
    }
    void Up() { --X; }
    void Down() { ++X; }
    void Left() { --Y; }
    void Right() { ++Y; }
    int X;
    int Y;
    int D;
};

class Stage {  //关卡类
   public:
    Stage(vector<string> theMap, pos thePlayer, int theNum = 0, int theStart = 0) {
        map = theMap;
        player = thePlayer;
        num = theNum;
        start = theStart;
    }
    vector<string> map;  //关卡地图
    pos player;          //玩家起始位置
    int num;             //关卡箱子数量
    int start;           //关卡起始箱子数量
};

class step {  //步骤类
   public:
    step(int theD = 0, char thePush = BLANK) {
        D = theD;
        push = thePush;
    }
    int D;      //方向
    char push;  //移动类型
};

vector<Stage> stages;                           //所有关卡
vector<int> scores;                             //所有关卡所得分数
int now = 0;                                    //当前关卡
int num = 0;                                    //关卡数量
vector<string> zero;                            //隐藏关卡地图
pos playerZero;                                 //隐藏关卡玩家起点坐标
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取标准输出设备句柄
COORD coord;                                    //坐标

void HideCursor() {                           //隐藏光标
    CONSOLE_CURSOR_INFO CursorInfo;           //光标信息
    GetConsoleCursorInfo(hOut, &CursorInfo);  //获取控制台光标信息
    CursorInfo.bVisible = false;              //隐藏控制台光标
    SetConsoleCursorInfo(hOut, &CursorInfo);  //设置控制台光标状态
}

bool Welcome() {  //主菜单
    cout << "推箱子游戏\n建议调大字体，调整合适窗口大小，使用黑体再进行游戏\n" << endl;
    cout << "请输入关卡  输入范围: 1 ~ " << num << "\t(输入'0'退出程序)" << endl;
    cin >> now;
    if (now == 0) return true;
    while (now < 1 || now > num) {
        cout << "输入为" << now << "，请重新输入" << endl;
        cin >> now;
    }
    system("cls");
    return false;
}

void StageInitialize() {                        //文件中读取关卡地图与分数
    stages.push_back(Stage(zero, playerZero));  //关卡0--不可访问
    scores.push_back(0);                        //关卡0分数--不可访问

    //从文件中获取关卡地图
    ifstream infile;
    infile.open("stages.dat");

    string line;
    vector<string> mapN;
    pos playerN;

    while (!infile.eof()) {
        getline(infile, line);
        if (line[0] == '#') {  //读取了一关
            playerN.X = line[1] - '0', playerN.Y = line[2] - '0';
            stages.push_back(Stage(mapN, playerN, line[3] - '0', line[4] - '0'));
            ++num;         //关卡数量加一
            mapN.clear();  //临时地图清空
            continue;
        }
        mapN.push_back(line);
    }
    infile.close();

    //从文件中获取关卡分数
    infile.open("scores.dat");

    int score;
    int numS = 0;

    while (!infile.eof()) {
        infile >> score;
        ++numS;
        scores.push_back(score);
    }
    infile.close();

    //判断关卡地图数量和关卡分数数量是否一致
    if (num != numS) {
        cerr << "文件错误，关卡地图数量与关卡分数数量不一致，程序即将退出" << endl;
        system("pause");
        exit(-1);
    }
}

void ShowStage() {  //打印当前关卡游戏界面
    //打印地图
    Stage stageN = stages[now];
    for (int i = 0; i < stageN.map.size(); ++i) {
        for (int j = 0; j < stageN.map[i].size(); ++j) {
            if (stageN.map[i][j] == '0')
                cout << "  ";
            else if (stageN.map[i][j] == '1')
                cout << "■";
            else if (stageN.map[i][j] == '2')
                cout << "※";
            else if (stageN.map[i][j] == '3')
                cout << "□";
            else if (stageN.map[i][j] == '4')
                cout << "★";
        }
        cout << endl;
    }
    //打印信息
    cout << "关卡：" << now << " \t当前分数：0"
         << "\t\t历史最低分：" << scores[now] << endl;
    cout << "WADS--上左右下移动  R--重开  Z--回退  Q--返回主菜单" << endl;
    //打印人物
    coord.X = stageN.player.Y * 2, coord.Y = stageN.player.X;
    SetConsoleCursorPosition(hOut, coord);
    cout << "♀";
    SetConsoleCursorPosition(hOut, coord);
}

bool Move() {  //移动等功能实现
    char in, inin;
    Stage stageN = stages[now];
    int x = 0, y = 0, score = 0, satisfy = stageN.start;
    stack<step> steps;  //操作步骤

    //控制逻辑
    while (in = getch()) {
        x = stageN.player.X, y = stageN.player.Y;
        switch (in) {
            case 'w':
            case 'W': {
                if (stageN.map[x - 1][y] == BLANK || stageN.map[x - 1][y] == GOAL) {  //空
                    stageN.player.Up();
                    inin = BLANK;
                    steps.push(step(up, BLANK));
                } else if (stageN.map[x - 1][y] == REACH) {  //箱子推出目标点
                    if (stageN.map[x - 2][y] == BLANK) {     //箱子能移动
                        stageN.map[x - 2][y] = BOX;
                        stageN.map[x - 1][y] = GOAL;
                        stageN.player.Up();
                        inin = BOX;
                        stageN.player.D = up;  //推箱子方向
                        --satisfy;             //到达目标点箱子减一
                        steps.push(step(up, BOX));
                    } else if (stageN.map[x - 2][y] == GOAL) {  //箱子推到终点
                        stageN.map[x - 2][y] = REACH;
                        stageN.map[x - 1][y] = GOAL;
                        stageN.player.Up();
                        inin = REACH;
                        stageN.player.D = up;  //推箱子方向
                        steps.push(step(up, REACH));
                    } else
                        goto end;                          //箱子无法推动
                } else if (stageN.map[x - 1][y] == BOX) {  //箱子
                    if (stageN.map[x - 2][y] == BLANK) {   //箱子能移动
                        stageN.map[x - 2][y] = BOX;
                        stageN.map[x - 1][y] = BLANK;
                        stageN.player.Up();
                        inin = BOX;
                        stageN.player.D = up;  //推箱子方向
                        steps.push(step(up, BOX));
                    } else if (stageN.map[x - 2][y] == GOAL) {  //箱子推到终点
                        stageN.map[x - 2][y] = REACH;
                        stageN.map[x - 1][y] = BLANK;
                        stageN.player.Up();
                        inin = REACH;
                        stageN.player.D = up;  //推箱子方向
                        ++satisfy;             //到达目标点箱子加一
                        steps.push(step(up, REACH));
                    } else
                        goto end;  //箱子无法推动
                } else {           //墙
                    goto end;
                }
                break;
            }
            case 's':
            case 'S': {
                if (stageN.map[x + 1][y] == BLANK || stageN.map[x + 1][y] == GOAL) {  //空
                    stageN.player.Down();
                    inin = BLANK;
                    steps.push(step(down, BLANK));
                } else if (stageN.map[x + 1][y] == REACH) {  //箱子推出目标点
                    if (stageN.map[x + 2][y] == BLANK) {     //箱子能移动
                        stageN.map[x + 2][y] = BOX;
                        stageN.map[x + 1][y] = GOAL;
                        stageN.player.Down();
                        inin = BOX;
                        stageN.player.D = down;  //推箱子方向
                        --satisfy;               //到达目标点箱子减一
                        steps.push(step(down, BOX));
                    } else if (stageN.map[x + 2][y] == GOAL) {  //箱子推到终点
                        stageN.map[x + 2][y] = REACH;
                        stageN.map[x + 1][y] = GOAL;
                        stageN.player.Down();
                        inin = REACH;
                        stageN.player.D = down;  //推箱子方向
                        steps.push(step(down, REACH));
                    } else
                        goto end;                          //箱子无法推动
                } else if (stageN.map[x + 1][y] == BOX) {  //箱子
                    if (stageN.map[x + 2][y] == BLANK) {   //箱子能移动
                        stageN.map[x + 2][y] = BOX;
                        stageN.map[x + 1][y] = BLANK;
                        stageN.player.Down();
                        inin = BOX;
                        stageN.player.D = down;  //推箱子方向
                        steps.push(step(down, BOX));
                    } else if (stageN.map[x + 2][y] == GOAL) {  //箱子推到终点
                        stageN.map[x + 2][y] = REACH;
                        stageN.map[x + 1][y] = BLANK;
                        stageN.player.Down();
                        inin = REACH;
                        stageN.player.D = down;  //推箱子方向
                        ++satisfy;               //到达目标点箱子加一
                        steps.push(step(down, REACH));
                    } else
                        goto end;  //箱子无法推动

                } else {  //墙
                    goto end;
                }
                break;
            }
            case 'a':
            case 'A': {
                if (stageN.map[x][y - 1] == BLANK || stageN.map[x][y - 1] == GOAL) {  //空
                    stageN.player.Left();
                    inin = BLANK;
                    steps.push(step(left, BLANK));
                } else if (stageN.map[x][y - 1] == REACH) {  //箱子推出目标点
                    if (stageN.map[x][y - 2] == BLANK) {     //箱子能移动
                        stageN.map[x][y - 2] = BOX;
                        stageN.map[x][y - 1] = GOAL;
                        stageN.player.Left();
                        inin = BOX;
                        stageN.player.D = left;  //推箱子方向
                        --satisfy;               //到达目标点箱子减一
                        steps.push(step(left, BOX));
                    } else if (stageN.map[x][y - 2] == GOAL) {  //箱子推到终点
                        stageN.map[x][y - 2] = REACH;
                        stageN.map[x][y - 1] = GOAL;
                        stageN.player.Left();
                        inin = REACH;
                        stageN.player.D = left;  //推箱子方向
                        steps.push(step(left, REACH));
                    } else
                        goto end;                          //箱子无法推动
                } else if (stageN.map[x][y - 1] == BOX) {  //箱子
                    if (stageN.map[x][y - 2] == BLANK) {   //箱子能移动
                        stageN.map[x][y - 2] = BOX;
                        stageN.map[x][y - 1] = BLANK;
                        stageN.player.Left();
                        inin = BOX;
                        stageN.player.D = left;  //推箱子方向
                        steps.push(step(left, BOX));
                    } else if (stageN.map[x][y - 2] == GOAL) {  //箱子推到终点
                        stageN.map[x][y - 2] = REACH;
                        stageN.map[x][y - 1] = BLANK;
                        stageN.player.Left();
                        inin = REACH;
                        stageN.player.D = left;  //推箱子方向
                        ++satisfy;               //到达目标点箱子加一
                        steps.push(step(left, REACH));
                    } else
                        goto end;  //箱子无法推动

                } else {  //墙
                    goto end;
                }
                break;
            }
            case 'd':
            case 'D': {
                if (stageN.map[x][y + 1] == BLANK || stageN.map[x][y + 1] == GOAL) {  //空
                    stageN.player.Right();
                    inin = BLANK;
                    steps.push(step(right, BLANK));
                } else if (stageN.map[x][y + 1] == REACH) {  //箱子推出目标点
                    if (stageN.map[x][y + 2] == BLANK) {     //箱子能移动
                        stageN.map[x][y + 2] = BOX;
                        stageN.map[x][y + 1] = GOAL;
                        stageN.player.Right();
                        inin = BOX;
                        stageN.player.D = right;  //推箱子方向
                        --satisfy;                //到达目标点箱子减一
                        steps.push(step(right, BOX));
                    } else if (stageN.map[x][y + 2] == GOAL) {  //箱子推到终点
                        stageN.map[x][y + 2] = REACH;
                        stageN.map[x][y + 1] = GOAL;
                        stageN.player.Right();
                        inin = REACH;
                        stageN.player.D = right;  //推箱子方向
                        steps.push(step(right, REACH));
                    } else
                        goto end;                          //箱子无法推动
                } else if (stageN.map[x][y + 1] == BOX) {  //箱子
                    if (stageN.map[x][y + 2] == BLANK) {   //箱子能移动
                        stageN.map[x][y + 2] = BOX;
                        stageN.map[x][y + 1] = BLANK;
                        stageN.player.Right();
                        inin = BOX;
                        stageN.player.D = right;  //推箱子方向
                        steps.push(step(right, BOX));
                    } else if (stageN.map[x][y + 2] == GOAL) {  //箱子推到终点
                        stageN.map[x][y + 2] = REACH;
                        stageN.map[x][y + 1] = BLANK;
                        stageN.player.Right();
                        inin = REACH;
                        stageN.player.D = right;  //推箱子方向
                        ++satisfy;                //到达目标点箱子加一
                        steps.push(step(right, REACH));
                    } else
                        goto end;  //箱子无法推动

                } else {  //墙
                    goto end;
                }
                break;
            }
            case 'r':
            case 'R': {  //重新开始该关卡
                coord.X = 0, coord.Y = stageN.map.size() + 2;
                SetConsoleCursorPosition(hOut, coord);
                char restart = 2;
                cout << "是否重新开始本关卡 是--1 否--0";
                while (restart = getch()) {
                    if (restart == '1') {  //继续下一关
                        system("cls");
                        return true;
                    } else if (restart == '0') {  //不进行操作
                        SetConsoleCursorPosition(hOut, coord);
                        cout << "                                ";
                        coord.X = stageN.player.Y * 2, coord.Y = stageN.player.X;
                        SetConsoleCursorPosition(hOut, coord);
                        goto end;
                    }
                }
                break;
            }
            case 'z':
            case 'Z': {                //撤回操作
                if (!steps.empty()) {  //回到上一步
                    switch (steps.top().D) {
                        case up: {  //向下
                            inin = BLANK;
                            if (steps.top().push == BOX) {
                                inin = WALL;
                                stageN.player.D = up;
                                stageN.map[x - 1][y] = BLANK;
                                if (stageN.map[x][y] == BLANK)
                                    stageN.map[x][y] = BOX;
                                else {
                                    stageN.map[x][y] = REACH;
                                    ++satisfy;
                                }
                            } else if (steps.top().push == REACH) {
                                --satisfy;
                                inin = GOAL;
                                stageN.player.D = up;
                                stageN.map[x - 1][y] = GOAL;
                                stageN.map[x][y] = BOX;
                            }
                            stageN.player.Down();
                            break;
                        }
                        case down: {  //向上
                            inin = BLANK;
                            if (steps.top().push == BOX) {
                                inin = WALL;
                                stageN.player.D = down;
                                stageN.map[x + 1][y] = BLANK;
                                if (stageN.map[x][y] == BLANK)
                                    stageN.map[x][y] = BOX;
                                else {
                                    stageN.map[x][y] = REACH;
                                    ++satisfy;
                                }
                            } else if (steps.top().push == REACH) {
                                --satisfy;
                                inin = GOAL;
                                stageN.player.D = down;
                                stageN.map[x + 1][y] = GOAL;
                                stageN.map[x][y] = BOX;
                            }
                            stageN.player.Up();
                            break;
                        }
                        case left: {  //向右
                            inin = BLANK;
                            if (steps.top().push == BOX) {
                                inin = WALL;
                                stageN.player.D = left;
                                stageN.map[x][y - 1] = BLANK;
                                if (stageN.map[x][y] == BLANK)
                                    stageN.map[x][y] = BOX;
                                else {
                                    stageN.map[x][y] = REACH;
                                    ++satisfy;
                                }
                            } else if (steps.top().push == REACH) {
                                --satisfy;
                                inin = GOAL;
                                stageN.player.D = left;
                                stageN.map[x][y - 1] = GOAL;
                                stageN.map[x][y] = BOX;
                            }
                            stageN.player.Right();
                            break;
                        }
                        case right: {  //向左
                            inin = BLANK;
                            if (steps.top().push == BOX) {
                                inin = WALL;
                                stageN.player.D = right;
                                stageN.map[x][y + 1] = BLANK;
                                if (stageN.map[x][y] == BLANK)
                                    stageN.map[x][y] = BOX;
                                else {
                                    stageN.map[x][y] = REACH;
                                    ++satisfy;
                                }
                            } else if (steps.top().push == REACH) {
                                --satisfy;
                                inin = GOAL;
                                stageN.player.D = right;
                                stageN.map[x][y + 1] = GOAL;
                                stageN.map[x][y] = BOX;
                            }
                            stageN.player.Left();
                            break;
                        }
                    }
                    steps.pop();
                    score -= 2;
                } else {  //步骤栈为空，无响应
                    goto end;
                }
                break;
            }
            case 'q':
            case 'Q': {
                coord.X = 0, coord.Y = stageN.map.size() + 2;
                SetConsoleCursorPosition(hOut, coord);
                char restart = 2;
                cout << "是否返回主菜单 是--1 否--0";
                while (restart = getch()) {
                    if (restart == '1') {  //继续下一关
                        system("cls");
                        return false;
                    } else if (restart == '0') {  //不进行操作
                        SetConsoleCursorPosition(hOut, coord);
                        cout << "                                ";
                        coord.X = stageN.player.Y * 2, coord.Y = stageN.player.X;
                        SetConsoleCursorPosition(hOut, coord);
                        goto end;
                    }
                }
                break;
            }
            default: {  //无效输入
                goto end;
            }
        }

        //移动一步加一分
        ++score;
        //绘制输出画面
        if (stageN.map[x][y] == BLANK)
            cout << "  ";  //玩家移动前位置置空
        else if (stageN.map[x][y] == GOAL)
            cout << "□";  //玩家移动前位置变回目标点
        else if (stageN.map[x][y] == REACH)
            cout << "★";
        else if (stageN.map[x][y] == BOX)
            cout << "※";

        coord.X = stageN.player.Y * 2, coord.Y = stageN.player.X;
        SetConsoleCursorPosition(hOut, coord);  //光标移动至玩家位置
        cout << "♀";

        if (inin == BOX || inin == REACH || inin == GOAL || inin == WALL) {
            switch (stageN.player.D) {  //判断箱子方向
                case up: {
                    if (inin == GOAL || inin == WALL)
                        coord.Y -= 2;
                    else
                        coord.Y -= 1;
                    break;
                }
                case down: {
                    if (inin == GOAL || inin == WALL)
                        coord.Y += 2;
                    else
                        coord.Y += 1;
                    break;
                }
                case left: {
                    if (inin == GOAL || inin == WALL)
                        coord.X -= 4;
                    else
                        coord.X -= 2;
                    break;
                }
                case right: {
                    if (inin == GOAL || inin == WALL)
                        coord.X += 4;
                    else
                        coord.X += 2;
                    break;
                }
            }
            SetConsoleCursorPosition(hOut, coord);

            if (inin == BOX)
                cout << "※";
            else if (inin == REACH)
                cout << "★";
            else if (inin == GOAL)
                cout << "□";
            else
                cout << "  ";
        }

        //打印分数
        coord.X = 26, coord.Y = stageN.map.size();
        Sleep(30);  //时间过小图像打印会出现问题
        SetConsoleCursorPosition(hOut, coord);
        cout << score << ' ';

        //光标回到人物位置
        coord.X = stageN.player.Y * 2, coord.Y = stageN.player.X;
        SetConsoleCursorPosition(hOut, coord);

        if (satisfy == stageN.num) {                       //所有箱子推到目标点
            if (score < scores[now]) scores[now] = score;  //更新历史最好成绩
            Sleep(300);
            system("cls");
            cout << "第" << now << "关通过！"
                 << " 分数为：" << score << "  历史最低分为：" << scores[now] << endl;

            if (now < num) {  //询问是否进行下一关
                cout << "是否进行下一关 是--1 否--0" << endl;
                char choose = 2;
                while (choose = getch()) {
                    if (choose == '1') {  //继续下一关
                        system("cls");
                        ++now;
                        return true;
                    } else if (choose == '0') {  //返回主菜单
                        return false;
                    }
                }
            } else {  //全部通过
                cout << "恭喜你通过了全部关卡！！！" << endl;
                system("pause");
                system("cls");
                return false;
            }
        }
    end:
        continue;
    }
    throw exception();
    return false;
}

void UpdateScores() {  //分数保存至文件中
    ofstream outfile;
    outfile.open("scores.dat");
    vector<int>::const_iterator it = scores.begin() + 1;
    while (it != scores.end() - 1) {
        outfile << *it << endl;
        ++it;
    }
    outfile << *it;
    outfile.close();
}

void pushBoxes() {  //推箱子游戏
    StageInitialize();
wel:
    if (Welcome()) goto end;
show:
    ShowStage();
    if (Move())
        goto show;
    else
        goto wel;
end:
    UpdateScores();
}

int main() {
    HideCursor();
    pushBoxes();
    CloseHandle(hOut);
    return 0;
}