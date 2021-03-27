#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>

const int N=101;
int RC,Rank=0;
int sx,sy;
int cx[]={-1,0,0,1};
int cy[]={0,-1,1,0};
int Map[N][N];
int Difficulty=0;
void Menu();
void Differ();
void CreateMaze(int,int);
void PrintMaze();
void Start();
int Getdir();

int main(){
    //generate the console
    /*int h=80,w=80;
	char chCmd[32];
	sprintf(chCmd,"mode con cols=%d lines=%d",h,w);
	system(chCmd);*/
    srand(time(NULL));
    //generate the menu
    Menu();
    //choose the difficulty
    Differ();
    //creat the maze
    CreateMaze(2,2);
    //print the maze
    PrintMaze();
    //start to play
    Start();
    return 0;
}

void Menu(){
    system("cls");
    puts("As we all know, HIMCRH is a fan of Coca-Cola.");
    puts("Unfortunately, he is trapped in a maze.");
    puts("If he can't leave the maze, he can only drink the Pepsi.");
    puts("You, a kind freshman of UESTC, decide to help him.");
    puts("Press \"Enter\" to start your journey!");
    while(getchar()=='\n')
    return;
}

void Differ(){
    system("cls");
    puts("No pain, no gain; more pain, more gain!");
    puts("There are three difficulties for you to choose:");
	puts("Input \"1\" for a little bottle of Coca-Cola");
	puts("Input \"2\" for a big bottle of Coca-Cola");
	puts("Input \"3\" for a ton of Coca-Cola");
    puts("Please make this choice with your conscience!");
    puts("----------------------------------------------------");
    puts("You can press \"ESC\" to exit");
    char ch=_getch();
    while(ch<'1'||ch>'3'){
        if(ch==27){
            exit(0);
        }
        puts("Your input is invalid");
        ch=getchar();
    }
    Difficulty=ch-'0';
    switch(Difficulty){
		case 1:{
            RC=24;
            break;
            }
		case 2:{
            RC=44;
            break;
            }
		case 3:{
            RC=64;
            break;
            }
	}
    for (int i=1;i<RC-1;i++){
        for(int j=0;j<RC;j++){
            Map[i][j]=1;
        }
    }
    for (int i = 0; i < RC; i++){
		Map[i][0] = 0;
		Map[0][i] = 0;
		Map[i][RC - 1] = 0;
		Map[RC - 1][i] = 0;
	}
    sx=2;
    sy=1;
    return;
}

void CreateMaze(int x,int y){
    Map[x][y] = 0;

	int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
	for (int i = 0; i < 4; i++) {
		int r = rand() % 4;
		int temp = dir[0][0];
		dir[0][0] = dir[r][0];
		dir[r][0] = temp;
 
		temp = dir[0][1];
		dir[0][1] = dir[r][1];
		dir[r][1] = temp;
	}
	for (int i = 0; i < 4; i++) {
		int dx = x;
		int dy = y;
		int range = 1 + (Rank == 0 ? 0 : rand() % Rank);
		while (range>0) {
            dx += dir[i][0];
			dy += dir[i][1];
			//排除掉回头路
			if (Map[dx][dy] == 0) {
				break;
			}
			//判断是否挖穿路径
			int count = 0;
			for (int j = dx - 1; j < dx + 2; j++) {
				for (int k = dy - 1; k < dy + 2; k++) {
					//abs(j - dx) + abs(k - dy) == 1 确保只判断九宫格的四个特定位置
					if (abs(j - dx) + abs(k - dy) == 1 && Map[j][k] == 0) {
						count++;
					}
				}
			}
			if (count > 1) {
				break;
			}
			//确保不会挖穿时，前进
			--range;
			Map[dx][dy] = 0;
		}
		//没有挖穿危险，以此为节点递归
		if (range <= 0) {
			CreateMaze(dx, dy);
		}
	}
}

void PrintMaze(){
    system("cls");
    Map[2][1]=0;
    for(int i=RC-3;i>=0;i--){
        if(Map[i][RC-3]==0){
            Map[i][RC-2]=0;
            break;
        }
    }
    for(int i=1;i<RC-1;i++){
        for(int j=1;j<RC-1;j++){
            if(i==sx&&j==sy){
                printf("Y ");
            }
            else if(Map[i][j]==1){
                printf("回");
            }
            else if(Map[i][j]==0){
                printf("  ");
            }
        }
        printf("\n");
    }
    puts("You can press \"ESC\" to exit");
}

int Getdir(){
    char ch=_getch();
    switch(ch){
    	case 72:return 0;
    	case 75:return 1;
        case 77:return 2;
        case 80:return 3;
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
		PrintMaze();
		int d=Getdir();
		int nx=sx+cx[d];
		int ny=sy+cy[d];
		if(ny==RC-1){
			printf("\033[33mCongratulations!\n");
			puts("Press \"Enter\" to back to menu");
			while(getchar()^'\n');
			Differ();
		}
		else if(!Map[nx][ny]){
            sx=nx;
            sy=ny;
        }
	}
}