/*本alpha stupid运用简化版机器学习遗传算法模型对于棋手策略参数进行优化;
用棋手互相对局，每一代进行排名，对局获胜的靠前，优秀的棋手互相交配（参数取均值）；
由于仅用本机CPU生一代就要1个小时左右，所以我仅仅繁殖了四代（本应跑上万代才有点用）
数据如下：（靠前的五个比较优秀，后五个是每一代新生成的）
generation=0:
0:402.000000 1:218.000000 2:71.000000 3:33.000000 4:13.000000 5:1.000000 6:1.000000
0:790.000000 1:409.000000 2:146.000000 3:54.000000 4:8.000000 5:5.000000 6:1.000000
0:597.000000 1:300.000000 2:65.000000 3:22.000000 4:9.000000 5:1.000000 6:1.000000
0:687.000000 1:104.000000 2:97.000000 3:21.000000 4:13.000000 5:2.000000 6:1.000000
0:652.000000 1:178.000000 2:77.000000 3:44.000000 4:20.000000 5:3.000000 6:1.000000
0:388.000000 1:281.000000 2:113.000000 3:40.000000 4:14.000000 5:1.000000 6:1.000000
0:1274.000000 1:375.000000 2:91.000000 3:18.000000 4:7.000000 5:4.000000 6:1.000000
0:521.000000 1:341.000000 2:66.000000 3:51.000000 4:11.000000 5:1.000000 6:1.000000
0:944.000000 1:296.000000 2:49.000000 3:26.000000 4:8.000000 5:3.000000 6:1.000000
0:902.000000 1:144.000000 2:105.000000 3:61.000000 4:20.000000 5:2.000000 6:1.000000
generation=1:
0:944.000000 1:296.000000 2:49.000000 3:26.000000 4:8.000000 5:3.000000 6:1.000000
0:687.000000 1:104.000000 2:97.000000 3:21.000000 4:13.000000 5:2.000000 6:1.000000
0:402.000000 1:218.000000 2:71.000000 3:33.000000 4:13.000000 5:1.000000 6:1.000000
0:790.000000 1:409.000000 2:146.000000 3:54.000000 4:8.000000 5:5.000000 6:1.000000
0:597.000000 1:300.000000 2:65.000000 3:22.000000 4:9.000000 5:1.000000 6:1.000000
0:596.000000 1:313.500000 2:108.500000 3:43.500000 4:10.500000 5:3.000000 6:1.000000 
0:867.000000 1:352.500000 2:97.500000 3:40.000000 4:8.000000 5:4.000000 6:1.000000
0:790.000000 1:409.000000 2:146.000000 3:54.000000 4:8.000000 5:5.000000 6:1.000000
0:596.000000 1:313.500000 2:108.500000 3:43.500000 4:10.500000 5:3.000000 6:1.000000
0:842.000000 1:124.000000 2:61.000000 3:36.000000 4:21.000000 5:4.000000 6:1.000000
generation=2:
0:596.000000 1:313.500000 2:108.500000 3:43.500000 4:10.500000 5:3.000000 6:1.000000
0:867.000000 1:352.500000 2:97.500000 3:40.000000 4:8.000000 5:4.000000 6:1.000000 
0:597.000000 1:300.000000 2:65.000000 3:22.000000 4:9.000000 5:1.000000 6:1.000000
0:944.000000 1:296.000000 2:49.000000 3:26.000000 4:8.000000 5:3.000000 6:1.000000
0:687.000000 1:104.000000 2:97.000000 3:21.000000 4:13.000000 5:2.000000 6:1.000000
0:770.000000 1:304.750000 2:78.750000 3:34.750000 4:9.250000 5:3.000000 6:1.000000
0:770.500000 1:298.000000 2:57.000000 3:24.000000 4:8.500000 5:2.000000 6:1.000000
0:731.500000 1:333.000000 2:103.000000 3:41.750000 4:9.250000 5:3.500000 6:1.000000 
0:770.500000 1:298.000000 2:57.000000 3:24.000000 4:8.500000 5:2.000000 6:1.000000
0:867.000000 1:127.000000 2:55.000000 3:25.000000 4:12.000000 5:2.000000 6:1.000000
generation=3:
0:770.000000 1:304.750000 2:78.750000 3:34.750000 4:9.250000 5:3.000000 6:1.000000  
0:687.000000 1:104.000000 2:97.000000 3:21.000000 4:13.000000 5:2.000000 6:1.000000 
0:596.000000 1:313.500000 2:108.500000 3:43.500000 4:10.500000 5:3.000000 6:1.000000 
0:944.000000 1:296.000000 2:49.000000 3:26.000000 4:8.000000 5:3.000000 6:1.000000   
0:731.500000 1:333.000000 2:103.000000 3:41.750000 4:9.250000 5:3.500000 6:1.000000  
0:944.000000 1:296.000000 2:49.000000 3:26.000000 4:8.000000 5:3.000000 6:1.000000   
0:857.000000 1:300.375000 2:63.875000 3:30.375000 4:8.625000 5:3.000000 6:1.000000   
0:770.000000 1:304.750000 2:78.750000 3:34.750000 4:9.250000 5:3.000000 6:1.000000   
0:770.000000 1:304.750000 2:78.750000 3:34.750000 4:9.250000 5:3.000000 6:1.000000   
0:1160.000000 1:345.000000 2:70.000000 3:33.000000 4:9.000000 5:1.000000 6:1.000000 
generation=4:
0:770.000000 1:304.750000 2:78.750000 3:34.750000 4:9.250000 5:3.000000 6:1.000000
0:687.000000 1:104.000000 2:97.000000 3:21.000000 4:13.000000 5:2.000000 6:1.000000
0:596.000000 1:313.500000 2:108.500000 3:43.500000 4:10.500000 5:3.000000 6:1.000000
0:944.000000 1:296.000000 2:49.000000 3:26.000000 4:8.000000 5:3.000000 6:1.000000
0:731.500000 1:333.000000 2:103.000000 3:41.750000 4:9.250000 5:3.500000 6:1.000000 
0:944.000000 1:296.000000 2:49.000000 3:26.000000 4:8.000000 5:3.000000 6:1.000000
0:944.000000 1:296.000000 2:49.000000 3:26.000000 4:8.000000 5:3.000000 6:1.000000
0:770.000000 1:304.750000 2:78.750000 3:34.750000 4:9.250000 5:3.000000 6:1.000000
0:770.000000 1:304.750000 2:78.750000 3:34.750000 4:9.250000 5:3.000000 6:1.000000
0:1007.000000 1:336.000000 2:124.000000 3:27.000000 4:14.000000 5:4.000000 6:1.000000

这一个棋手目前看来比较优秀：
0:770.000000 1:304.750000 2:78.750000 3:34.750000 4:9.250000 5:3.000000 6:1.000000

与玩家的对战在game_start函数，wasd进行移动，j进行落子。运用第四代最优棋手
的参数，本alpha_stupid的策略似乎还不错，可以虐室友了。本次由于时间问题暂
时没有用easyx进行图形优化，后续将使用easyx对界面进行设计；
*/

