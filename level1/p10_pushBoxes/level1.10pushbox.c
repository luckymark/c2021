/*
墙会被推动->空格长度和标记长度不一样
判断前面的情况
记录步数
读入文件，记录关卡
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#define Length 10//游戏界面的长和宽

int x = 0, y = 0;
int walkcnt = 0;
int score = 0;

int map[Length][Length] = { 0 };// 定义的游戏界面模型

int count1();
int count2();
void CursorGoto(int x, int y);//光标定位
void up();
void down();
void left();
void right();
void ChooseLevel();
void GetMap(FILE*fp);
void DrawMap();
int find();
void HomeScreen();
void EndScreen();
int grade();
void SaveGrade();

int main()
{
    int n, m;
    system("title 推箱子游戏~");
    system("color F3");
    
    HomeScreen();
    ChooseLevel();

    getchar();

    system("cls");

    n = count1();

    while (1)
    {
        system("cls");
        DrawMap();
        m = count2();
        walkcnt++;

        switch (getchar())
        {
        case 'w':up(); break;
        case 's':down(); break;
        case 'a':left(); break;
        case 'd':right(); break;
        default:printf("请重新输入");break;
        }

        if (n == m)
        {
            EndScreen();
            SaveGrade();
            return 0;
        }
    }
}

// 按w的时候的输出结果
void up()
{
    find();
    switch (map[x - 1][y])//判断人前面是什么
    {
    case 0://空
    {
        map[x - 1][y] = 3;
        map[x][y] = 0;
        break;
    }
    case 1:break;//墙
    case 2://箱子
    {
        if (map[x - 2][y] == 0)//箱子前面空，箱子和人一起动
        {
            map[x - 2][y] = 2;
            map[x - 1][y] = 3;
            map[x][y] = 0;
        }
        else
        {
            if (map[x - 2][y] == 4)//箱子前面是目标
            {
                map[x][y] = 0;
                map[x - 1][y] = 3;
                map[x - 2][y] = 5;
            }
        }
        break;
    }
    }
}

//按d的时候的输出结果
void down()
{
    find();
    switch (map[x + 1][y])
    {
    case 0:
    {
        map[x + 1][y] = 3;
        map[x][y] = 0;
        break;
    }
    case 1:break;
    case 2:
    {
        if (map[x + 2][y] == 0)
        {
            map[x + 2][y] = 2;
            map[x + 1][y] = 3;
            map[x][y] = 0;
        }
        else
        {
            if (map[x + 2][y] == 4)
            {
                map[x][y] = 0;
                map[x + 1][y] = 3;
                map[x + 2][y] = 5;
            }
        }
        break;
    }
    }
}

//按a的时候的输出结果
void left()
{
    find();
    switch (map[x][y - 1])
    {
    case 0:
    {
        map[x][y - 1] = 3;
        map[x][y] = 0;
        break;
    }
    case 1:break;
    case 2:
    {
        if (map[x][y - 2] == 0)
        {
            map[x][y - 2] = 2;
            map[x][y - 1] = 3;
            map[x][y] = 0;
        }
        else
        {
            if (map[x][y - 2] == 4)
            {
                map[x][y] = 0;
                map[x][y - 1] = 3;
                map[x][y - 2] = 5;
            }
        }
        break;
    }
    }
}

//按d的时候的输出结果
void right()
{
    find();
    switch (map[x][y + 1])
    {
    case 0://空
    {
        map[x][y + 1] = 3;
        map[x][y] = 0;
        break;
    }
    case 1:break;
    case 2:
    {
        if (map[x][y + 2] == 0)
        {
            map[x][y + 2] = 2;
            map[x][y + 1] = 3;
            map[x][y] = 0;
        }
        else
        {
            if (map[x][y + 2] == 4)
            {
                map[x][y] = 0;
                map[x][y + 1] = 3;
                map[x][y + 2] = 5;
            }
        }
        break;
    }
    }
}

void DrawMap()
{
    for (x = 0; x < Length; x++)
    {
        for (y = 0; y < Length; y++)
        {
            if (map[x][y] == 1)
                printf("■"); //输出砖块的样子
            if (map[x][y] == 3)
                printf("♀"); //输出自己的位置
            if (map[x][y] == 2)
                printf("□"); //输出箱子
            if (map[x][y] == 4)
                printf("☆"); //输出箱子要到的位置
            if (map[x][y] == 0)
                printf("  "); //输出空白
            if (map[x][y] == 5)
                printf("★"); //输出箱子到了该到的位置
        }
        printf("\n");
    }
}
//找到自己的位置
int find()//用break只能跳出内层循环，不能跳出两层
{
    for (x = 0; x < Length; x++)
        for (y = 0; y < Length; y++)
        {
            if (map[x][y] == 3)return 0;
        }
    return 0;
}
//箱子要到的位置的个数
int count1()
{
    int n = 0;
    for (x = 0; x < Length; x++)
        for (y = 0; y < Length; y++)
        {
            if (map[x][y] == 4)
                n++;
        }
    return n;
}
//箱子到了位置的个数
int count2()
{
    int m = 0;
    for (x = 0; x < Length; x++)
        for (y = 0; y < Length; y++)
        {
            if (map[x][y] == 5)
                m++;
        }
    return m;
}
//制作主界面
void HomeScreen()
{
    system("cls");
    CursorGoto(39, 8);
    printf("欢迎来到超级有趣的推箱子游戏");
    CursorGoto(34, 10);
    printf("游戏规则");
    CursorGoto(34, 12);
    printf("按wsad控制小人上下左右移动，按回车键结束输入");
    CursorGoto(34, 14);
    printf("输入0 退出游戏");
    CursorGoto(34, 16);
    printf("输入1-4 选择关卡");
}
//记录得分
int grade()
{
    score = 1000 / walkcnt;
    return score;
}

void ChooseLevel()
{
    int n;
    scanf_s("%d", &n);
    FILE* fp;
    fp = NULL;
    switch (n)
    {
    case 0:
    {
        system("cls");  //退出游戏则输出提示信息
        CursorGoto(34, 12);
        printf("欢迎下次光临");
        exit(0);
    }
    case 1:
    {
        fp = fopen("D:/tmp/pushbox/level1.txt", "a+");
        GetMap(fp);
        break;
    }
    case 2:
    {
        fp = fopen("D:/tmp/pushbox/level2.txt", "a+");
        GetMap(fp);
        break;
    }
    case 3:
    {
        fp = fopen("D:/tmp/pushbox/level3.txt", "a+");
        GetMap(fp);
        break;
    }
    case 4:
    {
        fp = fopen("D:/tmp/pushbox/level4.txt", "a+");
        GetMap(fp);
        break;
    }
    }
    fclose(fp);
}

void GetMap(FILE*fp)
{
    for (int i = 0;i < Length;i++)
    {
        for (int j = 0;j < Length;j++)
            fscanf_s(fp, "%d", &map[i][j]);
    }  
}

void SaveGrade()
{
    FILE* fp;
    fp = NULL;
    fp = fopen("D:/tmp/pushbox/level1.txt", "a+");
    fprintf(fp, "\n您第本关的得分是%d\n", score);
    fprintf(fp, "%s\r\t", __DATE__);
    fprintf(fp, "%s\r\n", __TIME__);
    fclose(fp);
}

void EndScreen()
{
    system("cls");
    CursorGoto(39, 8);
    printf("$￥游戏胜利￥$~\n");
    CursorGoto(39, 10);
    printf("您走过的步数是%d\n", walkcnt);
    score = grade(score);
    CursorGoto(39, 12);
    printf("您本关卡得分%d\n", score);
    system("pause");
}
void CursorGoto(int x, int y) //光标定位
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}