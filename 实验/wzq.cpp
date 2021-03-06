#include<bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;

#define gc c=getchar()
#define r(x) read(x)
#define ll long long

const int N=19;
const int INF=1e7;
const int Limit=20;
int Board[N][N];
//-1: unused
// 0: black 
// 1: white 

int x,y;
int Step;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

int GetDirection(){
    while(1){
        Sleep(20);
        if(_kbhit()){
            switch(_getch()){
                case 72:return 0;
                case 'w':return 0;
                case 75:return 1;
                case 'a':return 1;
                case 77:return 2;
                case 'd':return 2;
                case 80:return 3;
                case 's':return 3;
                case 13:return 4;
                case 27:exit(0);
            }
        }
    }
}

int GetChoice1(){
    while(1){
        Sleep(20);
        if(_kbhit()){
            switch(_getch()){
                case '1':return 1;
                case '2':return 2;
                case '3':return 3;
                case 27 :exit(0);
            }
        }
    }
}

int GetChoice2(){
    while(1){
        Sleep(20);
        if(_kbhit()){
            switch(_getch()){
                case 'b':return 0;
                case 'w':return 1;
                case 27 :exit(0);
            }
        }
    }
}

int KeyToValue(){
    while(1){
        Sleep(20);
        if(_kbhit()){
            return _getch();
        }
    }
}

inline void Print(){
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

inline bool Check(){
    for(int i=0;i<N;++i){
        for(int j=0;j+4<N;++j){
            if(~Board[i][j]&&Board[i][j]==Board[i][j+1]&&Board[i][j+1]==Board[i][j+2]&&Board[i][j+2]==Board[i][j+3]&&Board[i][j+3]==Board[i][j+4])return 1;
            if(~Board[j][i]&&Board[j][i]==Board[j+1][i]&&Board[j+1][i]==Board[j+2][i]&&Board[j+2][i]==Board[j+3][i]&&Board[j+3][i]==Board[j+4][i])return 1;
        }
    }
    for(int i=0;i+4<N;++i){
        for(int j=0;j+4<N;++j){
            if(~Board[i][j]&&Board[i][j]==Board[i+1][j+1]&&Board[i+1][j+1]==Board[i+2][j+2]&&Board[i+2][j+2]==Board[i+3][j+3]&&Board[i+3][j+3]==Board[i+4][j+4])return 1;
        }
    }
    for(int i=0;i+4<N;++i){
        for(int j=4;j<N;++j){
            if(~Board[i][j]&&Board[i][j]==Board[i+1][j-1]&&Board[i+1][j-1]==Board[i+2][j-2]&&Board[i+2][j-2]==Board[i+3][j-3]&&Board[i+3][j-3]==Board[i+4][j-4])return 1;
        }
    }
    return 0;
}

int dxx[]={1,1,1,0};
int dyy[]={1,-1,0,1};
int dxxx[]={1,1,1,0,-1,-1,-1,0};
int dyyy[]={1,-1,0,1,-1,1,0,-1};

inline int Risk(bool Color,int x,int y){
    int Sum=0;
    for(int d=0;d<4;++d){
        int len=1,cnt=0,nx=x,ny=y;
        for(int i=1;;++i){
            nx+=dxx[d];
            ny+=dyy[d];
            if(nx>=N||nx<0||ny>=N||ny<0||Board[nx][ny]==(Color^1)){
                ++cnt;
                break;
            }
            if(Board[nx][ny]==-1||i==5)break;
            ++len;
        }
        nx=x,ny=y;
        for(int i=1;;++i){
            nx-=dxx[d];
            ny-=dyy[d];
            if(nx>=N||nx<0||ny>=N||ny<0||Board[nx][ny]==(Color^1)){
                ++cnt;
                break;
            }
            if(Board[nx][ny]==-1||i==5)break;
            ++len;
        }
        if(len>=5)return INF;
        if(len==4&&!cnt)return INF-1;
        else if(cnt==2)Sum+=(len!=1);
        else Sum+=pow(10,len-cnt);
    }
    return Sum;
}

pair<pair<int,int>,int> dfs(int dep,bool Color,int MaxLimit){
    vector<pair<int,pair<int,int> > >Points;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(~Board[i][j])continue;
            int Rating=Risk(Color,i,j);
            if(Rating==INF)return {{i,j},INF};
            if(dep&&Rating==INF-1){
                if(dfs(0,Color^1,INF).second!=INF){
                    return {{i,j},INF};
                }
                Rating=-INF;
            }
            Points.push_back({Rating,{i,j}});
        }
    }
    sort(Points.begin(),Points.end());
    int x=-1,y=-1;
    int Max=-1e9;
    for(auto P:Points){
        int i=P.second.first;
        int j=P.second.second;
        int Rating=P.first;
        if(dep){
                Board[i][j]=Color;
                Rating-=dfs(dep-1,Color^1,Rating-Max).second;
                Rating=min(Rating,INF);
                Rating=max(Rating,-INF);
                Board[i][j]=-1;
        } 
        if(Rating>Max)x=i,y=j,Max=Rating;
        if(Max>=MaxLimit)return {{x,y},Max};
    }
    return {{x,y},Max};
}

