#include <stdio.h>
#include "def.h"
#include <windows.h>
void tree(int **board, int choose, steps *current, int deep, int *a, int *b)
{
    if (deep == 0)
    {
        current->scores = board_scores(board, abs(1 - choose));
        return;
    }              //���ѵ���ײ�
    int count = 0; //�������̿����Կ���������Ŀ
    for (int i = 1; i < 17; i++)
        for (int j = 1; j < 17; j++)
            if (board[i][j] == empty)
            {
                int tmp[17][17];
                for (int i = 0; i < 17; i++)
                    for (int j = 0; j < 17; j++)
                        tmp[i][j] = board[i][j];
                //ģ������
                if (deep % 2 == 1)
                {
                    board[i][j] = choose;
                }
                else
                {
                    board[i][j] = abs(1 - choose);
                }
                //��������ʼ���ӽڵ�
                count++;
                current->nextstep = (steps *)realloc(current->nextstep, count * sizeof(steps));
                current->nextstep[count - 1].nextstep = NULL;
                current->nextstep[count - 1].x = i;
                current->nextstep[count - 1].y = j;
                //��һ���ڵ��¼�ò��ܽڵ���
                current->nextstep[0].num = count;
                //����
                tree(board, choose, &current->nextstep[count - 1], deep - 1, a, b);
                //��ʼ�����ڵ�
                if (count == 1)
                {
                    current->scores = current->nextstep[count - 1].scores;
                }
                //����С����
                if (deep % 2 == 0) //��������
                {
                    if (current->scores < current->nextstep[count - 1].scores)
                        current->scores = current->nextstep[count - 1].scores;
                }
                else //��С����
                {
                    if (current->scores > current->nextstep[count - 1].scores)
                        current->scores = current->nextstep[count - 1].scores;
                }
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
steps *find_steps(steps *head)
{
    for (int i = 1; i < head->nextstep[0].num; i++)
    {
        if (head->nextstep[i].scores == head->scores)
            return &head->nextstep[i];
    }
}
