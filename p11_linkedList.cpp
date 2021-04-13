#include <conio.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define dd double
#define ll long long 
#define ull unsigned long long 
// #include "p11_linkedList.h"
using namespace std;
const int N1=105;

int n, tot;
struct node{
int val; node *nxt;
};
node *head;

int get_command();
node* createnode(int x);
void releasenode(node* now);
node* insert(int pos,int x);
void del();
void DEL(int pos);
void print(int type);
node* inverse();
int find_first(int w);
int find_nxt(int pos,int w);

void ins()
{
    system("cls");
    print(0);
    puts("Please input new point's position and its value.");
    int pos, w;
    scanf("%d %d",&pos,&w);
    insert(pos,w);
}
void del()
{
    system("cls");
    print(0);
    puts("Please input the position where you want to delete.");
    int pos;
    scanf("%d",&pos);
    DEL(pos);
}
void abnor()
{
    puts("");
    puts("Press [0] to continue...");
    int to;
    while(1)
    {
        to=get_command();
        if(to==0) break;
    }
}
int find1()
{
    system("cls");
    puts("Please input the value you want to find.");
    int pos,w; scanf("%d",&w);
    pos = find_first(w);
    printf("%d",pos);
    abnor();
    return pos;
}
int now_w;
int findn(int st)
{
    system("cls");
    puts("Please input the value you want to find.");
    int pos,w; 
    if(st==-1){
        pos=-1; puts("Please redirect the start position by press [5] in your next command.");
        // if(now_w == w) pos=-1; else { scanf("%d",&w); pos = find_nxt(st,w); now_w = w; }
    }else{ scanf("%d",&w); pos = find_nxt(st,w); now_w = w; }
    printf("%d",pos); 
    abnor();
    return pos;
}

int main()
{
    // freopen("a.in","r",stdin);
    printf("Plz input the size of your linkedlist:");
    scanf("%d",&n);
    puts("Plz input the elements in order in your linkedlist:");
    puts("The last element will be linked with the first element.");
    head = new node ((node){0,NULL}); 
    for(int i=0;i<n;i++) 
    {
        int x;
        scanf("%d",&x);
        insert(i,x);
    }
    while(1)
    {
        system("cls");
        puts("Press [1] to insert a point.");
        puts("Press [2] to delete a point.");
        puts("Press [3] to print the linkedlist.");
        puts("Press [4] to inverse the linkedlist.");
        puts("Press [5] to find the first position of the w.");
        puts("Press [6] to find the next position of the w.");
        puts("Press [/] to quit");
        int to=get_command(), st;
        switch(to)
        {
            case 1: ins(); break;
            case 2: del(); break;
            case 3: print(1); break;
            case 4: inverse(); break;
            case 5: st=find1(); break;
            case 6: st=findn(st); break;
        }
        if(to==7) break;
    }
    return 0;
}

int get_command()
{
    int input=getch(),to;
    switch(input)
    {
        case '1': to=1; break;
        case '2': to=2; break;
        case '3': to=3; break;
        case '4': to=4; break;
        case '5': to=5; break;
        case '6': to=6; break;
        case '/': to=7; break;
        case '0': to=0; break;
        default : to=-1; break; 
    }
    return to;
}
void releasenode(node* now)
{
    int cnt=tot; node *nxt;
    for(;cnt;cnt--)
    {
        nxt = (*now).nxt;
        delete now;
        if(cnt>1) now = nxt;
    }
}
node* createnode(int x)
{
    node *buf = new node ((node){x,NULL});
    return buf;
}
node* insert(int pos,int x)
{
    node* now=head; 
    if((*now).nxt==NULL){ (*now).val=x; (*now).nxt=now; tot++; return now; } //原链表没有元素
    pos--;
    for(;pos;now=(*now).nxt,pos--);
    node *nxt = (*now).nxt, *cur = createnode(x);
    (*now).nxt = cur; (*cur).nxt = nxt;
    tot++;
    return cur;
}
void DEL(int pos)
{
    node* now=head; 
    if(pos==1) pos=tot; else pos--;
    for(;pos>1;now=(*now).nxt,pos--);
    node *cur = (*now).nxt;
    (*now).nxt = (*cur).nxt; 
    delete cur;
    tot--;
}
void print(int type)
{
    node *now; now=head; int cnt=tot;
    for(;cnt;cnt--,now=(*now).nxt)
    {
        printf("%d ",(*now).val);
    }
    if(type==0) puts("");
    if(type==1) abnor();
}
node* inverse()
{
    node *cur = createnode((*head).val), *now, *tmp, *nxt, *st; 
    (*cur).nxt = cur;
    now = head; st = cur;
    int cnt = tot;
    for(;cnt;cnt--,now=(*now).nxt)
    {
        nxt = (*now).nxt;
        if(cnt!=1) tmp = createnode((*nxt).val); else tmp = st;
        (*tmp).nxt = cur;
        cur = tmp;
    }
    releasenode(head);
    head = cur;
    print(1); 
    return cur;
}
int find_first(int w)
{
    node* now = head; int cnt=1;
    for(;cnt<=tot;cnt++,now=(*now).nxt)
    {
        if((*now).val==w) break;
    }
    if(cnt==tot+1) return -1;
    return cnt;
}
int find_nxt(int pos,int w) //pos之后的第一个w值
{
    node* now = head; int cnt=pos;
    for(;cnt;now=(*now).nxt,cnt--); cnt=pos+1;
    for(;cnt<=tot;cnt++,now=(*now).nxt)
    {
        if((*now).val==w) break;
    }
    if(cnt==tot+1) return -1;
    return cnt;
}
