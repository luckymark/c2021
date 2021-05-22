/*
#include "go.h"
typedef struct
{
    int Alpha;
    int Beta;
    int X;
    int Y;
}Tree;
//怎么表示撇捺？不好批量建立一维数组，斜着的再建立二维数组

int search(int x, int y, int me, int vis[][L + 2], int copy[][L + 2])//搜索有多少颗连子
{
    int value = 0;
    int maxdir = 0;
    int T, F;

    if (me == 1)
    {
        T = red;
        F = white;
    }
    else
    {
        F = red;
        T = white;
    }

    for (int i = 0;i < 8;i++)//i表示八个方向
        for (int j = 1;j <= 5;j++)//j表示沿这个方向走了几步
        {
            int dx = x + j * dir[i][0];
            int dy = y + j * dir[i][1];
            if (copy[dx][dy] != T)
            {
                if (j > value)
                {
                    value = j;//记录最大连子数和最大的方向
                    maxdir = i;
                }
                break;
            }
        }

    //特殊情况优先

    //标记已经搜索且在最大路径上的节点，避免重复搜索
    for (int j = 0;j <= value;j++)
    {
        int dx = x + j * dir[maxdir][0];
        int dy = y + j * dir[maxdir][1];
        vis[dx][dy] = 1;
    }

    //判断连子的死活
    int dx1 = x + value * dir[maxdir][0];
    int dy1 = y + value * dir[maxdir][1];
    int dx2 = x - dir[maxdir][0];
    int dy2 = y - dir[maxdir][1];
    if (dx1 < 0 || dy1 < 0)
        value--;
    else
        if (copy[dx1][dy1] == F || copy[dx1][dy1] == wall)
            value--;
    if (copy[dx2][dy2] == F || copy[dx2][dy2] == wall)
        value--;
    return value;
}

int evaluate(int me, int copy[][L + 2])//全局评估某一方的分数,turn=1评估red，a=2评估white
{
    int  k = 0, score = 0;
    int value = 0;
    int vis[17][17] = { {0},{0} };

    //遍历找到我方棋子开始search 连子
    for (int i = 1;i < L + 1;i++)
        for (int j = 1;j < L + 1;j++)
        {
            if (copy[i][j] == me && (!vis[i][j]))//是我方且没有被搜索过
            {
                value = search(i, j, me, vis, copy);
                //计分方式：n连子，10^n，有一边死了n-1
                score = score + pow(10, value);
            }
        }
    return score;
}

int minMax_AB(int depth, int me, int Alpha, int Beta)
//分数传递,t为1表示红棋，为2表示白棋,调用时Alpha，Beta赋为NGIF,PTIF
{
    int i, j;
    int c[L + 2][L + 2];
    int minmax;
    int rival;
    Tree tree;
    tree.Alpha = Alpha;
    tree.Beta = Beta;
    tree.X = 0;
    tree.Y = 0;
    if (me == 1)
        rival = 2;
    else
        rival = 1;
    if (depth == 0 || judge_winner(tree.X, tree.Y, me) == me)
        return evaluate(me);
    if (depth % 2 == 0)//判断是min层还是max层,偶数是min层
    {
        for (i = 1;i < L + 1;i++)
            for (j = 1;j < L + 1;j++)
            {
                if (!board[i][j] && neighbor(i, j) && tree.Alpha < tree.Beta)
                {
                    c[i][j] = me;
                    minmax = minMax_AB(depth - 1, rival, tree.Alpha, tree.Beta);
                    c[i][j] = 0;
                    if (minmax < tree.Beta)
                    {
                        tree.Beta = minmax;
                        tree.X = j;
                        tree.Y = i;
                        if (tree.Alpha >= tree.Beta)
                            return tree.Alpha;//α剪枝，抛弃后续节点
                    }
                }
            }
        return tree.Beta;
    }
    else
    {
        for (i = 1;i < L + 1;i++)
            for (j = 1;j < L + 1;j++)
            {
                if (!board[i][j] && neighbor(i, j) && tree.Alpha < tree.Beta)
                {
                    //用一个新的数组表示棋盘，以免破坏原棋盘
                    c[i][j] = me;
                    minmax = minMax_AB(depth - 1, rival, tree.Alpha, tree.Beta);
                    c[i][j] = 0;
                    if (minmax > tree.Alpha)
                    {
                        tree.Alpha = minmax;
                        tree.X = j;
                        tree.Y = i;
                        if (tree.Alpha >= tree.Beta)
                            return tree.Beta;//α剪枝，抛弃后续节点
                    }
                }
            }
        AI_x = tree.X;
        AI_y = tree.Y;
        return tree.Alpha;
    }

}


int neighbor(int x, int y)//判断空位置两步之内是否有邻居
{
    for (int di = 0;di < 8;di++)//i表示八个方向
        for (int dj = 1;dj < 3;dj++)//j表示沿这个方向走了几步
        {
            int dx = x + dj * dir[di][0];
            int dy = y + dj * dir[di][1];
            if (dx > 0 && dx < L + 1 && dy>0 && dy < L + 1)
                if (board[dx][dy] == red || board[dx][dy] == white)
                    return 1;
        }
    return 0;
}

*/
