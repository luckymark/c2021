#include "../include/GV.h"

//只发射一发，向自机直线移动
void shot_bullet_H000(int n){
        int k;
        if(shot[n].cnt==0){
                if(shot[n].flag!=2 && (k=shot_search(n))!=-1){
                        shot[n].bullet[k].knd   =enemy[shot[n].num].blknd2;
                        shot[n].bullet[k].angle =shotatan2(n);
                        shot[n].bullet[k].flag  =1;
                        shot[n].bullet[k].x             =enemy[shot[n].num].x;
                        shot[n].bullet[k].y             =enemy[shot[n].num].y;
                        shot[n].bullet[k].col   =enemy[shot[n].num].col;
                        shot[n].bullet[k].cnt   =0;
                        shot[n].bullet[k].spd   =3;
                        se_flag[0]=1;
                }
        }
}

//100次计数中发射10发，向着自机直线发射（一般是自机狙）
void shot_bullet_H001(int n){
        int t=shot[n].cnt;
        int k;
        if(t>=0 && t<100 && t%10==0){//100次计数中每10次计数发射1次
                if(shot[n].flag!=2 && (k=shot_search(n))!=-1){//敌人存在，并且子弹可登录的话
                        shot[n].bullet[k].knd   =enemy[shot[n].num].blknd2;//子弹登录
                        shot[n].bullet[k].angle =shotatan2(n);//角度
                        shot[n].bullet[k].flag  =1;//flag
                        shot[n].bullet[k].x     =enemy[shot[n].num].x;//坐标
                        shot[n].bullet[k].y     =enemy[shot[n].num].y;
                        shot[n].bullet[k].col   =enemy[shot[n].num].col;//颜色
                        shot[n].bullet[k].cnt   =0;//计数器
                        shot[n].bullet[k].spd   =3;//速度
                        se_flag[0]=1;
                }
        }
}

//100次计数中发射10发，向着自机直线发射（记忆角度）
void shot_bullet_H002(int n){
        int t=shot[n].cnt;
        int k;
        if(t>=0 && t<100 && t%10==0){
                if(t==0)
                        shot[n].base_angle[0]=shotatan2(n);
                if(shot[n].flag!=2 && (k=shot_search(n))!=-1){
                        shot[n].bullet[k].knd   =enemy[shot[n].num].blknd2;
                        shot[n].bullet[k].angle =shot[n].base_angle[0];
                        shot[n].bullet[k].flag  =1;
                        shot[n].bullet[k].x     =enemy[shot[n].num].x;
                        shot[n].bullet[k].y     =enemy[shot[n].num].y;
                        shot[n].bullet[k].col   =enemy[shot[n].num].col;
                        shot[n].bullet[k].cnt   =0;
                        shot[n].bullet[k].spd   =3;
                        se_flag[0]=1;
                }
        }
}

//100次计数中10发，向着自机速度变化地直线发射
void shot_bullet_H003(int n){
        int t=shot[n].cnt;
        int k;
        if(t>=0 && t<100 && t%10==0){
                if(shot[n].flag!=2 && (k=shot_search(n))!=-1){
                        shot[n].bullet[k].knd   =enemy[shot[n].num].blknd2;
                        shot[n].bullet[k].angle =shotatan2(n);
                        shot[n].bullet[k].flag  =1;
                        shot[n].bullet[k].x     =enemy[shot[n].num].x;
                        shot[n].bullet[k].y     =enemy[shot[n].num].y;
                        shot[n].bullet[k].col   =enemy[shot[n].num].col;
                        shot[n].bullet[k].cnt   =0;
                        shot[n].bullet[k].spd   =1+5.0/100*t;
                        se_flag[0]=1;
                }
        }
}

//0.5秒一次地圆形发射
void shot_bullet_H004(int n){
        int t=shot[n].cnt;
        int k;
        if(t>=0 && t<120 && t%20==0){
                double angle=shotatan2(n);
                for(int i=0;i<20;i++){
                        if(shot[n].flag!=2 && (k=shot_search(n))!=-1){
                                shot[n].bullet[k].knd   =enemy[shot[n].num].blknd2;
                                shot[n].bullet[k].angle =angle+PI2/20*i;
                                shot[n].bullet[k].flag  =1;
                                shot[n].bullet[k].x     =enemy[shot[n].num].x;
                                shot[n].bullet[k].y     =enemy[shot[n].num].y;
                                shot[n].bullet[k].col   =enemy[shot[n].num].col;
                                shot[n].bullet[k].cnt   =0;
                                shot[n].bullet[k].spd   =4;
                        }
                        se_flag[0]=1;
                }
        }
}

//散射
void shot_bullet_H005(int n){
        int t=shot[n].cnt;
        int k;
        if(t>=0 && t<120 && t%2==0){
                if(shot[n].flag!=2 && (k=shot_search(n))!=-1){
                        shot[n].bullet[k].knd   =enemy[shot[n].num].blknd2;
                        shot[n].bullet[k].angle =shotatan2(n)+rang(PI/4);
                        shot[n].bullet[k].flag  =1;
                        shot[n].bullet[k].x     =enemy[shot[n].num].x;
                        shot[n].bullet[k].y     =enemy[shot[n].num].y;
                        shot[n].bullet[k].col   =enemy[shot[n].num].col;
                        shot[n].bullet[k].cnt   =0;
                        shot[n].bullet[k].spd   =3+rang(1.5);
                        se_flag[0]=1;
                }
        }
}

