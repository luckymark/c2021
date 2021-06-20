#include "assist.h"

int gBoard[M_SIZE][M_SIZE]; //棋盘

/*******************************************
Function: is_win

Description: 从当前下棋位置判断下棋方是否已经赢了

Input: x->int 棋子坐标
       y->int 棋子坐标
       chessColor->int 当前下棋方棋子的颜色

Return: TRUE赢了；FALSE没赢
********************************************/
int is_win(int x, int y, int chessColor) {
    int i, j, n1 = 0, n2 = 0;
    for (i = x, j = y + 1; j < M_SIZE; j++) { //往右累加，计算右边棋子个数
        if (gBoard[i][j] == chessColor)
            n1++;
        else
            break;
    }
    for (i = x, j = y; j >= 0; j--) { //往左累加，计算左边棋子个数
        if (gBoard[i][j] == chessColor)
            n2++;
        else
            break;
    }
    if (n1 + n2 >= 5)
        return TRUE;
    n1 = 0;
    n2 = 0;
    for (i = x, j = y; i >= 0; i--) { //向上检索
        if (gBoard[i][j] == chessColor)
            n1++;
        else
            break;
    }
    for (i = x + 1, j = y; i < M_SIZE; i++) { //向下检索
        if (gBoard[i][j] == chessColor)
            n2++;
        else
            break;
    }
    if (n1 + n2 >= 5)
        return TRUE;
    n1 = 0;
    n2 = 0;
    for (i = x - 1, j = y + 1; i >= 0 && j < M_SIZE; i--, j++) { //向右上检索
        if (gBoard[i][j] == chessColor)
            n1++;
        else
            break;
    }
    for (i = x, j = y; i < M_SIZE && j >= 0; i++, j--) { //向左下检索
        if (gBoard[i][j] == chessColor)
            n2++;
        else
            break;
    }
    if (n1 + n2 >= 5)
        return TRUE;
    n1 = 0;
    n2 = 0;
    for (i = x, j = y; i >= 0 && j >= 0; i--, j--) {//向左上检索
        if (gBoard[i][j] == chessColor)
            n1++;
        else
            break;
    }
    for (i = x + 1, j = y + 1; i < M_SIZE && j < M_SIZE; i++, j++) {//向右下检索
        if (gBoard[i][j] == chessColor)
            n2++;
        else
            break;
    }
    if (n1 + n2 >= 5)
        return TRUE;
    return FALSE;
}



