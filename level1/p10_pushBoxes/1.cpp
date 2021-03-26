//操作：上:w		下:s		左:a		右:d		
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>


int level = 0, LevelRow[2] = { 8,6 }, LevelCol[2] = { 4,6 };
char gameMap[2][100] = { { "E:\\test\\1.txt"}, { "E:\\test\\2.txt"} };
char map1[8][4], map2[], str[2000] = { 0 };
char up = 'w', down = 's', left = 'a', right = 'd';
int x, y;

void CursorTo_x_y(int x, int y);
void makeMap();
void move(char b[], int raw, int col);

int main() {
	makeMap();
	move(str, LevelRow[level], LevelCol[level]);
	if (level < 2)
	{
		makeMap();
		move(str, LevelRow[level], LevelCol[level]);
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
void makeMap()
{
	FILE* fp;
	errno_t err = fopen_s(&fp, gameMap[level], "r");
	//if (err != 0) printf("失败");
	fgets(str, 1000, fp);
	//fscanf_s(fp,"%s", map,100);
	fclose(fp);
	system("color f2");
	if (level == 0)
	{
		str[17] = '@';
		int q = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			printf("%c", str[i]);
			if ((i + 1) % LevelCol[level] == 0)
				printf("\n");
		}
		x = 5;
		y = 1;
		CursorTo_x_y(6, 1);
		putchar('*');
		CursorTo_x_y(x, y);
	}
	if (level == 1)
	{
		str[14] = '@', str[15] = '@';
		int q = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			printf("%c", str[i]);
			if ((i + 1) % LevelCol[level] == 0)
				printf("\n");
		}
		x = 1;
		y = 2;
		CursorTo_x_y(1, 3);
		putchar('*');
		CursorTo_x_y(1, 4);
		putchar('*');
		CursorTo_x_y(x, y);
	}

}
void move(char b[], int row, int col)
{
	char** a = (char**)calloc(row, sizeof(char**));
	int q = 0;
	for (int i = 0; i < row; i++)
	{
		a[i] = (char*)calloc(col, sizeof(char*));
		for (int j = 0; j < col; j++)
		{
			a[i][j] = b[q++];
		}
	}
	int score = 0;
	while (1)
	{

		char key = _getch();//输入要执行的操作
		score++;
		CursorTo_x_y(x, y);
		if (key == up && (a[x - 1][y] == ' ' || (a[x - 1][y] == '@' && a[x - 2][y] == ' ')))
		{
			x = x - 1;
			CursorTo_x_y(x, y);
			if (a[x][y] == '@')
			{
				putchar(' ');
				a[x][y] = ' ';
				CursorTo_x_y(x - 1, y);
				putchar('@');
				a[x - 1][y] = '@';
				CursorTo_x_y(x, y);
			}
		}
		if (key == down && (a[x + 1][y] == ' ' || (a[x + 1][y] == '@' && a[x + 2][y] == ' ')))
		{
			x = x + 1;
			CursorTo_x_y(x, y);
			if (a[x][y] == '@')
			{
				putchar(' ');
				a[x][y] = ' ';
				CursorTo_x_y(x + 1, y);
				putchar('@');
				a[x + 1][y] = '@';
				CursorTo_x_y(x, y);
			}
		}
		if (key == left && (a[x][y - 1] == ' ' || (a[x][y - 1] == '@' && a[x][y - 2] == ' ')))
		{
			y = y - 1;
			CursorTo_x_y(x, y);
			if (a[x][y] == '@')
			{
				putchar(' ');
				a[x][y] = ' ';
				CursorTo_x_y(x, y - 1);
				putchar('@');
				a[x][y - 1] = '@';
				CursorTo_x_y(x, y);
			}
		}
		if (key == right && (a[x][y + 1] == ' ' || (a[x][y + 1] == '@' && a[x][y + 2] == ' ')))
		{
			y = y + 1;
			CursorTo_x_y(x, y);
			if (a[x][y] == '@')
			{
				putchar(' ');
				a[x][y] = ' ';
				CursorTo_x_y(x, y + 1);
				putchar('@');
				a[x][y + 1] = '@';
				CursorTo_x_y(x, y);
			}
		}
		if (level == 0)
		{
			if (a[6][1] == '@')
			{
				printf("you win the level %d of the game,your score is %d\n\
					the level %d is coming soon", level, score, level + 1);
				Sleep(3000);
				system("cls");
				break;
			}
		}
		if (level == 1)
		{
			static int j = 0;
			static int k = 0;
			if (a[1][3] == '@')
			{
				j = score;
			}
			if (j + 1 == score)
			{
				CursorTo_x_y(1, 3);
				putchar('*');
				CursorTo_x_y(x, y);
			}
			if (a[1][4] == '@')
			{
				k = score;
			}
			if (k + 1 == score)
			{
				CursorTo_x_y(1, 4);
				putchar('*');
				CursorTo_x_y(x, y);
			}
			if (a[1][3] == '@' && a[1][4] == '@') {
				printf("you win the level %d of the game,your score is %d\n\
					the level %d is under developing", level, score, ++level);
				Sleep(2000);
				system("cls");
				break;
			}
		}
	}
	FILE* fp;
	fopen_s(&fp, "E:\\test\\score.txt", "a");
	fprintf(fp, "your score of level %d is %d\n", level, score);
	fclose(fp);
	level++;
}