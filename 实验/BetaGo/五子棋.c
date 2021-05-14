/*界面文字和系统文字重叠
悔棋擦不干净
弹窗上的字是乱码*/
/*
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#define N 65
#define size 60
#define L 3

int status[N][N]={{0},{0}};//记录棋盘情况,0无，1红棋/玩家，2为白棋/电脑 
int flag=0;//判断输赢 
int direct[2];//方向
int Value1[N][N]={{0},{0}};//计算权值 
int Value2[N][N]={{0},{0}};//计算权值
int regrex,regrey,regrex1,regrey1; 
int count=0;//计算棋子数量 

void chess_board();//打印棋盘 
void red_movexy();//红子棋移动光标
void white_movexy();//白棋移动光标 
void red_chess(int x,int y);//红棋
void white_chess(int x,int y);//白棋
void man_man();
void man_machine();//人机对战
int judge_chess(int x,int y);//判断这个位置是否下过 
int judge_winner(int x,int y,int temp);//判断输赢 
void machine_attack();//电脑进攻权值 
void machine_defend();//电脑防守权值 
void find_position();//寻找最佳权值
void Regret();//悔棋函数 

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

void chess_menu()//打印棋盘旁的菜单 
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
	printf("模   式");
	gotoxy(75,15);
	printf("提   示");
}

void red_movexy()//红棋移动光标 
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
    	gotoxy(direct[0],direct[1]);
    }
        temp=judge_chess(direct[1],direct[0]);
	    if(temp==1)
	    {
	    	gotoxy(70,22);
	    		BackGround(4, 0);
				printf("这里已经被人下过了");
			goto loop2;
		}
}

void white_movexy()//白棋移动光标 
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
				int message=MessageBox(NULL, TEXT("是否确定悔棋？"), TEXT("友情提示"),MB_OKCANCEL);
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
				printf("这里已经被人下过了");
			goto loop1;
		}
}

void red_chess(int x,int y)//打印红棋 
{
	BackGround(4,3);
	regrex=x;//记录上一落子的位置 ,方便悔棋 
	regrey=y;
	count++;
	printf("●");
	status[x][y]=1;
}

void white_chess(int x,int y)//打印白棋
{
	BackGround(7,3);
	regrex1=x;
	regrey1=y;
	printf("●");
	count++;
	status[x][y]=2;
}

void machine_chess(int x,int y)//电脑落子
{
	BackGround(7,3);
	status[x][y]=2;
	regrex1=x;
	regrey1=y;
	count++;
	gotoxy(y,x);
	printf("●");
}

int judge_chess(int x,int y)//判断这个地方是否有棋子
{
	if(status[x][y]==0)
		return 0;
	else
		return 1;
} 

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

void machine_attack()//电脑进攻权值 
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
				for(i1=i,j1=j-4;j1>=2;j1-=4)//往左数寻找电脑棋子数
				{
					if(status[i1][j1]==2)
						k1++;
					else
						break;
				}
				for(i1=i,j1=j+4;j1<=58;j1+=4)//往右数寻找电脑棋子数
				{
					if(status[i1][j1]==2)
						k2++;
					else
						break;
				}
				k=k1>k2? k1:k2;
				k1=k2=0;
				for(i1=i-2,j1=j;i1>=1;i1-=2)//往上数寻找电脑棋子数
				{
					if(status[i1][j1]==2)
						k1++;
					else
						break;
				}
				for(i1=i+2,j1=j;i1<=30;i1+=2)//往下数寻找电脑棋子数
				{
					if(status[i1][j1]==2)
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1? k:k1;
				k1=k2=0;
				for(i1=i-2,j1=j-4;i1>=0&&j1>=0;i1-=2,j1-=4)//往左上数寻找电脑棋子数
				{
					if(status[i1][j1]==2)
						k1++;
					else
						break;
				}
				for(i1=i+2,j1=j+4;i1<=30&&j1<=58;i1+=2,j1+=4)//往右下数寻找电脑棋子数
				{
					if(status[i1][j1]==2 )
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1?k:k1;
				k1=k2=0;
				for(i1=i+2,j1=j-4;i1<=30&&j1>=2;i1+=2,j1-=4)//往左下数寻找电脑棋子数
				{
					if(status[i1][j1]==2)
						k1++;
					else
						break;
				}
				for(i1=i-2,j1=j+4;i1>=1&&j1<=58;i1-=2,j1+=4)//往右上数寻找电脑棋子数
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

void machine_defend()//防守权值
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
				for(i1=i,j1=j-4;j1>=2;j1-=4)//往左数寻找玩家棋子数
				{
					if(status[i1][j1]==1)
						k1++;
					else
						break;
				}
				for(i1=i,j1=j+4;j1<=58;j1+=4)//往右数寻找玩家棋子数
				{
					if(status[i1][j1]==1)
						k2++; 
					else
						break;
				}
				k=k1>k2? k1:k2;
				k1=k2=0;
				for(i1=i-2,j1=j;i1>=1;i1-=2)//往上数寻找玩家棋子数
				{
					if(status[i1][j1]==1)
						k1++;
					else
						break;
				}
				for(i1=i+2,j1=j;i1<=30;i1+=2)//往下数寻找玩家棋子数
				{
					if(status[i1][j1]==1)
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1?k:k1;
				k1=k2=0;
				for(i1=i-2,j1=j-4;i1>=1&&j1>=2;i1-=2,j1-=4)//往左上数寻找玩家棋子数
				{
					if(status[i1][j1]==1)
						k1++;
					else
						break;
				}
				for(i1=i+2,j1=j+4;i1<=30&&j1<=58;i1+=2,j1+=4)//往右下数寻找玩家棋子数
				{
					if(status[i1][j1]==1)
						k2++;
					else
						break;
				}
				k1=k1>k2? k1:k2;
				k=k>k1?k:k1;
				k1=k2=0;
				for(i1=i+2,j1=j-4;i1<=30&&j1>=2;i1+=2,j1-=4)//往左下数寻找玩家棋子数
				{
					if(status[i1][j1]==1)
						k1++;
					else
						break;
				}
				for(i1=i-2,j1=j+4;i1>=1&&j1<=58;i1-=2,j1+=4)//往右上数寻找玩家棋子数
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

void find_position()//找到最有价值的位置
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
	direct[1]=k1;  //将找到的位置传给光标
	direct[0]=k2;
}

void man_man()//人人对战模式
{
	loop5:system("cls");
	char key;
	int control;
	gotoxy(2, 3);
	printf("1.红 子 先 手");
	
	gotoxy(2, 5);
	printf("2.白 子 先 手");
	
	gotoxy(2, 7);
	printf("(输入相应序号选择)");
	key=_getch();
	system("cls");
	if(key=='1')
		control=1;
	else if(key=='2')
		control=-1;
	else
		goto loop5;
	gotoxy(70,5);
	printf("   人 人 对 战    "); 
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
			printf("   红 子 执 手    "); 
			red_movexy();
			red_chess(direct[1],direct[0]);
			flag=judge_winner(direct[1],direct[0],1);
		}
		else
		{
			gotoxy(70,22);
			BackGround(6,0);
			printf("   白 子 执 手    "); 
			white_movexy();
			white_chess(direct[1],direct[0]);
			flag=judge_winner(direct[1],direct[0],2);
		}
		control=-control;
	}
	if(flag==1)
	{
		BackGround(7,0);
		MessageBox(NULL,TEXT("游戏结束，红子胜利"),TEXT("五子棋游戏"),MB_OK);
	}
	if(flag==2)
	{
		MessageBox(NULL,TEXT("游戏结束，白子胜利"),TEXT("五子棋游戏"),MB_OK);
	}
	if(count>=225)
	{
		MessageBox(NULL,TEXT("游戏结束，平局"),TEXT("五子棋游戏"),MB_OK);
	}
}

void man_machine()//人机对战模式 
{
	loop6:system("cls");
	char key;
	int control;
	gotoxy(2, 3);
	printf("1.玩 家 先 手（玩家为红子）");
	
	gotoxy(2, 5);
	printf("2.电 脑 先 手（电脑为白子）");
	
	gotoxy(2, 7);
	printf("(输入相应序号选择)");
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
	printf("   人 机 对 战    ");
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
			printf("   玩 家 执 手    "); 
			red_movexy();
			red_chess(direct[1],direct[0]);
			flag=judge_winner(direct[1],direct[0],1);
		}
		else
		{
			gotoxy(70,size/L-5);
			BackGround(6,0);
			printf("   电 脑 执 手    "); 
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
		MessageBox(NULL,TEXT("太厉害了，您战胜了电脑!"),TEXT("五子棋游戏"),MB_OK);
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
	
	gotoxy(20, 20);
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
			int message = MessageBox(NULL, "是否退出？", "友情提示", MB_OKCANCEL);
			if (IDCANCEL == message)
				goto loop;
			if (IDOK == message)break;
		}
		
	}
}

*/
