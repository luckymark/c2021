#include <stdio.h>
#include "def.h"
#include <windows.h>
void printf_board(int **board) //棋盘打印
{
    printf("〇①②③④⑤⑥⑦⑧⑨⑩1112131415\n");
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (board[i][j] == empty || board[i][j] == useful)
                printf("□");
            else if (board[i][j] == black)

            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
                                                                             FOREGROUND_RED); //将输出颜色改为红色
                printf("○");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
                                                                             FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //输出后将输出颜色改回白色
            }
            else if (board[i][j] == white)
                printf("●");
            else if (board[i][j] == wall)
                printf("■");
        }
        printf("%d", i);
        puts("");
    }

    printf("〇①②③④⑤⑥⑦⑧⑨⑩1112131415");
    puts("");
}
int **creatboard(void) //棋盘创建函数
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
    } //建围墙
    return board;
}