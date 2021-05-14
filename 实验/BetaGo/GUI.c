#include "go.h"

void welcome()//游戏菜单 
{
	int k;
	char choose;
	system("cls");
	for (k = 2;k <= 12;k += 2)//游戏菜单 
	{
		gotoxy(5, k);
		printf("|-----------------|");
	}
	gotoxy(5, 3);
	printf("|  五 子 棋 游 戏 |");

	gotoxy(5, 5);
	printf("|     菜    单    |");

	gotoxy(5, 7);
	printf("|  1.人 机 对 战  |");

	gotoxy(5, 9);
	printf("|  2.游 戏 帮 助  |");

	gotoxy(5, 11);
	printf("|  3.退 出 游 戏  |");

	gotoxy(5, 15);
	printf("温馨提示:输入菜单对应序号进行操作");

	gotoxy(5, 20);
	printf("祝您游戏愉快！");

	gotoxy(13, 20);
}

char Gametips()//游戏帮助 
{
	char choose;
	int key;

	system("cls");

	gotoxy(2, 3);
	printf("游戏操作：");

	gotoxy(4, 5);
	printf("① 红色棋子WASD移动光标选择下棋位置,按空格键确认,按Q悔棋");

	gotoxy(4, 7);
	printf("② 白色棋子↑↓←→移动光标选择下棋位置,按0确认,按B悔棋");

	gotoxy(2, 19);
	printf("（按E键返回，按其它任意键退出）");

	return _getch();
}

void chess_board()//打印棋盘 
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

void BackGround(unsigned int ForeColor, unsigned int BackGroundColor)  //颜色 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  //获取控制台的句柄
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//改变当前光标的背景和字体颜色
}

void gotoxy(int x, int y)    //光标函数 
{
	HANDLE handle;
	COORD coord;   //获取坐标轴结构体
	coord.X = x;
	coord.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);  //获取控制台句柄，值为-11
	SetConsoleCursorPosition(handle, coord);   //移动光标到x，y处
}