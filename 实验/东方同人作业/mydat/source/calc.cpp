#include "../include/GV.h"

//Title处理
void calc_stage_title(){

        if(stage_title.appear_cnt==stage_count){//如果现在是开始显示的时刻的话
                stage_title.flag=1;
                stage_title.img = LoadGraph("../dat/img/board/subject0.png");
        }

        if(stage_title.flag==0)return;

        if(stage_title.cnt<128)//在最初的128次计数中逐渐变量
                stage_title.brt+=2;
        if(stage_title.cnt>128+128)//逐渐变暗
                stage_title.brt-=2;
        if(stage_title.cnt>128+128+128){//结束
                stage_title.cnt=0;
                stage_title.brt=0;
                stage_title.flag=0;
                DeleteGraph(stage_title.img);//释放图像
                return ;
        }

        stage_title.cnt++;
		//强制结束的时候需要释放图像
}

//道具的收取处理
void calc_item_indraw(int i){
        double v = item[i].state ? 8 : 3;//state如果是1的话速度为8否则为3
        double angle=atan2(ch.y-item[i].y,ch.x-item[i].x);//计算与自机的角度
        item[i].x += cos(angle)*v;
        item[i].y += sin(angle)*v;
}

//计算道具的移动等
void calc_item(){
        for(int i=0;i<ITEM_MAX;i++){
                if(item[i].flag>0){
                        if(item[i].state==0)
                                if(ch.y<ITEM_GET_BORDER_LINE)//如果是收取状态的话
                                        item[i].state=1;
                        if(item[i].state==0){//如果是普通状态的话
                                double x=ch.x-item[i].x,y=ch.y-item[i].y;
                                //如果在低速状态中的自机附近的话
                                if(CheckStatePad(configpad.slow)>0 &&
                                                x*x+y*y<ITEM_INDRAW_RANGE*ITEM_INDRAW_RANGE){
                                        calc_item_indraw(i);//收取一部分
                                }
                                else{
                                        if(item[i].v<2.5)//增加速度
                                                item[i].v+=0.06;
                                        item[i].y+=item[i].v;//移动
                                }
                        }
                        else{//如果是收取状态的话
                                calc_item_indraw(i);
                        }
                        item[i].cnt++;
                        if(item[i].y>FMY+50)
                                item[i].flag=0;
                }
        }
}


void calc_flash(){
        if(flash.flag>0){
                if(flash.knd==0){
                        if(flash.cnt==0)flash.brt=0;
                        if(flash.cnt<flash.to_cnt)
                                flash.brt+=255.0/flash.to_cnt;
                        else
                                flash.brt-=255.0/flash.to_cnt;
                }
                if(flash.knd==1){
                        if(flash.cnt==0)flash.brt=255;
                        flash.brt-=255.0/flash.to_cnt;
                }
                flash.cnt++;
                if(flash.knd==0){
                        if(flash.cnt>flash.to_cnt*2)
                                flash.flag=0;
                }
                if(flash.knd==1){
                        if(flash.cnt>flash.to_cnt)
                                flash.flag=0;
                }
        }
}

void calc_main(){
        calc_stage_title();
        calc_item();
        calc_flash();//闪屏(42)
}

