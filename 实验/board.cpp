#include <stdio.h>
#include "def.h"
#include <windows.h>
void printf_board(int **board)
{
    printf("©–¢Ù¢Ú¢Û¢Ü¢Ý¢Þ¢ß¢à¢á¢â1112131415\n");
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (board[i][j] == empty || board[i][j] == useful)
                printf("¡õ");
            else if (board[i][j] == black)

            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
                                                                             FOREGROUND_RED);
                printf("¡ð");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
                                                                             FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else if (board[i][j] == white)
                printf("¡ñ");
            else if (board[i][j] == wall)
                printf("¡ö");
        }
        printf("%d", i);
        puts("");
    }

    printf("©–¢Ù¢Ú¢Û¢Ü¢Ý¢Þ¢ß¢à¢á¢â1112131415");
    puts("");
}
int **creatboard(void) //ÆåÅÌ´´½¨º¯Êý
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