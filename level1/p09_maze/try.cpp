#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<math.h>
#include<conio.h>
 
#define L 20
 
//墙和路径的标识
#define WALL  0
#define ROUTE 1
 
//控制迷宫的复杂度，数值越大复杂度越低，最小值为0
static int Rank = 0;
 
//生成迷宫
void CreateMaze(int **maze, int x, int y);
void print(int **Maze);
void move(int** Maze, char t, int *x, int *y);
int init(int** Maze);
void start(int** Maze);
 
int main() {
	
	int **Maze = (int**)malloc(L * sizeof(int *));
	for (int i = 0; i < L; i++) 
	{
		Maze[i] = (int*)calloc(L, sizeof(int));
	}
	
	start(Maze);
	
	for (int i = 0; i < L; i++) free(Maze[i]);
	free(Maze);
	return 0;
}

void start(int** Maze)
{
	char t;
	int x=2,y=1,out=0;
	int *p=&x,*q=&y;
	out=init(Maze);
	system("cls");
	printf("输入WASD进行移动,输入ESC结束游戏\n\n\n");
	print(Maze);
	while(1)
	{
		t=getch();
		if(t==27)
		{
			break;
			printf("游戏结束");
		}
		system("cls");
		move(Maze,t,p,q);
		print(Maze);
		if(x==out&&y==L-2)
		{
			system("cls");
			printf("游戏胜利!\n\n");
			Sleep(1500);
			break;
		}
	}
}

int init(int** Maze)
{
	srand((unsigned)time(NULL));
 

 
	//最外围层设为路径的原因，为了防止挖路时挖出边界，同时为了保护迷宫主体外的一圈墙体被挖穿
	for (int i = 0; i < L; i++){
		Maze[i][0] = ROUTE;
		Maze[0][i] = ROUTE;
		Maze[i][L - 1] = ROUTE;
		Maze[L - 1][i] = ROUTE;
	}
 
	//创造迷宫，（2，2）为起点
	CreateMaze(Maze, 2, 2);
 
	//画迷宫的入口和出口
	Maze[2][1] = ROUTE;
 
 	int i;
	//由于算法随机性，出口有一定概率不在（L-3,L-2）处，此时需要寻找出口
	for ( i = L - 3; i >= 0; i--) {
		if (Maze[i][L - 3] == ROUTE) {
			Maze[i][L - 2] = ROUTE;
			break;
		}
	}
	return i;
 
}

void move(int** Maze, char t, int *x, int *y) {
	int i = *x, j = *y;//记录原始位置
	switch(t) {
		case 'w':	//向上移动
			*x -= 1;
			break;
		case 's':	//向下移动
			*x += 1;
			break;
		case 'a':	//向左移动
			*y -= 1;
			break;
		case 'd':	//向右移动
			*y += 1;
			break;
		default:
			break;
	}
	if(*x>=0 && *x<L-1 && *y>=0 && *y<L-1 && Maze[*x][*y]!=WALL) {//符合条件，移动
		Maze[i][j] = 1;
		Maze[*x][*y] = 2;
	} else {//保持位置不变
		*x = i;
		*y = j;
	}
}

void print(int **Maze)
{
	
	//画迷宫
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			if (Maze[i][j] == ROUTE) {
				printf("  ");
			}
			else if(Maze[i][j]==WALL){
				printf("国");
			}
			else
				printf("人");
		}
		printf("\n");
	}
 

 } 

void CreateMaze(int **maze, int x, int y) {
	maze[x][y] = ROUTE;
 
	//确保四个方向随机
	int direction[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
	for (int i = 0; i < 4; i++) {
		int r = rand() % 4;
		int temp = direction[0][0];
		direction[0][0] = direction[r][0];
		direction[r][0] = temp;
 
		temp = direction[0][1];
		direction[0][1] = direction[r][1];
		direction[r][1] = temp;
	}
 
	//向四个方向开挖
	for (int i = 0; i < 4; i++) {
		int dx = x;
		int dy = y;
 
		//控制挖的距离，由Rank来调整大小
		int range = 1 + (Rank == 0 ? 0 : rand() % Rank);
		while (range>0) {
			dx += direction[i][0];
			dy += direction[i][1];
 
			//排除掉回头路
			if (maze[dx][dy] == ROUTE) {
				break;
			}
 
			//判断是否挖穿路径
			int count = 0;
			for (int j = dx - 1; j < dx + 2; j++) {
				for (int k = dy - 1; k < dy + 2; k++) {
					//abs(j - dx) + abs(k - dy) == 1 确保只判断九宫格的四个特定位置
					if (abs(j - dx) + abs(k - dy) == 1 && maze[j][k] == ROUTE) {
						count++;
					}
				}
			}
 
			if (count > 1) {
				break;
			}
 
			//确保不会挖穿时，前进
			--range;
			maze[dx][dy] = ROUTE;
		}
 
		//没有挖穿危险，以此为节点递归
		if (range <= 0) {
			CreateMaze(maze, dx, dy);
		}
	}
}
