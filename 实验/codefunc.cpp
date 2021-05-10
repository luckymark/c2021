#include <stdio.h>
#include "def.h"
#include <windows.h>
void create_tree(int** board, int choose, steps* current, int deep)
{
    if (deep == 0)
        return;
   
    else if (deep != 3)
    {
        current = (steps*)malloc(sizeof(steps));
        current->nextstep = NULL;
    }
    int count = 0;
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 15; j++)
            if (board[i][j] == empty)
            {
                int** tmp = creatboard();
                copyboard(board, tmp);
                count++;
                current->nextstep = (steps*)realloc(current->nextstep, count * sizeof(steps));
                current->nextstep[count - 1].x = i;
                current->nextstep[count - 1].y = j;
                if (deep % 2 == 0)
                {
                    if (choose == black)
                        board[i][j] = white;
                    else
                        board[i][j] = black;
                }
                else
                {
                    if (choose == black)
                        board[i][j] = black;
                    else
                        board[i][j] = white;
                }
                current->nextstep[count - 1].scores = getscores(board, choose);
                current->nextstep[count - 1].nextstep = NULL;
                create_tree(board, choose, current->nextstep[count-1].nextstep, deep - 1);
                copyboard(tmp,board);
                free(tmp);
            }
}
int getscores(int** board,int choose)
{
    
    return 1;
}