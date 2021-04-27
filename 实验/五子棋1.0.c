#include "go.h"
//�ж���Ӯ���ж��Ƿ��¹�
int flag = 0;//�ж���Ӯ
int count = 0;//������������ 

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
	for(i=1;i<=30;i++)
	    for(j=0;j<=60;j+=4)
	    {
			gotoxy(j, i);
	    	printf("|");
		}
	for(i=1;i<=31;i+=2)
	    for(j=1;j<=57;j+=4)
	    {
	    	gotoxy(j,i);
	    	printf("---");
		}
}

void chess_menu()//��ӡ�����ԵĲ˵� 
{
	int i,j;
	for(i=1;i<=29;i++)
	{
		gotoxy(67,i);
		printf("||");
	}
	for(i=1;i<=29;i++)
	{
		gotoxy(89,i);
		printf("||");
	}
	gotoxy(69,1);
	printf("--------------------");
	gotoxy(69,29);
	printf("--------------------");
	gotoxy(75,3);
	printf("ģ   ʽ");
	gotoxy(75,20);
	printf("��   ʾ");
}

void board_array()
{
	board = (int**)malloc(L * sizeof(int*));
	for (int i = 0;i < L+2;i++)
		board[i] = (int*)calloc(L, sizeof(int));
	for (int i = 0;i < L+2;i++)
		for (int j = 0;j < L+2;j++)//����߽����⣬��һ���߽磬�߽�=3
			//1-15������
		{
			if (i != 0 && i != L+1 && j != 0 && j != L+1)
				board[i][j] = 0;
			else
				board[i][j] = 3;
		}
}

void man_move()//�����ƶ���� 
{
	loop1:gotoxy(4*man_x,2*man_y+1);
	char key='y';
	while(key!='0')
	{
	    key=_getch();
		switch(key)
		{
    		case 72:
	    		man_y--;
	    		if(man_y<=1)
	    		    man_y=1;
    			break;
    		case 80:
    			man_y++;
	    		if(man_y>=15)
	    		    man_y=15;
    			break;
    		case 75:
	    		man_x--;
	    		if(man_x<=1)
	    		    man_x=1;
	    		break;
    		case 77:
	    		man_x++;
	    		if(man_x>=15)
	    		    man_x=15;
    			break;
    		case 'B':
    		case 'b':
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
		//convert(man_x, man_y, man_x2, man_y2);
		gotoxy(4 * man_x, 2 * man_y + 1);
    }
	if (board[man_y][man_x])
	{
		gotoxy(70, 22);
		BackGround(4, 0);
		printf("�����Ѿ������¹���");
		goto loop1;
	}
	else 
	{
		board[man_y][man_x] = white;
		BackGround(7, 0);
		man_regrex = man_x;
		man_regrey = man_y;
		printf("��");
	}
}

void machine_move()//�����ú��ӣ�����ð���
{
	generator(red, white);
	//convert(AI_x, AI_y, AI_x2, AI_y2);
	gotoxy(4*AI_x, 2*AI_y+1);//����������˳���Ƿ���
	BackGround(4, 0);
	AI_regrex = AI_x;//��¼������һ���ӵ�λ�� ,������� 
	AI_regrey = AI_y;
	printf("��");
}
/*
void convert(int* px,int* py,int* qx,int* qy)
{
	*qx = 4 * (*px);
	*qy = 2 * (*qy) + 1;
}//��ӡ�������̺�����ģ������֮��������Ҫת��
*/

int judge_chess(int x,int y)//�ж�����ط��Ƿ�������
{
	if(board[x][y]==0)
		return 0;
	else
		return 1;
} 
/*
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

*/

void man_machine()//�˻���սģʽ 
{
	loop6:system("cls");
	char key;
	int control;
	gotoxy(2, 3);
	printf("1.�� �� �� ��");
	
	gotoxy(2, 5);
	printf("2.�� �� �� ��");
	
	gotoxy(2, 7);
	printf("���Ϊ���ӣ�����Ϊ����(������Ӧ���ѡ��)");
	key=_getch();
	system("cls");
	if(key=='1')
		control=1;
	else if(key=='2')
	{
		control=-1;
	}
	else 
		goto loop6;
	gotoxy(70,5);
	printf("   �� �� �� ս    ");
	man_y=7;
	man_x=8;
	chess_board();
	board_array();
	chess_menu();
	while(flag==0)
	{
		if(control==1)
		{
			gotoxy(70,22);
			BackGround(6,0);
			printf("   �� �� ִ ��    "); 
			man_move();
			//flag=judge_winner(direct[1],direct[0],1);
		}
		else
		{
			gotoxy(70,22);
			BackGround(6,0);
			printf("   �� �� ִ ��    "); 
			machine_move();
			//flag=judge_winner(direct[1],direct[0],2);
		}
		control=-control;
	}
	gotoxy(8,18);
	if(flag==1)
	{
		BackGround(7,0);
		MessageBox(NULL,TEXT("̫�����ˣ�����Ȼսʤ�˵���!"),TEXT("��������Ϸ"),MB_OK);
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
	gotoxy(man_x2,man_y2);
	BackGround(0,0);
 	printf("  ");
	board[man_y][man_x]=0;
	gotoxy(AI_y2,AI_x2);
	BackGround(0,0);
 	printf("  ");
	board[AI_y][AI_x]=0;
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
	
	gotoxy(13, 20);
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
	char choose, temp;
loop:welcome();
	choose = _getch();
	switch (choose)
	{
	case '1':
		
		break;
	case '2':
		man_machine();
		break;
	case '3':
		temp = Gametips();
		if (temp == 'E' || temp == 'e')
			goto loop;
		break;
	case '4':
	case '5':
	{
		int message = MessageBox(NULL, TEXT("�Ƿ��˳���"),TEXT( "������ʾ"), MB_OKCANCEL);
		if (IDCANCEL == message)
			goto loop;
		if (IDOK == message)
		{
			break;
		}
	}
	}
}
