# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <windows.h>

int map[8][10][10];
int  role_i, role_j;
int count;
int isFinishCount[8] = { 0 };
int finishSum;
int N=0;

void gotoxy(int x, int y);
void HideCursor();
void startup();
void show();
void updateWithInput();
void updateWithoutInput();


int main()
{
	FILE* fp=fopen("map.txt","r");
	if (fp==NULL){
		printf("���ļ�");
		return -1;
	}
	for (int i=0;i<8;i++){
		for (int j=0;j<10;j++){
			for (int k=0;k<10;k++){
				fscanf(fp,"%d",&map[i][j][k]);
			}
			fscanf(fp,"\n");
		}
	}
	fclose(fp);
	
	startup();

	while (1) {
		show();
		updateWithoutInput();
		updateWithInput();
	}

	FILE* fp2=fopen("step.txt","w");
	if (fp2==NULL){
		printf("���ļ�");
	}
	fprintf(fp2,"��˴���Ϸ�Ĳ���Ϊ%d\n",N);
	fclose(fp2);
	return 0;
}

void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void startup() 
{
	HideCursor();
	role_i = 6;
	role_j = 2;
	count = 0;
	finishSum = 0;
}

void show() 
{
	system("color f9");

	int i, j;
	gotoxy(0, 0);
	printf("���л�Ӣ�����������Ϊ wasd ���� ��������\n");
	printf("��ҪĿ�꣺�ѡ��Ƶ���ɽ�����һ��\n");
	printf("������ͨ������ѡ��ؿ���1-8��\n");
	printf("�����������ڵ� %d ��\n\n", count + 1);
	printf("��ͨ������%d\n", finishSum);
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			switch (map[count][i][j])
			{
			case 0://�յ�
				printf("  ");
				break;
			case 1://ǽ
				printf("��");
				break;
			case 3://Ŀ�ĵ�
				printf("��");
				break;
			case 4://����
				printf("��");
				break;
			case 7://�����ƽ�Ŀ�ĵ�
				printf("��");
				break;
			case 5://��
			case 8://��
				printf("��");
				break;
			}
		}
		printf("\n");
	}

}

void updateWithInput() 
{
	char hit;
	if (_kbhit())
	{
		hit = _getch();
		if (hit >= '1' && hit <= '8')
		{
			count = hit - 1 - '0';
		}
		switch (hit)
		{
		case 'w':
		case 'W':
		case 72:
			if (map[count][role_i - 1][role_j] == 0 || map[count][role_i - 1][role_j] == 3)
			{
				map[count][role_i - 1][role_j] += 5;
				map[count][role_i][role_j] -= 5;
				N+=1;
			}
			if (map[count][role_i - 1][role_j] == 4 || map[count][role_i - 1][role_j] == 7)
			{
				if (map[count][role_i - 2][role_j] != 1 && map[count][role_i - 2][role_j] != 4 && map[count][role_i - 2][role_j] != 7)
				{
					map[count][role_i - 2][role_j] += 4;
					map[count][role_i - 1][role_j] += 1;
					map[count][role_i][role_j] -= 5;
					N+=1;
				}
			}
			break;
		case 's':
		case 'S':
		case 80:
			if (map[count][role_i + 1][role_j] == 0 || map[count][role_i + 1][role_j] == 3)
			{

				map[count][role_i + 1][role_j] += 5;
				map[count][role_i][role_j] -= 5;
				N+=1;
			}
			if (map[count][role_i + 1][role_j] == 4 || map[count][role_i + 1][role_j] == 7)
			{
				if (map[count][role_i + 2][role_j] != 1 && map[count][role_i + 2][role_j] != 4 && map[count][role_i + 2][role_j] != 7)
				{
					map[count][role_i + 2][role_j] += 4;
					map[count][role_i + 1][role_j] += 1;
					map[count][role_i][role_j] -= 5;
					N+=1;
				}

			}
			break;
		case 'a':
		case 'A':
		case 75:
			if (map[count][role_i][role_j - 1] == 0 || map[count][role_i][role_j - 1] == 3)
			{
				map[count][role_i][role_j - 1] += 5;
				map[count][role_i][role_j] -= 5;
				N+=1;
			}
			if (map[count][role_i][role_j - 1] == 4 || map[count][role_i][role_j - 1] == 7)
			{
				if (map[count][role_i][role_j - 2] != 1 && map[count][role_i][role_j - 2] != 4 && map[count][role_i][role_j - 2] != 7)
				{
					map[count][role_i][role_j - 2] += 4;
					map[count][role_i][role_j - 1] += 1;
					map[count][role_i][role_j] -= 5;
					N+=1;
				}
			}
			break;
		case'd':
		case'D':
		case 77:
			if (map[count][role_i][role_j + 1] == 0 || map[count][role_i][role_j + 1] == 3)
			{
				map[count][role_i][role_j + 1] += 5;
				map[count][role_i][role_j] -= 5;
				N+=1;
			}
			if (map[count][role_i][role_j + 1] == 4 || map[count][role_i][role_j + 1] == 7)
			{
				if (map[count][role_i][role_j + 2] != 1 && map[count][role_i][role_j + 2] != 4 && map[count][role_i][role_j + 2] != 7)
				{
					map[count][role_i][role_j + 2] += 4;
					map[count][role_i][role_j + 1] += 1;
					map[count][role_i][role_j] -= 5;
					N+=1;
				}
			}
			break;
		}
	}
}

void updateWithoutInput() 
{
	bool isMapFinish = true;
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (map[count][i][j] == 4)
			{
				isMapFinish = false;
				goto NEXT;
			}
		}
	}
NEXT:

	finishSum = 0;

	for (i = 0; i < 8; i++)
	{
		if (isFinishCount[i] == 1)
		{
			finishSum++;
		}
	}

	if (isMapFinish)
	{
		printf("\a");
		printf("���ƶ��Ĵ�����%d��\n",N);
		isFinishCount[count] = 1;

		for (i = 0; i < 8; i++)
		{
			if (isFinishCount[i] == 0)
			{
				break;
			}
		}

		if (i == 8)
		{
			printf("OK! You Win!\n");
			system("pause");
			exit(-1);
		}

		if (count < 8)
		{
			count++;
		}
		else
		{
			count = i;
		}

	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (map[count][i][j] == 5 || map[count][i][j] == 8)
			{
				role_i = i;
				role_j = j;
				goto NEXT_1;
			}
		}
	}
NEXT_1:
	;
}

