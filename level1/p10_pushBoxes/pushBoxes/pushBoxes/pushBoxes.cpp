// pushBoxes.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void printmap(char *p);
int main()
{
	int score = 100, step = 0, time = 1;
	char direction;
	char* man, * position[4];
	int n;
	printf("Please enter '1' or '2' to choose map\npress w a s d to move\n");
	scanf_s("%d", &n); //选择地图
	FILE* loadmap;
	char map[8][8] = { 0 };
	switch (n)
	{
	case 1:
	{
		freopen_s(&loadmap, "map1.txt", "r", stdin);
		position[0] = &map[1][3]; position[1] = &map[3][6]; position[2] = &map[4][1]; position[3] = &map[6][4];
		man = &map[4][4];//指针分别指向地点、人物
		break;
	}
	case 2:
	{
		freopen_s(&loadmap, "map2.txt", "r", stdin);
		position[0] = &map[1][3]; position[1] = &map[1][4]; position[2] = &map[2][4]; position[3] = &map[3][5];
		man = &map[6][3];//指针分别指向地点、人物
		break;
	}
	default:return -1;
	}
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
			scanf_s("%c", &map[i][j], 1);
	}//加载地图


	//开始游玩
	while ('O' != *position[0] || 'O' != *position[1] || 'O' != *position[2] || 'O' != *position[3])
	{
		system("cls");
		printmap(map[0]);
		printf("\n\nscore:%d,step:%d", score, step);
		switch (direction = _getch())
		{
		case 'w':
		{
			if (*(man - 8) == ' ' || *(man - 8) == 'X')
			{
				*man = ' '; man -= 8; *man = 'I'; score--; step++;
			}
			else
			{
				if (*(man - 8) == 'O' && (*(man - 16) == ' ') || *(man - 16) == 'X')
				{
					*man = ' '; man -= 8; *man = 'I'; *(man - 8) = 'O'; score--; step++;
				}
				else break;
			}
			for (int i = 0; i <= 3; i++)
			{
				if (*position[i] == ' ')
					*position[i] = 'X';
			}
			break;
		}
		case 'a':
		{
			if (*(man - 1) == ' ' || *(man - 1) == 'X')
			{
				*man = ' '; man -= 1; *man = 'I'; score--; step++;
			}
			else
			{
				if (*(man - 1) == 'O' && (*(man - 2) == ' ') || *(man - 2) == 'X')
				{
					*man = ' '; man -= 1; *man = 'I'; *(man - 1) = 'O'; score--; step++;
				}
				else break;
			}
			for (int i = 0; i <= 3; i++)
			{
				if (*position[i] == ' ')
					*position[i] = 'X';
			}
			break;
		}
		case 's':
		{
			if (*(man + 8) == ' ' || *(man + 8) == 'X')
			{
				*man = ' '; man += 8; *man = 'I'; score--; step++;
			}
			else
			{
				if (*(man + 8) == 'O' && (*(man + 16) == ' ') || *(man + 16) == 'X')
				{
					*man = ' '; man += 8; *man = 'I'; *(man + 8) = 'O'; score--; step++;
				}
				else break;
			}
			for (int i = 0; i <= 3; i++)
			{
				if (*position[i] == ' ')
					*position[i] = 'X';
			}
			break;
		}
		case 'd':
		{
			if (*(man + 1) == ' ' || *(man + 1) == 'X')
			{
				*man = ' '; man += 1; *man = 'I'; score--; step++;
			}
			else
			{
				if (*(man + 1) == 'O' && (*(man + 2) == ' ') || *(man + 2) == 'X')
				{
					*man = ' '; man += 1; *man = 'I'; *(man + 1) = 'O'; score--; step++;
				}
				else break;
			}
			for (int i = 0; i <= 3; i++)
			{
				if (*position[i] == ' ')
					*position[i] = 'X';
			}
			break;
		}
		}
	}
	system("cls");
	printmap(map[0]);
	printf("you win");
	if (n == 1)
	{
		freopen_s(&loadmap, "score1.txt", "a", stdout);
	}
	if (n == 2)
	{
		freopen_s(&loadmap, "score2.txt", "a", stdout);
	}
	printf("\nYour score is:%d", score);
	system("pause");
	if (loadmap != NULL)
		fclose(loadmap);
	return 0;
}

//打印地图的函数
void printmap(char* p)
{
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			printf("%c", *p); p++;
		}
		printf("\n");
	}
	return;
}

