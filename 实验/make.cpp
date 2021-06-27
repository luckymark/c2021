#include <stdio.h>
#include "def.h"
#include <windows.h>
#include <math.h>
steps *head_creat(void) //初始化根节点
{
    steps *head = (steps *)malloc(sizeof(steps));
    head->nextstep = NULL;
    head->num = 0;
    head->scores = 0;
    head->win = 0;
    head->x = 0;
    head->y = 0;
    return head;
} //根据tree函数确定机器落子位置
steps *find_steps(steps *head)
{
    for (int i = 0; i < head->nextstep[0].num; i++)
        if (head->nextstep[i].win > head->win)
        {
            head->scores = head->nextstep[i].scores;
            head->win = head->nextstep[i].win;
        } //迭代加深部分代码，用于将路径改为最短路径
    for (int i = 1; i < head->nextstep[0].num; i++)
    {
        if (head->nextstep[i].scores == head->scores)
            return &head->nextstep[i];
    }
}

//用于标记可落子点，便于查找
void mark(int **board, int x, int y)
{
    int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
    for (int i = 0; i < 8; i++)
    {
        if (board[x + dir[i][0]][y + dir[i][1]] == empty)
        {
            board[x + dir[i][0]][y + dir[i][1]] = useful;
        }
        /*else if (board[x + dir[i][0]][y + dir[i][1]] != wall)
        {
            if (board[x + dir[i][0] + dir[i][0]][y + dir[i][1] + dir[i][1]] == empty)
            {
                board[x + dir[i][0] + dir[i][0]][y + dir[i][1] + dir[i][1]] = useful;
            }
    }*/
        //鉴于一般五子棋都是贴着下，故不往外增加层数
    }
}