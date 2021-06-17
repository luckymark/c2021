#include <stdio.h>
#include "def.h"
#include <windows.h>
#include <stdlib.h>
int cmp1(const void *a, const void *b)
{
    each *da = (each *)a;
    each *db = (each *)b;
    if (da->scores > db->scores)
        return 1;
    else
        return 0;
}
int cmp2(const void *a, const void *b)
{
    each *da = (each *)a;
    each *db = (each *)b;
    if (da->scores < db->scores)
        return 1;
    else
        return 0;
}
void tree(int **board, int user, steps *current, int deep, int *a, int *b, int x, int y)
{
    int num = 0;
    if (deep == 0)
    {
        current->scores = board_scores(board, abs(1 - user));
        return;
    } //深搜到最底层

    each cell[225];
    for (int i = 1; i <= 15; i++)
        for (int j = 1; j <= 15; j++)
        {
            if (board[i][j] == empty && canplay(board, i, j))
            {

                cell[num].x = i;
                cell[num].y = j;
                if (deep % 2 == 0)
                    board[i][j] = abs(1 - user);
                else
                    board[i][j] = user;
                //cell[num].scores = steps_scores(board, i, j);
                board[i][j] = empty;
                num++;
            }
        }
    /*if (deep % 2 == 1)
        qsort(cell, num, sizeof(each), cmp1);
    else
        qsort(cell, num, sizeof(each), cmp2);*/

    current->nextstep = (steps *)malloc(num * sizeof(steps)); //分配子节点
    current->nextstep[0].num = num;                           //第一个节点记录该层总节点数
    for (int i = 0; i < num; i++)
    {
        //棋盘暂存
        int tmp[17][17];
        for (int i = 0; i < 17; i++)
            for (int j = 0; j < 17; j++)
                tmp[i][j] = board[i][j];

        //模拟下棋
        if (deep % 2 == 1)
        {
            board[cell[i].x][cell[i].y] = user;
        }
        else
        {
            board[cell[i].x][cell[i].y] = abs(1 - user);
        }

        //创建并初始化子节点
        current->nextstep[i].nextstep = NULL; //初始化子节点
        current->nextstep[i].x = cell[i].x;   //子节点x
        current->nextstep[i].y = cell[i].y;   //子节点y

        //迭代加深
        if (deep % 2 == 0)
        {
            if (win(board, cell[i].x, cell[i].y) == 1)
            {
                current->nextstep[i].win = deep;
                current->nextstep->scores = board_scores(board, abs(1 - user));
                tree_search(current, i + 1, deep);
                for (int i = 0; i < 17; i++)
                    for (int j = 0; j < 17; j++)
                        board[i][j] = tmp[i][j];
                continue;
            }
            else
                current->nextstep[i].win = 0;
        }
        else
        {
            current->nextstep[i].win = 0;
        }
        //深搜
        tree(board, user, &current->nextstep[i], deep - 1, a, b, x, y);
        tree_search(current, i + 1, deep);

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
void tree_search(steps *current, int position, int deep)
{
    //初始化根节点
    if (position == 1)
    {
        current->scores = current->nextstep[position - 1].scores;
        current->win = current->nextstep[position - 1].win;
    }
    //极大极小搜索
    if (deep % 2 == 0) //极大搜索
    {
        if (current->scores < current->nextstep[position - 1].scores)
        {
            current->scores = current->nextstep[position - 1].scores;
            current->win = current->nextstep[position - 1].win;
        }
    }
    else //极小搜索
    {
        if (current->scores > current->nextstep[position - 1].scores)
        {
            current->scores = current->nextstep[position - 1].scores;
            current->win = current->nextstep[position - 1].win;
        }
    }
}
steps *head_creat(void)
{
    steps *head = (steps *)malloc(sizeof(steps));
    head->nextstep = NULL;
    head->num = 0;
    head->scores = 0;
    head->win = 0;
    head->x = 0;
    head->y = 0;
    return head;
}