#include <bits/stdc++.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#define consider_step 4 //考虑步数
#define total_num 10    //棋手人数
#define size 11         //棋盘大小
#define generations 10  //进化代数
#define mod (1 + total_num / 2) * total_num / 4
using namespace std;

//空闲为0 先手执白1 后手执黑2
struct ChessBoard //某种局面
{
    int board[size][size];                     //仅需保存一盘棋局即可
    bool end_game(int x, int y, int condition) //判断游戏是否结束
    {
        for (int i = 0; i <= 7; i += 2)
            if (judge(x, y, condition, i) + judge(x, y, condition, i + 1) - 1 >= 5)
                return true;
        return false;
    }
    void print_board() //打印棋盘
    {
        system("cls");
        printf("\n");
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == -1)
                    printf("%c", '|');
                if (board[i][j] == 0)
                    printf("_");
                if (board[i][j] == 1)
                    printf("%c", 'x');
                if (board[i][j] == 2)
                    printf("%c", 'o');
                printf(" ");
            }
            printf("\n");
        }
    }
    int judge(int x, int y, int condition, int direction)
    { //判断第一个阻挡点,八个方向 0上 1下 2左 3右 4右上 5左下 6左上 7右下
        int con = 0;
        if (direction == 0) //上
        {
            while (board[x - con][y] == condition)
            {
                ++con;
                if (x - con == -1)
                    break;
            }
            return con;
        }
        if (direction == 1) //下
        {
            while (board[x + con][y] == condition)
            {
                ++con;
                if (x + con == size)
                    break;
            }
            return con;
        }
        if (direction == 2) //左
        {
            while (board[x][y - con] == condition)
            {
                ++con;
                if (y - con == -1)
                    break;
            }
            return con;
        }
        if (direction == 3) //右
        {
            while (board[x][y + con] == condition)
            {
                ++con;
                if (y + con == size)
                    break;
            }
            return con;
        }
        if (direction == 4) //右上
        {
            while (board[x - con][y + con] == condition)
            {
                ++con;
                if (x - con == -1 || y + con == size)
                    break;
            }
            return con;
        }
        if (direction == 5) //左下
        {
            while (board[x + con][y - con] == condition)
            {
                ++con;
                if (x + con == size || y - con == -1)
                    break;
            }
            return con;
        }
        if (direction == 6) //左上
        {
            while (board[x - con][y - con] == condition)
            {
                ++con;
                if (x - con == -1 || y - con == -1)
                    break;
            }
            return con;
        }
        if (direction == 7) //右下
        {
            while (board[x + con][y + con] == condition)
            {
                ++con;
                if (x + con == size || y + con == size)
                    break;
            }
            return con;
        }
        return 0;
    }
} B;

