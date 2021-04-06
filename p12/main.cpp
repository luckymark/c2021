#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
const int M = 10000;

int N,P; // 表示当前数量与总数量

typedef struct{
    int num;                //货品编号
    char name[30];              //货品名称
    int stock;                //原始库存
    int in;                       //入库数目
    int out;                //出库数目
    int amount;                   //最终库存
} goods;

goods g[M];                 //用于存放货品信息
goods in[M];                //用于存放入库货品信息
goods out[M];               //用于存放出库货品信息

void read();    //读取货品信息

void add();

void off();

void display();

int write();

int main(){
  int op = 1;
  read();
  while(op){
    system("cls");
    printf("\n\n");
    printf("*********************************************\n");
    printf("*                                           *\n");
    printf("*       1.add              2.off            *\n");
    printf("*                                           *\n");
    printf("*       3.display          4.exit           *\n");
    printf("*                                           *\n");
    printf("*********************************************\n");
    printf("Select the function you need:");
    scanf("%d",&op);
    switch(op){
      case 1:add(); display();break;
      case 2:off(); display();break;
      case 3:display(); break;
      case 4:op = 0; break;
    }
    printf("\n\nPress any key to continue...\n");
  }
  write();
  system("pause");
  return 0;
}

void read(){
    FILE* fp;
    N = 0;
    fp = fopen("C:\\Users\\john\\CLionProjects\\p12\\goods.txt","r");
    while(fscanf(fp,"%d%s", &g[N].num, &g[N].name) != EOF)
        N ++;
    fclose(fp);
    P = N;
}

void add(){        //读入入库文件
    FILE* fp;
    int i,j;
    N = 0;
    fp = fopen("C:\\Users\\john\\CLionProjects\\p12\\stock.txt","r");
    while(fscanf(fp,"%d%d",&in[N].num, &in[N].in) != EOF)
        N++;
    fclose(fp);
    for(i = 0;i < P;i++){
        for(j = 0;j < N;j++){
            if(in[i].num == g[j].num)
                g[j].in = in[j].in;
        }
    }
    for(i = 0;i < P;i++)
        g[i].amount = g[i].stock + g[i].in;
}

void off(){    //读入出库文件
    FILE* fp;
    int i,j;
    N=0;
    fp = fopen("C:\\Users\\john\\CLionProjects\\p12\\stockout.txt","r");
    while(fscanf(fp,"%d%d", &out[N].num, &out[N].out) != EOF)
        N++;
    fclose(fp);
    for(i = 0;i < P; i++){
        for(j = 0;j < N; j++){
            if(out[i].num == g[j].num)
                g[j].out = out[j].out;
        }
    }
    for(i = 0; i < P; i++)
        g[i].amount = g[i].stock + g[i].in - g[i].out;
}

void display(){        //显示库存情况
    int i,j;
    system("cls");
    printf("num       name     stock       add       off     final\n");
    for(i = 0,j = 1;i < P; i++, j++){
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
            printf("%-9d  %-10s%-10d%-10d%-10d%-10d\n", g[i].num, g[i].name, g[i].stock, g[i].in, g[i].out, g[i].amount);
            if(j % 10 == 0 && j != P){        //每次显示十行
                printf("Press any key to continue...");
                getch();
                puts("\n");
                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN | FOREGROUND_BLUE);
                printf("num  name  add  off  final\n");
           }
    }
}

int write(){
    FILE* fp;
    int i;
    fp = fopen("C:\\Users\\john\\CLionProjects\\p12\\amount.txt","w");
    for(i = 0; i < P; i++)
        fprintf(fp,"%d %s %d %d %d %d\n",g[i].num,g[i].name,g[i].stock,g[i].in,g[i].out,g[i].amount);
    fclose(fp);
    return 1;
}
