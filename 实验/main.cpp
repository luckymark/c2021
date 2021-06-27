#include <stdio.h>
#include <windows.h>
#include "def.h"
int main()
{
    //创建一个棋盘
    int **board = creatboard();
    //选择黑白棋
    int user = -1;
    while (user != 1 && user != 2)
    {
        printf("1.选择黑棋(红色)2.选择白棋(黑棋先手)\n");
        scanf_s("%d", &user);
        if (user == 1)
        {
            Roleplay(board, black);
            break;
        }
        else if (user == 2)
        {
            board[7][7] = black; //默认机器下在棋盘最中间
            Roleplay(board, white);
            break;
        }
    }
    //
    free(board);
    system("Pause");
    return 0;
}
