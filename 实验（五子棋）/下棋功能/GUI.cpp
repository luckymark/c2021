#include "Chess.h"

//��Ϸ�˵� 
void welcome()
{
	int k;
	char choose;
	system("cls");
	BackGround(9, 15);
	gotoxy(32, 2);
	printf("$$$$$$$$$$$$$$$$$$$");
	gotoxy(32, 17);
	printf("$$$$$$$$$$$$$$$$$$$");
	for (k = 4;k <= 16;k += 2)//��Ϸ�˵� 
	{
		gotoxy(32, k);
		printf("|-----------------|");
	}
	BackGround(2, 15);
	gotoxy(32, 5);
	printf("|  �� �� �� �� Ϸ |");

	gotoxy(32, 7);
	printf("|     ��    ��    |");

	gotoxy(32, 9);
	printf("|  1.�� �� �� ս  |");

	gotoxy(32, 11);
	printf("|  2.�� �� �� ս  |");

	gotoxy(32, 13);
	printf("|  3.�� Ϸ �� ��  |");

	gotoxy(32, 15);
	printf("|  4.�� �� �� Ϸ  |");	

	gotoxy(20, 19);
	BackGround(6, 15);
	printf("��ܰ��ʾ:����˵���Ӧ��Ž��в���");

	gotoxy(20, 21);
	printf("ף����Ϸ��죡");

	gotoxy(20, 22);
}
//��Ϸ����
char Gametips() 
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
//��ӡ���� 
void chess_board()
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
//��ӡ�����ԵĲ˵�
void chess_menu() 
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
//������ƶ���������ʱ���ͼ�ζԹ������λ�ý��ж�λ
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
//�����λ
void clearlocation(int x, int y)                 
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
//������ɫ���ƺ���
void BackGround(unsigned int ForeColor, unsigned int BackGroundColor)  
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  //��ȡ����̨�ľ��
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//�ı䵱ǰ���ı�����������ɫ
}
//��꺯�� 
void gotoxy(int x, int y)    
{
	HANDLE handle;
	COORD coord;   //��ȡ������ṹ��
	coord.X = x;
	coord.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);  //��ȡ����̨�����ֵΪ-11
	SetConsoleCursorPosition(handle, coord);   //�ƶ���굽x��y��
}