#include "../include/GV.h"

extern void shot_bullet_H000(int);extern void shot_bullet_H001(int);extern void shot_bullet_H002(int);
extern void shot_bullet_H003(int);extern void shot_bullet_H004(int);extern void shot_bullet_H005(int);
extern void shot_bullet_H006(int);extern void shot_bullet_H007(int);extern void shot_bullet_H008(int);
extern void shot_bullet_H009(int);extern void shot_bullet_H010(int);extern void shot_bullet_H011(int);
extern void shot_bullet_H012(int);extern void shot_bullet_H013(int);extern void shot_bullet_H014(int);
extern void shot_bullet_H015(int);extern void shot_bullet_H016(int);extern void shot_bullet_H017(int);

void (*shot_bullet[SHOT_KND_MAX])(int) ={
        shot_bullet_H000,shot_bullet_H001,shot_bullet_H002,shot_bullet_H003,shot_bullet_H004,
        shot_bullet_H005,shot_bullet_H006,shot_bullet_H007,shot_bullet_H008,shot_bullet_H009,
        shot_bullet_H010,shot_bullet_H011,shot_bullet_H012,shot_bullet_H013,shot_bullet_H014,
        shot_bullet_H015,shot_bullet_H016,shot_bullet_H017,
};

double shotatan2(int n){
	return atan2(ch.y-enemy[shot[n].num].y,ch.x-enemy[shot[n].num].x);
}

int shot_search(int n){
	int i;
	for(i=0;i<SHOT_BULLET_MAX;i++){
		if(shot[n].bullet[i].flag==0){
			return i;
		}
	}
	return -1;
}
void shot_calc(int n){
        int i,max=0;
        if(enemy[shot[n].num].flag!=1)//如果敌人被打倒的话
                shot[n].flag=2;//将之前登录的射击的flag设置为无效
        for(i=0;i<SHOT_BULLET_MAX;i++){//计算第n号弹幕数据的子弹
                if(shot[n].bullet[i].flag>0){//如果那子弹并没有被登录
                        shot[n].bullet[i].x+=cos(shot[n].bullet[i].angle)*shot[n].bullet[i].spd;
                        shot[n].bullet[i].y+=sin(shot[n].bullet[i].angle)*shot[n].bullet[i].spd;
                        shot[n].bullet[i].cnt++;
                        if(shot[n].bullet[i].x<-50 || shot[n].bullet[i].x>FMX+50 ||
                                shot[n].bullet[i].y<-50 || shot[n].bullet[i].y>FMY+50){//如果跑到画面外面的话
                                if(shot[n].bullet[i].till<shot[n].bullet[i].cnt)//且比最低程度不会销毁的时间还要很长
                                        shot[n].bullet[i].flag=0;//销毁之
                        }
                }
        }
        //查询当前显示中的子弹的熟练是否至少还有一个
        for(i=0;i<SHOT_BULLET_MAX;i++)
                if(shot[n].bullet[i].flag>0)
                        return;
        if(enemy[shot[n].num].flag!=1){
                shot[n].flag=0;//終了
                enemy[shot[n].num].flag=0;
        }
}
void shot_main(){
        int i;
        for(i=0;i<SHOT_MAX;i++){//弹幕数据计算
				//如果flag为有效且设定的种类没有错误的情况（防止溢出）
                if(shot[i].flag!=0 && 0<=shot[i].knd && shot[i].knd<SHOT_KND_MAX){
                        shot_bullet[shot[i].knd](i);//调用.knd的弹幕计算函数的函数指针
                        shot_calc(i);//计算第i号弹幕
                        shot[i].cnt++;
                }
        }
}

