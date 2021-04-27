#include "Graphic.h"

void Print(){
    system("cls");
    printf("\033[43m\033[30m");
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(x==i&&y==j)printf("\033[44m");
            if(~Board[i][j])printf(Board[i][j]?"\033[37m¡ñ\033[30m":"¡ñ");
            else printf("£«");
            if(x==i&&y==j)printf("\033[43m");
        }
        putchar('\n');
    }
    printf("\033[0m");
}

string Name[2];
double Time[2];

void PrintPlayer(const string &s,const double &x){
    int n=s.length();
    for(int i=0;i<n;++i)putchar(s[i]);
    printf("\t%.4lfs\n",x);
}

bool Computer(const bool &Color){
    clock_t start=clock();
    printf("Step %d\n",Step);
    PrintPlayer("¡ï "+Name[Color],Time[Color]);
    PrintPlayer("¡î "+Name[Color^1],Time[Color^1]);
    if(Step>=2){
        F.clear();
        // if(Step&1){//w
	       //  auto tmp=olddfs(DeepLimit,Color,INF,0);
        //     x=tmp.second.first;
        //     y=tmp.second.second;
        // }
        // else {//b
            auto tmp=newdfs(9,Color,INF,0);
	        x=tmp.second.first;
	        y=tmp.second.second;
        // }
        // if(tmp.first<=-INF*0.9)return 1;
    }
    else if(Step==1){
        while(1){
            int d=rand()%8;
            int nx=x+dxxx[d];
            int ny=y+dyyy[d];
            if(nx>=0&&ny>=0&&nx<N&&ny<N){
                x=nx,y=ny;
                break;
            }
        }
        // x--;
        // y--;
    }
    Board[x][y]=Color;
    ++Step;
    clock_t end=clock();
    Time[Color]=(double)(end-start)/CLOCKS_PER_SEC;
    Print();
    return 0;
}

bool Player(int Color){
    clock_t start=clock();
    while(1){
        Print();
        printf("Step %d\n",Step);
        PrintPlayer("¡ï "+Name[Color],Time[Color]);
        PrintPlayer("¡î "+Name[Color^1],Time[Color^1]);
        int d=GetDirection();
        if(d==4){
            if(~Board[x][y])continue;
            Board[x][y]=Color;
            ++Step;
            clock_t end=clock();
            Time[Color]=(double)(end-start)/CLOCKS_PER_SEC;
            Print();
            return 0;
        }
        if(d==5)return 1;
        if(d==6){
            system("cls");
            Print();
            return Computer(Color);
        }
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(nx<0||nx>=N||ny<0||ny>=N)continue;
        x=nx,y=ny;
    }
    return 0;
}

void PlayerVSPlayer(){
    Name[0]="Player 1";
    Name[1]="Player 2";
    memset(Board,-1,sizeof(Board));
    x=y=N/2;
    Step=0;
    Print();
    while(1){
        if(Player(0)){
            puts("Player 1 (black) give up!");
            break;
        }
        if(Check()){
            puts("Player 1 (black) win!");
            break;
        }
        if(Step==N*N){
            puts("Tie!");
            break;
        }
        if(Player(1)){
            puts("Player 2 (white) give up!");
            break;
        }
        if(Check()){
            puts("Player 2 (white) win!");
            break;
        }
    }
}

void PlayerVSComputer(){
    memset(Board,-1,sizeof(Board));
    system("cls");
    puts("Please choose a game mode");
    puts("Press [ B ] choose black");
    puts("Press [ W ] choose white");
    puts("Press [ ESC ] anytime to exit");
    bool Color=GetChoice2();
    Name[Color]="Player";
    Name[Color^1]="Computer";
    x=y=N/2;
    Step=0;
    Print();
    if(Color){
        while(1){
            if(Computer(0)){
                puts("Computer gives up! You win!");
                break;
            }
            if(Check()){
                puts("You lose!");
                break;
            }
            if(Step==N*N){
                puts("Tie!");
                break;
            }
            if(Player(1)){
                puts("You give up! You lose!");
                break;
            }
            if(Check()){
                puts("You win!");
                break;
            }
        }
    }
    else {
        while(1){
            if(Player(0)){
                puts("You give up! You lose!");
                break;
            }
            if(Check()){
                puts("You win!");
                break;
            }
            if(Step==N*N){
                puts("Tie!");
                break;
            }
            if(Computer(1)){
                puts("Computer gives up! You win!");
                break;
            }
            if(Check()){
                puts("You lose!");
                break;
            }
        }
    }
}

void ComputerVSComputer(){
    Name[0]="Computer 1";
    Name[1]="Computer 2";
    memset(Board,-1,sizeof(Board));
    x=y=N/2;
    Step=0;
    Print();
    while(1){
        if(Computer(0)){
            puts("Computer 1 (black) give up!");
            break;
        }
        if(Check()){
            puts("Computer 1 (black) wins!");
            break;
        }
        if(Step==N*N){
            puts("Tie!");
            break;
        }
        if(Computer(1)){
            puts("Computer 2 (white) give up!");
            break;
        }
        if(Check()){
            puts("Computer 2 (white) wins!");
            break;
        }
    }
}

void Game(){
    system("cls");
    puts("Please choose a game mode");
    puts("Press [ 1 ] for the Player Vs Player Mode");
    puts("Press [ 2 ] for the Player Vs Computer Mode");
    puts("Press [ 3 ] for the Computer Vs Computer Mode");
    puts("Press [ ESC ] anytime to exit");
    switch(GetChoice1()){
        case 1:PlayerVSPlayer();break;
        case 2:PlayerVSComputer();break;
        case 3:ComputerVSComputer();break;
    }
    system("pause");
}

void Menu(){
    // system("mode con cols=60 lines=30");
    system("cls");
    puts("Welcome to the Wuziqi game!");
    puts("Press Arrow Key or [ W ], [ A ], [ S ], [ D ] to move");
    puts("Press [ Enter or Space ] to confirm");
    puts("Press [ H ] to get hint");
    puts("Press [ G ] to give up");
    system("pause");
    srand(time(0));
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            for(int k=0;k<5;++k){
                Hash[0][i][j]<<=15;
                Hash[1][i][j]<<=15;
                Hash[0][i][j]|=rand();
                Hash[1][i][j]|=rand();
            }
        }
    }
    while(1)Game();
}
