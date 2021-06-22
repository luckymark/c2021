#include "../include/GV.h"

//fps
#define FLAME 60

//fps的计数器，60帧1次记录作为基准的时刻
int fps_count,count0t;
//为了进行平均计算,记录60次1个周期的时间
int f[FLAME];
//平均fps
double ave;

//以FLAME fps为目标进行fps的计算和控制
void fps_wait(){
    int term,i,gnt;
    static int t=0;
    if(fps_count==0){//60帧1次的话
        if(t==0)//如果是最开始的话不等待
            term=0;
        else//基于上一次记录了的时间计算
            term=count0t+1000-GetNowCount();
    }
    else    //应该等待的时间=当前的理论时刻-当前的实际时刻
        term = (int)(count0t+fps_count*(1000.0/FLAME))-GetNowCount();

    if(term>0)//只等待应该等待的时间
        Sleep(term);

    gnt=GetNowCount();

    if(fps_count==0)// 60帧进行1次基准变更
        count0t=gnt;
    f[fps_count]=gnt-t;//记录1个周期的时间
    t=gnt;
    //平均计算
    if(fps_count==FLAME-1){
        ave=0;
        for(i=0;i<FLAME;i++)
            ave+=f[i];
        ave/=FLAME;
    }
    fps_count = (++fps_count)%FLAME ;
}

//在x,y的位置显示fps
void draw_fps(int x, int y){
    if(ave!=0){
        DrawFormatString(x, y,color[0],"[%.1f]",1000/ave);
    }
    return;
}