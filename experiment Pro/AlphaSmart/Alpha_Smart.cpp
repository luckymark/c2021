#include <bits/stdc++.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#ifndef consider_step
#define consider_step 4 //考虑步数
#define total_num 10    //棋手人数
#define size 15         //棋盘大小
#define generations 10  //进化代数
#define mod (1 + total_num / 2) * total_num / 4
using namespace std;
int previousx, previousy;
#endif
struct Node;
int fight(Node *a, Node *b);

struct Node //棋手，不同策略
{
    double weight[10];
    /*权重: 0五子相连 1四子两空 2四子一空 3三子两空 4三子一空
    5两子两空 6两子一空 7四子不空
    */
    //规定6恒为1.0 7为负
    void show_parameter() //展示参数
    {
        for (int i = 0; i <= 6; i++)
            printf("%d:%lf ", i, weight[i]);
        printf("\n");
    }
    void create() //创造一个新骑手
    {
        weight[6] = 1.0; //保证其为常数
        weight[5] = rand() % 10 + weight[6];
        weight[4] = rand() % 500 + 100 + weight[5];
        weight[3] = rand() % 2000 + 500 + weight[4];
        weight[2] = rand() % 5000 + 1000 + weight[3];
        weight[1] = rand() % 10000 + 10000 + weight[2];
        weight[0] = 1000000;          //保证递增
        weight[7] = -(rand() % 4000); //防止走无谓的步数
    }
    bool operator<(Node p) //对战结果决定排名
    {
        int win_game = 0;               //this赢的局数，两局，赢1平0负-1
        win_game += fight(this, &p);    //this先手
        win_game -= (!fight(&p, this)); //this后手
        if (win_game >= 0)
            return true;
        return false;
    }
    inline void variation()
    {
        int pos = rand() % 6;
        if (pos == 0)
            return;
        weight[pos] = (weight[pos - 1] + weight[pos + 1]) / 2;
    }
} node[total_num];

double get_score(int num, int blocks, Node *player) //连线数 封锁数 玩家
{
    if (num >= 5)
    {
        return player->weight[0]; //五子连线
    }
    else if (num == 4)
    {
        if (!blocks)
            return player->weight[1]; //四子两空
        if (blocks == 1)
            return player->weight[2]; //四子一空
        if (blocks == 2)
            return player->weight[7]; //四子不空
    }
    else if (num == 3)
    {
        if (!blocks)
            return player->weight[3]; //三子两空
        if (blocks == 1)
            return player->weight[4]; //三子一空
    }
    else if (num == 2)
    {
        if (!blocks)
            return player->weight[5]; //两子两空
        if (blocks == 1)
            return player->weight[6]; //两子一空
    }
    return 0;
}

double take_step_value(int x, int y, int condition, Node *player, int step)
{                                                                 //计算落子获得分数:坐标 黑白 弈者 步数，奇为自己，偶为对手
    B.board[x][y] = condition;                                    //落子
    double score = 0, new_score, attain_score = -double(INT_MAX); //最终分数 暂时分数 下一步最优分数
                                                                  //if (!(step | 1))
    int k1, k2, blocks;                                           //能走的步数 封堵数
    blocks = 0;
    k1 = B.judge(x, y, condition, 0); //上下
    k2 = B.judge(x, y, condition, 1);
    if (x - k1 == -1 || B.board[x - k1][y] == 3 - condition)
        blocks++;
    if (x + k2 == size || B.board[x + k1][y] == 3 - condition)
        blocks++;
    score += get_score(k1 + k2 - 1, blocks, player);
    blocks = 0;
    k1 = B.judge(x, y, condition, 2); //左右
    k2 = B.judge(x, y, condition, 3);
    if (y - k1 == -1 || B.board[x][y - k1] == 3 - condition)
        blocks++;
    if (y + k2 == size || B.board[x][y + k2] == 3 - condition)
        blocks++;
    score += get_score(k1 + k2 - 1, blocks, player);
    blocks = 0;
    k1 = B.judge(x, y, condition, 4); //右上
    k2 = B.judge(x, y, condition, 5);
    if (x - k1 == -1 || y + k1 == size || B.board[x - k1][y + k1] == 3 - condition)
        blocks++;
    if (x + k2 == size || y - k2 == -1 || B.board[x + k2][y - k2] == 3 - condition)
        blocks++;
    score += get_score(k1 + k2 - 1, blocks, player);
    blocks = 0;
    k1 = B.judge(x, y, condition, 6); //右下
    k2 = B.judge(x, y, condition, 7);
    if (x + k1 == size || y + k1 == size || B.board[x + k1][y + k1] == 3 - condition)
        blocks++;
    if (x - k2 == -1 || y - k2 == -1 || B.board[x - k2][y - k2] == 3 - condition)
        blocks++;
    score += get_score(k1 + k2 - 1, blocks, player);
    if (step < consider_step) //仍需考虑下一步
    {
        for (int i = max(0, previousx - 5); i < min(size, previousx + 5); i++)
            for (int j = max(0, previousy - 5); j < min(size, previousy + 5); j++)
            {
                if (!B.board[i][j])
                {
                    new_score = take_step_value(i, j, 3 - condition, player, step + 1);
                    //以自己的思维模拟对方出棋
                    if (new_score > attain_score)
                        attain_score = new_score;
                }
            }
    }
    else
        attain_score = 0;
    B.board[x][y] = 0;
    return score - attain_score;
}

