#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
const int N = 105;
struct Edges{
    int u,v,x,y;
};
int R,C,x,y,sx,sy,step;
bool Map[N][N];
int Map_id[N][N];
int fa[N*N];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int get_direction();//获取方向键
void menu();//菜单
void Difficulty();//难度选择
int get_choice();//获取难度系数
void Map_create();//创建地图
int Con(int &x,int &y);//连通路
int find(int x);
void Print();

int main(){
    srand(time(NULL));
    menu();
    Difficulty();
    while(1){
        system("cls");
        Print();
        int d=get_direction();
        int nx=x+dx[d];
		int ny=y+dy[d];
		if(ny>sy){
			printf("\033[33mCongratulations!\n");
			puts("Press \"Enter\" to back to menu");
			while(getchar()^'\n');
			Difficulty();
		}
		else if(ny>=0&&!Map[nx][ny]){
            x=nx,y=ny;
            step++;
        }
    }
    return 0;
}

int get_direction(){
    while(1){
        Sleep(20);
        //kbhit：检测到键盘有读入
        if(kbhit()){
            switch (getch()){
                case 72:return 0;//up
                case 80:return 1;//down
                case 75:return 2;//left
                case 77:return 3;//right
                case 0x1B:exit(0);//esc
            }
        }
    }
}
int get_choice(){
    while(1){
        Sleep(20);
        if(kbhit()){
            switch(getch()){
                case '1':return 1;
                case '2':return 2;
                case '3':return 3;
                case 0x1B:exit(0);
            }
        }
    }
}
void menu(){
    system("cls");
    //\033[ ; m ____ \033[0m    调用颜色
    puts("\033[33mTeacher Zou lost his way in the library");
    puts("\033[33mLet's help him find the library exit");
    puts("\"\033[32m#\033[33m\" is wall");
    puts("\"\033[32m \033[33m\" is road");
    puts("\"\033[31m@\033[33m\" is your position");
    puts("\033[33mPress arrow key to move");
	puts("\033[33mPress \"Enter\" to start");
    while(getchar()!='\n');
    return;
}
void Difficulty(){
    x=1,y=0,step=0;
    system("cls");
    for(int i=0;i<=R;i++){
        for(int j=0;j<=C;j++){
            Map[i][j]=0;
        }
    }
    //用于上一次游戏结束后初始化
    puts("Please choose the difficulty");
	puts("Input \"1\" for Easy Mode");
	puts("Input \"2\" for Medium Mode");
	puts("Input \"3\" for Hard Mode");
	puts("You can press \"ESC\" anytime to exit");
	switch(get_choice()){
		case 1:{R=10,C=20;break;}
		case 2:{R=20,C=40;break;}
		case 3:{R=30,C=60;break;}
	}
    Map_create();
}
void Map_create(){
    for(int i=0;i<=R;i++){
        for(int j=0;j<=C;j++){
            Map[i][j]=1;
            //初始化全为墙
        }
    }
    int tot = 0;
    for(int i=1;i<=R;i+=2){
        for(int j=1;j<=C;j+=2){
            Map[i][j]=0;
            //将所有奇数位置放空
            Map_id[i][j]=++tot;
            //给予每一个空位置一个id值
        }
    }
    for(int i=1;i<=tot;i++){
        fa[i]=i;
        //为并查集找联通路设置初始id
    }
    vector<Edges>Edge;
    for(int i=1;i<R;i+=2){
		for(int j=1;j<C;j+=2){
			if(i+2<R)Edge.push_back({Map_id[i][j],Map_id[i+2][j],i+1,j});
			if(j+2<C)Edge.push_back({Map_id[i][j],Map_id[i][j+2],i,j+1});
            //将空之间的墙都加入数列
		}
	}
    random_shuffle(Edge.begin(),Edge.end());
    //将墙的顺序随机排列
    for(auto &i:Edge){
        //遍历Edge中每个元素
        if(Con(i.u,i.v)){
            Map[i.x][i.y]=0;
            //代表x，y两个区域并未联通，将墙拆除
        }
    }
    Map[1][0]=0;
    Map[R-1][C]=0;
    //拆除首尾的墙
    sx=R-1;
    sy=C;
    //终点位置
}
int Con(int &x,int &y){
    if(find(x)^find(y)){
        fa[fa[x]]=fa[y];
        return 1;
    }
    return 0;
}
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
    //并查集
}
void Print(){
    printf("\033[33mYou have used %d steps\n\033[32m",step);
	for(int i=0;i<=R;++i){
		for(int j=0;j<=C;++j){
			if(i==x&&j==y)printf("\033[5m\033[31m%c\033[25m\033[32m",'@');
			else putchar(Map[i][j]?'#':' ');
		}
		puts("");
	}
}