#include <stdio.h>
#include <windows.h>
#include "def.h"
int main()
{
    //����һ������
    int **board = creatboard();
    //ѡ��ڰ���
    int user = -1;
    while (user != 1 && user != 2)
    {
        printf("1.ѡ�����(��ɫ)2.ѡ�����(��������)\n");
        scanf_s("%d", &user);
        if (user == 1)
        {
            Roleplay(board, black);
            break;
        }
        else if (user == 2)
        {
            board[7][7] = black; //Ĭ�ϻ��������������м�
            Roleplay(board, white);
            break;
        }
    }
    //
    free(board);
    system("Pause");
    return 0;
}