int fight(Node *a, Node *b) //a先手b后手对战
{
    int round = 0;
    memset(B.board, 0, sizeof(B.board)); //清空棋盘
    while (true)
    {
        round += 2;
        if (round >= size * size - 4) //和棋
            return 0;
        double value = -double(INT_MAX), new_value; //最大分数
        int X1 = 0, Y1 = 0, X2 = 0, Y2 = 0;         //决定落子位置
        if (round == 1)                             //第一步乱下
        {
            previousx = X1 = rand() % size;
            previousy = Y2 = rand() % size;
        }
        else
        {
            for (int i = max(0, previousx - 5); i < min(size, previousx + 5); i++)
                for (int j = max(0, previousy - 5); j < min(size, previousy + 5); j++)
                {
                    if (!B.board[i][j]) //可以落子
                    {
                        new_value = take_step_value(i, j, 1, a, 1); //得到分数
                        if ((new_value > value) || (new_value == value && (rand() | 1)))
                        {
                            value = new_value;
                            previousx = X1 = i;
                            previousy = Y1 = j;
                        }
                    }
                }
        }
        B.board[X1][Y1] = 1;
        value = -INT_MAX;
        if (B.end_game(X1, Y1, 1)) //先手五子连线
            return 1;
        for (int i = max(0, previousx - 5); i < min(size, previousx + 5); i++)
            for (int j = max(0, previousy - 5); j < min(size, previousy + 5); j++)
            {
                if (!B.board[i][j]) //可以落子
                {
                    new_value = take_step_value(i, j, 2, b, 1);
                    if ((new_value > value) || (new_value == value && (rand() | 1)))
                    {
                        value = new_value;
                        previousx = X2 = i;
                        previousy = Y2 = j;
                    }
                }
            }
        B.board[X2][Y2] = 2;
        if (B.end_game(X2, Y2, 2))
            return -1; //后手五子连线
    }
}

int Russian_roulette() //轮盘赌，凭借概率提取父母
{
    int chosen = int(long(rand()) * long(rand()) % mod);
    //排名靠前获得更大遗传概率
    int _down = 1, _up = total_num / 2;
    int mid = (_up + _down) / 2;
    while (mid > _down)
    {
        if ((1 + mid) * mid / 2 < chosen)
        {
            _down = mid;
            mid = (mid + _up) / 2;
            continue;
        }
        else if ((1 + mid) * mid / 2 > chosen)
        {
            _up = mid;
            mid = (mid + _down) / 2;
            continue;
        }
        else
            return total_num / 2 - mid;
    }
    return total_num / 2 - mid;
}

void GA() //棋手进行遗传淘汰
{         //每一代淘汰一半棋手
    sort(node + 1, node + 1 + total_num);
    for (int i = total_num / 2 + 1; i <= total_num - 1; i++) //生产后代
    {
        int parent1 = Russian_roulette();
        int parent2 = Russian_roulette();
        for (int j = 0; j <= 6; j++)
            node[i].weight[j] = (node[parent1].weight[j] + node[parent2].weight[j]) / 2.0; //遗传
    }
    node[total_num].create();                 //每次重新创造一个棋手
    for (int i = 1; i <= total_num / 20; i++) //对1/20的棋手进行变异
    {
        int k = rand() % total_num + 1;
        node[k].variation();
    }
}

