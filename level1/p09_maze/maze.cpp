#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>

using namespace std;

#define gc c=getchar()
#define r(x) read(x)
#define ll long long

template<typename T>
inline void read(T&x){
	x=0;T k=1;char gc;
	while(!isdigit(c)){if(c=='-')k=-1;gc;}
	while(isdigit(c)){x=x*10+c-'0';gc;}x*=k;
}

const int N=105;

int fa[N*N];
bool Map[N][N];
int PointID[N][N];

struct Edges{
	int u,v,x,y;
};

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

inline bool uni(const int &x,const int &y){
	if(find(x)^find(y)){
		fa[fa[x]]=fa[y];
		return 1;
	}
	return 0;
}

int R;
int C;

int sx,sy,tx,ty,x,y,step;

inline void GenerateMap(){
	for(int i=0;i<=R;++i){
		for(int j=0;j<=C;++j){
			Map[i][j]=1;
		}
	}
	int tot=0;
	for(int i=1;i<R;i+=2){
		for(int j=1;j<C;j+=2){
			Map[i][j]=0;
			PointID[i][j]=++tot;
		}
	}
	for(int i=1;i<=tot;++i)fa[i]=i;
	vector<Edges>Edge;
	for(int i=1;i<R;i+=2){
		for(int j=1;j<C;j+=2){
			if(i+2<R)Edge.push_back({PointID[i][j],PointID[i+2][j],i+1,j});
			if(j+2<C)Edge.push_back({PointID[i][j],PointID[i][j+2],i,j+1});
		}
	}
	random_shuffle(Edge.begin(),Edge.end());
	for(auto &e:Edge){
		if(uni(e.u,e.v))Map[e.x][e.y]=0;
	}
	for(int i=0;i<=R;++i){
		if(Map[i][1])continue;
		for(int j=R;~j;--j){
			if(Map[j][C-1])continue;
			if(find(PointID[i][1])!=find(PointID[j][C-1]))continue;
			sx=i,sy=0;
			tx=j,ty=C;
			Map[sx][sy]=0;
			Map[tx][ty]=0;
			return ;
		}
	}
	GenerateMap();
}

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

int GetDirection(){
    while(1){
    	Sleep(20);
        if(_kbhit()){
            switch(_getch()){
            	case 72:return 0;
            	case 75:return 1;
            	case 77:return 2;
            	case 80:return 3;
            	case 27:exit(0);
            }
        }
    }
}

int GetChoice(){
    while(1){
    	Sleep(20);
        if(_kbhit()){
            switch(_getch()){
            	case '1':return 1;
            	case '2':return 2;
            	case '3':return 3;
            	case 27:exit(0);
            }
        }
    }
}

inline void Print(){
	printf("\033[33mYou have used %d steps\n\033[32m",step);
	for(int i=0;i<=R;++i){
		for(int j=0;j<=C;++j){
			if(i==x&&j==y)printf("\033[5m\033[31m%c\033[25m\033[32m",'@');
			else putchar(Map[i][j]?'#':' ');
		}
		puts("");
	}
}

inline void Difficulty(){
	for(int i=0;i<=R;++i){
		for(int j=0;j<=C;++j){
			Map[i][j]=0;
		}
	}
	system("cls");
	puts("Please choose the difficulty");
	puts("Input \"1\" for Easy Mode");
	puts("Input \"2\" for Medium Mode");
	puts("Input \"3\" for Hard Mode");
	puts("You can press \"ESC\" anytime to exit");
	switch(GetChoice()){
		case 1:{R=10,C=20;break;}
		case 2:{R=20,C=40;break;}
		case 3:{R=30,C=60;break;}
	}
	GenerateMap();
	x=sx;
	y=sy;
	step=0;
}

inline void Menu(){
	system("cls");
	puts("\033[33mWelcome to my maze!");
	puts("\"\033[32m#\033[33m\" is wall");
	puts("\"\033[32m \033[33m\" is road");
	puts("\"\033[5m\033[31m@\033[25m\033[33m\" is your position");
	puts("Press arrow key to move");
	puts("Press \"Enter\" to start");
	while(getchar()^'\n');
	Difficulty();
}

int main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	system("mode con cols=61 lines=35");
	srand(time(NULL));
	Menu();
	while(1){
		system("cls");
		Print();
		int d=GetDirection();
		int nx=x+dx[d];
		int ny=y+dy[d];
		if(ny>ty){
			printf("\033[33mCongratulations!\n");
			puts("Press \"Enter\" to back to menu");
			while(getchar()^'\n');
			Difficulty();
		}
		else if(~ny&&!Map[nx][ny])x=nx,y=ny,++step;
	}
	return 0;
}