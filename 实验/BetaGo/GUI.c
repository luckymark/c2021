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
	printf("����ִ���ӣ����ִ����");

	gotoxy(4, 7);
	printf("��Ұ����������ƶ����ѡ������λ��,���ո�ȷ��,��B����");

	gotoxy(2, 19);
	printf("����E�����أ�������������˳���ף����Ϸ��죩");

	return _getch();
}

void chess_board()//��ӡ���� 
{
	int i, j;
	for (i = 1;i <= 29;i++)
		for (j = 4;j <= 60;j += 4)
		{
			gotoxy(j, i);
			printf("|");
		}
	for (i = 1;i <= 29;i += 2)
		for (j = 5;j <= 57;j += 4)
		{
			gotoxy(j, i);
			printf("---");
		}
	for (j = 5;j <= 57;j += 4)
	{
		gotoxy(j, 0);   
		printf("����");
		gotoxy(j, 30);
		printf("����");
	}		
}

void chess_menu()//��ӡ�����ԵĲ˵� 
{
	int i, j;
	for (i = 1;i <= 29;i++)
	{
		gotoxy(67, i);
		printf("||");
	}
	for (i = 1;i <= 29;i++)
	{
		gotoxy(89, i);
		printf("||");
	}
	gotoxy(69, 1);
	printf("--------------------");
	gotoxy(69, 29);
	printf("--------------------");
	gotoxy(75, 3);
	printf("ģ   ʽ");
	gotoxy(75, 20);
	printf("��   ʾ");
}

void location(int x, int y,int color)                    // ��λ
{
	if (color == red)
		BackGround(4, 0);
	else
		BackGround(7, 0);
	//�����������ƶ��������Ǹ��������Ͳ��ƶ�����Χ�жϣ��߽粻�����λ���Ҳ����Ǹ���
	if (x > 1 && y > 1)
	{
		gotoxy(x * 4 - 2, y * 2 - 2);puts("��");
	}	
	if (x < 15 && y > 1)
	{
		gotoxy(x * 4 + 2, y * 2 - 2);puts("��");
	}
	if (x > 1 && y < 15)
	{
		gotoxy(x * 4 - 2, y * 2);puts("��");
	}
	if (x < 15 && y < 15)
	{
		gotoxy(x * 4 + 2, y * 2);puts("��");
	}	
}

void clearlocation(int x, int y)                 //�����λ
{
	if (x > 1 && y > 1)
	{
		gotoxy(x * 4 - 2, y * 2 - 2);puts("  ");
	}
	if (x < 15 && y > 1)
	{
		gotoxy(x * 4 + 2, y * 2 - 2);puts("  ");
	}
	if (x > 1 && y < 15)
	{
		gotoxy(x * 4 - 2, y * 2);puts("  ");
	}
	if (x < 15 && y < 15)
	{
		gotoxy(x * 4 + 2, y * 2);puts("  ");
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