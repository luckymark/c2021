#include "go.h"
#define PTIF 2147483647//������,Beta
#define NGIF -2147483648//������,Alpha

int board[L+2][L+2];

int AI_regrex, AI_regrey, man_regrex, man_regrey;

int AI_x, AI_y;
int man_x, man_y;//man_y=i,man_x=j
//board[i][j]��position֮��Ĺ�ϵgotoxy(4 * (man_x-1), 2 * (man_y-1) + 1)
int dir[][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };//����ĳ�������

int flag = 0;//�ж���Ӯ
int count = 0;//������������ 

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
	loop1:gotoxy(4 * (man_x - 1), 2 * (man_y - 1) + 1);
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
		gotoxy(4 * (man_x-1), 2 * (man_y-1) + 1);
    }
	if (board[man_y][man_x])
	{
		gotoxy(70, 22);
		BackGround(4, 0);
		printf("�����Ѿ����¹���");
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



void machine_move()//��ӡAI�����ӵĺ����������ú��ӣ�����ð���
{
	minMax_AB(4, red, NGIF, PTIF,board);
	board[AI_y][AI_x] = red;
	gotoxy(4*(AI_x-1), 2*(AI_y-1)+1);//����������˳���Ƿ���
	BackGround(4, 0);
	AI_regrex = AI_x;//��¼������һ���ӵ�λ�� ,������� 
	AI_regrey = AI_y;
	printf("��");
}

int judge_winner(int x, int y, int me)//�ж���Ӯ��Ҫ��������������
{
	int n1 = 0, n2 = 0;
	int flag = 0;
	for (int i = 0;i < 4;i++)//i��ʾ�˸�����
	{
		for (int j = 0;j <= 5;j++)//j��ʾ������������˼���
		{
			int dx = x + j * dir[i][0];
			int dy = y + j * dir[i][1];
			if (board[dy][dx] == me)//AI_x,AI_y���������ϵ�x��y����ʾ����Ҫ������
				n1++;
			else 
				break;
		}
		for (int j = 0;j <= 5;j++)//j��ʾ������������˼���
		{
			int dx = x + j * dir[7 - i][0];
			int dy = y + j * dir[7 - i][1];
			if (board[dy][dx] == me)
				n2++;
			else 
				break;
		}
		if (n1 + n2 >= 6)
		{
			flag = me;
			return flag;
		}
		n1 = 0;
		n2 = 0;
	}
	return flag;
}

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
	control = 1;
	if(key!='1'&& key!='2')
	{
		printf("����������");
		goto loop6;
	}	
	gotoxy(70,5);
	printf("   �� �� �� ս    ");
	man_y=7;
	man_x=8;
	chess_board();
	board_array();
	chess_menu();
	if (key == '2')
	{
		AI_x = 7;
		AI_y = 8;
		gotoxy(4 * (AI_x - 1), 2 * (AI_y - 1) + 1);//������һ�������м�λ��
		BackGround(4, 0);
		AI_regrex = AI_x;//��¼������һ���ӵ�λ�� ,������� 
		AI_regrey = AI_y;
		board[AI_y][AI_x] = 1;
		printf("��");
	}
	while(flag==0)
	{
		if(control==1)
		{
			gotoxy(70,22);
			BackGround(6,0);
			printf("   �� �� ִ ��    "); 
			man_move();
			flag=judge_winner(man_x,man_y,white);
		}
		else
		{
			gotoxy(70,22);
			BackGround(6,0);
			printf("   �� �� ִ ��    "); 
			machine_move();
			flag=judge_winner(AI_x,AI_y,red);
		}
		control=-control;
	}
	gotoxy(8,18);
	if(flag==white)
	{
		BackGround(7,0);
		MessageBox(NULL,TEXT("̫�����ˣ���սʤ�˵���!"),TEXT("��������Ϸ"),MB_OK);
	}
	if(flag==red)
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
	gotoxy(4 * (man_x - 1), 2 * (man_y - 1) + 1);
	BackGround(0,0);
 	printf("  ");
	board[man_y][man_x]=0;
	gotoxy(4 * (AI_x - 1), 2 * (AI_y - 1) + 1);
	BackGround(0,0);
 	printf("  ");
	board[AI_y][AI_x]=0;
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
		man_machine();
		break;
	case '2':
		temp = Gametips();
		if (temp == 'E' || temp == 'e')
			goto loop;
		break;
	case '3':
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
