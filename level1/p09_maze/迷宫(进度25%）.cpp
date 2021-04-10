#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<cstdlib>
#include<windows.h>
using namespace std;

bool maze[100][100]={0};
bool road[100][100]={0};
int n,finish;

typedef struct squr{
    int x;
    int y;
    struct squr *next;
    struct squr *former;
};

void print_maze(int n);
int go_if(struct squr *now);
void go_through(struct squr **begi);

int main(){
    char b;
    cin>>n;
    print_maze(n);
}

void go_through(struct squr **begi){
    struct squr *go_to=(struct squr*)malloc(sizeof(struct squr));
    struct squr *p;
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

    }
}

int go_if(struct squr *now){
    bool up=(1-road[now->x][(now->y)-2])&((now->y)-2>0);
    bool down=(1-road[now->x][now->y+2])&((now->y)+2<n);
    bool left=(1-road[(now->x)-2][now->y])&((now->x)-2>0);
    bool right=(1-road[(now->x)+2][now->y])&((now->x)+2<n);
    int num=0;
    if(up)num++;
    if(down)num++;
    if(left)num++;
    if(right)num++;
    return num;
}

void print_maze(int n){
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

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(road[i][j]){
                cout<<"  ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}
/*void print_maze(){
	cout<<"¡ö  " ;
	for(int i=3;i<=10;i++){
		cout<<"¡ö";
	}
	cout<<endl;
	for(int i=2;i<=9;i++){
		cout<<"¡ö";
		for(int i=2;i<=9;i++){
			cout<<"  ";
		}
		cout<<"¡ö"<<endl;
	}
	for(int i=1;i<=8;i++){
		cout<<"¡ö";
	}
	cout<<"  ¡ö";
}*/


