#include <stdio.h>
#include "def.h"
#include <windows.h>
void tree(int **board, int user, steps *current, int deep, int *a, int *b, int x, int y)
{
    if (deep == 0)
    {
        current->scores = board_scores(board, abs(1 - user));
        return;
    } //深搜到最底层
    each cell[225];
    for (int i = 1; i <= 15; i++)
        for (int j = 1; j <= 15; j++)
        {
            cell[(i - 1) * 15 + j - 1].x = i;
            cell[(i - 1) * 15 + j - 1].y = j;
            cell[(i - 1) * 15 + j - 1].scores = (i - x) * (i - x) + (j - y) * (j - y);
        }
    /*for (int i = 0; i < 225; i++)
        for (int j = 0; j < i; j++)
        {
            each tmp;
            if (cell[i].scores > cell[j].scores)
            {
                tmp = cell[j];
                cell[j] = cell[i];
                cell[i] = tmp;
            }
        }*/
    /*if (deep % 2 == 0)
    {
        for (int i = 0; i < 225; i++)
            for (int j = 0; j < i; j++)
            {
                each tmp;
                if (cell[i].scores > cell[j].scores)
                {
                    tmp = cell[j];
                    cell[j] = cell[i];
                    cell[i] = tmp;
                }
            }
    }
    else
    {
        for (int i = 0; i < 225; i++)
            for (int j = 0; j < i; j++)
            {
                each tmp;
                if (cell[i].scores < cell[j].scores)
                {
                    tmp = cell[j];
                    cell[j] = cell[i];
                    cell[i] = tmp;
                }
            }
    }
*/
    int count = 0; //根据棋盘可能性控制树根数目
    for (int i = 0; i < 225; i++)
        if (board[cell[i].x][cell[i].y] == empty && canplay(board, cell[i].x, cell[i].y))
        {

            //棋盘暂存
            int tmp[17][17];
            for (int i = 0; i < 17; i++)
                for (int j = 0; j < 17; j++)
                {
                    tmp[i][j] = board[i][j];
                }
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
            count++;
            current->nextstep = (steps *)realloc(current->nextstep, count * sizeof(steps)); //分配子节点
            current->nextstep[count - 1].nextstep = NULL;                                   //初始化子节点
            current->nextstep[count - 1].x = cell[i].x;                                     //子节点x
            current->nextstep[count - 1].y = cell[i].y;                                     //子节点y
            //第一个节点记录该层总节点数
            current->nextstep[0].num = count;
            //迭代加深
            if (deep % 2 == 0)
            {
                if (win(board, cell[i].x, cell[i].y) == 1)
                {
                    current->nextstep[count - 1].win = deep;
                    current->nextstep->scores = board_scores(board, abs(1 - user));
                    tree_search(current, count, deep);
                    for (int i = 0; i < 17; i++)
                        for (int j = 0; j < 17; j++)
                            board[i][j] = tmp[i][j];
                    continue;
                }
                else
                    current->nextstep[count - 1].win = 0;
            }
            else
            {
                current->nextstep[count - 1].win = 0;
            }
            //深搜
            tree(board, user, &current->nextstep[count - 1], deep - 1, a, b, x, y);
            tree_search(current, count, deep);
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
void tree_search(steps *current, int count, int deep)
{
    //初始化根节点
    if (count == 1)
    {
        current->scores = current->nextstep[count - 1].scores;
        current->win = current->nextstep[count - 1].win;
    }
    //极大极小搜索
    if (deep % 2 == 0) //极大搜索
    {
        if (current->scores < current->nextstep[count - 1].scores)
        {
            current->scores = current->nextstep[count - 1].scores;
            current->win = current->nextstep[count - 1].win;
        }
    }
    else //极小搜索
    {
        if (current->scores > current->nextstep[count - 1].scores)
        {
            current->scores = current->nextstep[count - 1].scores;
            current->win = current->nextstep[count - 1].win;
        }
    }
    //剪枝
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