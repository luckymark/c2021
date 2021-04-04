#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;
int cnt[3]={2,3,5},maze[16][16];
int x,y=1,cur=1,scr[3]={100000,100000,100000},sc;
string name;
void readMap(int a)
{
	FILE *p;
	if(a==1)
	p=fopen("level1.map","r");
	else if(a==2)
	p=fopen("level2.map","r");
	else if(a==3)
	p=fopen("level3.map","r");
	else return;
	for(int i=0;i<16;i++)
	for(int j=0;j<16;j++)
	fscanf(p,"%d",&maze[i][j]);
	return;
}
void Print()
{
	system("cls");
	cout<<"Level "<<cur<<endl;
	for(int i=0;i<=15;i++)
	for(int j=0;j<=15;j++)
	{
		if(i==y&&j==x)
		cout<<"¡ñ";
		else if(maze[i][j]==1)
		cout<<"¨¨";
		else if(maze[i][j]==2)
		cout<<"¡î";
		else if(maze[i][j]==3)
		cout<<"¡ï";
		else if(!maze[i][j])
		cout<<"  ";
		if(j==15)
		cout<<endl;
	}
	return;
}
void Move()
{   
	Print();
    int ch;
    if (ch=getch())
    { 
        ch=getch();
        switch(ch)
        {
            case 72:
			{
				if(!maze[y-1][x]&&y-1>=0)
				y--,scr[sc]*=0.99;
				else if(maze[y-1][x]==3&&y-2>=0)
				{
					if(maze[y-2][x]==2)
					maze[y-1][x]=0,maze[y-2][x]=0,y--,scr[sc]*=0.99,cnt[cur-1]--;
					else if(!maze[y-2][x])
					maze[y-2][x]=3,maze[y-1][x]=0,y--,scr[sc]*=0.99;
				}
				break;
			}
            case 80:
            {
				if(!maze[y+1][x]&&y+1<=15)
				y++,scr[sc]*=0.99;
				else if(maze[y+1][x]==3&&y+2>=0)
				{
					if(maze[y+2][x]==2)
					maze[y+1][x]=0,maze[y+2][x]=0,y++,scr[sc]*=0.99,cnt[cur-1]--;
					else if(!maze[y+2][x])
					maze[y+2][x]=3,maze[y+1][x]=0,y++,scr[sc]*=0.99;
				}
				break;
			}
            case 75:
            {
				if(!maze[y][x-1]&&x-1>=0)
				x--,scr[sc]*=0.99;
				else if(maze[y][x-1]==3&&x-2>=0)
				{
					if(maze[y][x-2]==2)
					maze[y][x-1]=0,maze[y][x-2]=0,x--,scr[sc]*=0.99,cnt[cur-1]--;
					else if(!maze[y][x-2])
					maze[y][x-2]=3,maze[y][x-1]=0,x--,scr[sc]*=0.99;
				}
				break;
			}
            case 77:
            {
				if(!maze[y][x+1]&&x+1<=15)
				x++,scr[sc]*=0.99;
				else if(maze[y][x+1]==3&&x+2>=0)
				{
					if(maze[y][x+2]==2)
					maze[y][x+1]=0,maze[y][x+2]=0,x++,scr[sc]*=0.99,cnt[cur-1]--;
					else if(!maze[y][x+2])
					maze[y][x+2]=3,maze[y][x+1]=0,x++,scr[sc]*=0.99;
				}
				break;
			}
            default:break;
            break;
        }
    }  
    return;
}
void Menu()
{
	cout<<"Welcome to the Push Box Game!"<<endl;
	cout<<"Please enter your name:";
	getline(cin,name);
	return; 
}
int main()
{
	Menu();
	Print();
	while(cur!=4)
	{
		readMap(cur);
		while(cnt[cur-1])
		Move();
		x=0,y=1,cur++,sc++;
	}
	system("cls");
	cout<<"You Win!"<<endl;
	cout<<"Your score:"<<endl;
	cout<<"Level1 Score: "<<scr[0]<<" Level2 Score: "<<scr[1]<<" Level3 Score: "<<scr[2];
	freopen("score.txt","w",stdout);
	cout<<"Name: "<<name<<" Level1 Score: "<<scr[0]<<" Level2 Score: "<<scr[1]<<" Level3 Score: "<<scr[2];
	return 0;
}
