#include <stdio.h>
#include "def.h"
#include <windows.h>
void Roleplay(int **board, int choose, steps *head)
{

    int x, y;
    int ok = 1;
    while (ok)
    {
        system("cls");
        printf_board(board);
        puts("第几行:");
        scanf_s("%d", &x);
        puts("第几列:");
        scanf_s("%d", &y);
        if (x > 0 && y > 0 && x < 17 && y < 17)
        {
            if (board[x][y] == empty)
            {
                board[x][y] = choose;
                ok = 0;
            }
        }
    }
    system("cls");
    printf_board(board);
    if (win(board, x, y))
    {
        puts("you win");
        free(head->nextstep);
        head->nextstep = NULL;
        return;
    }
    Robotplay(board, choose, head);
}
void Robotplay(int **board, int choose, steps *head)
{
    int max = 10000000;
    int min = -10000000;
    int *a = &min;
    int *b = &max;
    tree(board, choose, head, deepth, a, b);
    int x = find_steps(head)->x;
    int y = find_steps(head)->y;
    if (choose == white)
        board[x][y] = black;
    else
        board[x][y] = white;
    system("cls");
    printf_board(board);
    if (win(board, x, y))
    {
        puts("you lose");
        free(head->nextstep);
        head->nextstep = NULL;
        return;
    }
    free(head->nextstep);
    head->nextstep = NULL;
    Roleplay(board, choose, head);
    return;
}