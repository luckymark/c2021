#include "go.h"

void welcome()//��Ϸ�˵� 
{
	int k;
	char choose;
	system("cls");
	for (k = 2;k <= 12;k += 2)//��Ϸ�˵� 
	{
		gotoxy(5, k);
		printf("|-----------------|");
	}
	gotoxy(5, 3);
	printf("|  �� �� �� �� Ϸ |");

	gotoxy(5, 5);
	printf("|     ��    ��    |");

	gotoxy(5, 7);
	printf("|  1.�� �� �� ս  |");

	gotoxy(5, 9);
	printf("|  2.�� Ϸ �� ��  |");

	gotoxy(5, 11);
	printf("|  3.�� �� �� Ϸ  |");

	gotoxy(5, 15);
	printf("��ܰ��ʾ:����˵���Ӧ��Ž��в���");

	gotoxy(5, 20);
	printf("ף����Ϸ��죡");

	gotoxy(13, 20);
}

char Gametips()//��Ϸ���� 
{
	char choose;
	int key;

	system("cls");

	gotoxy(2, 3);
	printf("��Ϸ������");

	gotoxy(4, 5);
	printf("�� ��ɫ����WASD�ƶ����ѡ������λ��,���ո��ȷ��,��Q����");

	gotoxy(4, 7);
	printf("�� ��ɫ���ӡ��������ƶ����ѡ������λ��,��0ȷ��,��B����");

	gotoxy(2, 19);
	printf("����E�����أ�������������˳���");

	return _getch();
}

void chess_board()//��ӡ���� 
{
	int i, j;
	for (i = 1;i <= 30;i++)
		for (j = 0;j <= 60;j += 4)
		{
			gotoxy(j, i);
			printf("|");
		}
	for (i = 1;i <= 31;i += 2)
		for (j = 1;j <= 57;j += 4)
		{
			gotoxy(j, i);
			printf("---");
		}
}

void BackGround(unsigned int ForeColor, unsigned int BackGroundColor)  //��ɫ 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  //��ȡ����̨�ľ��
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//�ı䵱ǰ���ı�����������ɫ
}

void gotoxy(int x, int y)    //��꺯�� 
{
	HANDLE handle;
	COORD coord;   //��ȡ������ṹ��
	coord.X = x;
	coord.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);  //��ȡ����̨�����ֵΪ-11
	SetConsoleCursorPosition(handle, coord);   //�ƶ���굽x��y��
}