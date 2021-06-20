#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "function.h"
 
//��ʼ��Ϸ
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
                printf("��ϲ������˼�¼!\n");
                bestscore = score;
                write(bestscore,nmap);
            }
            printf("��ϲ��ͨ���ˣ�\n");
            printf("����������ҳ......\n");
            Sleep(1500);
            break;
        }
    }
}

//��ӡ�Թ�
void print(int map[][L] ,int score,int bestscore){
    system("cls");
    int i, j;
    printf("��ǰ�ۼƲ���: %d\n",score);
    printf("��ѳɼ���    %d\n",bestscore);
    for(i = 0; i < L; i++){
        for(j = 0; j < L; j++){
            switch(map[i][j]){
                case ROUTE:
                    printf("  ");
                    break;
                case WALL:
                    printf("��");
                    break;
                case PLAYER:
                    printf("��");
                    break;
                case BOX:
                    printf("��");
                    break;
                case DESTINATION:
                    printf("��");
                    break;
                case FINSHED:
                    printf("��");
                    break;
                case PFINSHED:
                    printf("��");
                    break;
            }
        }
        printf("\n");
    }
}

//����С�˵��ƶ��������ƶ��Ĺ��̾�������仯�Ĺ���
int (*tuidong(int map[][L]))[L]
{
    int count = 0,caw=0;//�к���
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
    {//��
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

//��
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
//��
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
//��
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

//�����ɵ����ӵĸ���
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

//��ȡ��ͼ����
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

//��Ϸ˵��
void explain(){
    system("cls");
    printf("��ӭ������������Ϸ......\n");
    printf("����Ϸ��������\n");
    printf("ʹ��w���ƣ�����s����\n");
    printf("ʹ��a���ƣ�ʹ��d����\n");
    printf("��ϷĿ���ǽ����е������Ƶ���Ӧ��Ŀ�ĵ���\n");
    printf("��Ϸ�����л���ʱ��¼��Ĳ�����ϣ�����ܹ����Ƽ�¼��\n");
    printf("ע�⣺����Ϸ����ʱ���԰�q�˳���Ϸ���ص�������\n");
    system("pause");
}

void write(int bestscore,int num){
    int (*map)[L];
    map=(int(*)[L])malloc((3*L+3)*sizeof(int[L]));
    FILE* fp;
    //�ֶ�ȡԭ���ļ���Ϊ������ѳɼ���ֵ����׼��
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

    map[num*L+num-1][0] = bestscore; //������ѳɼ�
    //����д���ļ��Ը�����ѳɼ�
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


