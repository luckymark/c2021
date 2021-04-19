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
	puts("\033[33mPress a numble from \"1\" to \"4\" to select a map");
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
    system("cls");
    //printf("111\n");
    freopen("boxsmap.txt","r",stdin);
    char ch=getchar();
    while(ch!=Difficulty+'A'-1)
    ch=getchar();
    scanf("%d %d",&Row,&Col);
    aim=0;
    score=0;
    for(int i=0;i<Row;i++){
        while(ch!='-'&&ch!='#')
        ch=getchar();
        for(int j=0;j<Col;j++){
            //printf("111\n");
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
    fclose(stdin);
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

void PrintMap(){
    for(int i=0;i<Row;i++){
        for(int j=0;j<Col;j++){
            switch (Map[i][j]){
            case 'Y':{printf("\033[31m♂");break;}
            case 'B':{printf("\033[31mB");break;}    
            case '#':{printf("\033[32m#");break;}
            case '$':{printf("\033[32m$");break;}
            case '.':{printf("\033[32m.");break;}
            case 'A':{printf("\033[34mA");break;}
            case '-':{putchar(' ');break;}
            }
        }
        printf("\n");
        //printf("111  %d  111\n",i);
    }
    puts("♂ means the man.");
    puts("# means the wall.");
    puts("$ means the box.");
    puts(". means the aimed location without the box.");
    puts("A means the aimed location with a box.");
    puts("B means the man on an aimed location .");
    puts("\033[33mYou can press \"ESC\" to exit.");
    puts("\033[33mYou can press \"q\" to back to the menu.");
}

void Start(){
    //printf("11111\n");
    while(1){
		system("cls");
		if(score==aim){
			printf("\033[33mCongratulations!\n");
			printf("\033[33mPress \"Enter\" to back to menu\n");
            while(getchar()!='\n');
            Menu();
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
            Map[sx][sy]=(Map[sx][sy]=='Y'?'-':'.');
            Map[nx][ny]='Y';
            sx=nx;
            sy=ny;
        }
        else if(Map[nx][ny]=='$'){
            if(Map[nnx][nny]=='-'){
                Map[nnx][nny]='$';
                Map[nx][ny]='Y';
                Map[sx][sy]=(Map[sx][sy]=='Y'?'-':'.');
                sx=nx;
                sy=ny;
            }
            else if(Map[nnx][nny]=='.'){
                Map[nnx][nny]='A';
                Map[nx][ny]='Y';
                Map[sx][sy]=(Map[sx][sy]=='Y'?'-':'.');
                sx=nx;
                sy=ny;
                score++;
            }
        }
        else if(Map[nx][ny]=='A'){
            if(Map[nnx][nny]=='-'){
                Map[nnx][nny]='$';
                Map[nx][ny]='Y';
                Map[sx][sy]=(Map[sx][sy]=='Y'?'-':'.');
                sx=nx;
                sy=ny;
                score--;
            }
            else if(Map[nnx][nny]=='.'){
                Map[nnx][nny]='A';
                Map[nx][ny]='Y';
                Map[sx][sy]=(Map[sx][sy]=='Y'?'-':'.');
                sx=nx;
                sy=ny;
            }
        }
        else if(Map[nx][ny]=='.'){
                Map[nx][ny]='B';
                Map[sx][sy]=(Map[sx][sy]=='Y'?'-':'.');
                sx=nx;
                sy=ny;
        }
	}
}