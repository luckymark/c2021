
#include <stdio.h>
#include <windows.h>
#include "def.h"

int main()
{
    //����һ������
    int **board = creatboard();
    //��ʼ������
    test_board(board); //�����ô���
    steps tree;
    steps *head = &tree;
    head->x = 0;
    head->y = 0;
    head->scores = 0;
    head->num = 0;
    head->nextstep = NULL;
    //ѡ��ڰ���
    //
    int choose = -1;
    while (choose != 1 && choose != 2)
    {
        printf("1.ѡ����壨��ʵ�ǰ�ɫ�� 2.ѡ����壨��ʵ�Ǻ�ɫ��(��������)\n");
        scanf_s("%d", &choose);
        if (choose == 1)
        {
            Roleplay(board, black, head);
            break;
        }
        else if (choose == 2)
        {
            board[8][8] = black; //Ĭ�ϻ��������������м�
            Roleplay(board, white, head);
            break;
        }
    }
    //
    free(board);
    system("Pause");
    return 0;
}
