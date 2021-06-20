/*推箱子小游戏，经测试可以正常运行，
1. 将p09迷宫游戏改造为“推箱子”游戏；
1. 在地图中增加箱子、箱子目标位置等图形；
1. 当玩家将所有箱子归位，则显示玩家赢得了游戏；
1. 按玩家走动步数记分；
1. 设计多个关卡，每一关的地图从文件中读取，玩家每关的分数记录到文件中；
注意：运行前请将各个文件放到同一工程目录下，
若不能正常运行，请将读写文件的路径改为绝对路径*/ 

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "function.h" 

int main() {
    int(*map)[L];
    char c;
    while (1) {
        system("cls");
        printf("---------------------\n");
        printf("---欢迎来到推箱子小游戏---\n");
        printf("----1. 关卡1 -----\n");
        printf("----2. 关卡2 -----\n");
        printf("----3. 关卡3 -----\n");
        printf("----4. 游戏说明---\n");
        printf("----0. 退出游戏 -----\n");
        printf("--------------------\n");
        c = _getch();
        switch (c) {
            case '1':
                map= fileReader(1);
                start(map,1);
                break;
            case '2':
                map = fileReader(2);
                start(map,2);
                break;
            case '3':
                map = fileReader(3);
                start(map,3);
                break;
            case '4':
                explain();
                break;
            case '0':
                printf("欢迎下次继续游玩........\n");
                Sleep(1500);
                exit(0);
        }
    }
}

