#include "../include/GV.h"
//名称的最大字数
#define STR_MAX 64
//可以检查的函数的最大数
#define FUNC_MAX 30
//计数当前是第几个
int func_count;
//保存上一次测定的时间
LONGLONG lt;
//保存测定数据用的变量
typedef struct{
        int tm;
        char str[STR_MAX];
}func_tm_t;
func_tm_t func_tm[FUNC_MAX];

//登录在st变量中接受到的数据。如果flag为1的话就重置
void enter_func_tm(char st[], int flag){
        int i;
        LONGLONG nowtm;
        if(func_count>=FUNC_MAX){
                printfDx("func_count的值%d异常\n",func_count);
                return ;
        }
        nowtm=GetNowHiPerformanceCount() ;
        if(nowtm-lt<INT_MAX){//如果在int可以表示的范围内的话
                func_tm[func_count].tm=(int)(nowtm-lt);//保存处理时间
                memcpy(func_tm[func_count].str,st,STR_MAX-1);//复制字符串
                func_tm[func_count].str[STR_MAX-1]=0;//放入终止符（\0）
        }
        else//如果超出的话
                func_tm[func_count].tm=-1;//错误

        lt=nowtm ;//保存上一次记录的时刻

        if(flag==1){//重置
                for(i=func_count+1;i<FUNC_MAX;i++)
                        func_tm[i].str[0]=0;
                func_count=0;
        }
        else
                func_count++;
}

//绘制数据
void draw_func_tm(int x, int y){
        int i;
        unsigned int total=0;
        for(i=0;i<FUNC_MAX;i++){
                if(func_tm[i].str[0]==0)break;
                DrawFormatStringToHandle(x,y+14*i,color[0],font[0],"%05.2f:%s",func_tm[i].tm/1000.0,func_tm[i].str );
                total+=func_tm[i].tm;
        }
        DrawFormatStringToHandle(x,y+14*i,color[0],font[0],"合计:%05.2f",total/1000.0);
}