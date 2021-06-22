#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define N 0x7fff
int step=0;
bool ans=1;
char maze[N][N];
int h,l,hh,ll;
int n;
void pr()
{
  system("cls");
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      putchar(maze[i][j]);
      if(j==n) cout<<endl;
    }
  }
  printf("steps:%d",step);
  return;
}
void up()
{
  if(maze[h-1][l]=='@')
  {
    printf("error");
    return;
  }
  if(maze[h-1][l]==' ')
  {
    maze[h][l]=' ';
    maze[h-1][l]='#';
    h=h-1;
    step++;
    return;
  }
}
void right()
{
  if(maze[h][l+1]=='@')
  {
    printf("error");
    return;
  }
  if(maze[h][l+1]==' ')
  {
    maze[h][l]=' ';
    maze[h][l+1]='#';
    l=l+1;
    step++;
    return;
  }
  printf("steps:%d",step);
}
void left()
{
  if(maze[h][l-1]=='@')
  {
    printf("error");
    return;
  }
  if(maze[h][l-1]==' ')
  {
    maze[h][l]=' ';
    maze[h][l-1]='#';
    l=l-1;
    step++;
    return;
  }
}
void down()
{
  if(maze[h+1][l]=='@')
  {
    printf("error");
    return;
  }
  if(maze[h+1][l]==' ')
  {
    maze[h][l]=' ';
    maze[h+1][l]='#';
    h=h+1;
    step++;
    return;
  }
}
int main()
{
    freopen("mazein.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        char fuck=getchar();
        if(fuck=='\n') j--;
        else maze[i][j]=fuck;
        //printf("%c",maze[i][j]);
      }
    }
    pr();
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(maze[i][j]=='#')
        {
          h=i;
          hh=i;
          l=j;
          ll=j;
        }
      }
    }
    int ch;
    while(ans){
      //cout<<1<<endl;
      ch=getch();
      switch(ch)
      {
        case 0xe0:{
          ch=getch();
          switch(ch)
          {
            case 72:{
              up();
              pr();
              break;
            }
            case 80:{
              down();
              pr();
              break;
            }
            case 75:{
              left();
              pr();
              break;
            }
            case 77:{
              right();
              pr();
              break;
            }
            default: printf("error");
          }
          break;
        }
        default:printf("error");
      }
      if(l==1||l==n||h==1||h==n)
      {
        if(l!=ll||h!=hh)
        {
          break;
        }
      }
    }
    printf("You win! And your final steps is %d",step);
    system("pause");
}
