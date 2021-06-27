#include <stdio.h>
#include "def.h"
#include <windows.h>
#include <stdlib.h>
void tree(int **board, int user, steps *current, int deep, int *a, int *b, int x, int y)
{
    int num = 0;
    if (deep == 0)
    {
        current->scores = board_scores(board, user);
        return;
    } //���ѵ���ײ�

    //����ʽ����
    each cell[225];
    for (int i = 1; i <= 15; i++)
        for (int j = 1; j <= 15; j++)
        {
            if (board[i][j] == useful)
            {

                cell[num].x = i;
                cell[num].y = j;
                if (deep % 2 == 0)
                    board[i][j] = abs(1 - user);
                else
                    board[i][j] = user;
                cell[num].scores = steps_scores(board, i, j);
                board[i][j] = useful;
                num++;
            }
        }
    if (deep % 2 == 1)
        qsort(cell, num, sizeof(each), cmp1);
    else
        qsort(cell, num, sizeof(each), cmp2);

    current->nextstep = (steps *)malloc(num * sizeof(steps)); //�����ӽڵ�
    current->nextstep[0].num = num;                           //��һ���ڵ��¼�ò��ܽڵ���
    for (int i = 0; i < num; i++)
    {
        //�����ݴ�
        int tmp[17][17];
        for (int i = 0; i < 17; i++)
            for (int j = 0; j < 17; j++)
                tmp[i][j] = board[i][j];

        //ģ������
        if (deep % 2 == 1)
        {
            board[cell[i].x][cell[i].y] = user;
            mark(board, cell[i].x, cell[i].y);
        }
        else
        {
            board[cell[i].x][cell[i].y] = abs(1 - user);
            mark(board, cell[i].x, cell[i].y);
        }

        //��������ʼ���ӽڵ�
        current->nextstep[i].nextstep = NULL; //��ʼ���ӽڵ�
        current->nextstep[i].x = cell[i].x;   //�ӽڵ�x
        current->nextstep[i].y = cell[i].y;   //�ӽڵ�y

        //��������
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
        //����
        tree(board, user, &current->nextstep[i], deep - 1, a, b, x, y);
        tree_search(current, i + 1, deep);
        //��֦
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
    //��ʼ�����ڵ�
    if (position == 1)
    {
        current->scores = current->nextstep[position - 1].scores;
        current->win = current->nextstep[position - 1].win;
        return;
    }
    //����С����
    if (deep % 2 == 0) //��������
    {
        if (current->scores < current->nextstep[position - 1].scores)
        {
            current->scores = current->nextstep[position - 1].scores;
            current->win = current->nextstep[position - 1].win;
        }
        return;
    }
    else //��С����
    {
        if (current->scores > current->nextstep[position - 1].scores)
        {
            current->scores = current->nextstep[position - 1].scores;
            current->win = current->nextstep[position - 1].win;
        }
        return;
    }
}
