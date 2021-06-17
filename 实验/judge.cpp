#include <stdio.h>
#include "def.h"
#include <windows.h>
#include <math.h>
int win(int **board, int x, int y) //胜利判断函数
{
    int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
    int obj = board[x][y];
    int times = 4; //横竖两斜四个方向共四次
    for (int i = 0; i < times; i++)
    {
        int deep1 = 0; //一个方向上
        int deep2 = 0; //另一个方向上
        int dx = x;
        int dy = y;
        for (int j = 0; j < 5; j++)
            if (board[dx + dir[2 * i][0]][dy + dir[2 * i][1]] == obj)
            {
                deep1++;
                dx = dx + dir[2 * i][0];
                dy = dy + dir[2 * i][1];
            }
            else
                break;
        if (deep1 == 4)
        {
            return 1;
        } //直接ok
        else
        {
            dx = x;
            dy = y;
            for (int j = 0; j < 5; j++)
                if (board[dx + dir[2 * i + 1][0]][dy + dir[2 * i + 1][1]] == obj)
                {
                    deep2++;
                    dx = dx + dir[2 * i + 1][0];
                    dy = dy + dir[2 * i + 1][1];
                }
                else
                    break; //找同一直线的另一个方向
            int deep = deep1 + deep2 + 1;
            if (deep >= 5)
            {
                return 1;
            }
        }
    }
    return 0;
}
steps *find_steps(steps *head)
{
    for (int i = 0; i < head->nextstep[0].num; i++)
        if (head->nextstep[i].win > head->win)
        {
            head->scores = head->nextstep[i].scores;
            head->win = head->nextstep[i].win;
        }
    for (int i = 1; i < head->nextstep[0].num; i++)
    {
        if (head->nextstep[i].scores == head->scores)
            return &head->nextstep[i];
    }
}
void mark(int **board, int x, int y)
{
    int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
    for (int i = 0; i < 8; i++)
    {
        if (board[x + dir[i][0]][y + dir[i][1]] == empty)
        {
            board[x + dir[i][0]][y + dir[i][1]] = useful;
        }
        else if (board[x + dir[i][0]][y + dir[i][1]] != wall)
        {
            if (board[x + dir[i][0] + dir[i][0]][y + dir[i][1] + dir[i][1]] == empty)
            {
                board[x + dir[i][0] + dir[i][0]][y + dir[i][1] + dir[i][1]] = useful;
            }
        }
    }
}