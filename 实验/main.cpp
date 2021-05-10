//������ʵ��
#include <stdio.h>
#include <windows.h>
#include "def.h"

int main()
{

    //��������ʼ��15x15������
    int **board = creatboard();
    //����
    steps tree;
    steps *head = &tree;
    head->x = 0;
    head->y = 0;
    head->scores = 0;
    head->nextstep = NULL;
    int count = 0;
    //�û�ѡ����廹�Ǻ���
    int choose = 0;
    while (choose != black && choose != white)
    {
        printf("ѡ����廹�ǰ�����(��������)\n1������\n2������\n");
        scanf("%d", &choose);
        if (choose == black)
        {
            Roleplay(board, choose, head);
            break;
        }
        else if (choose == white)
        {
            board[6][6] = black; //Ĭ�������м�
            Roleplay(board, choose, head);
            break;
        }
    }

    free(board);
    system("Pause");
    return 0;
}
