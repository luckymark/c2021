#include "pushboxs.h"
using namespace std;


const int N=20;
int Col,Row;
int sx,sy;
int score=0,aim=0;
int cx[]={-1,0,0,1};
int cy[]={0,-1,1,0};
char Map[N][N];
int Difficulty=0;

void Menu(){
    system("cls");
    puts("\033[33mYou are requested to push boxs to the aimed location.");
    puts("\033[33mPress \"Enter\" to start your journey!");
    while(getchar()=='\n')
    return;
}

void Differ(){
    system("cls");
	puts("\033[33mPress a numble from \"1\" to \"5\" to select a map");
    puts("\033[33m----------------------------------------------------");
    puts("\033[33mYou can press \"ESC\" to exit");
    char ch=_getch();
    while(ch<'1'||ch>'5'){
        if(ch==27){
            exit(0);
        }
        puts("\033[33mYour input is invalid");
        ch=_getch();
    }
    Difficulty=ch-'0';
    return;
}

void CreateMap(){
    freopen("boxsmap.txt","r",stdin);
    char ch=getchar();
    while(ch!=Difficulty||ch<'1'||ch>'5')
    ch=getchar();
    scanf("%d %d",&Row,&Col);
    for(int i=0;i<Row;i++){
        while(ch!='-'&&ch!='#')
        ch=getchar();
        for(int j=0;j<Col;j++){
            Map[i][j]=ch;
            if(ch=='Y'){
                sx=i;
                sy=j;
            }
            else if(ch=='$'){
                aim++;
            }
            ch=getchar();
        }
    }
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
            CreateMap();
            //start to play
            Start();
        }
       	case 27:exit(0);
        default:{
            return Getdir();
        }
    }
}

void PrintMaze(){
    for(int i=0;i<Row;i++){
        for(int j=0;j<Col;j++){
            if(i==sx&&j==sy){
                printf("\033[31m♂");
                putchar(' ');
            }
            else if(Map[i][j]=='#'){
                printf("\033[32m回");
            }
            else if(Map[i][j]=='$'){
                printf("☆");
            }
            else if(Map[i][j]=='.'){
                printf("◎");
            }
            else if(Map[i][j]=='A'){
                printf("★");
            }
            else if(Map[i][j]=='-'){
                printf("  ");
            }
        }
        printf("\n");
    }
    puts("♂ means the man.");
    puts("回 means the wall.");
    puts("☆ means the box.");
    puts("◎ means the aimed location without the box.");
    puts("★ means the aimed location with a box.");
    puts("\033[33mYou can press \"ESC\" to exit.");
    puts("\033[33mYou can press \"q\" to back to the menu.");
}

void Start(){
    while(1){
		system("cls");
		if(score==aim){
			printf("\033[33mCongratulations!\n");
			puts("\033[33mPress \"Enter\" to back to menu");
			while(getchar()!='\n');
			Differ();
            //creat the maze
            CreateMap();
            //start to play
            Start();
		}
		PrintMap();
		int d=Getdir();
		int nx=sx+cx[d],nnx=sx+2*cx[d];//nx为人物的移动，nnx为箱子的移动
		int ny=sy+cy[d],nny=sy+2*cy[d];
	    if(Map[nx][ny]=='-'){
            Map[sx][sy]='-';
            Map[nx][ny]='Y';
            sx=nx;
            sy=ny;
        }
        else if(Map[nx][ny]=='$'){
            if(Map[nnx][nny]=='-'){
                Map[nnx][nny]='$';
                Map[nx][ny]='Y';
                Map[sx][sy]='-';
                sx=nx;
                sy=ny;
            }
            else if(Map[nnx][nny]=='.'){
                Map[nnx][nny]='A';
                Map[nx][ny]='Y';
                Map[sx][sy]='-';
                sx=nx;
                sy=ny;
                score++;
            }
        }
        else if(Map[nx][ny]=='A'){
            if(Map[nnx][nny]=='-'){
                Map[nnx][nny]='$';
                Map[nx][ny]='Y';
                Map[sx][sy]='-';
                sx=nx;
                sy=ny;
                score--;
            }
            else if(Map[nnx][nny]=='.'){
                Map[nnx][nny]='A';
                Map[nx][ny]='Y';
                Map[sx][sy]='-';
                sx=nx;
                sy=ny;
            }
        }
	}
}