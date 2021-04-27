#include "go.h"
int evaluate(int me, int others);
void generator(int me, int others);
  
//怎么表示撇捺？不好批量建立一维数组，斜着的再建立二维数组


int evaluate(int me,int others)
{   
    int  k=0, score=0;
    int  T = me, F = others;

    for (int i = 1;i < L + 1;i++)//检查横向
        for (int j = 1;j < L + 1;j++)
        {
            if (board[i][j] == T)
            {  

                k = 1;
                int t = j;//用t暂时存储j,方便之后检查前面的情况，然后j++,避免重复检查
                j++;
                while (board[i][j] == T)
                {
                    j++;
                    k++;
                }                 
                if (board[i][j] == F || board[i][t - 1] == F || board[i][j] == wall || board[i][t - 1] == wall)
                    k--;
                if ((board[i][j] == F && board[i][t - 1] == F) || (board[i][j] == wall && board[i][t - 1] == wall))
                    k = -1;//区分死棋和死一
                if (k >= 0)
                    score = score + pow(10, k);
                j = t;
            }
        }

    for (int i = 1;i < L + 1;i++)//竖向检查
        for (int j = 1;j < L + 1;j++)
        {
            if (board[i][j] == T)
            {     
                k = 1;
                int t = i;
                i++;
                while (board[i][j] == T)//i=16,这里经过一次i++后，i已经在连棋的后面一格了
                {
                    i++;
                    k++;
                }
                if (board[t - 1][j] == F || board[i][j] == F || board[t - 1][j] == wall || board[i][j] == wall)
                    k--;
                if ((board[t - 1][j] == F && board[i][j] == F )|| (board[t - 1][j] == wall && board[i + 1][j] == wall))
                    k = -1;//区分死棋和死一
                if (k >= 0)
                    score = score + pow(10, k);
                i = t;
            }
        }

    for (int i = 1;i < L + 1;i += 1)//检查主对角线
        for (int j = 1;j < L + 1;j += 1)
        {
            if (board[i][j] == T)
            {           
                k = 1;
                int t1 = i, t2 = j;
                i++; 
                j++;
                while (board[i][j] == T)
                {
                    i++; 
                    j++;
                    k++;
                }                    
                if (board[t1 - 1][t2 - 1] == F || board[i][j] == F || board[t1 - 1][t2 - 1] == wall || board[i][j] == wall)
                    //判断不是边界
                    k--;
                if ((board[t1 - 1][t2 - 1] == F && board[i][j] == F )|| (board[t1 - 1][t2 - 1] == wall && board[i][j] == wall))
                    k = -1;//区分死棋和死一
                if (k >= 0)
                    score = score + pow(10, k);
                i = t1;
                j = t2;
            }
        }

    for (int i = 1;i < L + 1;i += 1)//检查反对角线
        for (int j = 1;j < L + 1;j += 1)
        {
            if (board[i][j] == T)
            {
                k = 1;
                int t1 = i, t2 = j;
                i += 1;
                j -= 1;
                while (board[i][j] == T)
                {
                    i += 1;
                    j -= 1;
                    k++;
                }
                if (board[t1 - 1][t2 + 1] == F || board[i][j] == F || board[i][j] == wall || board[i][j] == wall)
                    k--;//遇到边界也相当于是死棋
                if ((board[t1 - 1][t2 + 1] == F && board[i][j] == F )|| (board[i][j] == wall && board[i][j] == wall))
                    k = -1;//区分死棋和死一
                if (k >= 0)
                    score = score + pow(10, k);
                i = t1;
                j = t2;
            }
        }
    return score;
}

void generator(int me,int others)//先不管邻居，直接遍历
{
    int my_score = 0;
    int t = 0;
    int m, n;
    for (int i = 1;i < L + 1;i += 1)
        for (int j = 1;j < L + 1;j += 1)
        {   
            if (!board[i][j])//决策树，评估这个点下了棋之后的得分
            {
                board[i][j] = me;
                t=evaluate(me, others)- evaluate(others, me);
                n = evaluate(me, others);
                m = evaluate(others, me);
                board[i][j] = 0;
            }
            if (t > my_score)
            {
                board[i][j] = me;
                my_score = t;
                AI_x = j;//坐标表示和数组索引表示是反的
                AI_y = i;
            }
        }
}

//用什么数据结构储存有邻居的位置
/*
void neighbor()
{
    for (int i = 0;i < 15;i++)
        for (int j = 0;j < 15;j++)
        {
            if (!board[i][j])
            {

            }

        }
    

}
*/

