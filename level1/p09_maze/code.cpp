#include<iostream>
#include<conio.h>
using namespace std;
const bool maze[16][16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,0,1,1,0,0,0,1,0,1,0,1,0,1,0,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,0,1,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,1,1,0,1,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int x,y=1;
void Print();
void Move()
{   
    int ch;
    if (ch=getch())
    { 
        ch=getch();
        switch(ch)
        {
            case 72:
			{
				if(!maze[y-1][x]&&y-1>=0)
				y--;
				break;
			}
            case 80:
            {
				if(!maze[y+1][x]&&y+1<=15)
				y++;
				break;
			}
            case 75:
            {
				if(!maze[y][x-1]&&x-1>=0)
				x--;
				break;
			}
            case 77:
            {
				if(!maze[y][x+1]&&x+1<=15)
				x++;
				break;
			}
            default:break;
            break;
        }
        Print();
    }  
    return;
}
void Print()
{
	system("cls");
	for(int i=0;i<=15;i++)
	for(int j=0;j<=15;j++)
	{
		if(i==y&&j==x)
		cout<<"¡ñ";
		else if(maze[i][j])
		cout<<"¨¨";
		else if(!maze[i][j])
		cout<<"  ";
		if(j==15)
		cout<<endl;
	}
	return;
}
int main()
{
	Print();
	while(x!=15||y!=14)
	Move();
	cout<<"You Win!";
	return 0;
}
