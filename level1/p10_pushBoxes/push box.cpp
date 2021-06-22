#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define N 0x7fff
int step=0;
bool ans=1;
char box[N][N];
int h,l,hh,ll;
int n;
int anss;
//# means player , * means box , % means final goal;
void pr()
{
  system("cls");
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      putchar(box[i][j]);
      if(j==n) cout<<endl;
    }
  }
  printf("steps:%d",step);
  return;
}
void up()
{
  if(box[h-1][l]=='@')
  {
    printf("error");
    return;
  }
  if(box[h-1][l]=='%')
  {
    printf("error");
    return;
  }
  if(box[h-1][l]==' ')
  {
    box[h][l]=' ';
    box[h-1][l]='#';
    h=h-1;
    step++;
    return;
  }
  if(box[h-1][l]=='*')
  {
    if(box[h-2][l]==' ')
    {
      box[h-2][l]='*';
      box[h-1][l]='#';
      box[h][l]=' ';
      step++;
      h=h-1;
      return ;
    }
    if(box[h-2][l]=='%')
    {
      box[h-1][l]='#';
      box[h][l]=' ';
      h=h-1;
      step++;
      anss--;
    }
    if(box[h-2][l]=='@')
    {
      printf("error");
      return;
    }
  }
  printf("steps:%d",step);
}
void right()
{
  if(box[h][l+1]=='@')
  {
    printf("error");
    return;
  }
  if(box[h][l+1]=='%')
  {
    printf("error");
    return;
  }
  if(box[h][l+1]==' ')
  {
    box[h][l]=' ';
    box[h][l+1]='#';
    l=l+1;
    step++;
    return;
  }
  if(box[h][l+1]=='*')
  {
    if(box[h][l+2]==' ')
    {
      box[h][l+2]='*';
      box[h][l+1]='#';
      box[h][l]=' ';
      step++;
      l=l+1;
      return;
    }
    if(box[h][l+2]=='%')
    {
      box[h][l+1]='#';
      box[h][l]=' ';
      l=l+1;
      step++;
      anss--;
    }
    if(box[h][l+2]=='@')
    {
      printf("error");
      return;
    }
  }
  printf("steps:%d",step);
}
void left()
{
  if(box[h][l-1]=='@')
  {
    printf("error");
    return;
  }
  if(box[h][l-1]=='%')
  {
    printf("error");
    return;
  }
  if(box[h][l-1]==' ')
  {
    box[h][l]=' ';
    box[h][l-1]='#';
    l=l-1;
    step++;
    return;
  }
  if(box[h][l-1]=='*')
  {
    if(box[h][l-2]==' ')
    {
      box[h][l-2]='*';
      box[h][l-1]='#';
      box[h][l]=' ';
      step++;
      l=l-1;
      return ;
    }
    if(box[h][l-2]=='%')
    {
      box[h][l-1]='#';
      box[h][l]=' ';
      l=l-1;
      step++;
      anss--;
    }
    if(box[h][l-2]=='@')
    {
      printf("error");
      return;
    }
  }
}
void down()
{
  if(box[h+1][l]=='@')
  {
    printf("error");
    return;
  }
  if(box[h+1][l]=='%')
  {
    printf("error");
    return;
  }
  if(box[h+1][l]==' ')
  {
    box[h][l]=' ';
    box[h+1][l]='#';
    h=h+1;
    step++;
    return;
  }
  if(box[h+1][l]=='*')
  {
    if(box[h+2][l]==' ')
    {
      box[h+2][l]='*';
      box[h+1][l]='#';
      box[h][l]=' ';
      step++;
      h++;
      return ;
    }
    if(box[h+2][l]=='%')
    {
      box[h+1][l]='#';
      box[h][l]=' ';
      h++;
      step++;
      anss--;
    }
    if(box[h+2][l]=='@')
    {
      printf("error");
      return;
    }
  }
}
int main()
{
  puts("Input 1 to choose map1\n");
  puts("Input 2 to choose map2\n");
  int nn;
  cin>>nn;
  system("cls");
  if(nn==1) freopen("boxin1.txt","r",stdin);
  if(nn==2) freopen("boxin2.txt","r",stdin);
    scanf("%d%d",&n,&anss);
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        char ch=getchar();
        if(ch=='\n') j--;
        else box[i][j]=ch;
      }
    }
    pr();
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        if(box[i][j]=='#')
        {
          h=i;
          hh=i;
          l=j;
          ll=j;
        }
      }
    }
    int ch;
    while(anss){
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
