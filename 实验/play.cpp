#include <stdio.h>
#include "def.h"
#include <windows.h>
#include <time.h>
void Roleplay(int **board, int choose)
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
            if (board[x][y] == empty || board[x][y] == useful)
            {
                board[x][y] = choose;
                mark(board, x, y);
                ok = 0;
            }
        }
    }
    system("cls");
    printf_board(board);
    if (win(board, x, y))
    {
        puts("you win");
        return;
    }
    Robotplay(board, choose, x, y);
    return;
}
void Robotplay(int **board, int choose, int x, int y)
{
    clock_t t1;
    clock_t t2;
    t1 = clock();
    int max = Maxnn;
    int min = Minn;
    int *a = &min;
    int *b = &max;
    steps *head = head_creat();
    tree(board, choose, head, deepth, a, b, x, y);
    int dx = find_steps(head)->x;
    int dy = find_steps(head)->y;
    mark(board, dx, dy);
    board[dx][dy] = abs(1 - choose);
    t2 = clock();
    system("cls");
    printf_board(board);
    printf("%d\n", t2 - t1);
    system("pause");
    if (win(board, dx, dy))
    {
        puts("you lose");
        free(head->nextstep);
        head->nextstep = NULL;
        return;
    }
    free(head->nextstep);
    free(head);
    Roleplay(board, choose);
    return;
}