#include "Chess.h"
#include "max-min.h"

int board[L+2][L+2];//��ʾ���̵Ķ�ά����

int AI_regretx, AI_regrety, man_regretx, man_regrety;//��¼�˺�AI��һ�������λ�ã����ڻ���

int AI_x=0, AI_y=0;//��¼AI���������λ��
int man_x=0, man_y=0;//man_y=i,man_x=j
int man2_x=0, man2_y=0;
//board[i][j]��position֮��Ĺ�ϵgotoxy(4 * man_x, 2 * (man_y-1) + 1)
int dir[][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };//��ʾ�˸�����ĳ�������

int flag = 0;//�ж���Ӯ
int rank = 2;

//��ʼ����ʾ���̵�����
void board_init()
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
//ʵ���˿��ƵĹ���ƶ�������
void man_move()//��������ƶ���꣬Ϊ�������˶�սʱʵ�ֿ�������λ��Ҳٿأ�������ָ�봫��λ������ʵ�ֶ�̬
{
loop1:location(man_x, man_y,white);
	gotoxy(4 * (man_x) , 2 * (man_y - 1) + 1);
	char key='y';
	while(key!=' ')
	{
	    key=_getch();
		if (AI_x != 0 && AI_y != 0)//������֣���һ�β������
			clearlocation(AI_x, AI_y);
		clearlocation(man_x, man_y);
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
		location(man_x, man_y,white);
		gotoxy(4 * (man_x), 2 * (man_y-1) + 1);
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
		man_regretx = man_x;
		man_regrety = man_y;
		printf("��");
	}
}
//ʵ��AI���ƵĹ���ƶ�������
void machine_move()//��ӡAI�����ӵĺ����������ú��ӣ�����ð���
{
	//IDDFS();
	minMax_AB(rank, red, NGIF, PTIF, board);
	clearlocation(man_x, man_y);
	board[AI_y][AI_x] = red;
	location(AI_x, AI_y, red);
	gotoxy(4*AI_x, 2*(AI_y-1)+1);//����������˳���Ƿ���
	AI_regretx = AI_x;//��¼������һ���ӵ�λ�� ,������� 
	AI_regrety = AI_y;
	printf("��");
}
//ÿ��һ����֮���ж���Ӯ�ĺ���
int judge_winner(int x, int y, int me, int now_board[L+2][L+2])//�ж���Ӯ��Ҫ��������������
{
	int n1 = 0, n2 = 0;
	int flag = 0;
	for (int i = 0;i < 4;i++)//i��ʾ�˸�����
	{
		for (int j = 0;j <= 5;j++)//j��ʾ������������˼���
		{
			int dx = x + j * dir[i][0];
			int dy = y + j * dir[i][1];
			if (now_board[dy][dx] == me)//AI_x,AI_y���������ϵ�x��y����ʾ����Ҫ������
				n1++;
			else 
				break;
		}
		for (int j = 0;j <= 5;j++)//j��ʾ������������˼���
		{
			int dx = x + j * dir[7 - i][0];
			int dy = y + j * dir[7 - i][1];
			if (now_board[dy][dx] == me)
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
//ʵ���˻���ս���ܵĺ���
void man_machine()//�˻���սģʽ 
{
	system("color F2");
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
	gotoxy(2, 5);
	printf("�������Ѷȵȼ�(����ż��,��:2,4,6,�Ѷȵȼ�Խ��,��������Խ��):");
	rank = _getch() - '0';
	system("cls");
	control = 1;
	if(key!='1'&& key!='2')
	{
		printf("����������");
		goto loop6;
	}
	system("color 0F");
	gotoxy(70,5);
	printf("   �� �� �� ս    ");
	man_y=7;
	man_x=8;
	chess_board();
	board_init();
	chess_menu();
	if (key == '2')
	{
		AI_x = 7;
		AI_y = 8;
		AI_regretx = AI_x;//��¼������һ���ӵ�λ�� ,������� 
		AI_regrety = AI_y;
		board[AI_y][AI_x] = red;
		location(AI_x, AI_y,red);
		gotoxy(4 * AI_x, 2 * (AI_y - 1) + 1);//������һ�������м�λ	
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
			flag=judge_winner(man_x,man_y,white,board);
		}
		else
		{
			gotoxy(70,22);
			BackGround(6,0);
			printf("   �� �� ִ ��    "); 
			machine_move();
			flag=judge_winner(AI_x,AI_y,red,board);
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
}
//ʵ�������˶�ս���ܵĺ���
void man_man() 
{
	char key;
	int control=1;
	system("cls");
	gotoxy(70, 5);
	printf("   �� �� �� ս    ");
	man_y = 7;
	man_x = 8;
	man2_y = 7;
	man2_x = 8;
	chess_board();
	board_init();
	chess_menu();
	while (flag == 0)
	{
		if (control == 1)
		{
			gotoxy(70, 22);
			BackGround(6, 0);
			printf("   �� ��1 ִ ��    ");
			man_move();
			flag = judge_winner(man_x, man_y, white, board);
		}
		else
		{
			gotoxy(70, 22);
			BackGround(6, 0);
			printf("   �� ��2 ִ ��    ");
			man_move();
			flag = judge_winner(man2_x, man2_y, red, board);
		}
		control = -control;
	}
	if (flag == 1)
	{
		BackGround(7, 0);
		MessageBox(NULL, TEXT("��Ϸ����������ʤ��"), "��������Ϸ", MB_OK);
	}
	if (flag == 2)
	{
		MessageBox(NULL, TEXT("��Ϸ����������ʤ��"), "��������Ϸ", MB_OK);
	}
}
//ʵ�ֻ��幦�ܵĺ���
void Regret()//���庯�� 
{
	gotoxy(4 * man_regretx , 2 * (man_regrety - 1) + 1);
	BackGround(0,0);
 	printf("  ");
	board[man_regrety][man_regretx]=0;
	gotoxy(4 * AI_regretx , 2 * (AI_regrety - 1) + 1);
	BackGround(0,0);
 	printf("  ");
	board[AI_regrety][AI_regretx]=0;
} 

int main()
{
	system("title ������");
	system("mode con cols=92 lines=33");
	system("color F2");
	char choose, temp;
loop:welcome();
	choose = _getch();
	switch (choose)
	{
	case '1':
		man_machine();
		break;
	case '2':
		man_man();
		break;
	case '3':
		temp = Gametips();
		if (temp == 'E' || temp == 'e')
			goto loop;
		break;
	case '4':
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