void game_start() //玩家对战电脑模式，玩家先手
{
    memset(B.board, 0, sizeof(B.board));
    printf("player first? y or n\n");
    char c;
    cin >> c;
    if (c == 'n')
        B.board[size / 2][size / 2] = 2; //电脑先手
    B.print_board();
    int round = 0;
    while (true)
    {
        round += 2;
        if (round >= size * size - 4) //和棋
        {
            printf("Peaciful end!");
            return;
        }
        int x = 0, y = 0, pre = B.board[0][0]; //记录之前这个位置的放置类型
        B.board[x][y] = -1;
        while (true) //玩家操作
        {
            char c = getch();
            if (c == 'j' && !pre) //落子
            {
                B.board[x][y] = 1;
                previousx = x;
                previousy = y;
                B.print_board();
                if (B.end_game(x, y, 1)) //玩家获胜
                {
                    printf("The player wins!");
                    return;
                }
                break;
            }
            if (c == 'a') //左
            {
                if (y - 1 > -1)
                {
                    B.board[x][y] = pre;
                    pre = B.board[x][y - 1];
                    --y;
                    B.board[x][y] = -1;
                }
            }
            if (c == 's') //下
            {
                if (x + 1 < size)
                {
                    B.board[x][y] = pre;
                    pre = B.board[x + 1][y];
                    ++x;
                    B.board[x][y] = -1;
                }
            }
            if (c == 'w') //上
            {
                if (x - 1 > -1)
                {
                    B.board[x][y] = pre;
                    pre = B.board[x - 1][y];
                    --x;
                    B.board[x][y] = -1;
                }
            }
            if (c == 'd') //右
            {
                if (y + 1 < size)
                {
                    B.board[x][y] = pre;
                    pre = B.board[x][y + 1];
                    ++y;
                    B.board[x][y] = -1;
                }
            }
            B.print_board();
        }
        int score = -INT_MAX, new_score; //电脑操作
        x = 0;
        y = 0;
        for (int i = max(0, previousx - 5); i < min(size, previousx + 5); i++)
            for (int j = max(0, previousy - 5); j < min(size, previousy + 5); j++)
            {
                if (B.board[i][j])
                    continue;
                new_score = take_step_value(i, j, 2, &node[1], 1); //用最强的电脑棋手与之对战
                if ((new_score > score) || ((new_score == score) && (rand() | 1)))
                {
                    x = i;
                    y = j;
                    score = new_score;
                }
            }
        B.board[x][y] = 2; //落子
        B.print_board();
        if (B.end_game(x, y, 2)) //电脑获胜
        {
            printf("The computer wins!");
            return;
        }
    }
}

int main()
{
    srand(time(NULL));
    cout << "whether to machine learning for 5 hours before play?" << endl
         << "print y for yes, n for no" << endl;
    char c = getchar();
    if (c == 'y') //如果愿意机器自己学习十个小时左右；
    {
        for (int i = 1; i <= total_num; i++)
            node[i].create();
        printf("generation=%d:\n", 0);
        for (int i = 1; i <= total_num; i++)
            node[i].show_parameter();
        for (int generation = 1; generation <= generations; ++generation) //进化代数，确定最优解；
        {
            GA();
            printf("generation=%d:\n", generation);
            for (int i = 1; i <= total_num; i++)
                node[i].show_parameter();
        }
    }
    else
    {
        node[1].weight[0] = 100000;
        node[1].weight[1] = 8000;
        node[1].weight[2] = ;
        node[1].weight[3] = 34.75;
        node[1].weight[4] = 9.25;
        node[1].weight[5] = 3;
        node[1].weight[6] = 1;
        node[1].weight[7] = -4000;
        game_start(); //上面皆为机器学习内容，学习完成后玩家可与node[1]对战
        //这组参数较为优秀 0:770.000000 1:304.750000 2:78.750000 3:34.750000 4:9.250000 5:3.000000 6:1.000000
    }
    return 0;
}