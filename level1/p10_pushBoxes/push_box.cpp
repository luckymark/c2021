#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

//" "����·��"@"�����ˣ�"O"��������ӵ�λ�ã�"*"����ǽ��"#"�������ӡ�
//0." "����·��1."@"������,2."O"��������ӵ�λ��,3."*"����ǽ,4."#"��������,5."#"�������λ�õ����ӣ�6."@"�����˽������ӵ�λ��

int x = 0, y = 0;
int step = 0;

int map[8][8] ={0};

void read_map()
{
    FILE *p;
    int n = 0;
    printf("������ؿ�����1��2����"); 
    cin >> n;
    if(n==1)
    {
    	p = fopen("1.txt", "r");
	}
	else if(n==2)
	{
		p = fopen("2.txt", "r");
	}
    if(p==NULL)
    {
        printf("��ͼ��ʧ�ܣ�\n");
        exit(0);
    }
    int i = 0, j = 0;
    for (int i = 0; i < 8;i++)
    {
        for (int j = 0; j < 8;j++)
        {
            fscanf(p, "%d", &map[i][j]);
        }
    }
}
void paint()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8;j++)
        {
           if(0 == map[i][j])
			{
				printf(" ");
			}
            else if(1 == map[i][j])
			{
				printf("@");
			}
            else if(2 == map[i][j])
			{
				printf("O");
			}
            else if(3 == map[i][j])
			{
				printf("*");
			}
            else if(4 == map[i][j])
			{
				printf("#");
			}
            else if(5 == map[i][j])
			{
				printf("#");
			}
            else if(6 == map[i][j])
			{
				printf("@");
			}
        }
        printf("\n");
    }
}

void up()
{
    for(int i=0; i<8;i++)
	{
		for(int j=0; j<8;j++)
		{
			if(1 == map[i][j]||6==map[i][j])
			{
                x = i;
                y = j;
            }			
		}
	}
    if(3==map[x-1][y])
        return;
    if(0==map[x-1][y])
    {
        map[x - 1][y] = 1;
        if(6==map[x][y])
            map[x][y] = 2;
        if(1==map[x][y])
            map[x][y] = 0;
        step++;
    }
    if(2==map[x-1][y])
    {
        map[x - 1][y] = 6;
        if(6==map[x][y])
            map[x][y] = 2;
        if(1==map[x][y])
            map[x][y] = 0;
        step++;
    }
    if(4==map[x-1][y])
    {
        if(0== map[x-2][y])
        {
            map[x - 2][y] = 4;
            map[x - 1][y] = 1;
            if(6==map[x][y])
                map[x][y] = 2;
            else
                map[x][y] = 0;
            step++;
        }
        if(2==map[x-2][y])
        {
            map[x - 2][y] = 5;
            map[x - 1][y] = 1;
            if(6==map[x][y])
                map[x][y] = 2;
            else
                map[x][y] = 0;
            step++;
        }
        else
            return;
    }
    if(5==map[x-1][y])
    {
        if(0==map[x-2][y])
        {
            map[x - 2][y] = 4;
            map[x - 1][y] = 6;
            if(6==map[x][y])
                map[x][y] = 2;
            else
                map[x][y] = 0;
            step++;
        }
        if(2==map[x-2][y])
        {
            map[x - 2][y] = 5;
            map[x - 1][y] = 6;
            if(6==map[x][y])
                map[x][y] = 2;
            else
                map[x][y] = 0;
            step++;
        }
        else
            return;
    }
}

void down()
{
    for(int i=0; i<8;i++)
	{
		for(int j=0; j<8;j++)
		{
			if(1 == map[i][j]||6==map[i][j])
			{
                x = i;
                y = j;
            }			
		}
	}
    if(3==map[x+1][y])
        return;
    if(0==map[x+1][y])
    {
        map[x + 1][y] = 1;
        if(6==map[x][y])
            map[x][y] = 2;
        if(1==map[x][y])
            map[x][y] = 0;
        step++;
    }
    if(2==map[x+1][y])
    {
        map[x + 1][y] = 6;
        if(6==map[x][y])
            map[x][y] = 2;
        else
            map[x][y] = 0;
        step++;
    }
    if(4==map[x+1][y])
    {
        if(0== map[x+2][y])
        {
            map[x + 2][y] = 4;
            map[x + 1][y] = 1;
            if(6==map[x][y])
                map[x][y] = 2;
            if(1==map[x][y])
                map[x][y] = 0;
            step++;
        }
        if(2==map[x+2][y])
        {
            map[x + 2][y] = 5;
            map[x + 1][y] = 1;
            if(6==map[x][y])
                map[x][y] = 2;
            if(1==map[x][y])
                map[x][y] = 0;
            step++;
        }
        else
            return;
    }
    if(5==map[x+1][y])
    {
        if(0==map[x+2][y])
        {
            map[x + 2][y] = 4;
            map[x + 1][y] = 6;
            if(6==map[x][y])
                map[x][y] = 2;
            else
                map[x][y] = 0;
            step++;
        }
        if(2==map[x+2][y])
        {
            map[x + 2][y] = 5;
            map[x + 1][y] = 6;
            if(6==map[x][y])
                map[x][y] = 2;
            else
                map[x][y] = 0;
            step++;
        }
        else
            return;
    }
}

