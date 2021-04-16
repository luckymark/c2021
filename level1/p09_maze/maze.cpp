#include <conio.h>  //非标准
#include <windows.h>

#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

//方形迷宫最外圈固定为墙，坐标原点为左上角，终点为右下角
#define MAX_L 50  //迷宫最大边界长度--过大需调整窗口大小
#define WALL -1   //墙
#define BLANK 1   //空
#define up 6      //上
#define down 7    //下
#define left 8    //左
#define right 9   //右

class pos {  //位置类
   public:
    pos(int x = 1, int y = 1, int direction = 0) { X = x, Y = y, D = direction; }
    void Up() { --X; }
    void Down() { ++X; }
    void Left() { --Y; }
    void Right() { ++Y; }
    int X;
    int Y;
    int D;
};

pos player;                                     //玩家,默认初始化位置为(1,1)
char in;                                        //输入wsad进行上下左右移动
int maze[MAX_L][MAX_L];                         //迷宫
vector<pos> block;                              //墙
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // 获取标准输出设备句柄
COORD coord;                                    //坐标

void HideCursor() {
    CONSOLE_CURSOR_INFO CursorInfo;           //光标信息
    GetConsoleCursorInfo(hOut, &CursorInfo);  //获取控制台光标信息
    CursorInfo.bVisible = false;              //隐藏控制台光标
    SetConsoleCursorInfo(hOut, &CursorInfo);  //设置控制台光标状态

    COORD size = {MAX_L * 2 + 10, size.Y = MAX_L + 20};
    int i = SetConsoleScreenBufferSize(hOut, size);

    SMALL_RECT rc = {0, 0, MAX_L * 2 + 10, MAX_L + 20};
    int j = SetConsoleWindowInfo(hOut, true, &rc);
}

void FindBlock() {                                                           //找出与当前位置相邻的墙
    if (player.Y + 1 < MAX_L - 1 && maze[player.X][player.Y + 1] == WALL) {  //向右
        block.push_back(pos(player.X, player.Y + 1, right));
    }
    if (player.Y - 1 > 0 && maze[player.X][player.Y - 1] == WALL) {  //向左
        block.push_back(pos(player.X, player.Y - 1, left));
    }
    if (player.X - 1 > 0 && maze[player.X - 1][player.Y] == WALL) {  //向上
        block.push_back(pos(player.X - 1, player.Y, up));
    }
    if (player.X + 1 < MAX_L - 1 && maze[player.X + 1][player.Y] == WALL) {  //向下
        block.push_back(pos(player.X + 1, player.Y, down));
    }
}

void MazeInitialize() {                //初始化生成迷宫
    maze[player.X][player.Y] = BLANK;  //设置起点
    FindBlock();                       //压入起点下和右的墙
    pos here;                          //聚焦点

    //生成迷宫
    while (!block.empty()) {
        int rPos = rand() % block.size();
        here = block[rPos];
        player.X = here.X, player.Y = here.Y;  //玩家从起点飘到当前位置

        switch (here.D) {
            case up: {
                player.Up();
                break;
            }
            case down: {
                if (player.X + 1 < MAX_L - 1) player.Down();
                break;
            }
            case left: {
                player.Left();
                break;
            }
            case right: {
                if (player.Y + 1 < MAX_L - 1) player.Right();
                break;
            }
        }
        if (maze[player.X][player.Y] == WALL) {  //当前墙两边块均为墙
            maze[here.X][here.Y] = BLANK;        //当前墙置空
            maze[player.X][player.Y] = BLANK;    //目标块墙置空
            FindBlock();
        } else {  //目标块可以到达
        }
        block.erase(block.begin() + rPos);  //删除当前墙
    }
    //打印迷宫
    for (int i = 0; i < MAX_L; ++i) {
        for (int j = 0; j < MAX_L; ++j) {
            if (maze[i][j] == WALL)
                cout << "■";
            else if (maze[i][j] == BLANK)
                cout << "  ";
        }
        cout << endl;
    }
    //设置终点
    coord.X = (MAX_L - 2) * 2, coord.Y = MAX_L - 2;
    SetConsoleCursorPosition(hOut, coord);
    cout << "★";

    //打印玩家
    player.X = 1, player.Y = 1;
    coord.X = player.Y * 2, coord.Y = player.X;
    SetConsoleCursorPosition(hOut, coord);
    cout << "♀";
    SetConsoleCursorPosition(hOut, coord);
}

void Move() {  //控制移动
    clock_t sTime = clock();

    while (in = getch()) {
        switch (in) {
            case 'w':
            case 'W': {
                if (maze[player.X - 1][player.Y] == BLANK)
                    player.Up();
                else
                    goto end;

                break;
            }
            case 's':
            case 'S': {
                if (maze[player.X + 1][player.Y] == BLANK)
                    player.Down();
                else
                    goto end;

                break;
            }
            case 'a':
            case 'A': {
                if (maze[player.X][player.Y - 1] == BLANK)
                    player.Left();
                else
                    goto end;

                break;
            }
            case 'd':
            case 'D': {
                if (maze[player.X][player.Y + 1] == BLANK)
                    player.Right();
                else
                    goto end;
                break;
            }
            default: {  //无效输入
                break;
            }
        }
        if (player.Y == MAX_L - 2 && player.X == MAX_L - 2) {  //判断胜利
            clock_t eTime = clock();

            coord.Y = MAX_L, coord.X = 0;
            SetConsoleCursorPosition(hOut, coord);  //光标移动至玩家位置
            cout << "游戏胜利!!!" << endl;
            cout << "用时: " << (eTime - sTime) / 1000.0 << "秒" << endl;
            return;
        }
        cout << "  ";
        coord.X = player.Y * 2, coord.Y = player.X;
        SetConsoleCursorPosition(hOut, coord);  //光标移动至玩家位置
        cout << "♀";
        SetConsoleCursorPosition(hOut, coord);
        Sleep(10);
    end:
        continue;
    }
}

bool OneMore() {
    cout << "要再来一局吗???" << endl;
    cout << "是: 1 否: 0, 请输入数字" << endl;
    while (in = getch()) {
        if (in == '1') {
            system("cls");
            player.X = 1, player.Y = 1;  //设置玩家初始位置
            return true;
        } else if (in == '0') {
            system("cls");
            cout << "感谢游玩" << endl;
            cout << "再次按0退出程序" << endl;
            while (in = getch())
                if (in == '0') exit(0);
        } else {
            continue;
        }
    }
}

void Maze() {  //迷宫游戏
loop:
    memset(maze, WALL, sizeof(maze));  //填充墙
    MazeInitialize();                  //迷宫出现
    Move();                            //游戏中

    //胜利
    if (OneMore()) goto loop;
    //游戏结束
    CloseHandle(hOut);  // 关闭标准输出设备句柄
}

int main() {
    srand((unsigned)time(NULL));  //随机数种子
    HideCursor();
    Maze();
    return 0;
}