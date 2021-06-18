#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>
#include<windows.h>
using namespace std;

int maze[100][100]={0};
bool box[100][100]={0};
bool road[100][100]={0};
bool goal[100][100]={0};
int n,finish,now_x,now_y,step;

void go_up();
void go_down();
void go_right();
void go_left();
void maze_print(int x,int y);


int main(){
    char b;
    int m,read,x;
    bool end=0;
    FILE *fp;
	char str[10000]={' '};
	read=0;
	step=0;
	m=0;x=0;
	fp=fopen("C:\\Users\\Lenovo\\Desktop\\C程作业\\c2021\\level1\\p10_pushBoxes\\map.txt","rt");
    while(fgets(str, 100, fp)!=NULL) {
    	if(read==0){
    		n=int(str[0])-48;
		}
        printf("%s", str);
        for(int i=0;i<=100;i++){
    	    if((str[i]>='0'&&str[i]<='9')&&(read!=0||i!=0)){
    		    maze[x][m]=int(str[i])-48;
    		    road[x][m]=1;
    		    switch (maze[x][m]){
    		    	case 1:
    		    		road[x][m]=0;
    		    		break;
    		    	case 2:
    		    		now_x=x;
						now_y=m;
						break;
					case 3:
					    box[x][m]=1;
						break;
					case 4:
					    goal[x][m]=1;
						break;	
				}
    		    m++;
		    }
		    if(m==n){
			    m=0;
			    x++;
		    }
	    }
	    read++;
    }
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
        finish=1;
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		if(box[i][j]){
        			if(!goal[i][j]) finish=0;
				}
			}
		} 
		step++;
		if(finish==1)break;
    }
    cout<<"Congratulation!!"<<endl;
    cout<<"通关所用步数为"<<step;
	fprintf(fp,"%d",step);
    fclose(fp);
    return 0;
}


void go_up(){
     if(road[now_x-1][now_y]){
        if(box[now_x-1][now_y]){
        	if(road[now_x-2][now_y]){
        		box[now_x-1][now_y]=0;
        		box[now_x-2][now_y]=1;
        		now_x=now_x-1;
			}
		}
		else now_x=now_x-1;
     }
}

void go_down(){
    if(road[now_x+1][now_y]){
        if(box[now_x+1][now_y]){
        	if(road[now_x+2][now_y]){
        		box[now_x+1][now_y]=0;
        		box[now_x+2][now_y]=1;
        		now_x=now_x+1;
			}
		}
		else now_x=now_x+1;
     }
}

void go_left(){
    if(road[now_x][now_y-1]){
        if(box[now_x][now_y-1]){
        	if(road[now_x][now_y-2]){
        		box[now_x][now_y-1]=0;
        		box[now_x][now_y-2]=1;
        		now_y=now_y-1;
			}
		}
		else now_y=now_y-1;
     }
}

void go_right(){
    if(road[now_x][now_y+1]){
        if(box[now_x][now_y+1]){
        	if(road[now_x][now_y+2]){
        		box[now_x][now_y+1]=0;
        		box[now_x][now_y+2]=1;
        		now_y=now_y+1;
			}
		}
		else now_y=now_y+1;
     }
}

void maze_print(int x,int y){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!road[i][j]){
            	cout<<"O ";
			}
			else if(i==x&&j==y){
				cout<<"P ";
			}
			else if(box[i][j]){
				cout<<"H ";
			}
			else if(goal[i][j]){
				cout<<"# ";
			}
			else cout<<"  "; 
        }
        cout<<endl;
    }
}
