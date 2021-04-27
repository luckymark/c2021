#include "go.h"
//判断输赢，判断是否下过
int flag = 0;//判断输赢
int count = 0;//计算棋子数量 

void BackGround(unsigned int ForeColor, unsigned int BackGroundColor)  //颜色 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  //获取控制台的句柄
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//改变当前光标的背景和字体颜色
}

void gotoxy(int x, int y)    //光标函数 
{
	HANDLE handle;
	COORD coord;   //获取坐标轴结构体
	coord.X = x;
	coord.Y = y;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);  //获取控制台句柄，值为-11
	SetConsoleCursorPosition(handle, coord);   //移动光标到x，y处
}

void chess_board()//打印棋盘 
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
	board = (int**)malloc(L * sizeof(int*));
	for (int i = 0;i < L+2;i++)
		board[i] = (int*)calloc(L, sizeof(int));
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
		//convert(man_x, man_y, man_x2, man_y2);
		gotoxy(4 * man_x, 2 * man_y + 1);
    }
	if (board[man_y][man_x])
	{
		gotoxy(70, 22);
		BackGround(4, 0);
		printf("这里已经被人下过了");
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

void machine_move()//机器用红子，玩家用白子
{
	generator(red, white);
	//convert(AI_x, AI_y, AI_x2, AI_y2);
	gotoxy(4*AI_x, 2*AI_y+1);//坐标和数组的顺序是反的
	BackGround(4, 0);
	AI_regrex = AI_x;//记录电脑上一落子的位置 ,方便悔棋 
	AI_regrey = AI_y;
	printf("●");
}
/*
void convert(int* px,int* py,int* qx,int* qy)
{
	*qx = 4 * (*px);
	*qy = 2 * (*qy) + 1;
}//打印出的棋盘和数组模拟棋盘之间索引需要转换
*/

int judge_chess(int x,int y)//判断这个地方是否有棋子
{
	if(board[x][y]==0)
		return 0;
	else
		return 1;
} 
/*
int judge_winner(int x,int y,int temp)//判断输赢 
{ 
	int i,j,n1,n2;
	n1=n2=0;
	for(i=x,j=y+4;j<=58;j+=4)//右
	{
		if(status[i][j]==temp)
		    n1++;
		else
		    break;
	}
	for(i=x,j=y;j>=2;j-=4)//左
	{
		if(status[i][j]==temp)
		    n2++;
		else
		    break;
	}
	if(n1+n2>=5)
	    return temp;
	n1=n2=0;
	for(i=x,j=y;i>=1;i-=2)//上 
	{
		if(status[i][j]==temp)
		    n1++;
		else
		    break;
	}
	for(i=x+2,j=y;i<=30;i+=2)//下 
	{
		if(status[i][j]==temp)
		    n2++;
		else
		    break;
	}
	if(n1+n2>=5)
	    return temp;
	n1=n2=0;
	for(i=x-2,j=y+4;i>=1&&j<=58;i-=2,j+=4)//右上 
	{
		if(status[i][j]==temp)
		    n1++; 
		else
		    break;
	}
	for(i=x,j=y;i<=30&&j>=2;i+=2,j-=4)//左下
	{
		if(status[i][j]==temp)
		    n2++; 
		else
		    break;
	}
	if(n1+n2>=5)
	    return temp;
	n1=n2=0;
	for(i=x,j=y;i>=0&&j>=0;i-=2,j-=4)//左上 
	{
		if(status[i][j]==temp)
		    n1++; 
		else
		    break;
	}
	for(i=x+2,j=y+4;i<=30&&j<=58;i+=2,j+=4)//右下
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
	if(key=='1')
		control=1;
	else if(key=='2')
	{
		control=-1;
	}
	else 
		goto loop6;
	gotoxy(70,5);
	printf("   人 机 对 战    ");
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
			printf("   玩 家 执 手    "); 
			man_move();
			//flag=judge_winner(direct[1],direct[0],1);
		}
		else
		{
			gotoxy(70,22);
			BackGround(6,0);
			printf("   电 脑 执 手    "); 
			machine_move();
			//flag=judge_winner(direct[1],direct[0],2);
		}
		control=-control;
	}
	gotoxy(8,18);
	if(flag==1)
	{
		BackGround(7,0);
		MessageBox(NULL,TEXT("太厉害了，您竟然战胜了电脑!"),TEXT("五子棋游戏"),MB_OK);
	}
	if(flag==2)
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
	gotoxy(man_x2,man_y2);
	BackGround(0,0);
 	printf("  ");
	board[man_y][man_x]=0;
	gotoxy(AI_y2,AI_x2);
	BackGround(0,0);
 	printf("  ");
	board[AI_y][AI_x]=0;
} 

void welcome()//游戏菜单 
{
	int k;
	char choose;
	system("cls");
	for(k=2;k<=16;k+=2)//游戏菜单 
	{
		gotoxy(5,k);	
    	printf("|-----------------|");
	}
	gotoxy(5, 3);
	printf("|  五 子 棋 游 戏 |");
	
	gotoxy(5, 5);
	printf("|     菜    单    |");

	gotoxy(5, 7);
	printf("|  1.人 人 对 战  |");
	
	gotoxy(5, 9);
	printf("|  2.人 机 对 战  |");
	
	gotoxy(5, 11);	
	printf("|  3.游 戏 帮 助  |");
	
	gotoxy(5, 13);	
	printf("|  4.更 新 日 志  |");
	
	gotoxy(5, 15);
	printf("|  5.退 出 游 戏  |");
	
	gotoxy(5, 18);
	printf("温馨提示:输入菜单对应序号进行操作");
	
	gotoxy(5, 20);
	printf("祝您游戏愉快！");
	
	gotoxy(13, 20);
}

char Gametips()//游戏帮助 
{
	char choose;
	int key;
	
	system("cls");
	
	gotoxy(2, 3);
	printf("游戏操作："); 
		
	gotoxy(4, 5);
	printf("① 红色棋子WASD移动光标选择下棋位置,按空格键确认,按Q悔棋"); 
		
	gotoxy(4, 7);
	printf("② 白色棋子↑↓←→移动光标选择下棋位置,按0确认,按B悔棋");
		
	gotoxy(2, 19);
	printf("（按E键返回，按其它任意键退出）");
	
	return _getch();
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
