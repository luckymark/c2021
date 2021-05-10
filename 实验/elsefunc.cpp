#include <stdio.h>
#include "def.h"
#include <windows.h>

void printf_board(int** board)
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (board[i][j] == empty)
                printf("¡õ");
            else if (board[i][j] == black)
                printf("¡ñ");
            else if (board[i][j] == white)
                printf("¡ð");
        }
        puts("");
    }
}
void Roleplay(int** board,int choose,steps*head)
{
    system("cls");
    printf_board(board);
    //¼òÒ×²Ù×÷
    int x, y; 
    scanf_s("%d %d", &x, &y);
    board[x-1][y-1] = choose;
    system("cls");
    printf_board(board);
    Robotplay(board, choose,head);
}
void Robotplay(int** board, int choose, steps* head)
{   
    create_tree(board, choose,head,2);
    Roleplay(board, choose,head);
    return;
} 
int** creatboard(void)
{
    int **board = (int**)calloc(15, sizeof(int*));
    for (int i = 0; i < 15; i++)
        board[i] = (int*)calloc(15, sizeof(int));
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            board[i][j] = empty;
    return board;
}
void copyboard(int** from, int** to) 
{
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            to[i][j] = from[i][j];
}
void win(int** board)
{

}