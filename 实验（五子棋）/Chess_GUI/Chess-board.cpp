#include<stdio.h>
#include <graphics.h>
#include <conio.h>  //不要忘记引入预编译头文件
#define L 15
typedef struct chess //设置了一个棋type 的结构类型
{
	int x;
	int y;
}CHESS;
//全局变量
CHESS bla;
int judge[19 * 30][19 * 30];
int count = 0;//计数器：判断下哪种棋子
int flag = 0;//判断游戏是否结束
void chessboard()//画棋盘背景
{
	int step = 30;
	// 初始化绘图窗口
	initgraph(800, 600);
	// 设置背景色为蓝色
	setbkcolor(YELLOW);
	// 用背景色清空屏幕
	cleardevice();

	setlinestyle(PS_SOLID, 2);  // 画实线，宽度为2个像素
	setcolor(RGB(0, 0, 0));  // 设置为黑色
	outtextxy(600, 100, _T("W,A,S,D实现位置移动"));
	outtextxy(600, 120, _T("G键下棋子"));

	int i, j;
	for (i = 1; i <= L; i++)  // 画横线和竖线
	{
		line(i * step, 1 * step, i * step, L * step);
		line(1 * step, i * step, L * step, i * step);

	}
	for (i = 0; i <= L; i++)
		for (j = 0; j <= L; j++)
			judge[i][j] = 0;//初始化坐标判断
	bla.x = 10 * 30;
	bla.y = 10 * 30;//初始化棋子坐标
}
int inputchess(CHESS temp, int color, int t)
{
	bla = temp;
	setcolor(color);
	setfillcolor(color);
	if (bla.x <= L * 30 && bla.y <= L * 30)
		fillcircle(bla.x, bla.y, 12);
	judge[bla.x][bla.y] = t;//作标记
	int i, j, f;
	for (i = 0; i < L; i++) //判断是否有一方胜利
	{/*横向*/
		j = f = 0;
		while (f < 5 && j < L)
		{
			if (judge[i * 30][j * 30] == t) f++;
			else f = 0;
			j++;
		}
		if (f == 5) return  t;
	}
	for (j = 0; j < L; j++)
	{/*竖向*/
		i = f = 0;
		while (f < 5 && i < L)
		{
			if (judge[i * 30][j * 30] == t) f++;
			else f = 0;
			i++;
		}
		if (f == 5) return t;
	}
	for (i = 0; i < 12; i++)
	{/*下斜*/
		j = f = 0;
		while (f < 5 && j < 15)
		{
			if (judge[(i + f) * 30][(j + f) * 30] == t) f++;
			else { f = 0; j++; }
		}
		if (f == 5) return  t;
	}
	for (i = 4; i < 19; i++)
	{/*上斜*/
		j = f = 0;
		while (f < 5 && j < 12)
		{
			if (judge[(i - f) * 30][(j + f) * 30] == t) f++;
			else { f = 0; j++; }
		}
		if (f == 5) return  t;
	}
	return 0;
}

void cursor()//光标函数
{
	setcolor(RED);
	setfillcolor(WHITE);
	setwritemode(R2_XORPEN);//二进制模式绘图，便于光标的清除
	CHESS cur = bla;
	char c = ' ';
	fillcircle(cur.x, cur.y, 4);
	while (c != 'g')
	{
		c = _getch();
		switch (c)
		{
		case 'a':fillcircle(cur.x, cur.y, 4); cur.x -= 30; fillcircle(cur.x, cur.y, 4); break;
		case 'd':fillcircle(cur.x, cur.y, 4); cur.x += 30; fillcircle(cur.x, cur.y, 4); break;
		case 'w':fillcircle(cur.x, cur.y, 4); cur.y -= 30; fillcircle(cur.x, cur.y, 4); break;
		case 's':fillcircle(cur.x, cur.y, 4); cur.y += 30; fillcircle(cur.x, cur.y, 4); break;
		}
	}
	if (judge[cur.x][cur.y] != 0)
	{
		count--;
		fillcircle(cur.x, cur.y, 4);
	}
	else
	{
		int i, j, f;
		if (count % 2 == 0)
		{
			fillcircle(cur.x, cur.y, 4);
			flag = inputchess(cur, YELLOW, 2);
			if (flag == 2)
			{
				setcolor(BLACK);
				outtextxy(640, 300, _T("黑棋赢！"));
				printf("\n\n\n黑棋赢啦！\n\n\n\n\n\n");
			}
		}
		else
		{
			fillcircle(cur.x, cur.y, 4);
			flag = inputchess(cur, GREEN, 1);
			if (flag == 1)
			{
				outtextxy(640, 300, _T("红棋赢！"));
				printf("\n\n\n红棋赢啦！\n\n\n\n");

			}
		}
	}
	count++;
}

int main()
{
	chessboard();
	while (true)
	{
		cursor();
		if (flag == 1 || flag == 2)
			break;
	}
	_getch();
	closegraph();
	return 0;
}
