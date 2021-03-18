//操作：上:w		下:s		左:a		右:d		
#include<stdio.h>
#include<windows.h>
#include<conio.h>

void CursorTo_x_y(int x, int y);
void map();

char up = 'w', down = 's', left = 'a', right = 'd';
int x, y;
int i, j;
char a[20][70];

int main() {
	//用打印数组的方式来表示迷宫地图，用打印的字符表示墙，玩家等障碍物.
	map();
	system("color f2");
	//设置出口
	a[10][69] = ' ';
	//输出字符，也就是显示地图
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 70; j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	//光标跟踪任务的位置，设定初始位置，注意控制台的行列和数组的行列时相反的
	x = 18;
	y = 1;
	CursorTo_x_y(x, y);
	//移动光标
	while (1)
	{
		char key = _getch();//输入要执行的操作
		CursorTo_x_y(x, y);
		if(key == up && a[x-1][y] == ' ')
		{
			x = x - 1;
			CursorTo_x_y(x, y);
		}
		if(key == down && a[x+1][y] == ' ')
		{
			x = x + 1;
			CursorTo_x_y(x, y);
		}
		if(key == left && a[x][y-1] == ' ')
		{
			y = y - 1;
			CursorTo_x_y(x, y);
		}
		if(key == right && a[x][y] == ' ')
		{
			y = y + 1;
			CursorTo_x_y(x, y);
		}
		if (x == 10 && y == 69)
		{
			printf("win");
				break;
		}
	}

	getchar();
	return 0;
}
void CursorTo_x_y(int x, int y)
{
	COORD c;
	c.X = y;
	c.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void map()
{
	//初始化数组，空格表示可移动的空间
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 70; j++)
		{
			a[i][j] = ' ';
		}
	}
	//设置迷宫的边缘，用#表示
	for (j = 0; j < 70; j++)
	{
		a[0][j] = '#';
		a[19][j] = '#';
	}
	for (i = 0; i < 20; i++)
	{
		a[i][0] = '#';
		a[i][69] = '#';
	}
	//设置迷宫内的墙
	for (i = 0; i < 15; i++)
	{
		a[i][9] = '#';
	}
	for (i = 0; i < 10; i++)
	{
		a[i][16] = '#';
	}
	for (j = 0; j < 40; j++)
	{
		a[8][j] = '#';
		a[17][j] = '#';
	}
	for (i = 15; i < 18; i++)
	{
		a[i][7] = '#';
	}
	for (i = 0; i < 18; i++)
	{
		a[i][50] = '#';
	}
	for (i = 15; i < 19; i++)
	{
		a[i][41] = '#';
	}
	for (j = 10; j < 40; j++)
	{
		a[15][j] = '#';
	}
	a[18][41] = '#';
	a[15][4] = '#'; a[15][2] = '#'; a[15][3] = '#'; a[15][5] = '#'; a[15][6] = '#';
	a[13][2] = '#';	a[12][2] = '#'; a[15][7] = '#';	a[11][2] = '#';	a[9][2] = '#';
	a[13][3] = '#'; a[13][4] = '#'; a[13][5] = '#';
	a[17][5] = ' ';
	a[10][9] = ' ';
}
