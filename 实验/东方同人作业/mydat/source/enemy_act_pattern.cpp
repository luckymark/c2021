#include "../include/GV.h"

double rang(double ang){
	return (-ang+ang*2*GetRand(10000)/10000.0);
}

//移动模式0
//向下移动后停止然后向上移动
void enemy_pattern0(int i){
	int t=enemy[i].cnt;
	if(t==0)
		enemy[i].vy=3;
	if(t==40)
		enemy[i].vy=0;
	if(t==40+enemy[i].wait)
		enemy[i].vy=-3;
}

//移动模式1
//向下移动然后停止向左下移动
void enemy_pattern1(int i){
	int t=enemy[i].cnt;
	if(t==0)
        enemy[i].vy=3;//向下移动
    if(t==40)
        enemy[i].vy=0;//停止
    if(t==40+enemy[i].wait){//在登录的时间区间内停止
        enemy[i].vx=-1;//向左
        enemy[i].vy=2;//向下移动
        enemy[i].muki=0;//设置方向为左
	}
}

//移动模式2
//向下移动然后停止然后向右下移动
void enemy_pattern2(int i){
    int t=enemy[i].cnt;
    if(t==0)
        enemy[i].vy=3;//向下移动
    if(t==40)
        enemy[i].vy=0;//停止
    if(t==40+enemy[i].wait){// 在登录的时间区间内停止
        enemy[i].vx=1;//向右
        enemy[i].vy=2;//向下移动
        enemy[i].muki=2;//设置方向为右
    }
}

//移动模式3
//迅速地下降然后向左移动
void enemy_pattern3(int i){
    int t=enemy[i].cnt;
    if(t==0)
        enemy[i].vy=5;//向下移动
    if(t==30){//途中方向向左
        enemy[i].muki=0;
    }
    if(t<100){
        enemy[i].vx-=5/100.0;//左方向加速
        enemy[i].vy-=5/100.0;//减速
    }
}

//移动模式4
//迅速地下降然后向右移动
void enemy_pattern4(int i){
    int t=enemy[i].cnt;
    if(t==0)
        enemy[i].vy=5;//向下移动
    if(t==30){//途中方向向右
        enemy[i].muki=2;
    }
    if(t<100){
        enemy[i].vx+=5/100.0;//右方向加速
        enemy[i].vy-=5/100.0;//減速
    }
}

//移动模式5
//斜着向左下移动
void enemy_pattern5(int i){
    int t=enemy[i].cnt;
    if(t==0){
        enemy[i].vx-=1;
        enemy[i].vy=2;
        enemy[i].muki=0;
    }
}

//移动模式6
//斜着向右下移动
void enemy_pattern6(int i){
    int t=enemy[i].cnt;
    if(t==0){
        enemy[i].vx+=1;
        enemy[i].vy=2;
        enemy[i].muki=2;
    }
}

//移动模式7
//停止然后就那样向左上移动
void enemy_pattern7(int i){
    int t=enemy[i].cnt;
    if(t==enemy[i].wait){//在登录的时间区间内停止
        enemy[i].vx=-0.7;//向左
        enemy[i].vy=-0.3;//向上移动
        enemy[i].muki=0;//设置方向为左
    }
}

//移动模式8
//停止然后就那样向右上移动
void enemy_pattern8(int i){
    int t=enemy[i].cnt;
    if(t==enemy[i].wait){//在登录的时间区间内停止
        enemy[i].vx=+0.7;//向右
        enemy[i].vy=-0.3;//向上移动
        enemy[i].muki=2;//设置方向为右
    }
}

//移动模式9
//停止然后就那样向上移动
void enemy_pattern9(int i){
    int t=enemy[i].cnt;
    if(t==enemy[i].wait)//在登录的时间区间内停止
        enemy[i].vy=-1;//向上移动
}


//移动模式10
//下降然后转着圈往上移动
void enemy_pattern10(int i){
    int t=enemy[i].cnt;
    if(t==0) enemy[i].vy=4;//向下移动
    if(t==40)enemy[i].vy=0;//停止
    if(t>=40){
        if(t%60==0){
            int r=cos(enemy[i].ang)< 0 ? 0 : 1;
            enemy[i].sp=6+rang(2);
            enemy[i].ang=rang(PI/4)+PI*r;
            enemy[i].muki=2-2*r;
        }
        enemy[i].sp*=0.95;
    }
    if(t>=40+enemy[i].wait){
        enemy[i].vy-=0.05;
    }
}