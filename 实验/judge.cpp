#include <stdio.h>
#include "def.h"
#include <windows.h>
#include <math.h>
int judge_win(int **board, int x, int y, int dx, int dy, int obj, int deep)
{
    if (board[x + dx][y + dy] == obj)
    {
        deep++;
        int a = judge_win(board, x + dx, y + dy, dx, dy, obj, deep);
        return a;
    }
    else
        return deep;
}
int win(int **board, int x, int y) //胜利判断函数
{
    int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
    int obj = board[x][y];
    int times = 4; //横竖两斜四个方向共四次
    for (int i = 0; i < times; i++)
    {
        int deep1 = 0; //一个方向上
        int deep2 = 0; //另一个方向上
        deep1 = judge_win(board, x, y, dir[2 * i][0], dir[2 * i][1], obj, deep1);
        if (deep1 == 4)
        {
            return 1;
        } //直接ok
        else
        {
            deep2 = judge_win(board, x, y, dir[2 * i + 1][0], dir[2 * i + 1][1], obj, deep2); //找同一直线的另一个方向
            int deep = deep1 + deep2 + 1;
            if (deep >= 5)
            {
                return 1;
            }
        }
    }
    return 0;
}
void judge_ends(int **board, int x, int y, int dx, int dy, int obj, int deep, continuation *current)
{
    if (board[x + dx][y + dy] == obj)
    {
        deep++;
        judge_ends(board, x + dx, y + dy, dx, dy, obj, deep, current);
        return;
    }
    else
    {
        current->deep = deep;
        if (board[x + dx][y + dy] == empty)
            current->end = 0; //活路
        else
            current->end = 1; //死路
        return;
    }
}
int canplay(int **board, int x, int y)
{
    int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
    for (int i = 0; i < 8; i++)
    {
        if (board[x + dir[i][0]][y + dir[i][1]] == white || board[x + dir[i][0]][y + dir[i][1]] == black)
        {
            return 1;
        }
        else if (board[x + dir[i][0]][y + dir[i][1]] != wall)
        {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            for (int i = 0; i < 8; i++)
            {
                if (board[dx + dir[i][0]][y + dir[i][1]] == white || board[dx + dir[i][0]][y + dir[i][1]] == black)
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