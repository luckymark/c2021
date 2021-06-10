#include "Graphic.h"

string Name[2];
double Time[2];

void PrintPlayer(const string &s,const double &x){
    int n=s.length();
    for(int i=0;i<n;++i)putchar(s[i]);
    printf("\t%.4lfs\n",x);
}

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
    printf("Step %d\n",Step);
    PrintPlayer("¡ï "+Name[Step&1],Time[Step&1]);
    PrintPlayer("¡î "+Name[Step&1^1],Time[Step&1^1]);
}

bool Computer(const bool &Color){
    clock_t start=clock();
    if(Step>=2){
        F.clear();
        if(Step>=7){
            auto tmp=newdfs(9,Color,INF,0);
            x=tmp.second.first;
            y=tmp.second.second;
        }
        else {
            // auto tmp=olddfs(DeepLimit,Color,INF,0);

            auto tmp=newdfs(7,Color,INF,0);
            x=tmp.second.first;
            y=tmp.second.second;
        }
        // if(tmp.first<=-INF*0.9)return 1;
    }
    else if(Step==1){
        if(x==N/2&&y==N/2){
            while(1){
                int d=rand()%8;
                int nx=x+dxxx[d];
                int ny=y+dyyy[d];
                if(nx>=0&&ny>=0&&nx<N&&ny<N){
                    x=nx,y=ny;
                    break;
                }
            }
        }
        else {
            if(x>N/2)--x;
            else if(x<N/2)++x;
            if(y>N/2)--y;
            else if(y<N/2)++y;
        }
        // x--;
        // y++;
    }
    Board[x][y]=Color;
    ++Step;
    History[Step]={x,y};
    clock_t end=clock();
    Time[Color]=(double)(end-start)/CLOCKS_PER_SEC;
    Print();
    return 0;
}

int BackStep;

bool Player(int Color){
    clock_t start=clock();
    while(1){
        Print();
        int d=GetDirection();
        if(d==4){
            if(~Board[x][y])continue;
            Board[x][y]=Color;
            ++Step;
            History[Step]={x,y};
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
        if(d==7){
            if(Step<BackStep)continue;
            Board[History[Step].first][History[Step].second]=-1;
            --Step;
            if(BackStep==2){
                Board[History[Step].first][History[Step].second]=-1;
                --Step;
                x=History[Step].first;
                y=History[Step].second;
                return Player(Color);
            }
            else {
                x=History[Step].first;
                y=History[Step].second;
                Print();
                return 0;
            }
        }
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(nx<0||nx>=N||ny<0||ny>=N)continue;
        x=nx,y=ny;
    }
    return 0;
}

void PlayerVSPlayer(){
    human=1;
    Name[0]="Player 1";
    Name[1]="Player 2";
    memset(Board,-1,sizeof(Board));
    x=y=N/2;
    Step=0;
    BackStep=1;
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
    human=1;
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
    BackStep=2;
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
    human=0;
    Name[0]="Computer 1";
    Name[1]="Computer 2";
    memset(Board,-1,sizeof(Board));
    x=y=N/2;
    Step=0;
    bool Now=0;
    Print();
    while(1){
        if(_kbhit()){
            switch(_getch()){
                case 27:return ;
            }
        }
        if(Now){
            if(Computer(1)){
                puts("Computer 2 (white) give up!");
                break;
            }
            if(Check()){
                puts("Computer 2 (white) wins!");
                break;
            }
        }
        else {
            if(Computer(0)){
                puts("Computer 1 (black) give up!");
                break;
            }
            if(Check()){
                puts("Computer 1 (black) wins!");
                break;
            }
        }
        if(Step==N*N){
            puts("Tie!");
            break;
        }
        Now^=1;
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
    History[0]={N/2,N/2};
    Base[0]=1;
    for(int i=1;i<10;++i)Base[i]=Base[i-1]*3;
    memset(Data,-1,sizeof(Data));
    while(1)Game();
}
