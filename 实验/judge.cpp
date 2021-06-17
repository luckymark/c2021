#include <stdio.h>
#include "def.h"
#include <windows.h>
#include <math.h>
int win(int **board, int x, int y) //ʤ���жϺ���
{
    int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
    int obj = board[x][y];
    int times = 4; //������б�ĸ������Ĵ�
    for (int i = 0; i < times; i++)
    {
        int deep1 = 0; //һ��������
        int deep2 = 0; //��һ��������
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
        } //ֱ��ok
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
                    break; //��ͬһֱ�ߵ���һ������
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
    int px = x, py = y;
    for (int j = 0; j < 5; j++)
    {
        if (board[px + dx][py + dy] == obj)
        {
            deep++;
            px = px + dx;
            py = py + dy;
        }
        else
        {
            if (board[px + dx][py + dy] == empty)
                current->end = 0; //��·
            else
                current->end = 1; //��·
            break;
        }
    }
    current->deep = deep;
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