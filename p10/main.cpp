#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
void DisplayMap();
const int completelevel = 3;
int Map[20][20];
int level = 0;
int x,y;
int dataMap[30][20][20];
int bestdata[30] = {0};
int ReadKey()
{
    int a;
    a = getch();
    if(a == 114)
        return 0;
    if(a == 122)
        return 10;
    if(a == 120)
        return 11;
    if(a == 224)
    {
        a = getch();
        switch(a)
        {
            case 72:return 1;
            case 75:return 2;
            case 80:return 3;
            case 77:return 4;
        }
    }
    else
        return 0;
}
void FindXY()
{
    int i,j;
    for(i = 0;i<20;i++)
        for(j = 0;j<20;j++)
            if(Map[i][j] == 5 || Map[i][j] == 7)
            {
                y = i;x = j;break;
            }
}
void GameStart()
{
    int i,j;
    for(i = 0;i<20;i++)
        for(j = 0;j<20;j++)
            Map[i][j] = dataMap[level][i][j];
    FindXY();
    DisplayMap();
    printf("第 %d 关\t\t最佳纪录 %d 步\n\nR:重玩\tZ:上关\tX:下关\n",level+1,bestdata[level]);
}
void HandleKey(int key)
{
    if(key == 1)
    {
        int y1,y2;
        y1 = y-1;
        y2 = y-2;
        if(y1<0)
            return;
        else if(Map[y1][x] == 3||Map[y1][x] == 4)
        {
            if(Map[y2][x] == 3 ||Map[y2][x] == 4||Map[y2][x] == 1)
                return;
            else  if(Map[y2][x] == 0 ||Map[y2][x] == 2)
            {
                Map[y][x] -= 5;
                if(Map[y1][x] == 3)
                    Map[y1][x] = 5;
                else if(Map[y1][x] == 4)
                    Map[y1][x] = 7;
                if(Map[y2][x] == 0)
                    Map[y2][x] = 3;
                else if(Map[y2][x] == 2)
                    Map[y2][x] = 4;
                FindXY();

            }

        }
        else if(Map[y1][x] == 0 ||Map[y1][x] == 2)
        {

            Map[y][x] -= 5;Map[y1][x] += 5;
            FindXY();

        }

    }
    else if(key == 2) //左
    {
        int x1,x2;
        x1 = x-1;
        x2 = x-2;
        if(x1<0)
            return ;
        else if(Map[y][x1] == 1)
            return ;
        else if(Map[y][x1] == 3||Map[y][x1] == 4)
        {
            if(Map[y][x2] == 3 ||Map[y][x2] == 4||Map[y][x2] == 1)
                return ;
            else  if(Map[y][x2] == 0 ||Map[y][x2] == 2)
            {
                Map[y][x] -= 5;
                if(Map[y][x1] == 3)
                    Map[y][x1] = 5;
                else if(Map[y][x1] == 4)
                    Map[y][x1] = 7;
                if(Map[y][x2] == 0)
                    Map[y][x2] = 3;
                else if(Map[y][x2] == 2)
                    Map[y][x2] = 4;
                FindXY();

            }

        }
        else if(Map[y][x1] == 0 ||Map[y][x1] == 2)
        {

            Map[y][x] -= 5;Map[y][x1] += 5;
            FindXY();

        }

    }
    else if(key == 3)//下
    {
        int y1,y2;
        y1 = y+1;
        y2 = y+2;
        if(y1 >= 20)
            return ;
        else if(Map[y1][x] == 3||Map[y1][x] == 4)
        {
            if(Map[y2][x] == 3 ||Map[y2][x] == 4||Map[y2][x] == 1)
                return ;
            else  if(Map[y2][x] == 0 ||Map[y2][x] == 2)
            {
                Map[y][x] -= 5;
                if(Map[y1][x] == 3)
                    Map[y1][x] = 5;
                else if(Map[y1][x] == 4)
                    Map[y1][x] = 7;
                if(Map[y2][x] == 0)
                    Map[y2][x] = 3;
                else if(Map[y2][x] == 2)
                    Map[y2][x] = 4;
                FindXY();

            }

        }
        else if(Map[y1][x] == 0 ||Map[y1][x] == 2)
        {

            Map[y][x] -= 5;Map[y1][x] += 5;
            FindXY();

        }

    }
    else if(key == 4)//右
    {
        int x1,x2;
        x1 = x+1;
        x2 = x+2;
        if(x1 >= 20)
            return ;
        else if(Map[y][x1] == 1)
            return ;
        else if(Map[y][x1] == 3||Map[y][x1] == 4)
        {
            if(Map[y][x2] == 3 ||Map[y][x2] == 4||Map[y][x2] == 1)
                return ;
            else  if(Map[y][x2] == 0 ||Map[y][x2] == 2)
            {
                Map[y][x] -= 5;
                if(Map[y][x1] == 3)
                    Map[y][x1] = 5;
                else if(Map[y][x1] == 4)
                    Map[y][x1] = 7;
                if(Map[y][x2] == 0)
                    Map[y][x2] = 3;
                else if(Map[y][x2] == 2)
                    Map[y][x2] = 4;
                FindXY();
            }
        }
        else if(Map[y][x1] == 0 ||Map[y][x1] == 2)
        {

            Map[y][x] -= 5;Map[y][x1] += 5;
            FindXY();

        }
    }
}
void DisplayMap()
{
    int i,j;
    for(i = 0;i<20;i++)
    {
        for(j = 0;j<20;j++)
        {
            switch(Map[i][j])
            {
                case 0:printf("  ");break;
                case 1:printf("▓");break;
                case 2:printf("※");break;
                case 3:printf("□");break;
                case 4:printf("■");break;
                case 5:printf("♀");break;
                case 7:printf("♂");break;
            }
        }
        printf("\n");
    }

}
int JudgeComplete()
{
    int i,j;
    for(i = 0;i < 20; i++)
        for(j = 0;j < 20; j++)
            if(2 == Map[i][j]||3 == Map[i][j]) return 0;
    return 1;
}

