#include <stdio.h>
#include "def.h"
#include <windows.h>
#include <math.h>
int cmp1(const void *a, const void *b)
{
    each *da = (each *)a;
    each *db = (each *)b;
    if (da->scores > db->scores)
        return 1;
    else
        return 0;
} //排序函数（从小到大）
int cmp2(const void *a, const void *b)
{
    each *da = (each *)a;
    each *db = (each *)b;
    if (da->scores < db->scores)
        return 1;
    else
        return 0;
} //排序函数（从大到小）
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
        back dre1;
        back dre2;
        dre1.deep = 0;
        dre2.deep = 0;
        dre1.end = 0;
        dre2.end = 0;
        search(board, x, y, dir[2 * i][0], dir[2 * i][1], obj, &dre1);         //向一个方向寻找
        search(board, x, y, dir[2 * i + 1][0], dir[2 * i + 1][1], obj, &dre2); //向另一个方向寻找
        chesses = dre1.deep + dre2.deep + 1;
        int ends = 0;
        ends = dre1.end + dre2.end;
        sum = sum + scores(chesses, ends);
        if (x == 1 || x == 15 || y == 1 || y == 15)
            sum = sum * 0.8;
        return sum;
    }
}
void search(int **board, int x, int y, int dx, int dy, int obj, back *current)
{
    int px = x, py = y, deep = 0;
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
            if (board[px + dx][py + dy] == empty || board[px + dx][py + dy] == useful)
                current->end = 0; //活路
            else
                current->end = 1; //死路
            break;
        }
    }
    current->deep = deep;
}