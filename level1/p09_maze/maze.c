#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
HANDLE hOut;
#define wall 0
#define route 1
#define role 2
typedef struct mazeifo
{
    int x;
    int y;
} mazeifo;
void creatwall(int **maze, int length);
void creat_in(int **maze);
int creat_out(int **maze, int length);
void creatmaze(int x, int y, int **maze);
void printfmaze(int **maze, int length);
void roleplay(int **maze, int length, int ok);
void rolemove(int **maze, int key, mazeifo *inf);
int judge(int **maze, mazeifo *inf, int key);
int Rank;
int main()
{
    int i;
    int length;
    int **maze;
    puts("please input n");
    scanf_s("%d", &length);
    maze = (int **)malloc((length + 2) * sizeof(int *));
    for (i = 0; i < length + 2; i++)
        maze[i] = (int *)calloc((length + 2), sizeof(int));
    //创建迷宫二维数组(增加两列作为判断依据)，动态分配地址
    creatwall(maze, length);
    //填充迷宫
    creat_in(maze);
    //弄入口
    creatmaze(2, 2, maze);
    //挖迷宫
    int ok = creat_out(maze, length);
    //创建出口
    roleplay(maze, length, ok);
    //打印迷宫
    free(maze);
    system("Pause");
    return 0;
}
void creatwall(int **maze, int length)
{
    int i, j;
    for (i = 0; i <= length + 1; i++)
    {
        maze[0][i] = route;
        maze[i][0] = route;
        maze[i][length + 1] = route;
        maze[length + 1][i] = route;
    }
    for (i = 1; i <= length; i++)
        for (j = 1; j <= length; j++)
            maze[i][j] = wall;
}
void printfmaze(int **maze, int length)
{
    int i, j;
    for (i = 0; i <= length + 1; i++)
        for (j = 0; j <= length + 1; j++)
        {
            if (maze[i][j] == wall)
                printf("■");
            else if (maze[i][j] == route)
                printf("□");
            else if (maze[i][j] == role)
                printf("●");
            if (j == length + 1)
                printf("\n");
        }
}
void creat_in(int **maze)
{
    maze[2][1] = route;
    maze[2][2] = route;
}
void creatmaze(int x, int y, int **maze)
{
    maze[x][y] = route;

    //确保四个方向随机
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < 4; i++)
    {
        int r = rand() % 4;
        int temp = direction[0][0];
        direction[0][0] = direction[r][0];
        direction[r][0] = temp;

        temp = direction[0][1];
        direction[0][1] = direction[r][1];
        direction[r][1] = temp;
    }

    //向四个方向开挖
    for (int i = 0; i < 4; i++)
    {
        int dx = x;
        int dy = y;

        //控制挖的距离，由Rank来调整大小
        int range = 1 + (Rank == 0 ? 0 : rand() % Rank);
        while (range > 0)
        {
            dx += direction[i][0];
            dy += direction[i][1];

            //排除掉回头路
            if (maze[dx][dy] == route)
            {
                break;
            }

            //判断是否挖穿路径
            int count = 0;
            for (int j = dx - 1; j < dx + 2; j++)
            {
                for (int k = dy - 1; k < dy + 2; k++)
                {
                    //abs(j - dx) + abs(k - dy) == 1 确保只判断九宫格的四个特定位置
                    if (abs(j - dx) + abs(k - dy) == 1 && maze[j][k] == route)
                    {
                        count++;
                    }
                }
            }

            if (count > 1)
            {
                break;
            }

            //确保不会挖穿时，前进
            --range;
            maze[dx][dy] = route;
        }

        //没有挖穿危险，以此为节点递归
        if (range <= 0)
        {
            creatmaze(dx, dy, maze);
        }
    }
}
int creat_out(int **maze, int length)
{
    for (int i = length - 1; i > 1; i--)
    {
        if (maze[i][length - 1] == route)
        {
            maze[i][length] = route;
            return i;
        }
    }
}
void roleplay(int **maze, int length, int ok)
{
    mazeifo mazeinf;
    mazeifo *inf = &mazeinf;
    inf->x = 2, inf->y = 1;
    maze[2][1] = role;
    printfmaze(maze, length);
    while (maze[ok][length] != role)
    {
        if (_kbhit())
        {
            system("cls");
            rolemove(maze, _getch(), inf);
            printfmaze(maze, length);
        }
    }
    printf("\n you win!\n");
    return;
}
void rolemove(int **maze, int key, mazeifo *inf)
{
    switch (key)
    {
    case 72: //上
        if (judge(maze, inf, key))
        {
            maze[inf->x][inf->y] = route;
            maze[inf->x - 1][inf->y] = role;
            inf->x = inf->x - 1, inf->y = inf->y;
        }
        break;
    case 75: //左
        if (judge(maze, inf, key))
        {
            maze[inf->x][inf->y] = route;
            maze[inf->x][inf->y - 1] = role;
            inf->x = inf->x, inf->y = inf->y - 1;
        }
        break;
    case 77: //右
        if (judge(maze, inf, key))
        {
            maze[inf->x][inf->y] = route;
            maze[inf->x][inf->y + 1] = role;
            inf->x = inf->x, inf->y = inf->y + 1;
        }
        break;
    case 80: //下
        if (judge(maze, inf, key))
        {
            maze[inf->x][inf->y] = route;
            maze[inf->x + 1][inf->y] = role;
            inf->x = inf->x + 1, inf->y = inf->y;
        }
        break;
    }
}
int judge(int **maze, mazeifo *inf, int key)
{
    switch (key)
    {
    case 72: //上
        if (maze[inf->x - 1][inf->y] == route)
            return 1;
        else
            return 0;
        break;
    case 75: //左
        if (maze[inf->x][inf->y - 1] == route)
            return 1;
        else
            return 0;
        break;
    case 77: //右
        if (maze[inf->x][inf->y + 1] == route)
            return 1;
        else
            return 0;
        break;
    case 80: //下
        if (maze[inf->x + 1][inf->y] == route)
            return 1;
        else
            return 0;
        break;
    default:
        break;
    }
}