//散射（减速）
void shot_bullet_H006(int n){
        int t=shot[n].cnt;
        int k;
        if(t>=0 && t<120 && t%2==0){
                if(shot[n].flag!=2 && (k=shot_search(n))!=-1){
                        shot[n].bullet[k].knd   =enemy[shot[n].num].blknd2;
                        shot[n].bullet[k].angle =shotatan2(n)+rang(PI/4);
                        shot[n].bullet[k].flag  =1;
                        shot[n].bullet[k].x     =enemy[shot[n].num].x;
                        shot[n].bullet[k].y     =enemy[shot[n].num].y;
                        shot[n].bullet[k].col   =enemy[shot[n].num].col;
                        shot[n].bullet[k].cnt   =0;
                        shot[n].bullet[k].spd   =4+rang(2);
                        se_flag[0]=1;
                }
        }
        for(int i=0;i<SHOT_BULLET_MAX;i++){//所有子弹的循环
                if(shot[n].bullet[i].spd>1.5)//如果速度大于1.5的话
                        shot[n].bullet[i].spd-=0.04;//减速
        }
}

//妖梦弹幕
void shot_bullet_H007(int n){
        int t=shot[n].cnt;
        int k;
        if(t>=0 && t<=150 && t%10==0){
                for(int i=0;i<20;i++){
                        if(shot[n].flag!=2 && (k=shot_search(n))!=-1){
                                shot[n].bullet[k].knd   =7;
                                shot[n].bullet[k].angle =PI2/20*i;
                                shot[n].bullet[k].flag  =1;
                                shot[n].bullet[k].x     =enemy[shot[n].num].x+cos(PI/2+PI/150*t)*100;
                                shot[n].bullet[k].y     =enemy[shot[n].num].y+sin(PI/2+PI/150*t)*100;
                                shot[n].bullet[k].col   =2;
                                shot[n].bullet[k].cnt   =0;
                                shot[n].bullet[k].spd   =1.2;
                        }
                }
                for(int i=0;i<20;i++){
                        if(shot[n].flag!=2 && (k=shot_search(n))!=-1){
                                shot[n].bullet[k].knd   =7;
                                shot[n].bullet[k].angle =PI2/20*i;
                                shot[n].bullet[k].flag  =1;
                                shot[n].bullet[k].x     =enemy[shot[n].num].x+cos(PI/2-PI/150*t)*100;
                                shot[n].bullet[k].y     =enemy[shot[n].num].y+sin(PI/2-PI/150*t)*100;
                                shot[n].bullet[k].col   =4;
                                shot[n].bullet[k].cnt   =0;
                                shot[n].bullet[k].spd   =1.2;
                                se_flag[0]=1;
                        }
                }
        }
}

void shot_bullet_H008(int n){
    int t=shot[n].cnt;
    int k;
    if(t>=0 && t<1200 && t%90==0){
        double angle=rang(PI);
        for(int j=0;j<2;j++){//中途的时候就分裂为两部分
            for(int i=0;i<60;i++){//一次60个
                if(shot[n].flag!=2 && (k=shot_search(n))!=-1){
                    shot[n].bullet[k].knd    =8;//第8号子弹
                    shot[n].bullet[k].angle  =angle+PI2/60*i;//60个圆
                    shot[n].bullet[k].flag   =1;
                    shot[n].bullet[k].x      =enemy[shot[n].num].x;
                    shot[n].bullet[k].y      =enemy[shot[n].num].y;
                    shot[n].bullet[k].col    =4;//第4号颜色
                    shot[n].bullet[k].cnt    =0;
                    shot[n].bullet[k].state  =j;//状态。0或者是1表示不同旋转。
                    shot[n].bullet[k].spd    =2;
                }
            }
        }
        se_flag[0]=1;//播放发射音效
    }
    for(int i=0;i<SHOT_BULLET_MAX;i++){//所有子弹的循环
        if(shot[n].bullet[i].flag>0){//如果有登录了的子弹
            int state=shot[n].bullet[i].state;
            int cnt=shot[n].bullet[i].cnt;
            if(30<cnt && cnt<120){//如果是30~120次计数
                shot[n].bullet[i].spd-=1.2/90.0;//90次计数总共减去1.2
                shot[n].bullet[i].angle+=(PI/2)/90.0*(state?-1:1);//90次计数总共倾斜90°
            }
        }
    }
}
void shot_bullet_H009(int n){}
void shot_bullet_H010(int n){}
void shot_bullet_H011(int n){}
void shot_bullet_H012(int n){}
void shot_bullet_H013(int n){}
void shot_bullet_H014(int n){}
void shot_bullet_H015(int n){}
void shot_bullet_H016(int n){}
void shot_bullet_H017(int n){}
