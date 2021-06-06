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
	printf("|  2.游 戏 规 则  |");

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
	printf("电脑执红子，玩家执白子");

	gotoxy(4, 7);
	printf("玩家按↑↓←→移动光标选择下棋位置,按空格确认,按B悔棋");

	gotoxy(2, 19);
	printf("（按E键返回，按其它任意键退出，祝您游戏愉快）");

	return _getch();
}

void chess_board()//打印棋盘 
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
		printf("——");
		gotoxy(j, 30);
		printf("——");
	}		
}

void chess_menu()//打印棋盘旁的菜单 
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
	printf("模   式");
	gotoxy(75, 20);
	printf("提   示");
}

void location(int x, int y,int color)                    // 定位
{
	if (color == red)
		BackGround(4, 0);
	else
		BackGround(7, 0);
	//如果传给光标移动函数的是负数，光标就不移动，范围判断，边界不输出定位框，且不能是负数
	if (x > 1 && y > 1)
	{
		gotoxy(x * 4 - 2, y * 2 - 2);puts("┛");
	}	
	if (x < 15 && y > 1)
	{
		gotoxy(x * 4 + 2, y * 2 - 2);puts("┗");
	}
	if (x > 1 && y < 15)
	{
		gotoxy(x * 4 - 2, y * 2);puts("┓");
	}
	if (x < 15 && y < 15)
	{
		gotoxy(x * 4 + 2, y * 2);puts("┏");
	}	
}

void clearlocation(int x, int y)                 //清除定位
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