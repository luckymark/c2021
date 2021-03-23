#include<bits/stdc++.h>
#include <windows.h>

using namespace std;
char game_map[55][55],morex;
int n,m,px,py,wx,wy;
int pmy[]={-1,0,0,1};
int pmx[]={0,1,-1,0};
bool flag=1,win_flag=0;
void Menu()
{
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|       欢迎进入走迷宫游戏v0.5    |\n");
	printf("|                                 |\n");
	printf("|           请选择关卡            |\n");
    	printf("|          输入关卡数字           |\n");
    	printf("|          目前:1 to 1            |\n");
    	printf("|                                 |\n");
    	printf("|           0：退出游戏           |\n");
    	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    	printf("|墙:X    路:.    玩家:O    出口:# |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return ;
}
void game_open(int x)
{
	int x_game=x;
	string s1="mazegame",s2,s3=".txt";
	while(x)
	{
		s2=char(x%10+'0')+s2;
		x/=10;
	}
	s1=s1+s2+s3;
	cout<<s1<<endl;
	FILE *fp=fopen(s1.c_str(),"r");
	fscanf(fp,"%d%d%d%d%d%d",&n,&m,&px,&py,&wx,&wy);
	for(int i=1;i<=n;++i)
	fscanf(fp,"%s",&game_map[i]);
	fclose(fp);
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|       欢迎进入走迷宫游戏v0.5    |\n");
	printf("|                                 |\n");
	printf("|          正在进入第%d关         |\n",x_game);
    	printf("|                                 |\n");
    	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    	printf("|墙:X    路:.    玩家:O    出口:# |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    	Sleep(500);
	return ;
}
void Map_display()
{
	system("cls");
	for(int i=1;i<=n;++i)
	printf("%s\n",game_map[i]);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|墙:X       路:.       玩家:O      出口:#    |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("请输入wasd进行移动\n");
	printf("输入p认输\n");
}
void plmove(int x)
{
	if(game_map[px+pmx[x]][py+pmy[x]]=='X')
	{
		printf("撞墙了\n");
		return ;
	}
	if(game_map[px+pmx[x]][py+pmy[x]]=='#')
	{
		flag=0;
		win_flag=1;
		return ;
	}
	game_map[px+pmx[x]][py+pmy[x]]='O';
	game_map[px][py]='.';
	px+=pmx[x];
	py+=pmy[x];
	return ;
}
void game_work()
{
	char tmp;
	while(flag)
	{
		Map_display();
		cin>>tmp;
		switch(tmp)
		{
			case 'a':plmove(0);break;
			case 's':plmove(1);break;
			case 'w':plmove(2);break;
			case 'd':plmove(3);break;
			case 'p':flag=0;break;
			default :printf("错误指令!");
		}
		Sleep(500);
	}
	return ;
}
game_over()
{
	system("cls");
	if(win_flag)
	{
		printf("恭喜，过关了！！！！\n");
		printf("恭喜，过关了！！！！\n");
		printf("恭喜，过关了！！！！\n"); 
	}
	else 
	{
		printf("抱歉，您没能过关\n");
	}
	printf("  #请按回车键返回菜单#  \n");
	morex=getchar();morex=getchar();
}
int main()
{
	Menu();
	bool mf=1;
	int tmp; 
	while(mf)
	{
		cin>>tmp;
		if(tmp==0)
		{
			mf=0;
			break;
		}
		game_open(tmp);
		game_work();
		game_over();
		win_flag=0;
		flag=1;
		Menu();
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    	printf("|            已退出游戏           |\n");
    	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
} 
