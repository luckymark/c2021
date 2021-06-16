#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<math.h>
#include<conio.h>
 
#define L 20
 
//ǽ��·���ı�ʶ
#define WALL  0
#define ROUTE 1
 
//�����Թ��ĸ��Ӷȣ���ֵԽ���Ӷ�Խ�ͣ���СֵΪ0
static int Rank = 0;
 
//�����Թ�
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
	printf("����WASD�����ƶ�,����ESC������Ϸ\n\n\n");
	print(Maze);
	while(1)
	{
		t=getch();
		if(t==27)
		{
			break;
			printf("��Ϸ����");
		}
		system("cls");
		move(Maze,t,p,q);
		print(Maze);
		if(x==out&&y==L-2)
		{
			system("cls");
			printf("��Ϸʤ��!\n\n");
			Sleep(1500);
			break;
		}
	}
}

int init(int** Maze)
{
	srand((unsigned)time(NULL));
 

 
	//����Χ����Ϊ·����ԭ��Ϊ�˷�ֹ��·ʱ�ڳ��߽磬ͬʱΪ�˱����Թ��������һȦǽ�屻�ڴ�
	for (int i = 0; i < L; i++){
		Maze[i][0] = ROUTE;
		Maze[0][i] = ROUTE;
		Maze[i][L - 1] = ROUTE;
		Maze[L - 1][i] = ROUTE;
	}
 
	//�����Թ�����2��2��Ϊ���
	CreateMaze(Maze, 2, 2);
 
	//���Թ�����ںͳ���
	Maze[2][1] = ROUTE;
 
 	int i;
	//�����㷨����ԣ�������һ�����ʲ��ڣ�L-3,L-2��������ʱ��ҪѰ�ҳ���
	for ( i = L - 3; i >= 0; i--) {
		if (Maze[i][L - 3] == ROUTE) {
			Maze[i][L - 2] = ROUTE;
			break;
		}
	}
	return i;
 
}

void move(int** Maze, char t, int *x, int *y) {
	int i = *x, j = *y;//��¼ԭʼλ��
	switch(t) {
		case 'w':	//�����ƶ�
			*x -= 1;
			break;
		case 's':	//�����ƶ�
			*x += 1;
			break;
		case 'a':	//�����ƶ�
			*y -= 1;
			break;
		case 'd':	//�����ƶ�
			*y += 1;
			break;
		default:
			break;
	}
	if(*x>=0 && *x<L-1 && *y>=0 && *y<L-1 && Maze[*x][*y]!=WALL) {//�����������ƶ�
		Maze[i][j] = 1;
		Maze[*x][*y] = 2;
	} else {//����λ�ò���
		*x = i;
		*y = j;
	}
}

void print(int **Maze)
{
	
	//���Թ�
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			if (Maze[i][j] == ROUTE) {
				printf("  ");
			}
			else if(Maze[i][j]==WALL){
				printf("��");
			}
			else
				printf("��");
		}
		printf("\n");
	}
 

 } 

void CreateMaze(int **maze, int x, int y) {
	maze[x][y] = ROUTE;
 
	//ȷ���ĸ��������
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
 
	//���ĸ�������
	for (int i = 0; i < 4; i++) {
		int dx = x;
		int dy = y;
 
		//�����ڵľ��룬��Rank��������С
		int range = 1 + (Rank == 0 ? 0 : rand() % Rank);
		while (range>0) {
			dx += direction[i][0];
			dy += direction[i][1];
 
			//�ų�����ͷ·
			if (maze[dx][dy] == ROUTE) {
				break;
			}
 
			//�ж��Ƿ��ڴ�·��
			int count = 0;
			for (int j = dx - 1; j < dx + 2; j++) {
				for (int k = dy - 1; k < dy + 2; k++) {
					//abs(j - dx) + abs(k - dy) == 1 ȷ��ֻ�жϾŹ�����ĸ��ض�λ��
					if (abs(j - dx) + abs(k - dy) == 1 && maze[j][k] == ROUTE) {
						count++;
					}
				}
			}
 
			if (count > 1) {
				break;
			}
 
			//ȷ�������ڴ�ʱ��ǰ��
			--range;
			maze[dx][dy] = ROUTE;
		}
 
		//û���ڴ�Σ�գ��Դ�Ϊ�ڵ�ݹ�
		if (range <= 0) {
			CreateMaze(maze, dx, dy);
		}
	}
}
