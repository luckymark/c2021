/*�������ֺ�ϵͳ�����ص�
��������ɾ�
�����ϵ���������*/
/*
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#define N 65
#define size 60
#define L 3

int status[N][N]={{0},{0}};//��¼�������,0�ޣ�1����/��ң�2Ϊ����/���� 
int flag=0;//�ж���Ӯ 
int direct[2];//����
int Value1[N][N]={{0},{0}};//����Ȩֵ 
int Value2[N][N]={{0},{0}};//����Ȩֵ
int regrex,regrey,regrex1,regrey1; 
int count=0;//������������ 

void chess_board();//��ӡ���� 
void red_movexy();//�������ƶ����
void white_movexy();//�����ƶ���� 
void red_chess(int x,int y);//����
void white_chess(int x,int y);//����
void man_man();
void man_machine();//�˻���ս
int judge_chess(int x,int y);//�ж����λ���Ƿ��¹� 
int judge_winner(int x,int y,int temp);//�ж���Ӯ 
void machine_attack();//���Խ���Ȩֵ 
void machine_defend();//���Է���Ȩֵ 
void find_position();//Ѱ�����Ȩֵ
void Regret();//���庯�� 

void BackGround(unsigned int ForeColor, unsigned int BackGroundColor)  //��ɫ 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  //��ȡ����̨�ľ��
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//�ı䵱ǰ���ı�����������ɫ
}

void gotoxy(int x, int y)    //��꺯�� 
{
	HANDLE handle;
	COORD coord;   //��ȡ������ṹ��
	coord.X = x;
	coord.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);  //��ȡ����̨�����ֵΪ-11
	SetConsoleCursorPosition(handle, coord);   //�ƶ���굽x��y��
}

void chess_board()//��ӡ���� 
{
	int i,j;
	BackGround(1, 3);
	for (i = 0;i <= size / L;i++)
	    for(j=0;j<=size;j+=L)
	    {
	    	gotoxy(j,i);
	    	printf("|");
		}
	for(i=0;i<= size / L;i++)
	    for(j=1;j<=size;j+=L)
	    {
	    	gotoxy(j,i);
	    	printf("--");
		}
}

void chess_menu()//��ӡ�����ԵĲ˵� 
{
	int i,j;
	for(i=1;i<=size/L;i++)
	{
		gotoxy(67,i);
		printf("||");
	}
	for(i=1;i<= size / L;i++)
	{
		gotoxy(67,i);
		printf("||");
	}
	gotoxy(69,1);
	printf("--------------------");
	gotoxy(69, size / L);
	printf("--------------------");
	gotoxy(75,3);
	printf("ģ   ʽ");
	gotoxy(75,15);
	printf("��   ʾ");
}

void red_movexy()//�����ƶ���� 
{
	loop2:gotoxy(direct[0],direct[1]);
	char key='y';
	int temp;
	while(key!=' ')
	{
	    key=_getch();
		switch(key)
		{
			case 'W':
    		case 'w':
	    		direct[1]-=1;
	    		if(direct[1]<=1)
	    		    direct[1]=1;
    			break;
    		case 's':
    		case 'S':
    			direct[1]+=1;
	    		if(direct[1]>=size/L)
	    		    direct[1]= size / L;
    			break;
    		case 'a':
    		case 'A':
	    		direct[0]-=L;
	    		if(direct[0]<=2)
	    		    direct[0]=2;
	    		break;
    		case 'd':
    		case 'D':
	    		direct[0]+=L;
	    		if(direct[0]>=size)
	    		    direct[0]=size;
    			break;
    		case 'q':
    		case 'Q':
    		{ 
				int message=MessageBox(NULL,TEXT("�Ƿ�ȷ�����壿"),TEXT("������ʾ"),MB_OKCANCEL);
		        if(IDCANCEL==message)
					break;
			    if(IDOK==message)
			    {
			    	Regret();
    				break;
    			}
    		}
    	}
    	gotoxy(direct[0],direct[1]);
    }
        temp=judge_chess(direct[1],direct[0]);
	    if(temp==1)
	    {
	    	gotoxy(70,22);
	    		BackGround(4, 0);
				printf("�����Ѿ������¹���");
			goto loop2;
		}
}

void white_movexy()//�����ƶ���� 
{
	loop1:gotoxy(direct[0],direct[1]);
	char key='y';
	int temp;
	while(key!='0')
	{
	    key=_getch();
		switch(key)
		{
    		case 72:
	    		direct[1]-=1;
	    		if(direct[1]<=1)
	    		    direct[1]=1;
    			break;
    		case 80:
    			direct[1]+=1;
	    		if(direct[1]>= size / L)
	    		    direct[1]= size / L;
    			break;
    		case 75:
	    		direct[0]-=L;
	    		if(direct[0]<=2)
	    		    direct[0]=2;
	    		break;
    		case 77:
	    		direct[0]+=L;
	    		if(direct[0]>= size)
	    		    direct[0]= size;
    			break;
    		case 'B':
    		case 'b':
    		{ 
				int message=MessageBox(NULL, TEXT("�Ƿ�ȷ�����壿"), TEXT("������ʾ"),MB_OKCANCEL);
		        if(IDCANCEL==message)break;
			    if(IDOK==message)Regret();break;
    		}
    	}
    	gotoxy(direct[0],direct[1]);
    }
        temp=judge_chess(direct[1],direct[0]);
	    if(temp==1)
	    {
	    	gotoxy(70,22);
	    		BackGround(4, 0);
				printf("�����Ѿ������¹���");
			goto loop1;
		}
}

void red_chess(int x,int y)//��ӡ���� 
{
	BackGround(4,3);
	regrex=x;//��¼��һ���ӵ�λ�� ,������� 
	regrey=y;
	count++;
	printf("��");
	status[x][y]=1;
}

void white_chess(int x,int y)//��ӡ����
{
	BackGround(7,3);
	regrex1=x;
	regrey1=y;
	printf("��");
	count++;
	status[x][y]=2;
}

void machine_chess(int x,int y)//��������
{
	BackGround(7,3);
	status[x][y]=2;
	regrex1=x;
	regrey1=y;
	count++;
	gotoxy(y,x);
	printf("��");
}

int judge_chess(int x,int y)//�ж�����ط��Ƿ�������
{
	if(status[x][y]==0)
		return 0;
	else
		return 1;
} 

int judge_winner(int x,int y,int temp)//�ж���Ӯ 
{ 
	int i,j,n1,n2;
	n1=n2=0;
	for(i=x,j=y+4;j<=58;j+=4)//��
	{
		if(status[i][j]==temp)
		    n1++;
		else
		    break;
	}
	for(i=x,j=y;j>=2;j-=4)//��
	{
		if(status[i][j]==temp)
		    n2++;
		else
		    break;
	}
	if(n1+n2>=5)
	    return temp;
	n1=n2=0;
	for(i=x,j=y;i>=1;i-=2)//�� 
	{
		if(status[i][j]==temp)
		    n1++;
		else
		    break;
	}
	for(i=x+2,j=y;i<=30;i+=2)//�� 
	{
		if(status[i][j]==temp)
		    n2++;
		else
		    break;
	}
	if(n1+n2>=5)
	    return temp;
	n1=n2=0;
	for(i=x-2,j=y+4;i>=1&&j<=58;i-=2,j+=4)//���� 
	{
		if(status[i][j]==temp)
		    n1++; 
		else
		    break;
	}
	for(i=x,j=y;i<=30&&j>=2;i+=2,j-=4)//����
	{
		if(status[i][j]==temp)
		    n2++; 
		else
		    break;
	}
	if(n1+n2>=5)
	    return temp;
	n1=n2=0;
	for(i=x,j=y;i>=0&&j>=0;i-=2,j-=4)//���� 
	{
		if(status[i][j]==temp)
		    n1++; 
		else
		    break;
	}
	for(i=x+2,j=y+4;i<=30&&j<=58;i+=2,j+=4)//����
	{
		if(status[i][j]==temp)
		    n2++; 
		else
		    break;
	}
	if(n1+n2>=5)
	    return temp;
	return 0;
}

void machine_attack()//���Խ���Ȩֵ 
{
	int i1,j1;
	int k1,k2,k;
	for(int i=1;i<=30;i+=2)
	{
		for(int j=2;j<=58;j+=4)
		{
			if(status[i][j])
				Value1[i][j]=0;
			if(status[i][j]==0)
			{
				k1=k2=0;
				for(i1=i,j1=j-4;j1>=2;j1-=4)//������Ѱ�ҵ���������
				{
					if(status[i1][j1]==2)
						k1++;
					else
						break;
				}
				for(i1=i,j1=j+4;j1<=58;j1+=4)//������Ѱ�ҵ���������
				{
					if(status[i1][j1]==2)
						k2++;
					else
						break;
				}
				k=k1>k2? k1:k2;
				k1=k2=0;
				for(i1=i-2,j1=j;i1>=1;i1-=2)//������Ѱ�ҵ���������
				{
					if(status[i1][j1]==2)
						k1++;
					else
						break;
				}
				for(i1=i+2,j1=j;i1<=30;i1+=2)//������Ѱ�ҵ���������
				{
					if(status[i1][j1]==2)
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1? k:k1;
				k1=k2=0;
				for(i1=i-2,j1=j-4;i1>=0&&j1>=0;i1-=2,j1-=4)//��������Ѱ�ҵ���������
				{
					if(status[i1][j1]==2)
						k1++;
					else
						break;
				}
				for(i1=i+2,j1=j+4;i1<=30&&j1<=58;i1+=2,j1+=4)//��������Ѱ�ҵ���������
				{
					if(status[i1][j1]==2 )
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1?k:k1;
				k1=k2=0;
				for(i1=i+2,j1=j-4;i1<=30&&j1>=2;i1+=2,j1-=4)//��������Ѱ�ҵ���������
				{
					if(status[i1][j1]==2)
						k1++;
					else
						break;
				}
				for(i1=i-2,j1=j+4;i1>=1&&j1<=58;i1-=2,j1+=4)//��������Ѱ�ҵ���������
				{
					if(status[i1][j1]==2)
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1?k:k1;
				switch(k) 
				{ 
					case 3:
						Value1[i][j]=15;break;                       
					case 4:
						Value1[i][j]=25;break; 
					default:
						Value1[i][j]=3+2*k;break;
				}
			}
		}
	}
}

void machine_defend()//����Ȩֵ
{
	int i1, j1;
	int k1,k2,k;
	for(int i=1;i<=30;i+=2)
	{
		for(int j=2;j<=58;j+=4)
		{
			if(status[i][j])
				Value2[i][j]=0;
			if(status[i][j]==0)
			{
				k1=k2=0;
				for(i1=i,j1=j-4;j1>=2;j1-=4)//������Ѱ�����������
				{
					if(status[i1][j1]==1)
						k1++;
					else
						break;
				}
				for(i1=i,j1=j+4;j1<=58;j1+=4)//������Ѱ�����������
				{
					if(status[i1][j1]==1)
						k2++; 
					else
						break;
				}
				k=k1>k2? k1:k2;
				k1=k2=0;
				for(i1=i-2,j1=j;i1>=1;i1-=2)//������Ѱ�����������
				{
					if(status[i1][j1]==1)
						k1++;
					else
						break;
				}
				for(i1=i+2,j1=j;i1<=30;i1+=2)//������Ѱ�����������
				{
					if(status[i1][j1]==1)
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1?k:k1;
				k1=k2=0;
				for(i1=i-2,j1=j-4;i1>=1&&j1>=2;i1-=2,j1-=4)//��������Ѱ�����������
				{
					if(status[i1][j1]==1)
						k1++;
					else
						break;
				}
				for(i1=i+2,j1=j+4;i1<=30&&j1<=58;i1+=2,j1+=4)//��������Ѱ�����������
				{
					if(status[i1][j1]==1)
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1?k:k1;
				k1=k2=0;
				for(i1=i+2,j1=j-4;i1<=30&&j1>=2;i1+=2,j1-=4)//��������Ѱ�����������
				{
					if(status[i1][j1]==1)
						k1++;
					else
						break;
				}
				for(i1=i-2,j1=j+4;i1>=1&&j1<=58;i1-=2,j1+=4)//��������Ѱ�����������
				{
					if(status[i1][j1]==1)
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1?k:k1;
			    switch(k)
				{
					case 3:
						Value2[i][j]=10;break;                 
					case 4:                                       
						Value2[i][j]=20;break;
					default:
						Value2[i][j]=2+k*2;
				}
			}
		}
	}
}

void find_position()//�ҵ����м�ֵ��λ��
{
	int k1=0, k2=0;
	int i, j, max=0;
	for( i=1;i<=30;i+=2)
		for( j=2;j<=58;j+=4)
		{
			if(max<=Value1[i][j])
			{
				max=Value1[i][j];
				k1=i;
				k2=j;
			}
		}
	for( i=1;i<=30;i+=2)
		for( j=2;j<=58;j+=4)
		{
			if(max<=Value2[i][j])
			{
				max=Value2[i][j];
				k1=i;
				k2=j;
			}
		}
	direct[1]=k1;  //���ҵ���λ�ô������
	direct[0]=k2;
}

void man_man()//���˶�սģʽ
{
	loop5:system("cls");
	char key;
	int control;
	gotoxy(2, 3);
	printf("1.�� �� �� ��");
	
	gotoxy(2, 5);
	printf("2.�� �� �� ��");
	
	gotoxy(2, 7);
	printf("(������Ӧ���ѡ��)");
	key=_getch();
	system("cls");
	if(key=='1')
		control=1;
	else if(key=='2')
		control=-1;
	else
		goto loop5;
	gotoxy(70,5);
	printf("   �� �� �� ս    "); 
	direct[1]=15;
	direct[0]=30;
	chess_menu();
	chess_board();
	while(flag==0)
	{
		if(control==1)
		{
			gotoxy(70,22);
			BackGround(6,0);
			printf("   �� �� ִ ��    "); 
			red_movexy();
			red_chess(direct[1],direct[0]);
			flag=judge_winner(direct[1],direct[0],1);
		}
		else
		{
			gotoxy(70,22);
			BackGround(6,0);
			printf("   �� �� ִ ��    "); 
			white_movexy();
			white_chess(direct[1],direct[0]);
			flag=judge_winner(direct[1],direct[0],2);
		}
		control=-control;
	}
	if(flag==1)
	{
		BackGround(7,0);
		MessageBox(NULL,TEXT("��Ϸ����������ʤ��"),TEXT("��������Ϸ"),MB_OK);
	}
	if(flag==2)
	{
		MessageBox(NULL,TEXT("��Ϸ����������ʤ��"),TEXT("��������Ϸ"),MB_OK);
	}
	if(count>=225)
	{
		MessageBox(NULL,TEXT("��Ϸ������ƽ��"),TEXT("��������Ϸ"),MB_OK);
	}
}

void man_machine()//�˻���սģʽ 
{
	loop6:system("cls");
	char key;
	int control;
	gotoxy(2, 3);
	printf("1.�� �� �� �֣����Ϊ���ӣ�");
	
	gotoxy(2, 5);
	printf("2.�� �� �� �֣�����Ϊ���ӣ�");
	
	gotoxy(2, 7);
	printf("(������Ӧ���ѡ��)");
	key=_getch();
	system("cls");
	if(key=='1')
		control=1;
	else if(key=='2')
	{
		control=1;
		machine_chess(13,26);
	}
	else 
		goto loop6;
	gotoxy(70,5);
	printf("   �� �� �� ս    ");
	direct[1]=15;
	direct[0]=30;
	chess_menu();
	chess_board();
	while(flag==0)
	{
		if(control==1)
		{
			gotoxy(70,size/L-5);
			BackGround(6,0);
			printf("   �� �� ִ ��    "); 
			red_movexy();
			red_chess(direct[1],direct[0]);
			flag=judge_winner(direct[1],direct[0],1);
		}
		else
		{
			gotoxy(70,size/L-5);
			BackGround(6,0);
			printf("   �� �� ִ ��    "); 
			machine_defend();
			machine_attack();
			find_position();
			machine_chess(direct[1],direct[0]);
			flag=judge_winner(direct[1],direct[0],2);
		}
		control=-control;
	}
	gotoxy(8,18);
	if(flag==1)
	{
		BackGround(7,0);
		MessageBox(NULL,TEXT("̫�����ˣ���սʤ�˵���!"),TEXT("��������Ϸ"),MB_OK);
	}
	if(flag==2)
	{
		MessageBox(NULL,TEXT("��Ϸ������������˵���"),TEXT("��������Ϸ"),MB_OK);
	}
	if(count>=225)
	{
		MessageBox(NULL,TEXT("ƽ��"),TEXT("��������Ϸ"),MB_OK);
	}
}

void Regret()//���庯�� 
{
	gotoxy(regrey,regrex);
	BackGround(0,0);
 	printf("  ");
	status[regrex][regrey]=0;
	gotoxy(regrey1,regrex1);
	BackGround(0,0);
 	printf("  ");
	status[regrex1][regrey1]=0;
	count-=2;
} 

void welcome()//��Ϸ�˵� 
{
	int k;
	char choose;
	system("cls");
	for(k=2;k<=16;k+=2)//��Ϸ�˵� 
	{
		gotoxy(5,k);	
    	printf("|-----------------|");
	}
	gotoxy(5, 3);
	printf("|  �� �� �� �� Ϸ |");
	
	gotoxy(5, 5);
	printf("|     ��    ��    |");

	gotoxy(5, 7);
	printf("|  1.�� �� �� ս  |");
	
	gotoxy(5, 9);
	printf("|  2.�� �� �� ս  |");
	
	gotoxy(5, 11);	
	printf("|  3.�� Ϸ �� ��  |");
	
	gotoxy(5, 13);	
	printf("|  4.�� �� �� ־  |");
	
	gotoxy(5, 15);
	printf("|  5.�� �� �� Ϸ  |");
	
	gotoxy(5, 18);
	printf("��ܰ��ʾ:����˵���Ӧ��Ž��в���");
	
	gotoxy(5, 20);
	printf("ף����Ϸ��죡");
	
	gotoxy(20, 20);
}

char Gametips()//��Ϸ���� 
{
	char choose;
	int key;
	
	system("cls");
	
	gotoxy(2, 3);
	printf("��Ϸ������"); 
		
	gotoxy(4, 5);
	printf("�� ��ɫ����WASD�ƶ����ѡ������λ��,���ո��ȷ��,��Q����"); 
		
	gotoxy(4, 7);
	printf("�� ��ɫ���ӡ��������ƶ����ѡ������λ��,��0ȷ��,��B����");
		
	gotoxy(2, 19);
	printf("����E�����أ�������������˳���");
	
	return _getch();
}


int main()
{
	system("title ������");
	system("mode con cols=92 lines=33");
	system("color F0");
	char choose,temp;
	loop:welcome();
	choose=_getch();
	switch(choose)
	{
		case '1':
			man_man();
			break;
		case '2':
			man_machine();
			break;
		case '3':
			temp=Gametips();
			if(temp=='E'||temp=='e')
				goto loop;
			break;
		case '5':
		{
			int message = MessageBox(NULL, "�Ƿ��˳���", "������ʾ", MB_OKCANCEL);
			if (IDCANCEL == message)
				goto loop;
			if (IDOK == message)break;
		}
		
	}
}

*/
