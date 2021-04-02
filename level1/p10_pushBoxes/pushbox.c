#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define role 2
#define route 1
#define wall 0
#define box 3
#define end 4
typedef struct information
{
    int boxes; //箱子数
    int ends;  //终点数
    int role_x;
    int role_y;
    int wins;
    int steps;
} infor;
typedef struct ending
{
    int x;
    int y;
} ending;
ending *fillmaze(int **maze, int n, FILE *mazein, infor *tips, ending *xixi);
void printfmaze(int **maze, int n, ending *xixi, infor *tips);
void roleplay(int **maze, int length, infor *tips, ending *xixi, int n);
void rolemove(int **maze, int key, infor *tips);
int judge(int **maze, infor *tips, int key);
int main()
{
    int again = 1;
    while (again)
    {
        int choose;
        printf("choose level:easy-1,normal-2");
        scanf("%d", &choose);
        FILE *mazein = NULL;
        FILE *stepsout = NULL;
        switch (choose)
        {
        case 1:
            mazein = fopen("maze.txt", "r");
            stepsout = fopen("steps.txt", "w");
            break;
        case 2:
            printf("waitting for updating\n");
            break;
        }
        int **maze;
        int n;
        fscanf(mazein, "%d", &n);
        maze = (int **)calloc(n, sizeof(int *));
        for (int i = 0; i < n; i++)
            maze[i] = (int *)calloc(n, sizeof(int));
        infor note;
        infor *tips = &note;
        tips->boxes = 0;
        tips->ends = 0;
        tips->wins = 0;
        tips->steps = 0;
        ending *xixi = (ending *)calloc(n, sizeof(ending));
        fillmaze(maze, n, mazein, tips, xixi);
        roleplay(maze, n, tips, xixi, n);
        fprintf(stepsout, "the scores of mode %d is %d\n", choose, tips->steps);
        printf("do you want to play again? yes--1 no--0 \n");
        scanf("%d", &again);
        free(maze);
        free(xixi);
    }
    system("Pause");

    return 0;
}
ending *fillmaze(int **maze, int n, FILE *mazein, infor *tips, ending *xixi)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            fscanf(mazein, "%d", &maze[i][j]);
            if (maze[i][j] == role)
            {
                tips->role_x = i;
                tips->role_y = j;
            }
            else if (maze[i][j] == box)
                tips->boxes++;
            else if (maze[i][j] == end)
            {
                tips->ends++;
                (xixi + (tips->ends) - 1)->x = i;
                (xixi + (tips->ends) - 1)->y = j;
            }
        }
    return xixi;
    fclose(mazein);
}
void printfmaze(int **maze, int n, ending *xixi, infor *tips)
{
    int now;
    for (int k = 1; k <= (tips->ends); k++)
        if (maze[(xixi + k - 1)->x][(xixi + k - 1)->y] == route)
            maze[(xixi + k - 1)->x][(xixi + k - 1)->y] = 4;
        else if (maze[(xixi + k - 1)->x][(xixi + k - 1)->y] == box)
            now++;
    if (now == tips->boxes)
        tips->wins = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            switch (maze[i][j])
            {
            case 0:
                printf("0");
                break;
            case 1:
                printf("1");
                break;
            case 2:
                printf("2");
                break;
            case 3:
                printf("3");
                break;
            case 4:
                printf("4");
                break;
            }
        }
        printf("\n");
    }
    printf("your current steps are %d\n", tips->steps);
}
void roleplay(int **maze, int length, infor *tips, ending *xixi, int n)
{
    printfmaze(maze, length, xixi, tips);
    while (1)
    {
        if (_kbhit())
        {
            system("cls");
            rolemove(maze, _getch(), tips);
            printfmaze(maze, length, xixi, tips);
            if (tips->wins)
            {
                printf("you win,your end steps are %d\n", tips->steps);
                return;
            }
        }
    }
    printf("\n you win!\n");
    return;
}
void rolemove(int **maze, int key, infor *tips)
{
    switch (key)
    {
    case 72: //上
        if (judge(maze, tips, key) == 1)
        {
            maze[tips->role_x][tips->role_y] = route;
            maze[tips->role_x - 1][tips->role_y] = role;
            tips->role_x = tips->role_x - 1, tips->role_y = tips->role_y;
            tips->steps++;
        }
        else if (judge(maze, tips, key) == 2)
        {
            maze[tips->role_x][tips->role_y] = route;
            maze[tips->role_x - 1][tips->role_y] = role;
            maze[tips->role_x - 2][tips->role_y] = box;
            tips->role_x = tips->role_x - 1, tips->role_y = tips->role_y;
            tips->steps++;
        }
        break;
    case 75: //左
        if (judge(maze, tips, key) == 1)
        {
            maze[tips->role_x][tips->role_y] = route;
            maze[tips->role_x][tips->role_y - 1] = role;
            tips->role_x = tips->role_x, tips->role_y = tips->role_y - 1;
            tips->steps++;
        }
        else if (judge(maze, tips, key) == 2)
        {
            maze[tips->role_x][tips->role_y] = route;
            maze[tips->role_x][tips->role_y - 1] = role;
            maze[tips->role_x][tips->role_y - 2] = box;
            tips->role_x = tips->role_x, tips->role_y = tips->role_y - 1;
            tips->steps++;
        }
        break;
    case 77: //右
        if (judge(maze, tips, key) == 1)
        {
            maze[tips->role_x][tips->role_y] = route;
            maze[tips->role_x][tips->role_y + 1] = role;
            tips->role_x = tips->role_x, tips->role_y = tips->role_y + 1;
            tips->steps++;
        }
        else if (judge(maze, tips, key) == 2)
        {
            maze[tips->role_x][tips->role_y] = route;
            maze[tips->role_x][tips->role_y + 1] = role;
            maze[tips->role_x][tips->role_y + 2] = box;
            tips->role_x = tips->role_x, tips->role_y = tips->role_y + 1;
            tips->steps++;
        }
        break;
    case 80: //下
        if (judge(maze, tips, key) == 1)
        {
            maze[tips->role_x][tips->role_y] = route;
            maze[tips->role_x + 1][tips->role_y] = role;
            tips->role_x = tips->role_x + 1, tips->role_y = tips->role_y;
            tips->steps++;
        }
        else if (judge(maze, tips, key) == 2)
        {
            maze[tips->role_x][tips->role_y] = route;
            maze[tips->role_x + 1][tips->role_y] = role;
            maze[tips->role_x + 2][tips->role_y] = box;
            tips->role_x = tips->role_x + 1, tips->role_y = tips->role_y;
            tips->steps++;
        }
        break;
    }
}
int judge(int **maze, infor *tips, int key)
{
    switch (key)
    {
    case 72: //上
        if (maze[tips->role_x - 1][tips->role_y] == route || maze[tips->role_x - 1][tips->role_y] == end)
            return 1;
        else if (maze[tips->role_x - 1][tips->role_y] == box && (maze[tips->role_x - 2][tips->role_y] == route || maze[tips->role_x - 2][tips->role_y] == end))
            return 2;
        else
            return 0;
        break;
    case 75: //左
        if (maze[tips->role_x][tips->role_y - 1] == route || maze[tips->role_x][tips->role_y - 1] == end)
            return 1;
        else if (maze[tips->role_x][tips->role_y - 1] == box && (maze[tips->role_x][tips->role_y - 2] == route || maze[tips->role_x][tips->role_y - 2] == end))
            return 2;
        else
            return 0;
        break;
    case 77: //右
        if (maze[tips->role_x][tips->role_y + 1] == route || maze[tips->role_x][tips->role_y + 1] == end)
            return 1;
        else if (maze[tips->role_x][tips->role_y + 1] == box && (maze[tips->role_x][tips->role_y + 2] == route || maze[tips->role_x][tips->role_y + 2] == end))
            return 2;
        else
            return 0;
        break;
    case 80: //下
        if (maze[tips->role_x + 1][tips->role_y] == route || maze[tips->role_x + 1][tips->role_y] == end)
            return 1;
        else if (maze[tips->role_x + 1][tips->role_y] == box && (maze[tips->role_x + 2][tips->role_y] == route || maze[tips->role_x + 2][tips->role_y] == end))
            return 2;
        else
            return 0;
        break;
    default:
        break;
    }
}
