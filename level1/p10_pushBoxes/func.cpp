//
// Created by chovy on 2021/5/6.
//
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "func.h"

void menu(void)
{
    int k=1;
    int (*map)[L];
    while(k)
    {
        system("cls");
        printf("\nwelcome to the game\n");
        printf("1.\t\tlevel1\n");
        printf("2.\t\tlevel2\n");
        printf("3.\t\tlevel3\n");
        printf("4.\t\texit\n");
        int c;
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                map=fileReader(1);
                start(map,1);
                break;
            }
            case 2:
            {
                map=fileReader(2);
                start(map,2);
                break;
            }
            case 3:
            {
                map=fileReader(3);
                start(map,3);
                break;
            }
            case 4:
            {
                printf("thank you for your playing......\n");
                k=0;
                Sleep(1500);
                break;
            }
            default:
                break;
        }
    }
}

void start(int map[][L],int nmap) {
    int num,goal = 0;
    for(int i=0;i<L;i++){
        for(int j = 0;j<L;j++){
            if(map[i][j]==destination)
                goal++;
        }
    }
    print(map);
    while(1){
        map = Push(map);
        if(map==NULL)
            return;
        print(map);
        num = check(map);
        if(num==goal)
        {
            printf("通过!\n");
            Sleep(500);
            break;
        }
    }
}

void print(int map[][L])
{
    system("cls");
    for(int i=0;i<L;++i)
    {
        for(int j=0;j<L;++j)
        {
            switch(map[i][j])
            {
                case route:
                {
                    printf(" ");
                    break;
                }
                case wall:
                {
                    printf("墙");
                    break;
                }
                case player:
                {
                    printf("人");
                    break;
                }
                case box:
                {
                    printf("回");
                    break;
                }
                case destination:
                {
                    printf("终");
                    break;
                }
            }
        }
        printf("\n");
    }
}

int check(int map[][L])
{
    int num=0;
    for(int i=0;i<L;++i)
    {
        for(int j=0;j<L;++j)
        {
            if(map[i][j]==finish)
                num++;
        }
    }
    return num;
}

int (*Push(int map[][L]))[L]
{
    int count=0,caw=0;
    int push;
    push=getch();
    for(int i=0;i<L;++i)
    {
        for(int j=0;j<L;++j)
        {
            if(map[i][j]==player||map[i][j]==pfinish)
            {
                count=i;
                caw=j;
            }
        }
    }
    switch (push)
    {
        case 'w':
            if(map[count-1][caw]==route||map[count-1][caw]==destination)
            {
                map[count][caw]-=2;
                map[count-1][caw]+=2;
            }
            else if(map[count-1][caw]==box||map[count-1][caw]==finish)
            {
                if(map[count-2][caw]==route||map[count-2][caw]==destination)
                {
                    map[count][caw]-=2;
                    map[count-1][caw]-=1;
                    map[count-2][caw]+=3;
                }
            }
            break;

//下
        case 's':
            if(map[count+1][caw]==route||map[count+1][caw]==destination)
            {
                map[count][caw]-=2;
                map[count+1][caw]+=2;
            }
            else if(map[count+1][caw]==box||map[count+1][caw]==finish)
            {
                if(map[count+2][caw]==route||map[count+2][caw]==destination)
                {
                    map[count][caw]-=2;
                    map[count+1][caw]-=1;
                    map[count+2][caw]+=3;
                }
            }
            break;
//左
        case 'a':
            if(map[count][caw-1]==route||map[count][caw-1]==destination)
            {
                map[count][caw]-=2;
                map[count][caw-1]+=2;
            }
            else if(map[count][caw-1]==box||map[count][caw-1]==finish)
            {
                if(map[count][caw-2]==route||map[count][caw-2]==destination)
                {
                    map[count][caw]-=2;
                    map[count][caw-1]-=1;
                    map[count][caw-2]+=3;
                }
            }
            break;
//右
        case 'd':
            if(map[count][caw+1]==route||map[count][caw+1]==destination)
            {
                map[count][caw]-=2;
                map[count][caw+1]+=2;
            }
            else if(map[count][caw+1]==box||map[count][caw+1]==finish)
            {
                if(map[count][caw+2]==route||map[count][caw+2]==destination)
                {
                    map[count][caw]-=2;
                    map[count][caw+1]-=1;
                    map[count][caw+2]+=3;
                }
            }
    }
    return map;
}

int (*fileReader(int num))[L]{
    int (*map)[L];
    FILE* fp;
    if ((fp = fopen("map.txt", "r")) == NULL) {
        printf("File failed to open......\n");
        system("pause");
        exit(0);
    }
    for(;num>0;num--) {
        for (int i = 0; i < L; i++) {
            fscanf(fp, "%d %d %d %d %d %d %d %d", &map[i][0], &map[i][1], &map[i][2], &map[i][3], &map[i][4],
                   &map[i][5], &map[i][6], &map[i][7]);
        }
        fscanf(fp,"%d",&map[L][0]);
    }
    fclose(fp);
    return map;
}
