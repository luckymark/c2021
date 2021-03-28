#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<math.h>


//地图长度L，包括迷宫主体20，外侧的包围的墙体2，最外侧包围路径2（之后会解释）
#define L 24

//墙和路径的标识
#define WALL  0
#define ROUTE 1

//控制迷宫的复杂度，数值越大越简单，最小值为0
int Rank ;
//小人的位置坐标
int x;
int y;
//记录出口的位置
int z;

void CreateMaze(int** maze, int x, int y);//生成迷宫
void DrawMaze(int** maze);//画迷宫
void Move(int** maze);//移动小人
void HomeScreen();//主菜单
void CursorGoto(int x, int y);//光标定位
int main(void) 
{
	system("color F2");
	srand((unsigned)time(NULL));
	HomeScreen();
	system("cls");

	int** Maze = (int**)malloc(L * sizeof(int*));
	for (int i = 0; i < L; i++) 
	{
		Maze[i] = (int*)calloc(L, sizeof(int));
	}

	x = 2;
	y = 1;
	//创造迷宫，（2，2）为起点
	CreateMaze(Maze, 2, 2);
	DrawMaze(Maze);

	Move(Maze);

	for (int i = 0; i < L; i++) free(Maze[i]);
	free(Maze);

	system("pause");
	return 0;
}

void CreateMaze(int** maze, int x, int y)
{
	maze[x][y] = ROUTE;

	//最外围层设为路径的原因，为了防止挖路时挖出边界，同时为了保护迷宫主体外的一圈墙体被挖穿
	for (int i = 0; i < L; i++) 
	{
		maze[i][0] = ROUTE;
		maze[0][i] = ROUTE;
		maze[i][L - 1] = ROUTE;
		maze[L - 1][i] = ROUTE;
	}

	//确保四个方向随机
	int direction[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
	for (int i = 0; i < 4; i++) 
	{
		int r = rand() % 4;
		int temp = direction[0][0];
		direction[0][0] = direction[r][0];
		direction[r][0] = temp;

		temp = direction[0][1];
		direction[0][1] = direction[r][1];
		direction[r][1] = temp;
	}

	//向四个方向开挖
	for (int i = 0; i < 4; i++) 
	{
		int dx = x;
		int dy = y;

		//控制挖的距离，由Rank来调整大小
		int range = 1 + (Rank == 0 ? 0 : rand() % Rank);
		while (range > 0) 
		{
			dx += direction[i][0];
			dy += direction[i][1];

			//排除掉回头路
			if (maze[dx][dy] == ROUTE)
			{
				break;
			}

			//判断是否挖穿路径
			int count = 0;
			for (int j = dx - 1; j < dx + 2; j++) 
			{
				for (int k = dy - 1; k < dy + 2; k++) 
				{
					//abs(j - dx) + abs(k - dy) == 1 确保只判断九宫格的四个特定位置
					if (abs(j - dx) + abs(k - dy) == 1 && maze[j][k] == ROUTE) 
						count++;
				}
			}

			if (count > 1) break;

			//确保不会挖穿时，前进
			--range;
			maze[dx][dy] = ROUTE;
		}

		//没有挖穿危险，以此为节点递归
		if (range <= 0) 
			CreateMaze(maze, dx, dy);
	}

	//画迷宫的入口和出口
	maze[2][1] = ROUTE;

	//由于算法随机性，出口有一定概率不在（L-3,L-2）处，此时需要寻找出口
	for (int i = L - 3; i >= 0; i--) {
		if (maze[i][L - 3] == ROUTE) {
			maze[i][L - 2] = ROUTE;
			z = i;
			break;
		}
	}
}

void DrawMaze(int** maze)
{
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			if (maze[i][j] == ROUTE)
			{
				if(i==x&&j==y)
					printf("♀");
				else
					printf("  ");
			}
			else
			{
				printf("▓");
			}
		}
		printf("\n");
	}
	printf("a:向左移动\td:向右移动\n");
	printf("w:向上移动\ts:向下移动\n");
	printf("按回车结束输入");
}

void Move(int** maze)
{
	fflush(stdin);//多次使用getchar需要清空stdin，pause按任意键继续，这时会读入一个字符，所以也要清空
	char m;
	m = getchar();
	if(m=='\n')
		m = getchar();
	fflush(stdin);
	switch (m) 
	{
	case 'a':
		if (maze[x][y - 1] == WALL)
			Move(maze);
		else
			y = y - 1;
		break;
	case 'w':
		if (maze[x - 1][y] == WALL)
			Move(maze);
		else
			x = x - 1;
		break;
	case 's':
		if (maze[x + 1][y] == WALL)
			Move(maze);
		else
			x = x + 1;
		break;
	case 'd':
		if (maze[x][y + 1] == WALL)
			Move(maze);
		else
			y = y + 1;
		break;
	default:
		printf("请输入w，a，s，d");
		Move(maze);
		break;
	}
	system("cls");
	DrawMaze(maze);
	fflush(stdin);
	if (x == z && y == L-2)
		printf("恭喜您已经走出迷宫");
	else
		Move(maze);
}

void HomeScreen()
{
	system("cls");
	CursorGoto(39, 8);
	printf("欢迎来到迷宫游戏");
	CursorGoto(39, 10);
	printf("请按0-4选择难度等级\n");
	scanf_s("%d", &Rank);
}

void CursorGoto(int x, int y) 
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}