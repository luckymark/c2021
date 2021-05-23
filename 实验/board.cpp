#include <stdio.h>
#include "def.h"
#include <windows.h>
void printf_board(int **board)
{
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (board[i][j] == empty)
                printf("��");
            else if (board[i][j] == black)
                printf("��");
            else if (board[i][j] == white)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
                                                                             FOREGROUND_RED);
                printf("��");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
                                                                             FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else if (board[i][j] == wall)
                printf("��");
        }
        printf("%d", i);
        puts("");
    }

    printf("���٢ڢۢܢݢޢߢ���1112131415");
    puts("");
}
int **creatboard(void) //���̴�������
{
    int **board = (int **)calloc(17, sizeof(int *));
    for (int i = 0; i < 17; i++)
        board[i] = (int *)calloc(17, sizeof(int));
    for (int i = 0; i < 17; i++)
        for (int j = 0; j < 17; j++)
            board[i][j] = empty;
    for (int i = 0; i < 17; i++)
    {
        board[16][i] = wall;
        board[0][i] = wall;
        board[i][0] = wall;
        board[i][16] = wall;
    }
    return board;
}
void test_board(int **board)
{
    board[3][3] = black;
    board[4][4] = black;
    board[3][4] = white;
    board[4][3] = white;
    board[2][4] = white;
    board[2][6] = white;
    board[3][5] = white;
    board[3][6] = black;
    board[2][5] = black;
    board[4][5] = black;
}