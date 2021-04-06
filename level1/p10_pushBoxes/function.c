#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "function.h"
 
//开始游戏
void start(int map[][L],int nmap) {
    int num,goal = 0;
    int score = 0;
    int bestscore = map[L][0];
    for(int i=0;i<L;i++){
        for(int j = 0;j<L;j++){
            if(map[i][j]==DESTINATION)
                goal++;
        }
    }
    print(map,score,bestscore);
    while(1){
        map = tuidong(map);
        score ++;
        if(map==NULL)
            return;
        print(map,score,bestscore);
        num = check(map);
        if(num==goal) {
            if(score<bestscore){
                printf("恭喜你打破了记录!\n");
                bestscore = score;
                write(bestscore,nmap);
            }
            printf("恭喜你通关了！\n");
            printf("即将返回主页......\n");
            Sleep(1500);
            break;
        }
    }
}

//打印迷宫
void print(int map[][L] ,int score,int bestscore){
    system("cls");
    int i, j;
    printf("当前累计步数: %d\n",score);
    printf("最佳成绩：    %d\n",bestscore);
    for(i = 0; i < L; i++){
        for(j = 0; j < L; j++){
            switch(map[i][j]){
                case ROUTE:
                    printf("  ");
                    break;
                case WALL:
                    printf("■");
                    break;
                case PLAYER:
                    printf("♀");
                    break;
                case BOX:
                    printf("◆");
                    break;
                case DESTINATION:
                    printf("●");
                    break;
                case FINSHED:
                    printf("★");
                    break;
                case PFINSHED:
                    printf("♀");
                    break;
            }
        }
        printf("\n");
    }
}

//进行小人的移动，整个移动的过程就是数组变化的过程
int (*tuidong(int map[][L]))[L]
{
    int count = 0,caw=0;//行和列
    int i,j,tui;
    for(i=0;i<L;i++){
        for (j=0;j<L;j++)
        {
            if(map[i][j]==PLAYER||map[i][j]==PFINSHED)
            {
                count=i;
                caw=j;
            }
        }
    }

    tui=getch();
    switch(tui)
    {//上
        case 'w':
            if(map[count-1][caw]==ROUTE||map[count-1][caw]==DESTINATION)
            {
                map[count][caw]-=2;
                map[count-1][caw]+=2;
            }
            else if(map[count-1][caw]==BOX||map[count-1][caw]==FINSHED)
            {
                if(map[count-2][caw]==ROUTE||map[count-2][caw]==DESTINATION)
                {
                    map[count][caw]-=2;
                    map[count-1][caw]-=1;
                    map[count-2][caw]+=3;
                }
            }
            break;

//下
        case 's':
            if(map[count+1][caw]==ROUTE||map[count+1][caw]==DESTINATION)
            {
                map[count][caw]-=2;
                map[count+1][caw]+=2;
            }
            else if(map[count+1][caw]==BOX||map[count+1][caw]==FINSHED)
            {
                if(map[count+2][caw]==ROUTE||map[count+2][caw]==DESTINATION)
                {
                    map[count][caw]-=2;
                    map[count+1][caw]-=1;
                    map[count+2][caw]+=3;
                }
            }
            break;
//左
        case 'a':
            if(map[count][caw-1]==ROUTE||map[count][caw-1]==DESTINATION)
            {
                map[count][caw]-=2;
                map[count][caw-1]+=2;
            }
            else if(map[count][caw-1]==BOX||map[count][caw-1]==FINSHED)
            {
                if(map[count][caw-2]==ROUTE||map[count][caw-2]==DESTINATION)
                {
                    map[count][caw]-=2;
                    map[count][caw-1]-=1;
                    map[count][caw-2]+=3;
                }
            }
            break;
//右
        case 'd':
            if(map[count][caw+1]==ROUTE||map[count][caw+1]==DESTINATION)
            {
                map[count][caw]-=2;
                map[count][caw+1]+=2;
            }
            else if(map[count][caw+1]==BOX||map[count][caw+1]==FINSHED)
            {
                if(map[count][caw+2]==ROUTE||map[count][caw+2]==DESTINATION)
                {
                    map[count][caw]-=2;
                    map[count][caw+1]-=1;
                    map[count][caw+2]+=3;
                }
            }
            break;
        case 'q':
            return 0;
    }
    return map;
}

//检测完成的箱子的个数
int check(int map[][L]){
    int num=0;
    for(int i=0;i<L;i++){
        for(int j=0;j<L;j++){
            if(map[i][j]==FINSHED){
                num++;
            }
        }
    }
    return num;
}

//读取地图内容
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

//游戏说明
void explain(){
    system("cls");
    printf("欢迎来到推箱子游戏......\n");
    printf("本游戏共有三关\n");
    printf("使用w上移，适用s下移\n");
    printf("使用a左移，使用d右移\n");
    printf("游戏目的是将所有的箱子推到对应的目的地上\n");
    printf("游戏过程中会随时记录你的步数，希望你能够打破记录！\n");
    printf("注意：在游戏中随时可以按q退出游戏，回到主界面\n");
    system("pause");
}

void write(int bestscore,int num){
    int (*map)[L];
    map=(int(*)[L])malloc((3*L+3)*sizeof(int[L]));
    FILE* fp;
    //现读取原有文件，为更新最佳成绩的值做好准备
    if ((fp = fopen("map.txt", "r")) == NULL) {
        printf("File failed to open......\n");
        system("pause");
        exit(0);
    }
    for (int i = 0; i < 3*L+3; i++) {
        if(i==L||i==2*L+1||i==3*L+2)
            fscanf(fp,"%d",&map[i][0]);
        else
            fscanf(fp, "%d %d %d %d %d %d %d %d", &map[i][0], &map[i][1], &map[i][2], &map[i][3], &map[i][4],
                   &map[i][5], &map[i][6], &map[i][7]);
    }
    fclose(fp);

    map[num*L+num-1][0] = bestscore; //更新最佳成绩
    //重新写入文件以更新最佳成绩
    if ((fp = fopen("map.txt", "w")) == NULL) {
        printf("File failed to open......\n");
        system("pause");
        exit(0);
    }
    for(int i = 0;i< 3*L+3;i++){
        if(i==L||i==2*L+1||i==3*L+2)
            fprintf(fp,"%d\n",map[i][0]);
        else
            fprintf(fp, "%d %d %d %d %d %d %d %d\n", map[i][0], map[i][1], map[i][2], map[i][3], map[i][4],
                    map[i][5], map[i][6], map[i][7]);
    }
    fclose(fp);
}


