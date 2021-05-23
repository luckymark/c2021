#include <stdio.h>
#include "def.h"
#include <windows.h>
void tree(int **board, int choose, steps *current, int deep, int *a, int *b)
{
    if (deep == 0)
    {
        current->scores = board_scores(board, abs(1 - choose));
        return;
    }              //深搜到最底层
    int count = 0; //根据棋盘可能性控制树根数目
    for (int i = 1; i < 17; i++)
        for (int j = 1; j < 17; j++)
            if (board[i][j] == empty)
            {
                int tmp[17][17];
                for (int i = 0; i < 17; i++)
                    for (int j = 0; j < 17; j++)
                        tmp[i][j] = board[i][j];
                //模拟下棋
                if (deep % 2 == 1)
                {
                    board[i][j] = choose;
                }
                else
                {
                    board[i][j] = abs(1 - choose);
                }
                //创建并初始化子节点
                count++;
                current->nextstep = (steps *)realloc(current->nextstep, count * sizeof(steps));
                current->nextstep[count - 1].nextstep = NULL;
                current->nextstep[count - 1].x = i;
                current->nextstep[count - 1].y = j;
                //第一个节点记录该层总节点数
                current->nextstep[0].num = count;
                //深搜
                tree(board, choose, &current->nextstep[count - 1], deep - 1, a, b);
                //初始化根节点
                if (count == 1)
                {
                    current->scores = current->nextstep[count - 1].scores;
                }
                //极大极小搜索
                if (deep % 2 == 0) //极大搜索
                {
                    if (current->scores < current->nextstep[count - 1].scores)
                        current->scores = current->nextstep[count - 1].scores;
                }
                else //极小搜索
                {
                    if (current->scores > current->nextstep[count - 1].scores)
                        current->scores = current->nextstep[count - 1].scores;
                }
                //剪枝
                if (deep % 2 == 0)
                {
                    if (current->scores < *a)
                    {
                        free(current->nextstep);
                        return;
                    }
                }
                else if (deep % 2 == 1)
                {
                    if (current->scores > *b)
                    {
                        free(current->nextstep);
                        return;
                    }
                }
                for (int i = 0; i < 17; i++)
                    for (int j = 0; j < 17; j++)
                        board[i][j] = tmp[i][j];
            }
    if (deep % 2 == 1)
    {
        current->scores < *b;
        *b = current->scores;
        *a = Minn;  
    }
    else
    {
        current->scores > *a;
        *a = current->scores;
        *b = Maxnn;                        
    }
    if (deep != deepth)
        free(current->nextstep);
    return;
}
steps *find_steps(steps *head)
{
    for (int i = 1; i < head->nextstep[0].num; i++)
    {
        if (head->nextstep[i].scores == head->scores)
            return &head->nextstep[i];
    }
}
