#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<math.h>


//��ͼ����L�������Թ�����20�����İ�Χ��ǽ��2��������Χ·��2��֮�����ͣ�
#define L 24

//ǽ��·���ı�ʶ
#define WALL  0
#define ROUTE 1

//�����Թ��ĸ��Ӷȣ���ֵԽ��Խ�򵥣���СֵΪ0
int Rank ;
//С�˵�λ������
int x;
int y;
//��¼���ڵ�λ��
int z;

void CreateMaze(int** maze, int x, int y);//�����Թ�
void DrawMaze(int** maze);//���Թ�
void Move(int** maze);//�ƶ�С��
void HomeScreen();//���˵�
void CursorGoto(int x, int y);//��궨λ
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
	//�����Թ�����2��2��Ϊ���
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

	//����Χ����Ϊ·����ԭ��Ϊ�˷�ֹ��·ʱ�ڳ��߽磬ͬʱΪ�˱����Թ��������һȦǽ�屻�ڴ�
	for (int i = 0; i < L; i++) 
	{
		maze[i][0] = ROUTE;
		maze[0][i] = ROUTE;
		maze[i][L - 1] = ROUTE;
		maze[L - 1][i] = ROUTE;
	}

	//ȷ���ĸ��������
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

	//���ĸ�������
	for (int i = 0; i < 4; i++) 
	{
		int dx = x;
		int dy = y;

		//�����ڵľ��룬��Rank��������С
		int range = 1 + (Rank == 0 ? 0 : rand() % Rank);
		while (range > 0) 
		{
			dx += direction[i][0];
			dy += direction[i][1];

			//�ų�����ͷ·
			if (maze[dx][dy] == ROUTE)
			{
				break;
			}

			//�ж��Ƿ��ڴ�·��
			int count = 0;
			for (int j = dx - 1; j < dx + 2; j++) 
			{
				for (int k = dy - 1; k < dy + 2; k++) 
				{
					//abs(j - dx) + abs(k - dy) == 1 ȷ��ֻ�жϾŹ�����ĸ��ض�λ��
					if (abs(j - dx) + abs(k - dy) == 1 && maze[j][k] == ROUTE) 
						count++;
				}
			}

			if (count > 1) break;

			//ȷ�������ڴ�ʱ��ǰ��
			--range;
			maze[dx][dy] = ROUTE;
		}

		//û���ڴ�Σ�գ��Դ�Ϊ�ڵ�ݹ�
		if (range <= 0) 
			CreateMaze(maze, dx, dy);
	}

	//���Թ�����ںͳ���
	maze[2][1] = ROUTE;

	//�����㷨����ԣ�������һ�����ʲ��ڣ�L-3,L-2��������ʱ��ҪѰ�ҳ���
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
					printf("��");
				else
					printf("  ");
			}
			else
			{
				printf("��");
			}
		}
		printf("\n");
	}
	printf("a:�����ƶ�\td:�����ƶ�\n");
	printf("w:�����ƶ�\ts:�����ƶ�\n");
	printf("���س���������");
}

void Move(int** maze)
{
	fflush(stdin);//���ʹ��getchar��Ҫ���stdin��pause���������������ʱ�����һ���ַ�������ҲҪ���
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
		printf("������w��a��s��d");
		Move(maze);
		break;
	}
	system("cls");
	DrawMaze(maze);
	fflush(stdin);
	if (x == z && y == L-2)
		printf("��ϲ���Ѿ��߳��Թ�");
	else
		Move(maze);
}

void HomeScreen()
{
	system("cls");
	CursorGoto(39, 8);
	printf("��ӭ�����Թ���Ϸ");
	CursorGoto(39, 10);
	printf("�밴0-4ѡ���Ѷȵȼ�\n");
	scanf_s("%d", &Rank);
}

void CursorGoto(int x, int y) 
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}