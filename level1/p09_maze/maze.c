#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <conio.h>

int rank = 6;
//地图边长 L，包括迷宫主体 20，外侧的包围的墙体 2，最外侧包围路径 2
#define L 24
#define WALL 0 //墙
#define ROUTE 1 //路径
#define PLAYER 2 //玩家

void menu();
void start();
void degree();
int init(int** maze);
void print(int** maze);
void creatMaze(int** maze, int x, int y);
void move(int** maze, char t, int& x, int& y);


int main() {
    menu();
    return 0;
}

//显示主菜单
void menu() {
    char c;
    while (1) {
        system("cls");
        printf("---------------------\n");
        printf("---欢迎来到迷宫游戏---\n");
        printf("----1. 开始游戏 -----\n");
        printf("----2. 游戏难度 -----\n");
        printf("----0. 退出游戏 -----\n");
        printf("--------------------\n");
        c = _getch();
        switch (c) {
            case '1':
                start();
                break;
            case '2':
                degree();
                break;
            case '0':
                printf("欢迎下次继续游玩........\n");
                Sleep(1500);
                exit(0);
            default:
                break;
        }
    }
}

//开始游戏
void start() {
    char t;
    //x，y是玩家的坐标，out是出口的纵坐标(行号)
    int i, x = 2, y = 1, out = 0;
    //初始化随机数种子，利用系统时间生成随机数,之后就可以使用rand函数生成随机数
    srand((unsigned)time(NULL));
    //初始化迷宫
    int** maze = (int**)malloc(L * sizeof(int*));
    for (i = 0; i < L; i++) {
        maze[i] = (int*)calloc(L, sizeof(int));
    }
    //得到出口纵坐标
    out = init(maze);
    system("cls");
    print(maze);
    while (t = _getch()) {
        system("cls");
        move(maze, t, x, y);
        print(maze);
        if (x == out && y == L - 2) {
            system("cls");
            printf("恭喜你，到达了终点!\n");
            printf("即将返回主菜单\n");
            Sleep(1500);
            break;
        }
    }
    for (i = 0; i < L; i++)
        free(maze[i]);
    free(maze);
}

void degree() {
    char t;
    system("cls");
    printf("---------------------\n");
    printf("---请输入游戏难度---\n");
    printf("----- 1. 简单 -----\n");
    printf("----- 2. 中等 -----\n");
    printf("----- 3. 困难 -----\n");
    printf("--------------------\n");
    t = _getch();
    switch (t) {
        case '1':
            printf("已修改游戏难度为简单\n");
            rank = 6;
            break;
        case '2':
            printf("已修改游戏难度为中等\n");
            rank = 3;
            break;
        case '3':
            printf("已修改游戏难度为困难\n");
            rank = 0;
            break;
        default:
            break;
    }
    printf("按任意键返回菜单\n");
    system("pause");

}
//初始化迷宫
int init(int** maze) {
    int i;
    //将最外层都设置为空的路径，防止挖穿
    for (i = 0; i < L; i++) {
        maze[i][0] = ROUTE;
        maze[0][i] = ROUTE;
        maze[i][L - 1] = ROUTE;
        maze[L - 1][i] = ROUTE;
    }
    creatMaze(maze, 2, 2);//生成迷宫入口和出口
    maze[2][1] = PLAYER; //给玩家初始位置
    //寻找出口，出口可能不在[L-3][L-2]，因此需要查找
    for (i = L - 3; i >= 0; i--) {
        if (maze[i][L - 3] == ROUTE) {
            maze[i][L - 2] = ROUTE;
            return i; //出口返回纵坐标
        }
    }
}

//打印迷宫
void print(int** maze) {
    int i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < L; j++) {
            if (maze[i][j] == ROUTE)
                printf("  ");
            else if (maze[i][j] == WALL)
                printf("墙");
            else if (maze[i][j] == PLAYER)
                printf("十");
        }
        printf("\n");
    }
}

//构建迷宫
void creatMaze(int** maze, int x, int y) {
    maze[x][y] = ROUTE;
    //确保四个方向随机，而不再是固定的上下左右这种排列
    int direction[4][2] = { { 1,0 },{ -1,0 },{ 0,-1 },{ 0,1 } };
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int temp = direction[0][0];
        direction[0][0] = direction[r][0];
        direction[r][0] = temp;
        temp = direction[0][1];
        direction[0][1] = direction[r][1];
        direction[r][1] = temp;
    }
    //向四个方向开挖
    for (int i = 0; i < 4; i++) {
        int dx = x;
        int dy = y;
        //控制挖的距离，由Rank来调整大小
        int range = 1 + (rank == 0 ? 0 : rand() % rank);
        while (range > 0) {
            //计算出将要访问到的坐标
            dx += direction[i][0];
            dy += direction[i][1];
            //排除掉回头路
            if (maze[dx][dy] == ROUTE) {
                break;
            }
            //判断是否挖穿路径
            int count = 0;
            for (int j = dx - 1; j < dx + 2; j++) {
                for (int k = dy - 1; k < dy + 2; k++) {
                    //abs(j - dx) + abs(k - dy) == 1 确保只判断九宫格的四个特定位置
                    if (abs(j - dx) + abs(k - dy) == 1 && maze[j][k] == ROUTE) {
                        count++;
                    }
                }
            }
            //count大于1表明墙体会被挖穿，停止
            if (count > 1)
                break;
            //确保不会挖穿时，前进
            range -= 1;
            maze[dx][dy] = ROUTE;
        }
        //没有挖穿危险，以此为节点递归
        if (range <= 0) {
            creatMaze(maze, dx, dy);
        }
    }
}

//移动
void move(int** maze, char t, int& x, int& y) {
    int i, j;
    i = x;
    j = y;
    switch (t) {
        case 'w':
            x--;
            break;
        case 's':
            x++;
            break;
        case 'a':
            y--;
            break;
        case 'd':
            y++;
            break;
        default:
            break;
    }
    if (x >= 0 && x < L-1 && y >= 0 && y < L-1 && maze[x][y] != WALL) {
        maze[i][j] = ROUTE;
        maze[x][y] = PLAYER;
    }
    else {
        x = i;
        y = j;
    }
}
