#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <queue>
#include <algorithm>
#define FG FOREGROUND_GREEN
#define FR FOREGROUND_RED
#define FB FOREGROUND_BLUE
#define FI FOREGROUND_INTENSITY
#define dd double
#define ll long long 
#define ull unsigned long long 
using namespace std;

int n,m,Score,End,step;
HANDLE output[2];
COORD coord = {0,0};
DWORD bytes = 0;
int checkx(int x,int y)
{
    if(x>=1 && x<n && y>=1 && y<m) return 1;
    return 0;
}
int id(int x,int y){ return m*x+y; }
char data[32][102];
int fx[6] = {0,-1,1,0,0,0}, fy[6] = {0,0,0,-1,1,0}; //*wsad

//以下为部分借鉴的模板
//双缓冲解决闪屏问题
int cnt=0;

int checkok(int x,int y)
{
    return x>=1 && x<n && y>=1 && y<m;
}
void setcolor(HANDLE hCon,unsigned short ForeColor,unsigned short BackGroundColor)
{
    bool flag=SetConsoleTextAttribute(hCon,ForeColor|BackGroundColor); //设置文本及背景颜色
}
void initconsolveScreenBuffer(int &x,int &y)
{
    output[0] = CreateConsoleScreenBuffer(
        GENERIC_WRITE|GENERIC_READ,
        FILE_SHARE_WRITE|FILE_SHARE_READ,
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    output[1] = CreateConsoleScreenBuffer(
        GENERIC_WRITE|GENERIC_READ,
        FILE_SHARE_WRITE|FILE_SHARE_READ,
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    CONSOLE_CURSOR_INFO cci; //创建光标
    cci.bVisible = 0; //光标可见度
    cci.dwSize = 1; //光标大小
    SetConsoleCursorInfo(output[0],&cci);
    SetConsoleCursorInfo(output[1],&cci);
    //start data
    memset(data,0,sizeof(data));
    scanf("%d%d%d\n",&n,&m,&End);
    for(int i=0;i<=n;i++)
    {
        gets(data[i]); data[i][m+2]='\n';
        for(int j=0;j<=m;j++) if(data[i][j]=='@') 
            x=i, y=j;
    }
}
int get_toward()
{
    int input=getch(),to;
    switch(input)
    {
        case 'w': to=1; break;
        case 's': to=2; break;
        case 'a': to=3; break;
        case 'd': to=4; break;
        case '0': to=0; break; //退出程序
        case 224:
        {
            input=getch();
            switch(input)
            {
                case 72: to=1; break;
                case 80: to=2; break;
                case 75: to=3; break;
                case 77: to=4; break;
            }
            break; 
        }
        default : to=-1; break; 
    }
    return to;
}
void print_unique(HANDLE hout,int i,int y,int color)
{
    LPDWORD num=0;
    setcolor(hout,color,0); //|BACKGROUND_RED |FOREGROUND_INTENSITY
    WriteConsoleA(hout,data[i]+y,1,num,NULL);
}
void put_str(HANDLE hout,int color,char *s,int type)
{
    LPDWORD num=0;
    setcolor(hout,color,0);
    WriteConsoleA(hout,s,strlen(s),num,NULL);
    if(type) SetConsoleActiveScreenBuffer(hout); //把缓冲区作为显示的缓冲区
}

int is_start,task=1;
char str[100];
int show(HANDLE hout,int &x,int &y,int to)
{
    
    if(!to) return 0; if(to==-1) return 1; char c;
    if(checkok(x+fx[to],y+fy[to])) //&& 
    {
        c=data[x+fx[to]][y+fy[to]];
        if(c==' '||c=='@'){ //目标是空
            swap(data[x][y],data[x+fx[to]][y+fy[to]]);
            x+=fx[to]; y+=fy[to];
            if(c!='@') step++;
        }else if(c=='$'){ //目标是箱子
            if(checkok(x+2*fx[to],y+2*fy[to]))
            {
                if(data[x+2*fx[to]][y+2*fy[to]]=='?'){
                    data[x+fx[to]][y+fy[to]]=data[x][y]; data[x][y]=' '; 
                    data[x+2*fx[to]][y+2*fy[to]]='&';
                    Score++;
                    x+=fx[to]; y+=fy[to];
                    step++;
                }else if(data[x+2*fx[to]][y+2*fy[to]]==' '){
                    swap(data[x+fx[to]][y+fy[to]],data[x+2*fx[to]][y+2*fy[to]]);
                    swap(data[x+fx[to]][y+fy[to]],data[x][y]);
                    x+=fx[to]; y+=fy[to];
                    step++;
                }
            }
        }
    }
    
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    // setcolor(hout,FOREGROUND_GREEN|FOREGROUND_INTENSITY,0); //|BACKGROUND_RED |FOREGROUND_INTENSITY
    
    LPDWORD num=0;
    SetConsoleCursorPosition(hout,coord);
    sprintf(str,"LEVEL:%d\11\11",task);
    put_str(hout,FG|FB|FI,str,0);
    sprintf(str,"@:Player  "); 
    put_str(hout,FR|FI,str,0);
    sprintf(str,"#:Wall    \n"); 
    put_str(hout,FG|FI,str,0);
    
    sprintf(str,"Score:%d \11",step);
    put_str(hout,FG|FB|FI,str,0);
    sprintf(str,"$:Box     "); 
    put_str(hout,FG|FR|FI,str,0);
    sprintf(str,"?:Target  \n"); 
    put_str(hout,FR|FB|FI,str,0);
    sprintf(str,"\11\11&:Obtained\n"); 
    put_str(hout,FB|FI,str,0);
    
    for(int i=0;i<=n;i++) 
    {
        data[i][m+1]='\n'; //coord.Y=i; 
        for(int j=0;j<=m+1;j++)
        {
            switch(data[i][j])
            {
                case '@': print_unique(hout,i,j,FR|FI); break;
                case '#': print_unique(hout,i,j,FG|FI); break;
                case '$': print_unique(hout,i,j,FG|FR|FI); break;
                case '?': print_unique(hout,i,j,FR|FB|FI); break;
                case '&': print_unique(hout,i,j,FB|FI); break;
                default: print_unique(hout,i,j,0); break;
                // case ' ': print_unique(hout,i,j,0);
            }
        }
    }
    coord.Y=0;
    // h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleActiveScreenBuffer(hout); //把缓冲区作为显示的缓冲区
    // Sleep(2000);
    cnt++;
    return 1;
}
