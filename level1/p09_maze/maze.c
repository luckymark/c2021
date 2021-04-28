#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 23

int x,y;
int maze[N][N];
struct undeterminedWall
{
    int row;
    int column;
    int flag;
}wall[N*N];
int wallFlag[N*N];
int count=0;
char input;

void initialization(void);
void change(int a,int b);
void end(int x,int y);
void createMaze(void);
void print(void);
void find(void);
void playerMove(void);
void menu(void);
void succeed(void);
char enter(void);
int up(void);
int down(void);
int left(void);
int right(void);

void initialization()
{
    for (int i=0; i<N-1; i=N-1)
    {
        for (int j=0; j<N; j++)
        {
            maze[i][j]=0;
            maze[j][i]=0;
        }
    }
    for (int i=1; i<N-1; i++)
    {
        for (int j=1; j<N-1; j++) maze[i][j]=4;
    }
    for (int i=2; i<N-1; i+=2)
    {
        for (int j=1; j<N-1; j++)
        {
            maze[i][j]=5;
            maze[j][i]=5;
        }
    }
}

void change(int a,int b)
{
    if (maze[a+1][b]==5) {maze[a+1][b]=6; wall[count].flag=0; wall[count].row=a+1; wall[count++].column=b;}
    if (maze[a-1][b]==5) {maze[a-1][b]=6; wall[count].flag=1; wall[count].row=a-1; wall[count++].column=b;}
    if (maze[a][b+1]==5) {maze[a][b+1]=6; wall[count].flag=2; wall[count].row=a; wall[count++].column=b+1;}
    if (maze[a][b-1]==5) {maze[a][b-1]=6; wall[count].flag=3; wall[count].row=a; wall[count++].column=b-1;}
A:srand((unsigned)time(NULL));
    int n=rand()%count;
    int wallFlag,rowFlag,columnFlag,flag=0,r=0,s=0;
    switch (wall[n].flag)
    {
        case 0:
            if (maze[wall[n].row+1][wall[n].column]==4)
            {
                maze[wall[n].row+1][wall[n].column]=1;
                maze[wall[n].row][wall[n].column]=1;
                flag=0;
            }
            else {maze[wall[n].row][wall[n].column]=0; flag=1;}
            r=wall[n].row+1;
            s=wall[n].column;
            break;
        case 1:
            if (maze[wall[n].row-1][wall[n].column]==4)
            {
                maze[wall[n].row-1][wall[n].column]=1;
                maze[wall[n].row][wall[n].column]=1;
                flag=0;
            }
            else {maze[wall[n].row][wall[n].column]=0; flag=1;}
            r=wall[n].row-1;
            s=wall[n].column;
            break;
        case 2:
            if (maze[wall[n].row][wall[n].column+1]==4)
            {
                maze[wall[n].row][wall[n].column+1]=1;
                maze[wall[n].row][wall[n].column]=1;
                flag=0;
            }
            else {maze[wall[n].row][wall[n].column]=0; flag=1;}
            r=wall[n].row;
            s=wall[n].column+1;
            break;
        case 3:
            if (maze[wall[n].row][wall[n].column-1]==4)
            {
                maze[wall[n].row][wall[n].column-1]=1;
                maze[wall[n].row][wall[n].column]=1;
                flag=0;
            }
            else {maze[wall[n].row][wall[n].column]=0; flag=1;}
            r=wall[n].row;
            s=wall[n].column-1;
            break;
    }
    wallFlag=wall[n].flag;
    rowFlag=wall[n].row;
    columnFlag=wall[n].column;
    wall[n].flag=wall[count-1].flag;
    wall[n].row=wall[count-1].row;
    wall[n].column=wall[count-1].column;
    count--;
    if (count!=0)
    {
        switch (flag)
        {
            case 0: change(r,s); break;
            case 1: goto A; break;
        }
    }
}

