#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <queue>
#include <algorithm>
#define dd double
#define ll long long 
#define ull unsigned long long 
using namespace std;

// // 生成迷宫：生成树算法
// // 我的做法：随机边权然后最小生成树
int n,m,cte;
struct EDGE{ 
int x,y,w; 
friend bool operator < (const EDGE &s1,const EDGE &s2)
{
    return s1.w<s2.w;
}
}e[1500*4+5]; 


HANDLE output[2];
COORD coord = {0,0};
DWORD bytes = 0;
int cmp(EDGE aa,EDGE bb)
{
    return aa.w<bb.w;
}
int checkx(int x,int y)
{
    if(x>=1 && x<n && y>=1 && y<m) return 1;
    return 0;
}
int id(int x,int y){ return m*x+y; }
char data[32][52];
int fx[5] = {0,-1,1,0,0}, fy[5] = {0,0,0,-1,1}; //*wsad

void init_hard_version()
{
    puts("Plz choose difficulty:");
    puts("press [1] to choose easy difficulty");
    puts("press [2] to choose standard difficulty");
    puts("press [3] to choose hard difficulty");
    puts("press [4] to choose customized difficulty");
    int input=getch();
    switch(input)
    {
        case '1': n=10,m=10; break;
        case '2': n=20,m=20; break;
        case '3': n=26,m=50; break;
        case '4': 
        {
            puts("Plz input game map size:");
            printf("Number of Rows:"); scanf("%d",&n);
            printf("Number of Columns:"); scanf("%d",&m);
            n=min(n,26); m=min(m,50);
            break;
        }
    }
}

struct node{ int x,y; };
int fa[2005];
int idx(int x,int y){ return (x-1)*m+y; }
int findfa(int x)
{
    int y=x,tmp;
    while(y!=fa[y]) y=fa[y];
    while(fa[x]!=x){
        tmp=fa[x]; fa[x]=y, x=tmp;
    }
    return y;
}
void printmap()
{
    system("cls");
    for(int i=0;i<=n;i++,puts("")) for(int j=0;j<=m;j++) 
        if(data[i][j]) printf("%c",data[i][j]);
        else printf(" ");
}
void build_puzzle()
{
    for(int i=1;i<n;i++) for(int j=1;j<m;j++) 
    {
        fa[idx(i,j)]=idx(i,j);
        if((i&1)^(j&1))
            e[++cte]=(EDGE){i,j,rand()*rand()%1000000};
        else if(i&1) data[i][j]=0; 
    }
    sort(e+1,e+cte+1);
    int x,y,ia,ib;
    for(int j=1;j<=cte;j++)
    {
        x=e[j].x; y=e[j].y; //id=idx(x,y);
        if(x&1){
            if(checkx(x,y-1)&&checkx(x,y+1))
            {
                ia=idx(x,y-1); ib=idx(x,y+1);
                ia=findfa(ia); ib=findfa(ib);
                if(ia!=ib){ 
                    fa[ia]=ib; data[x][y]=0; }
                else{
                    // data[x][y]='$';
                }
            }
        }else{
            if(checkx(x+1,y)&&checkx(x-1,y))
            {
                ia=idx(x+1,y); ib=idx(x-1,y);
                ia=findfa(ia); ib=findfa(ib);
                if(ia!=ib){ 
                    fa[ia]=ib; data[x][y]=0; }
                else{
                    // data[x][y]='$';
                }
            }
        }
    }
    // printmap();
}

//以下为部分借鉴的模板
//双缓冲解决闪屏问题
void initconsolveScreenBuffer();
int show(HANDLE hout,int &x,int &y,int to);
int get_toward();
int cnt=0;

void setcolor(HANDLE hCon,unsigned short ForeColor,unsigned short BackGroundColor)
{
    // HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE); //获得缓冲区句柄
    bool flag=SetConsoleTextAttribute(hCon,ForeColor|BackGroundColor); //设置文本及背景颜色
    flag=flag^1; flag=flag^1;
    // SetConsoleTextAttribute(hCon,FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_GREEN); //设置文本及背景颜色
}
void initconsolveScreenBuffer()
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
    for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) data[i][j]='#';
    build_puzzle();
    data[0][1]='W';
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
int is_start;
int show(HANDLE hout,int &x,int &y,int to)
{
    if(!to) return 0; if(to==-1) return 1;
    if(x+fx[to]>=1 && x+fx[to]<n && y+fy[to]>=1 && y+fy[to]<m && !data[x+fx[to]][y+fy[to]]) //&& 
    {
        swap(data[x][y],data[x+fx[to]][y+fy[to]]);
        x+=fx[to]; y+=fy[to];
    }
    if(is_start) data[0][1]='#';
    
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    setcolor(hout,FOREGROUND_GREEN|FOREGROUND_INTENSITY,0); //|BACKGROUND_RED |FOREGROUND_INTENSITY
    
	GetConsoleScreenBufferInfo(hout, &csbiInfo); //未改变？？？？
    csbiInfo.dwCursorPosition=coord;
	// wOldColorAttrs = csbiInfo.wAttributes;
    
    if(cnt==2)
        bytes=0;
    LPDWORD num=0;
    SetConsoleCursorPosition(hout,coord);
    for(int i=0;i<=n;i++) 
    {
        coord.Y=i;
        data[i][m+1]='\n';
        WriteConsoleA(hout,data[i],m+2,num,NULL);
        GetConsoleScreenBufferInfo(hout, &csbiInfo); 
    }
    coord.Y=0;
    SetConsoleActiveScreenBuffer(hout); //把缓冲区作为显示的缓冲区
    
    cnt++;
    return 1;
}



int main()
{
    // scanf("%d",&n);
    srand(time(NULL));
    // system("color 0E");
    init_hard_version();
    initconsolveScreenBuffer();
    int to=2,now=1,x=0,y=1; //初始化输出一次
    is_start=1; show(output[now],x,y,to); is_start=0; now^=1;
    while(to=get_toward())
    {
        show(output[now],x,y,to);
        if(x==n-1 && y==m-1) 
            { n=n; break; }
        now^=1;
    }
    LPDWORD num=0;
    // coord.Y=n+3;
    WriteConsoleA(output[now],"\n",1,num,NULL);
    WriteConsoleA(output[now],"Congratulations!\n",17,num,NULL);
    SetConsoleActiveScreenBuffer(output[now]); //把缓冲区作为显示的缓冲区
    // puts("YOU WIN!");
    Sleep(1000000);
    return 0;
}


