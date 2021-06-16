#include "assist.h"

int gBoard[M_SIZE][M_SIZE]; //����

/*******************************************
Function: is_win

Description: �ӵ�ǰ����λ���ж����巽�Ƿ��Ѿ�Ӯ��

Input: x->int ��������
       y->int ��������
       chessColor->int ��ǰ���巽���ӵ���ɫ

Return: TRUEӮ�ˣ�FALSEûӮ
********************************************/
int is_win(int x, int y, int chessColor) {
    int i, j, n1 = 0, n2 = 0;
    for (i = x, j = y + 1; j < M_SIZE; j++) { //�����ۼӣ������ұ����Ӹ���
        if (gBoard[i][j] == chessColor)
            n1++;
        else
            break;
    }
    for (i = x, j = y; j >= 0; j--) { //�����ۼӣ�����������Ӹ���
        if (gBoard[i][j] == chessColor)
            n2++;
        else
            break;
    }
    if (n1 + n2 >= 5)
        return TRUE;
    n1 = 0;
    n2 = 0;
    for (i = x, j = y; i >= 0; i--) { //���ϼ���
        if (gBoard[i][j] == chessColor)
            n1++;
        else
            break;
    }
    for (i = x + 1, j = y; i < M_SIZE; i++) { //���¼���
        if (gBoard[i][j] == chessColor)
            n2++;
        else
            break;
    }
    if (n1 + n2 >= 5)
        return TRUE;
    n1 = 0;
    n2 = 0;
    for (i = x - 1, j = y + 1; i >= 0 && j < M_SIZE; i--, j++) { //�����ϼ���
        if (gBoard[i][j] == chessColor)
            n1++;
        else
            break;
    }
    for (i = x, j = y; i < M_SIZE && j >= 0; i++, j--) { //�����¼���
        if (gBoard[i][j] == chessColor)
            n2++;
        else
            break;
    }
    if (n1 + n2 >= 5)
        return TRUE;
    n1 = 0;
    n2 = 0;
    for (i = x, j = y; i >= 0 && j >= 0; i--, j--) {//�����ϼ���
        if (gBoard[i][j] == chessColor)
            n1++;
        else
            break;
    }
    for (i = x + 1, j = y + 1; i < M_SIZE && j < M_SIZE; i++, j++) {//�����¼���
        if (gBoard[i][j] == chessColor)
            n2++;
        else
            break;
    }
    if (n1 + n2 >= 5)
        return TRUE;
    return FALSE;
}



