#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
char c; 
int n,m,mp[50][50],cnt,xx[]={1,-1,0,0},yy[]={0,0,1,-1};
struct Node
{
	int nx,ny;
}nod;
int main()
{
	while(1)
	{
		cout<<"欢迎来到推箱子小游戏"<<endl<<"请选择游戏难度等级（0-9）"<<endl;
		c=_getch();//_getch()函数用法比较奇特，需特殊记忆一下； 
		if(c>='0' && c<='9')
		{
			system("cls");
			break;
		}
		else cout<<"error"<<endl;
		Sleep(100);
		system("cls");
	}
	FILE*fp;
	char s[6]="x.txt";
	s[0]=c;
	fp=fopen(s,"r");
	if(fp==NULL)
	{
		cout<<"地图读取失败！"<<endl;
		return 0; 
	}
	else
	{
		fscanf(fp,"%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++) fscanf(fp,"%d",&mp[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) 
		{
			if(mp[i][j]==1) cout<<" ";
			else if(mp[i][j]==0) cout<<"#";
			else if(mp[i][j]==2) cout<<"@";
			else if(mp[i][j]==3) cout<<"^";
		} 
		cout<<endl;
	}
	cout<<"当前移动步数为："<<cnt<<endl;
	nod.nx=1;
	nod.ny=0;
	while(1)
	{
		int x0=nod.nx;
		int y0=nod.ny;
		if(mp[n-2][m-1]==2)
		{
			cout<<"恭喜你，通关了！"<<endl<<"最终使用步数："<<cnt<<endl; 
			system("pause"); 
			break;
		}
		int x1,y1;
		char t=_getch();
		if(t=='w')
		{
			x1=x0-1;
			y1=y0;
		}
		else if(t=='s')
		{
			x1=x0+1;
			y1=y0;
		}
		else if(t=='a')
		{
			x1=x0;
			y1=y0-1;
		}
		else if(t=='d')
		{
			x1=x0;
			y1=y0+1;
		}
		if(mp[x1][y1]==1)
		{
			nod.nx=x1;
			nod.ny=y1;
			mp[x0][y0]=1;
			mp[x1][y1]=3;
			system("cls");
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++) 
				{
					if(mp[i][j]==1) cout<<" ";
					else if(mp[i][j]==0) cout<<"#";
					else if(mp[i][j]==2) cout<<"@";
					else if(mp[i][j]==3) cout<<"^";
				}
				cout<<endl;
			}
			cout<<"当前移动步数为:"<< ++cnt <<endl; 
		}
		if(mp[x1][y1]==2 && mp[2*x1-x0][2*y1-y0]==1)
		{
			int con=0;
			for(int i=0;i<4;i++)
			{
				int dx=2*x1-x0+xx[i];
				int dy=2*y1-y0+yy[i];
				if(dx>=0 && dy>=0 && dx<n && dy<m && mp[dx][dy]==0) con++; 
			}
			if(con<=1 || nod.nx==n-2)
			{
				nod.nx=x1;
				nod.ny=y1;
				mp[x0][y0]=1;
				mp[x1][y1]=3;
				mp[2*x1-x0][2*y1-y0]=2;
				system("cls");
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<m;j++) 
					{
						if(mp[i][j]==1) cout<<" ";
						else if(mp[i][j]==0) cout<<"#";
						else if(mp[i][j]==2) cout<<"@";
						else if(mp[i][j]==3) cout<<"^";
					}
					cout<<endl;
				}
				cout<<"当前移动步数为:"<< ++cnt <<endl; 
			}
		}
	}
	return 0;
} 
