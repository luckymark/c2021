#include "chessboard.cpp"
#include "head.cpp"

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