string Name[2];
double Time[2];

inline void PrintPlayer(const string &s,const double &x){
    int n=s.length();
    for(int i=0;i<n;++i)putchar(s[i]);
    printf("\t%.4lfs\n",x);
}

inline void Computer(const bool &Color){
    clock_t start=clock();
    printf("Step %d\n",Step);
    PrintPlayer("¡ï "+Name[Color],Time[Color]);
    PrintPlayer("¡î "+Name[Color^1],Time[Color^1]);
    if(Step>=2){
        auto tmp=dfs(2,Color,INF);
        x=tmp.first.first;
        y=tmp.first.second;
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
    }
    Board[x][y]=Color;
    ++Step;
    clock_t end=clock();
    Time[Color]=(double)(end-start)/CLOCKS_PER_SEC;
    Print();
}

inline void Player(int Color){
    clock_t start=clock();
    while(1){
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
            return;
        }
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(nx<0||nx>=N||ny<0||ny>=N)continue;
        x=nx,y=ny;
        Print();
    }
}

inline void PlayerVSPlayer(){
    Name[0]="Player 1";
    Name[1]="Player 2";
    memset(Board,-1,sizeof(Board));
    x=y=N/2;
    Step=0;
    Print();
    while(1){
        Player(0);
        if(Check()){
            puts("Player 1 (black) win!");
            break;
        }
        if(Step==N*N){
            puts("Tie!");
            break;
        }
        Player(1);
        if(Check()){
            puts("Player 2 (white) win!");
            break;
        }
    }
}

inline void PlayerVSComputer(){
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
    while(1){
        Color?Computer(0):Player(0);
        if(Check()){
            puts(Color?"You lose!":"You win!");
            break;
        }
        if(Step==N*N){
            puts("Tie!");
            break;
        }
        Color?Player(1):Computer(1);
        if(Check()){
            puts(Color?"You win!":"You lose!");
            break;
        }
    }
}

inline void ComputerVSComputer(){
    Name[0]="Computer 1";
    Name[1]="Computer 2";
    memset(Board,-1,sizeof(Board));
    x=y=N/2;
    Step=0;
    Print();
    while(1){
        Computer(0);
        if(Check()){
            puts("Computer 1 (black) wins!");
            break;
        }
        if(Step==N*N){
            puts("Tie!");
            break;
        }
        Computer(1);
        if(Check()){
            puts("Computer 2 (white) wins!");
            break;
        }
    }
}

inline void Game(){
    srand(time(0));
    system("mode con cols=50 lines=25");
    while(1){
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
}

int main(){
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    Game();
    return 0;
}