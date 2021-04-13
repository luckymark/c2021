#include <conio.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define dd double
#define ll long long 
#define ull unsigned long long 
using namespace std;
const int N1=10005;

int n,m;
struct Ware{
char name[40];
int len,num;
}a[N1];

// 1. 实现如下的菜单（按数字选择菜单功能）：
// 	- 显示存货列表 // 1
// 	- 入库 // 2
// 	- 出库 // 3
// 	- 退出程序 // 0 
// 1. 实现菜单对应功能（需记录货物的型号、数量等信息）；
// 1. 程序启动时从文件中读取当前库存数据，退出时保存库存数据；

int get_command()
{
    int input=getch(),to;
    switch(input)
    {
        case '1': to=1; break;
        case '2': to=2; break;
        case '3': to=3; break;
        case '0': to=4; break;
        default : to=-1; break; 
    }
    return to;
}

int idx(char c){ 
    if(c=='-') return 0; if(c=='.') return 1;
    if('A'<=c&&c<='Z') return c-'A'+2;
    if('a'<=c&&c<='z') return c-'a'+28;
    if('0'<=c&&c<='9') return c-'0'+55;
} //' '之后的
int id[N1];
struct Trie{
int ch[N1*40][64],id[N1],tot;
int findx(char *s,int len)
{
    int x=0,c;
    for(int i=0;i<len;i++)
    {
        c=idx(s[i]);
        if(ch[x][c]) x=ch[x][c];
        else ch[x][c]=++tot, x=tot;
    }
    return x;
}
int upd(char *s,int len,int w)
{
    int x=findx(s,len);
    if(!id[x]) 
    {
        id[x]=++n; a[n].len=len;
        for(int j=0;j<len;j++) a[n].name[j]=s[j];
        a[n].name[len]=' ';
    }
    if(a[id[x]].num+w<0) return 0;
    a[id[x]].num+=w;
    return 1;
}
}tr;
void list();
void stock();
void ship();
void save();

int main()
{
    freopen("ware.txt","r",stdin);
    // fopen("ware.txt","r");
    scanf("%d",&m);
    char tmp[N1];
    for(int i=1;i<=m;i++) 
    {
        scanf("%s",tmp); int l=strlen(tmp); a[i].len=l;
        for(int j=0;j<l;j++) a[i].name[j]=tmp[j];
        scanf("%d",&a[i].num);
        tr.upd(a[i].name,l,0);
    }
    // fclose(stdin); fflush(stdin);
    freopen( "CON", "r", stdin );
    int to;
    while(1)
    {
        system("cls");
        puts("Press [1] to list");
        puts("Press [2] to stock");
        puts("Press [3] to ship");
        puts("Press [0] to quit");
        to=get_command();
        switch(to)
        {
            case 1: list(); break;
            case 2: stock(); break;
            case 3: ship(); break;
            case 4: save(); break;
        }
        if(to==4) break;
    }
    return 0;
}

void abnor()
{
    puts("");
    puts("Press [0] to continue...");
    int to;
    while(1)
    {
        to=get_command();
        if(to==4) break;
    }
}
void list()
{
    system("cls");
    int lmax=0;
    for(int i=1;i<=n;i++) lmax=max(lmax,a[i].len);
    for(int i=1;i<=n;i++)
    {
        printf("%s",a[i].name);
        for(int j=a[i].len;j<lmax;j++) putchar(' ');
        printf(": %d\n",a[i].num);
    }
    abnor();
}
char str[40];
void stock()
{
    system("cls");
    puts("Please input the goods' name and how much do you want to stock:");
    scanf("%s",str); int len=strlen(str),w; scanf("%d",&w);
    int fl=tr.upd(str,len,w);
    if(!fl) printf("Invalid stock! The number of remaining boxes will be negative\n"), abnor();
}
void ship()
{
    system("cls");
    puts("Please input the goods' name and how much do you want to ship:");
    scanf("%s",str); int len=strlen(str),w; scanf("%d",&w);
    int fl=tr.upd(str,len,-w);
    if(!fl) printf("Invalid shipment! The number of remaining boxes will be negative\n"), abnor();
}
void save()
{
    freopen("ware.txt","w",stdout);
    printf("%d\n",n);
    for(int i=1;i<=n;i++) 
    {
        printf("%s",a[i].name);
        printf(" %d\n",a[i].num);
    }
    fclose(stdout);
}