void end(int x,int y)
{
A:srand((unsigned)time(NULL));
    int n=rand()%N;
    if (x==1)
    {
        if (maze[N-2][n]==1) {maze[N-1][n]=3; goto B;}
        else goto A;
    }
    if (y==1)
    {
        if (maze[n][N-2]==1) {maze[n][N-1]=3; goto B;}
        else goto A;
    }
    if (x==N-2)
    {
        if (maze[1][n]==1) {maze[0][n]=3; goto B;}
        else goto A;
    }
    if (y==N-2)
    {
        if (maze[n][1]==1) {maze[n][0]=3; goto B;}
        else goto A;
    }
B:;
}

void createMaze()
{
    initialization();
    srand((unsigned)time(NULL));
    int a=rand()%4;
    int b=2*(rand()%(N/2-1))+1;
    int x=0,y=0;
    switch (a)
    {
        case 0:
            maze[1][b]=1;
            maze[0][b]=2;
            x=1;
            y=b;
            break;
        case 1:
            maze[b][1]=1;
            maze[b][0]=2;
            x=b;
            y=1;
            break;
        case 2:
            maze[N-2][b]=1;
            maze[N-1][b]=2;
            x=N-2;
            y=b;
            break;
        case 3:
            maze[b][N-2]=1;
            maze[b][N-1]=2;
            x=b;
            y=N-2;
            break;
    }
    change(x,y);
    end(x,y);
}

void print()
{
    system("clear");
    printf("\n\n");
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            switch (maze[i][j])
            {
                case 0: printf("■"); break;
                case 1: printf(" "); break;
                case 2: printf("⊙"); break;
                case 3: printf("☆"); break;
                case 5: printf("■"); break;
            }
        }
        printf("\n");
    }
}

void find()
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if (maze[i][j]==2)
            {
                x=i;
                y=j;
                break;
            }
        }
    }
}

int up()
{
    switch (maze[x-1][y])
    {
        case 0: break;
        case 1:
            maze[x][y]=1;
            maze[x-1][y]=2;
            break;
        case 3:
            maze[x][y]=1;
            maze[x-1][y]=2;
            return 1;
            break;
    }
    return 0;
}

int down()
{
    switch (maze[x+1][y])
    {
        case 0: break;
        case 1:
            maze[x][y]=1;
            maze[x+1][y]=2;
            break;
        case 3:
            maze[x][y]=1;
            maze[x+1][y]=2;
            return 1;
            break;
    }
    return 0;
}

int left()
{
    switch (maze[x][y-1])
    {
        case 0: break;
        case 1:
            maze[x][y]=1;
            maze[x][y-1]=2;
            break;
        case 3:
            maze[x][y]=1;
            maze[x][y-1]=2;
            return 1;
            break;
    }
    return 0;
}

int right()
{
    switch (maze[x][y+1])
    {
        case 0: break;
        case 1:
            maze[x][y]=1;
            maze[x][y+1]=2;
            break;
        case 3:
            maze[x][y]=1;
            maze[x][y+1]=2;
            return 1;
            break;
    }
    return 0;
}

char enter()
{
    system("stty raw");
    input=getchar();
    system("stty cooked");
    return input;
}

void playerMove()
{
    int flag=0;
    while(1)
    {
        print();
        find();
        switch (enter())
        {
            case 'w': flag=up(); break;
            case 's': flag=down(); break;
            case 'a': flag=left(); break;
            case 'd': flag=right(); break;
        }
        if (flag==1)
        {
            print();
            system("sleep 0.2s");
            system("clear");
            printf("恭喜你通过这一关！\n");
            break;
        }
    }
}

void menu()
{
    system("clear");
    printf("分别用WASD控制人物移动\n\n\n");
    printf("按任意键开始游戏\n");
    enter();
    system("clear");
}

void succeed()
{
    system("clear");
    printf("恭喜你通关了！\n\n");
    printf("按任意键退出");
    enter();
}

int main(int argc, const char * argv[])
{
    menu();
    createMaze();
    print();
    playerMove();
    succeed();
}