struct Node;
int fight(Node *a, Node *b);

struct Node //棋手，不同策略
{
    double weight[10];
    //权重: 0五子相连 1四子两空 2四子一空 3三子两空 4三子一空 5两子两空 6两子一空
    //规定5恒为1.0
    void show_parameter() //展示参数
    {
        for (int i = 0; i <= 6; i++)
            printf("%d:%lf ", i, weight[i]);
        printf("\n");
    }
    void create() //创造一个新骑手
    {
        weight[6] = 1.0; //保证其为常数
        weight[5] = rand() % 5 + weight[6];
        weight[4] = rand() % 20 + weight[5];
        weight[3] = rand() % 50 + weight[4];
        weight[2] = rand() % 100 + weight[3];
        weight[1] = rand() % 300 + weight[2];
        weight[0] = rand() % 1000 + weight[1]; //保证递增
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
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
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
        if (round == 1)
        {
            X1 = rand() % size;
            X2 = rand() % size;
        }
        else
        {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                {
                    if (!B.board[i][j]) //可以落子
                    {
                        new_value = take_step_value(i, j, 1, a, 1); //得到分数
                        if (new_value > value)
                        {
                            value = new_value;
                            X1 = i;
                            Y1 = j;
                        }
                        if (new_value == value && (rand() | 1))
                        {
                            value = new_value;
                            X1 = i;
                            Y1 = j;
                        }
                    }
                }
        }
        B.board[X1][Y1] = 1;
        value = -INT_MAX;
        if (B.end_game(X1, Y1, 1)) //先手五子连线
            return 1;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                if (!B.board[i][j]) //可以落子
                {
                    new_value = take_step_value(i, j, 2, b, 1);
                    if (new_value > value)
                    {
                        value = new_value;
                        X2 = i;
                        Y2 = j;
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
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                if (B.board[i][j])
                    continue;
                new_score = take_step_value(i, j, 2, &node[1], 1); //用最强的电脑棋手与之对战
                if (new_score > score)
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
    game_start(); //上面皆为机器学习内容，学习完成后玩家可与node[1]对战
    //这组参数较为优秀 0:770.000000 1:304.750000 2:78.750000 3:34.750000 4:9.250000 5:3.000000 6:1.000000
    return 0;
}