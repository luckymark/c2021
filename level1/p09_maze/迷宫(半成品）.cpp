#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<windows.h>
#include<ctime> 
using namespace std;

bool maze[100][100]={0};
bool road[100][100]={0};
int n,finish,now_x,now_y;

typedef struct squr{
    int x;
    int y;
    struct squr *next;
    struct squr *former;
};

void make_maze(int n);
void go_through(struct squr **begi);
struct squr* go_back(struct squr **begi);
void go_up();
void go_down();
void go_right();
void go_left();
void maze_print(int x,int y);


int main(){
    char b;
    bool end=0;
    cin>>n;
    unsigned seed; 
    seed = time(0);
    srand(seed);
    make_maze(n);
    //maze_print(0,1);
    now_x=0;
    now_y=1;
    while(scanf("%c",&b)&&!end){
        switch (b){
            case 'w':
                go_up();
                break;
            case 's':
                go_down();
                break;
            case 'd':
                go_right();
                break;
            case 'a':
                go_left();
                break;
        }
        maze_print(now_x,now_y);
        if(now_x==n-1&&now_y==n-2){
            break;
        }
    }
    cout<<"Congratulation!!";
}

void go_up(){
     if(road[now_x-1][now_y]){
         now_x=now_x-1;
     }
}

void go_down(){
    if(road[now_x+1][now_y]){
        now_x=now_x+1;
    }
}

void go_left(){
    if(road[now_x][now_y-1]){
        now_y=now_y-1;
    }
}

void go_right(){
    if(road[now_x][now_y+1]){
        now_y=now_y+1;
    }
}

struct squr* go_back(struct squr **begi){
    bool up=(1-road[(*begi)->x][((*begi)->y)-2])&(((*begi)->y)-2>0);
    bool down=(1-road[(*begi)->x][(*begi)->y+2])&(((*begi)->y)+2<n);
    bool left=(1-road[((*begi)->x)-2][(*begi)->y])&(((*begi)->x)-2>0);
    bool right=(1-road[((*begi)->x)+2][(*begi)->y])&(((*begi)->x)+2<n);
    int num=0;
    struct squr *p;
    if(up)num++;
    if(down)num++;
    if(left)num++;
    if(right)num++;
    if(num==0){
        p=(*begi)->former;
        go_back(&p);
    }
    else{
        return *begi;
    }
}

void go_through(struct squr **begi){
    struct squr *go_to=(struct squr*)malloc(sizeof(struct squr));
    struct squr *p;
    struct squr *again;
    bool up=(1-road[(*begi)->x][((*begi)->y)-2])&(((*begi)->y)-2>0);
    bool down=(1-road[(*begi)->x][(*begi)->y+2])&(((*begi)->y)+2<n);
    bool left=(1-road[((*begi)->x)-2][(*begi)->y])&(((*begi)->x)-2>0);
    bool right=(1-road[((*begi)->x)+2][(*begi)->y])&(((*begi)->x)+2<n);
    int num=0;
    int ch,choose=0;
    if(up)num++;
    if(down)num++;
    if(left)num++;
    if(right)num++;
    if(num>0){
        ch=rand()%num+1;
        while(1){
            if(up){
                ch--;
                choose=1;
                if(ch==0)break;
            }
            if(down){
                ch--;
                choose=2;
                if(ch==0)break;
            }
            if(left){
                ch--;
                choose=3;
                if(ch==0)break;
            }
            if(right){
                ch--;
                choose=4;
                if(ch==0)break;
            }
        }
        switch(choose){
            case 1:
                road[(*begi)->x][((*begi)->y)-2]=1;
                road[(*begi)->x][((*begi)->y)-1]=1;
                finish++;
                go_to->former=*begi;
                go_to->x=(*begi)->x;
                go_to->y=(*begi)->y-2;
                go_to->next=NULL;
                (*begi)->next=go_to;
                if(finish<int((n/2))*int((n/2)))go_through(&go_to);
                break;
            case 2:
                road[(*begi)->x][((*begi)->y)+2]=1;
                road[(*begi)->x][((*begi)->y)+1]=1;
                finish++;
                go_to->former=*begi;
                go_to->x=(*begi)->x;
                go_to->y=(*begi)->y+2;
                go_to->next=NULL;
                (*begi)->next=go_to;
                if(finish<int((n/2))*int((n/2)))go_through(&go_to);
                break;
            case 3:
                road[((*begi)->x)-2][(*begi)->y]=1;
                road[((*begi)->x)-1][(*begi)->y]=1;
                finish++;
                go_to->former=*begi;
                go_to->x=(*begi)->x-2;
                go_to->y=(*begi)->y;
                go_to->next=NULL;
                (*begi)->next=go_to;
                if(finish<int((n/2))*int((n/2)))go_through(&go_to);
                break;
            case 4:
                road[((*begi)->x)+2][(*begi)->y]=1;
                road[((*begi)->x)+1][(*begi)->y]=1;
                finish++;
                go_to->former=*begi;
                go_to->x=(*begi)->x+2;
                go_to->y=(*begi)->y;
                go_to->next=NULL;
                (*begi)->next=go_to;
                if(finish<int((n/2))*int((n/2)))go_through(&go_to);
                break;
        }
    }
    else{
        if(finish<int((n/2))*int((n/2))){
            p=(*begi)->former;
            again=go_back(&p);
            go_through(&again);
        }
    }
}


void make_maze(int n){
    struct squr *begin=(struct squr*)malloc(sizeof(struct squr));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i%2==1)&&(j%2==1)){
                maze[i][j]=1;
            }
        }
    }
    road[1][1]=1;
    begin->x=1;
    begin->y=1;
    finish=1;
    go_through(&begin);
    road[0][1]=1;
    road[n-1][n-2]=1;
}

void maze_print(int x,int y){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(road[i][j]&&(i!=x||j!=y)){
                cout<<"  ";
            }
            else if(road[i][j]){
                cout<<"G ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}