void left()
{
    for(int i=0; i<8;i++)
	{
		for(int j=0; j<8;j++)
		{
			if(1 == map[i][j]||6==map[i][j])
			{
                x = i;
                y = j;
            }			
		}
	}
    if(3==map[x][y-1])
        return;
    if(0==map[x][y-1])
    {
        map[x][y-1] = 1;
        if(6==map[x][y])
            map[x][y] = 2;
        if(1==map[x][y])
            map[x][y] = 0;
        step++;
    }
    if(2==map[x][y-1])
    {
        map[x][y-1] = 6;
        if(6==map[x][y])
            map[x][y] = 2;
        if(1==map[x][y])
            map[x][y] = 0;
        step++;
    }
    if(4==map[x][y-1])
    {
        if(0== map[x][y-2])
        {
            map[x][y-2] = 4;
            map[x][y-1] = 1;
            if(6==map[x][y])
                map[x][y] = 2;
            else
                map[x][y] = 0;
            step++;
        }
        if(2==map[x][y-2])
        {
            map[x][y-2] = 5;
            map[x][y-1] = 1;
            if(6==map[x][y])
                map[x][y] = 2;
            else
                map[x][y] = 0;
            step++;
        }
        else
            return;
    }
    if(5==map[x][y-1])
    {
        if(0==map[x][y-2])
        {
            map[x][y-2] = 4;
            map[x][y-1] = 6;
            if(6==map[x][y])
                map[x][y] = 2;
            else
                map[x][y] = 0;
            step++;
        }
        if(2==map[x][y-2])
        {
            map[x][y-2] = 5;
            map[x][y-1] = 6;
            if(6==map[x][y])
                map[x][y] = 2;
            else
                map[x][y] = 0;
            step++;
        }
        else
            return;
    }
}

void right()
{
    for(int i=0; i<8;i++)
	{
		for(int j=0; j<8;j++)
		{
			if(1 == map[i][j]||6==map[i][j])
			{
				x =i;
				y =j;
			}			
		}
	}
    if(3==map[x][y+1])
        return;
    if(0==map[x][y+1])
    {
        map[x][y+1] = 1;
        if(6==map[x][y])
            map[x][y] = 2;
        if(1==map[x][y])
            map[x][y] = 0;
        step++;
    }
    if(2==map[x][y+1])
    {
        map[x][y+1] = 6;
        if(6==map[x][y])
            map[x][y] = 2;
        else
            map[x][y] = 0;
        step++;
    }
    if(4==map[x][y+1])
    {
        if(0== map[x][y+2])
        {
            map[x][y+2] = 4;
            map[x][y+1] = 1;
            if(6==map[x][y])
                map[x][y] = 2;
            if(1==map[x][y])
                map[x][y] = 0;
            step++;
        }
        if(2==map[x][y+2])
        {
            map[x][y+2] = 5;
            map[x][y+1] = 1;
            if(6==map[x][y])
                map[x][y] = 2;
            if(1==map[x][y])
                map[x][y] = 0;
            step++;
        }
        else
            return;
    }
    if(5==map[x][y+1])
    {
        if(0==map[x][y+2])
        {
            map[x][y+2] = 4;
            map[x][y+1] = 6;
            if(6==map[x][y])
                map[x][y] = 2;
            else
                map[x][y] = 0;
            step++;
        }
        if(2==map[x][y+2])
        {
            map[x][y+2] = 5;
            map[x][y+1] = 6;
            if(6==map[x][y])
                map[x][y] = 2;
            else
                map[x][y] = 0;
            step++;
        }
        else
            return;
    }
}

int main()
{
    read_map();
    int sum = 0;
    for(int i = 0;i<8;i++)
    {
    	for(int j = 0;j<8;j++)
    	{
    		if(4==map[i][j])
    		{
    			sum++;
			}
		}
	}
    while(1)
    {
        system("cls");
        paint();
        int num = 0;
        for (int i = 0; i < 8;i++)
        {
            for (int j = 0; j < 8;j++)
            {
                if(5==map[i][j])
                    num++;
            }
        }
        if(sum==num)
        {
            printf("��Ϸ��������������%d��", step);
            break;
        }
        int ch1 = 0, ch2 = 0;
        if(ch1 = getch())
        {
            ch2 = getch();
            switch(ch2)
            {
                case 72:
                    up();
                    break;
                case 80:
                    down();
                    break;
                case 75:
                    left();
                    break;
                case 77:
                    right();
                    break;
            }
        }
    }
}
