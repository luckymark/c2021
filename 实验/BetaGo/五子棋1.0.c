#include "go.h"
#define PTIF 2147483647//正无穷,Beta
#define NGIF -2147483648//负无穷,Alpha

int board[L+2][L+2];

int AI_regrex, AI_regrey, man_regrex, man_regrey;

int AI_x, AI_y;
int man_x, man_y;//man_y=i,man_x=j
//board[i][j]与position之间的关系gotoxy(4 * (man_x-1), 2 * (man_y-1) + 1)
int dir[][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };//八向的常量数组

int flag = 0;//判断输赢
int count = 0;//计算棋子数量 

void chess_menu()//打印棋盘旁的菜单 
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
	printf("模   式");
	gotoxy(75,20);
	printf("提   示");
}

void board_array()
{
	for (int i = 0;i < L+2;i++)
		for (int j = 0;j < L+2;j++)//解决边界问题，加一个边界，边界=3
			//1-15是棋盘
		{
			if (i != 0 && i != L+1 && j != 0 && j != L+1)
				board[i][j] = 0;
			else
				board[i][j] = 3;
		}
}

void man_move()//白棋移动光标 
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
				int message=MessageBox(NULL,TEXT("是否确定悔棋？"),TEXT("友情提示"),MB_OKCANCEL);
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
		printf("这里已经被下过了");
		goto loop1;
	}
	else 
	{
		board[man_y][man_x] = white;
		BackGround(7, 0);
		man_regrex = man_x;
		man_regrey = man_y;
		printf("●");
	}
}



void machine_move()//打印AI的棋子的函数，机器用红子，玩家用白子
{
	minMax_AB(4, red, NGIF, PTIF,board);
	board[AI_y][AI_x] = red;
	gotoxy(4*(AI_x-1), 2*(AI_y-1)+1);//坐标和数组的顺序是反的
	BackGround(4, 0);
	AI_regrex = AI_x;//记录电脑上一落子的位置 ,方便悔棋 
	AI_regrey = AI_y;
	printf("●");
}

int judge_winner(int x, int y, int me)//判断输赢，要向两个方向搜索
{
	int n1 = 0, n2 = 0;
	int flag = 0;
	for (int i = 0;i < 4;i++)//i表示八个方向
	{
		for (int j = 0;j <= 5;j++)//j表示沿这个方向走了几步
		{
			int dx = x + j * dir[i][0];
			int dy = y + j * dir[i][1];
			if (board[dy][dx] == me)//AI_x,AI_y都是坐标上的x，y，表示数组要反过来
				n1++;
			else 
				break;
		}
		for (int j = 0;j <= 5;j++)//j表示沿这个方向走了几步
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

void man_machine()//人机对战模式 
{
	loop6:system("cls");
	char key;
	int control;
	gotoxy(2, 3);
	printf("1.玩 家 先 手");
	
	gotoxy(2, 5);
	printf("2.电 脑 先 手");
	
	gotoxy(2, 7);
	printf("玩家为白子，电脑为红子(输入相应序号选择)");
	key=_getch();
	system("cls");
	control = 1;
	if(key!='1'&& key!='2')
	{
		printf("请重新输入");
		goto loop6;
	}	
	gotoxy(70,5);
	printf("   人 机 对 战    ");
	man_y=7;
	man_x=8;
	chess_board();
	board_array();
	chess_menu();
	if (key == '2')
	{
		AI_x = 7;
		AI_y = 8;
		gotoxy(4 * (AI_x - 1), 2 * (AI_y - 1) + 1);//机器第一次下在中间位置
		BackGround(4, 0);
		AI_regrex = AI_x;//记录电脑上一落子的位置 ,方便悔棋 
		AI_regrey = AI_y;
		board[AI_y][AI_x] = 1;
		printf("●");
	}
	while(flag==0)
	{
		if(control==1)
		{
			gotoxy(70,22);
			BackGround(6,0);
			printf("   玩 家 执 手    "); 
			man_move();
			flag=judge_winner(man_x,man_y,white);
		}
		else
		{
			gotoxy(70,22);
			BackGround(6,0);
			printf("   电 脑 执 手    "); 
			machine_move();
			flag=judge_winner(AI_x,AI_y,red);
		}
		control=-control;
	}
	gotoxy(8,18);
	if(flag==white)
	{
		BackGround(7,0);
		MessageBox(NULL,TEXT("太厉害了，您战胜了电脑!"),TEXT("五子棋游戏"),MB_OK);
	}
	if(flag==red)
	{
		MessageBox(NULL,TEXT("游戏结束，您输给了电脑"),TEXT("五子棋游戏"),MB_OK);
	}
	if(count>=225)
	{
		MessageBox(NULL,TEXT("平局"),TEXT("五子棋游戏"),MB_OK);
	}
}

void Regret()//悔棋函数 
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
	system("title 五子棋");
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
		int message = MessageBox(NULL, TEXT("是否退出？"),TEXT( "友情提示"), MB_OKCANCEL);
		if (IDCANCEL == message)
			goto loop;
		if (IDOK == message)
		{
			break;
		}
	}
	}
}
