#include "maze.h"
using namespace std;

const int N=101;
int RC;
int sx=1,sy=1;
int cx[]={-1,0,0,1};
int cy[]={0,-1,1,0};
int Map[N][N];
int Difficulty=0;

void Menu(){
    puts("\033[33mAs we all know, HIMCRH is a fan of \033[31mCoca-Co1a.");
    puts("\033[33mUnfortunately, he is trapped in a maze.");
    puts("\033[33mIf he can't leave the maze, he can only drink the \033[34mPepsi.");
    puts("\033[33mYou, a kind freshman of UESTC, decide to help him.");
    puts("\033[33mPress \"Enter\" to start your journey!");
    while(getchar()=='\n')
    return;
}

void Differ(){
    system("cls");
    puts("\033[33mNo pain, no gain; more pain, more gain!");
    puts("\033[33mThere are three difficulties for you to choose:");
	puts("\033[33mInput \"1\" for a little bottle of \033[31mCoca-Co1a");
	puts("\033[33mInput \"2\" for a big bottle of \033[31mCoca-Cola");
	puts("\033[33mInput \"3\" for a ton of \033[31mCoca-Co1a");
    puts("\033[33mPlease make this choice with your conscience!");
    puts("\033[33m----------------------------------------------------");
    puts("\033[33mYou can press \"ESC\" to exit");
    char ch=_getch();
    while(ch<'1'||ch>'3'){
        if(ch==27){
            exit(0);
        }
        puts("\033[33mYour input is invalid");
        ch=_getch();
    }
    Difficulty=ch-'0';
    switch(Difficulty){
		case 1:{
            RC=23;
            break;
            }
		case 2:{
            RC=43;
            break;
            }
		case 3:{
            RC=53;
            break;
            }
	}
    return;
}

void CreateMaze(){
    sx=1;
    sy=1;
    srand(time(NULL));
    for(int i=0;i<RC;i++){
        for(int j=0;j<RC;j++){
        Map[i][j]=1;
        }
    }
    Map[1][1]=0;
    vector<cell> v;//存储未连接的单元格
    v.push_back({3,1});
    v.push_back({1,3});
    //printf("\033[33m111\n");
    while(v.size()){
        //printf("\033[33m111\n");
        int t=rand()%v.size();
        cell c=v[t];//随机选中未连接的单元格c
        if(Map[c.x][c.y]==0){
            v.erase(v.begin()+t);
            continue;
        }
        vector<cell> vlink;//存储c周围已连接的单元格
        for(int i=-2;i<=2;i+=2){
            int dx=c.x+i;
            if(dx<=0||dx>=RC-1)
            continue;
            for(int j=-2;j<=2;j+=2){
                if((i!=0&&j!=0)||(i==0&&j==0))
                continue;
                int dy=c.y+j;
                //printf("\033[33m%d %d\n",dx,dy);
                if(dy<=0||dy>=RC-1)
                continue;
                if(Map[dx][dy]==0)
                vlink.push_back({i,j});
                else
                v.push_back({dx,dy});
            }
        }
        int tt=rand()%vlink.size();
        cell choose=vlink[tt];//随机选中一个
        Map[c.x+choose.x/2][c.y+choose.y/2]=0;
        Map[c.x][c.y]=0;
        v.erase(v.begin()+t);
    }
    Map[RC-2][RC-1]=0;
}

void PrintMaze(){
    for(int i=0;i<RC;i++){
        for(int j=0;j<RC;j++){
            if(i==sx&&j==sy){
                printf("\033[31mY ");
            }
            else if(Map[i][j]==1){
                printf("\033[32m回");
            }
            else if(Map[i][j]==0){
                printf("  ");
            }
        }
        printf("\n");
    }
    puts("\033[33mYou can press \"ESC\" to exit.");
    puts("\033[33mYou can press \"q\" to back to the menu.");
}

int Getdir(){
    char ch=_getch();
    switch(ch){
    	case 72:return 0;
    	case 75:return 1;
        case 77:return 2;
        case 80:return 3;
        case 'q':{
            Differ();
            //creat the maze
            CreateMaze();
            //start to play
            Start();
        }
       	case 27:exit(0);
        default:{
            return Getdir();
        }
    }
}

void Start(){
    Map[2][1]=0;
    while(1){
		system("cls");
		if(sy==RC-1&&sx==RC-2){
			printf("\033[33mCongratulations!\n");
			puts("\033[33mPress \"Enter\" to back to menu");
			while(getchar()!='\n');
			Differ();
            //creat the maze
            CreateMaze();
            //start to play
            Start();
		}
		PrintMaze();
		int d=Getdir();
		int nx=sx+cx[d];
		int ny=sy+cy[d];
	    if(!Map[nx][ny]){
            sx=nx;
            sy=ny;
        }
	}
}