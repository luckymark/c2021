#include<bits/stdc++.h>
#include <windows.h>
#include <conio.h>

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

inline void Update();
inline void Game();

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
            	case 'r':return 4;
            	case 'b':return 5;
            	case 27:Update(),exit(0);
            }
        }
    }
}

struct Puzzle{
	vector<string>Origin;//- for space, # for wall, @ for man, . for the goal,$ for box
	int x0,y0;
	vector<string>Map;
	int R,C;
	int x,y;
	int grade;
	int step;
	inline void Init(){
		R=Origin.size();
		C=Origin[0].length();
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				if(Origin[i][j]=='@'){
					x0=i,y0=j;
					Origin[i][j]='-';
					return ;
				}
			}
		}
	}

	inline bool Check(){
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				if(Origin[i][j]=='.'&&Map[i][j]!='$'){
					return 0;
				}
			}
		}
		return 1;
	} 

	inline void Print(){
		system("cls");
		printf("\033[33mYou have used %d steps\n\033[32m",step);
		for(int i=0;i<R;++i){
			for(int j=0;j<C;++j){
				switch(Map[i][j]){
					case '-':putchar(' ');break;
					case '#':putchar('#');break;
					case '@':printf("\033[5m\033[31m@\033[25m\033[32m");break;
					case '.':printf("\033[36mX\033[32m");break;
					case '$':printf("\033[34mO\033[32m");break;
					default :break;
				}
			}
			putchar('\n');
		}
		puts("\033[33mPress [ ESC ] to exit");
		puts("\033[33mPress [ R ] to restart");
		puts("\033[33mPress [ B ] to back to menu");

	}

	inline void Start(){
		step=0;
		x=x0,y=y0;
		Map=Origin;
		Map[x][y]='@';
		while(1){
			Print();
			if(Check()){
				printf("\033[33mCongratulations!\n");
				if(!grade||grade>step){
					puts("New record!");
					grade=step;
				}
				break;
			}
			int d=GetDirection();
			if(d==4){
				Start();
				return;
			}
			if(d==5){
				Game();
				return;
			}
			int nx=x+dx[d];
			int ny=y+dy[d];
			switch(Map[nx][ny]){
				case '-':{
					Map[x][y]=((Origin[x][y]=='.')?'.':'-');
					Map[nx][ny]='@';
					x=nx,y=ny,++step;
					break;
				}
				case '.':{
					Map[x][y]=((Origin[x][y]=='.')?'.':'-');
					Map[nx][ny]='@';
					x=nx,y=ny,++step;
					break;
				}
				case '$':{
					if(Map[nx+dx[d]][ny+dy[d]]=='-'||Map[nx+dx[d]][ny+dy[d]]=='.'){
						Map[nx+dx[d]][ny+dy[d]]='$';
						Map[nx][ny]='@';
						Map[x][y]=((Origin[x][y]=='.')?'.':'-');
						x=nx,y=ny;
						++step;
					}
				}
				default :break;
			}
			
		}
	}

}null;

vector<Puzzle> Puzzles;
char str[105];

inline void Init(){
	freopen("Maps.txt","r",stdin);//From http://sokoban.cn/
	Puzzle P=null;
	while(scanf("%s",str)!=EOF){
		if(isdigit(str[0])){
			P.Init();
			Puzzles.push_back(P);
			P=null;
		}
		else {
			P.Origin.push_back(string(str));
		}
	}
	fclose(stdin);

	freopen("Grades.txt","r",stdin);
	for(int i=0;i<Puzzles.size();++i){
		scanf("%d",&Puzzles[i].grade);
	}
	fclose(stdin);
}

inline void Update(){
	freopen("Grades.txt","w",stdout);
	for(int i=0;i<Puzzles.size();++i){
		printf("%d ",Puzzles[i].grade);
	}
	puts("");
	fclose(stdout);
}

int GetChoice1(){
    while(1){
    	Sleep(20);
        if(_kbhit()){
            switch(_getch()){
            	case '1':return 1;
            	case '2':return 2;
            	case 27:Update(),exit(0);
            }
        }
    }
}

int GetChoice2(){
    while(1){
    	Sleep(20);
        if(_kbhit()){
        	char x=_getch();
        	if(isdigit(x)){
        		x-='0';
            	if(0<=x&&x<Puzzles.size()){
            		return x;
            	}
            }
            else if(x==27)Update(),exit(0);
        }
    }
}

inline void Level(){
	system("cls");
	printf("\033[33mPress [ 0 ] ~ [ %d ] to choose the level",Puzzles.size()-1);
	Puzzles[GetChoice2()].Start();
}

inline void Grade(){
	system("cls");
	printf("\033[33m");
	for(int i=0;i<Puzzles.size();++i){
		if(Puzzles[i].grade)printf("Level %d: %d steps\n",i,Puzzles[i].grade);
		else printf("Level %d: You haven't solve it yet.\n",i);
	}
}

inline void Game(){
	while(1){
		system("cls");
		puts("Press [ 1 ] to choose the level");
		puts("Press [ 2 ] to check your grade");
		puts("Press [ ESC ] anytime to exit");
		switch(GetChoice1()){
			case 1:Level();break;
			case 2:Grade();break;
		}
		puts("\nPress any key to continue");
		while(1){
	    	Sleep(20);
	        if(_kbhit())break;
	    }
	}
}

inline void Menu(){
	system("cls");
	puts("\033[33mWelcome to the Push Boxes Game!");
	puts("\"\033[32m#\033[33m\" is wall");
	puts("\" \" is road");
	puts("\"\033[34mO\033[33m\" is box");
	puts("\"\033[36mX\033[33m\" is target");
	puts("\"\033[5m\033[31m@\033[25m\033[33m\" is your position");
	puts("Press Arrow Key or [ W ], [ A ], [ S ], [ D ] to move");
	puts("\nPress any key to continue");
	while(1){
    	Sleep(20);
        if(_kbhit())break;
    }
    Game();
}

int main(){
	Init();
	Menu();
	return 0;
}