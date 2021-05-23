
#include <stdio.h>
#include <windows.h>
#include "def.h"

int main()
{
    //创建一个棋盘
    int **board = creatboard();
    //初始化树根
    test_board(board); //测试用代码
    steps tree;
    steps *head = &tree;
    head->x = 0;
    head->y = 0;
    head->scores = 0;
    head->num = 0;
    head->nextstep = NULL;
    //选择黑白棋
    //
    int choose = -1;
    while (choose != 1 && choose != 2)
    {
        printf("1.选择黑棋（其实是白色） 2.选择白棋（其实是红色）(黑棋先手)\n");
        scanf_s("%d", &choose);
        if (choose == 1)
        {
            Roleplay(board, black, head);
            break;
        }
        else if (choose == 2)
        {
            board[8][8] = black; //默认机器下在棋盘最中间
            Roleplay(board, white, head);
            break;
        }
    }
    //
    free(board);
    system("Pause");
    return 0;
}
