#include <stdio.h>
#include "def.h"
#include <windows.h>
void tree(int **board, int user, steps *current, int deep, int *a, int *b, int x, int y)
{
    if (deep == 0)
    {
        current->scores = board_scores(board, abs(1 - user));
        return;
    } //���ѵ���ײ�
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
    int count = 0; //�������̿����Կ���������Ŀ
    for (int i = 0; i < 225; i++)
        if (board[cell[i].x][cell[i].y] == empty && canplay(board, cell[i].x, cell[i].y))
        {

            //�����ݴ�
            int tmp[17][17];
            for (int i = 0; i < 17; i++)
                for (int j = 0; j < 17; j++)
                {
                    tmp[i][j] = board[i][j];
                }
            //ģ������
            if (deep % 2 == 1)
            {
                board[cell[i].x][cell[i].y] = user;
            }
            else
            {
                board[cell[i].x][cell[i].y] = abs(1 - user);
            }
            //��������ʼ���ӽڵ�
            count++;
            current->nextstep = (steps *)realloc(current->nextstep, count * sizeof(steps)); //�����ӽڵ�
            current->nextstep[count - 1].nextstep = NULL;                                   //��ʼ���ӽڵ�
            current->nextstep[count - 1].x = cell[i].x;                                     //�ӽڵ�x
            current->nextstep[count - 1].y = cell[i].y;                                     //�ӽڵ�y
            //��һ���ڵ��¼�ò��ܽڵ���
            current->nextstep[0].num = count;
            //��������
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
            //����
            tree(board, user, &current->nextstep[count - 1], deep - 1, a, b, x, y);
            tree_search(current, count, deep);
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
void tree_search(steps *current, int count, int deep)
{
    //��ʼ�����ڵ�
    if (count == 1)
    {
        current->scores = current->nextstep[count - 1].scores;
        current->win = current->nextstep[count - 1].win;
    }
    //����С����
    if (deep % 2 == 0) //��������
    {
        if (current->scores < current->nextstep[count - 1].scores)
        {
            current->scores = current->nextstep[count - 1].scores;
            current->win = current->nextstep[count - 1].win;
        }
    }
    else //��С����
    {
        if (current->scores > current->nextstep[count - 1].scores)
        {
            current->scores = current->nextstep[count - 1].scores;
            current->win = current->nextstep[count - 1].win;
        }
    }
    //��֦
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