void OpenData()
{
    int data;
    FILE *fp;
    if(level == 0) fp=fopen("C:\\Users\\john\\Desktop\\P10\\map1.txt","r");
    else if(level == 1) fp=fopen("C:\\Users\\john\\Desktop\\P10\\map2.txt","r");
    else if(level == 2) fp=fopen("C:\\Users\\john\\Desktop\\P10\\map3.txt","r");
    if(!fp)
    {
        printf("can't open file\n");
    }
    while(!feof(fp))
    {
        for(int i = 0; i < 20 ; i++)
            for (int j = 0; j < 20; j++)
                fscanf(fp,"%d",&dataMap[level][i][j]);
        printf("%4d",data);
    }
    printf("\n");
    fclose(fp);
    return;
}

void SaveData()
{
    ofstream ofile("C:\\Users\\john\\Desktop\\P10\\save.txt",ios::binary);
    if(!ofile)
    {
        printf("不能存入文件\n");
        return;
    }
    for(int i = 0;i<completelevel;i++)
        ofile.write((char *)&bestdata[i],sizeof(bestdata[i]));
    ofile.close();

}

int main()
{
    int key,move,movex,movey;
    while(1){
        OpenData();
        GameStart();
        move = 0;
        while(1)
        {
            movex = x;
            movey = y;
            key = ReadKey();
            if(1 != key&&2 != key&&3 != key&&4 != key) break;
            HandleKey(key);
            if(movex != x||movey != y)move++;
            system("cls");
            DisplayMap();
            printf("第 %d 关\t\t已走 %d 步\t最佳纪录 %d 步\n\nR:重玩\tZ:上关\tX:下关\n",level+1,move,bestdata[level]);
            if(JudgeComplete()) break;
        }
        if(10 == key)
        {
            if(0 == level){printf("这是第一关!!!");system("pause");}
            else level--;
        }
        else if(11 == key)
        {
            if(completelevel == level+1){printf("这是最后一关!!!");system("pause");}
            else level++;
        }
        else if(0 != key)
        {
            if(0 == bestdata[level]||move<bestdata[level])
            {
                bestdata[level] = move;
                printf("恭喜破纪录了\n");
                SaveData();
            }
            printf("恭喜进入下一关\n");
            level++;
            system("pause");
            system("cls");
        }
        if(completelevel == level)
        {
            printf("恭喜你打通所有关了！\n");
            system("pause");
            return 0;
        }
        system("cls");

    }
}
