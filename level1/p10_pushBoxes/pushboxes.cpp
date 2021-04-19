#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;

struct Map_datas{
    int i;
    int R,C;
    int Map[100][100];
};
int Map_now[100][100];
int step;
int x=-1,y=-1;
int p;//图p
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
vector<Map_datas>Map_data;
vector<int>Score_record;

void Map_init(void);
void Score_init(void);
void menu1(void);
void menu2(void);
int get_choice1(void);
void Map_choose(void);
void Score_view(void);
void Print(void);
void Game_start(void);
int get_direction(void);
void record_write(void);

int main(){
    Map_init();
    Score_init();
    menu1();
    return 0;
}

void Map_init(){
    freopen("level1/p10_pushBoxes/Maps.in","r",stdin);
    //freopen("Maps.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        Map_datas x;
        x.i=i;
        scanf("%d %d",&x.R,&x.C);
        for(int j=0;j<x.R;j++){
            for(int k=0;k<x.C;k++){
                scanf("%d",&x.Map[j][k]);
            }
        }
        Map_data.push_back(x);
    }
    fclose(stdin);
}
void Score_init(){
    freopen("level1/p10_pushBoxes/Score.in","r",stdin);
    //freopen("Score.in","r",stdin);
    int L=Map_data.size();
    for(int i=0;i<L;i++){
        int x;
        scanf("%d",&x);
        Score_record.push_back(x);
    }
    fclose(stdin);
    freopen("CON","r",stdin);
}
void menu1(){
    system("cls");
    puts("\"\033[32m#\033[33m\" is wall");
    puts("\"\033[32m \033[33m\" is road");
    puts("\"\033[36mX\033[33m\" is target");
    puts("\"\033[34mO\033[33m\" is box");
    puts("\"\033[39m$\033[33m\" is push succeed");
    puts("\"\033[31m@\033[33m\" is your position");
    puts("\033[33mPress arrow key to move");
	puts("\033[33mPress \"Enter\" to start");
    while(getchar()!='\n');
    menu2();
}
void menu2(){
    system("cls");
    puts("\033[33mPress 1 to choose the level");
    puts("\033[33mPress 2 to view the score");
    puts("\033[33mPress Esc to exit");
    switch(get_choice1()){
        case 1:Map_choose();break;
        case 2:Score_view();break;
    }
}
int get_choice1(){
    while(1){
        Sleep(20);
        if(kbhit()){
            switch(getch()){
                case '1':return 1;
                case '2':return 2;
                case 0X1B:record_write();exit(0);
            }
        }
    }
}
void Map_choose(){
    system("cls");
    step = 0;
    x=y=-1;
    printf("\033[33mYou can choose level from 1 to %d\n",int(Map_data.size()));
    scanf("%d",&p);
    if(p>=1&&p<=int(Map_data.size())){
        memcpy(Map_now,Map_data[p-1].Map,sizeof(Map_now));
        //将Map的数据取出
        p--;//让p对应vector的位置
        Game_start();
    }
    else{
        puts("Map not found");
        puts("Press enter to return to menu");
        getchar();//消掉回车
        while(getchar()!='\n');
        menu2();
    }
}
void Score_view(){
    system("cls");
    int L=Map_data.size();
    for(int i=0;i<L;i++){
        printf("Level%d_score:%d\n",i+1,Score_record[i]);
    }
    puts("Press enter to return to menu");
    while(getchar()!='\n');
    menu2();
}
void Print(){
    system("cls");
    printf("\033[33mYou have used %d steps\n",step);
    puts("Press \"r\" to return to the map chosen interface\n\033[32m");
    bool flag = 1;
    for(int i=0;i<Map_data[p].R;i++){
        for(int j=0;j<Map_data[p].C;j++){
            if(x==i&&y==j){
                printf("\033[31m@\033[32m");
                continue;
            }
            switch(Map_now[i][j]){
                case 0:putchar(' ');break;//空
                case 1:putchar('#');break;//墙
                case 2:printf("\033[31m@\033[32m");x=i;y=j;Map_now[i][j]=0;break;//所在地
                case 3:printf("\033[34mO\033[32m");flag=0;break;//箱子
                case 4:printf("\033[36mX\033[32m");flag=0;break;//目标位置
                case 5:printf("\033[39m$\033[32m");break;//重合
            }
        }
        puts("");
    }
    if(flag){
        printf("\033[33mCongratulations!\n");
		
        if(Score_record[p]==0||Score_record[p]>step){
            Score_record[p]=step;
            puts("New record!");
            //record_write();
        }
        puts("Press \"Enter\" to back to menu");    
        getchar();
		while(getchar()!='\n');
        menu2();
    }
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
                case 'r':Map_choose();break;
                case 0x1B:record_write();exit(0);//esc
            }
        }
    }
}
void Game_start(){
    system("cls");
    while(1){
        Print();
        int d=get_direction();
        int nx=x+dx[d];
		int ny=y+dy[d];
        switch(Map_now[nx][ny]){
            case 1:break;
            case 0:{
                x=nx;y=ny;
                step++;
                break;
            }
            case 4:{
                x=nx;y=ny;
                step++;
                break;
            }
            case 3:{
                int fx=nx+dx[d];
                int fy=ny+dy[d];
                if(Map_now[fx][fy]==0){
                    //前进二为空
                    swap(Map_now[nx][ny],Map_now[fx][fy]);
                    x=nx;y=ny;
                    step++;
                    break;
                }
                if(Map_now[fx][fy]==4){
                    //前进二为目标位置
                    Map_now[fx][fy]=5;
                    Map_now[nx][ny]=0;
                    x=nx;y=ny;
                    step++;
                    break;
                }
            }
            case 5:{
                int fx=nx+dx[d];
                int fy=ny+dy[d];
                if(Map_now[fx][fy]==0){
                    //前进二为空
                    Map_now[nx][ny]=4;
                    Map_now[fx][fy]=3;
                    x=nx;y=ny;
                    step++;
                    break;
                }
                if(Map_now[fx][fy]==4){
                    
                    Map_now[nx][ny]=4;
                    Map_now[fx][fy]=5;
                    x=nx;y=ny;
                    step++;
                    break;
                }
            }
        }
    }
}
void record_write(){
    freopen("level1/p10_pushBoxes/Score.in","w",stdout);
    for(int i=0;i<int(Score_record.size());i++){
        printf("%d ",Score_record[i]);
    }
    puts("");
    fclose(stdout);
    freopen("CON","w",stdout);
    system("cls");
}
