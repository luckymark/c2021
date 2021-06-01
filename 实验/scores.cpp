#include <stdio.h>
#include "def.h"
#include <windows.h>
#include <math.h>
int steps_scores(int **board, int x, int y) //估值函数
{
    int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
    int sum = 0;
    int times = 4;
    int obj = board[x][y];
    //连子判断
    for (int i = 0; i < times; i++)
    {
        int chesses = 0;
        back deep1;
        back deep2;
        deep1.deep = 0;
        deep2.deep = 0;
        deep1.end = 0;
        deep2.end = 0;
        judge_ends(board, x, y, dir[2 * i][0], dir[2 * i][1], obj, 0, &deep1);
        judge_ends(board, x, y, dir[2 * i + 1][0], dir[2 * i + 1][1], obj, 0, &deep2);
        chesses = deep1.deep + deep2.deep + 1;
        int ends = 0;
        ends = deep1.end + deep2.end;
        if (ends == 0)
        {
            switch (chesses)
            {
            case 1:
                sum += 10;
                break;
            case 2:
                sum += 100;
                break;
            case 3:
                sum += 1000;
                break;
            case 4:
                sum += 10000;
                break;
            case 5:
                sum += 100000000;
                break;
            default:
                break;
            }
        }
        else if (ends == 1)
        {
            switch (chesses)
            {
            case 1:
                sum += 1;
                break;
            case 2:
                sum += 10;
                break;
            case 3:
                sum += 100;
                break;
            case 4:
                sum += 1000;
                break;
            case 5:
                sum += 100000000;
                break;
            default:
                break;
            }
        }
        else
        {

            switch (chesses)
            {
            case 1:
                sum += 0;
                break;
            case 2:
                sum += 1;
                break;
            case 3:
                sum += 10;
                break;
            case 4:
                sum += 100;
                break;
            case 5:
                sum += 100000000;
                break;
            default:
                break;
            }
        }
    }
    if (x == 1 || x == 15 || y == 1 || y == 15)
        sum = sum * 0.8;
    return sum;
}
int board_scores(int **board, int choose)
{
    int sum = 0;
    for (int i = 1; i < 17; i++)
        for (int j = 1; j < 17; j++)
            if (board[i][j] == choose)
                sum = sum + steps_scores(board, i, j);
            else if (board[i][j] == abs(1 - choose))
                sum = sum - steps_scores(board, i, j) * 1.1;
    return sum;
}
