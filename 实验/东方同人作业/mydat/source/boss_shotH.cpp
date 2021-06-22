#include "../include/GV.h"

extern int search_boss_shot();
extern int search_lazer();
extern double bossatan2();
extern double bossatan3(int k,double x,double y);
extern int move_boss_pos(double x1,double y1,double x2,double y2,double dist, int t);
extern void input_phy_pos(double x,double y,int t);
extern void input_lphy(lazer_t *laz, int time, double angle);


void boss_shot_bulletH000(){
#define TM000 120
    int i,k,t=boss_shot.cnt%TM000;
    double angle;
    if(t<60 && t%10==0){
        angle=bossatan2();
        for(i=0;i<30;i++){
            if((k=search_boss_shot())!=-1){
                boss_shot.bullet[k].col      = 0;
                boss_shot.bullet[k].x     = boss.x;
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 8;
                boss_shot.bullet[k].angle = angle+PI2/30*i;
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt      = 0;
                boss_shot.bullet[k].spd      = 3;
                se_flag[0]=1;
            }
        }
    }
//    for(i=0;i<BOSS_BULLET_MAX;i++){
//        if(boss_shot.bullet[i].flag>0){
//
//        }
//    }
}

void boss_shot_bulletH001(){
#define TM001 60
    int i,k,t=boss_shot.cnt%TM001,t2=boss_shot.cnt;
    static int cnum;
    double angle;
    if(t2==0)
        cnum=0;
    if(t==0){
        boss_shot.base_angle[0]=bossatan2();
        if(cnum%4==3){
            move_boss_pos(40,30,FMX-40,120,60, 60);
        }
    }
    if(t==TM001/2-1)
        boss_shot.base_angle[0]+=PI2/20/2;
	if(t%(TM001/10)==0){
        angle=bossatan2();
        for(i=0;i<20;i++){
            if((k=search_boss_shot())!=-1){
                boss_shot.bullet[k].col   = 4;
                boss_shot.bullet[k].x     = boss.x;
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 8;
                boss_shot.bullet[k].angle = boss_shot.base_angle[0]+PI2/20*i;
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt   = 0;
                boss_shot.bullet[k].spd   = 2.7;
                se_flag[0]=1;
            }
        }
    }
    if(t%4==0){
        if((k=search_boss_shot())!=-1){
            boss_shot.bullet[k].col   = 0;
            boss_shot.bullet[k].x     = GetRand(FMX);
            boss_shot.bullet[k].y     = GetRand(200);
            boss_shot.bullet[k].knd   = 8;
            boss_shot.bullet[k].angle = PI/2;
            boss_shot.bullet[k].flag  = 1;
            boss_shot.bullet[k].cnt   = 0;
            boss_shot.bullet[k].spd   = 1+rang(0.5);
            se_flag[0]=1;
        }
    }
//    for(i=0;i<BOSS_BULLET_MAX;i++){
//        if(boss_shot.bullet[i].flag>0){
//
//        }
//    }
    if(t==TM001-1)
        cnum++;
}
void boss_shot_bulletH002(){
#define TM002 650
    int i,k,t=boss_shot.cnt%TM002;
    double angle;
    if(t==0 || t==210){
        move_boss_pos(40,50,FMX-40,150,100, 80);
    }
    if(t<180){
        for(i=0;i<2;i++){
            if((k=search_boss_shot())!=-1){
                boss_shot.bullet[k].col   = GetRand(6);
                boss_shot.bullet[k].x     = boss.x;
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 7;
                boss_shot.bullet[k].angle = rang(PI2/20)+PI2/10*t;
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt   = 0;
                boss_shot.bullet[k].spd   = 3.2+rang(2.1);
                boss_shot.bullet[k].state = 0;
                boss_shot.bullet[k].kaiten= 1;
            }
        }
        if(t%10==0)
            se_flag[0]=1;
    }
    if(210<t && t<270 && t%3==0){
        angle=bossatan2();
        for(i=0;i<8;i++){
            if((k=search_boss_shot())!=-1){
                boss_shot.bullet[k].col   = 0;
                boss_shot.bullet[k].x     = boss.x;
                boss_shot.bullet[k].y     = boss.y;
                boss_shot.bullet[k].knd   = 7;
                boss_shot.bullet[k].angle = angle-PI/2*0.8+PI*0.8/7*i+rang(PI/180);
                boss_shot.bullet[k].flag  = 1;
                boss_shot.bullet[k].cnt   = 0;
                boss_shot.bullet[k].spd   = 3.0+rang(0.3);
                boss_shot.bullet[k].state = 2;
                boss_shot.bullet[k].kaiten= 1;
            }
        }
        if(t%10==0)
            se_flag[0]=1;
    }
    for(i=0;i<BOSS_BULLET_MAX;i++){
        if(boss_shot.bullet[i].flag>0){
            if(boss_shot.bullet[i].state==0){
                if(t==190){
                    boss_shot.bullet[i].kaiten=0;
                    boss_shot.bullet[i].spd   =0;
                    boss_shot.bullet[i].col   =9;
                    boss_shot.bullet[i].cnt   =0;
                    boss_shot.bullet[i].state =1;
                }
            }
            if(boss_shot.bullet[i].state==1){
                if(boss_shot.bullet[i].cnt==200){
                    boss_shot.bullet[i].angle=rang(PI);
                    boss_shot.bullet[i].kaiten=1;
                }
                if(boss_shot.bullet[i].cnt>200)
                    boss_shot.bullet[i].spd+=0.01;
            }
        }
    }
}

void boss_shot_bulletH003(){
#define TM003 600
#define DF003 20 
    int i,j,k,t=boss_shot.cnt%TM003,t2=boss_shot.cnt;
    static int tcnt,cnt,cnum;
    double angle;
    if(t2==0){
        input_phy_pos(FMX/2,FMY/2, 50);
        cnum=0;
    }
    if(t==0){
        boss_shot.base_angle[0]=bossatan2();
        cnt=0;
        tcnt=2;
    }
    if(t<540 && t%3){
        angle=bossatan2();
        if(tcnt-2==cnt || tcnt-1==cnt){
            if(tcnt-1==cnt){
                boss_shot.base_angle[1]=boss_shot.base_angle[0]+PI2/DF003*cnt*(cnum?-1:1)-PI2/(DF003*6)*3;
                tcnt+=DF003-2;
            }
        }
        else{
            for(i=0;i<6;i++){
                if((k=search_boss_shot())!=-1){
                    boss_shot.bullet[k].col      = cnum?1:4;
                    boss_shot.bullet[k].x     = boss.x;
                    boss_shot.bullet[k].y     = boss.y;
                    boss_shot.bullet[k].knd   = 8;
                    boss_shot.bullet[k].angle 
                        = boss_shot.base_angle[0]+PI2/DF003*cnt*(cnum?-1:1)+PI2/(DF003*6)*i*(cnum?-1:1);
                    boss_shot.bullet[k].flag  = 1;
                    boss_shot.bullet[k].cnt      = 0;
                    boss_shot.bullet[k].spd      = 2;
                    se_flag[0]=1;
                }
            }
        }
        cnt++;
    }
    if(40<t&&t<540 && t%30==0){
        for(j=0;j<3;j++){
            angle=boss_shot.base_angle[1]-PI2/36*4;
            for(i=0;i<27;i++){
                if((k=search_boss_shot())!=-1){
                    boss_shot.bullet[k].col   = cnum?6:0;
                    boss_shot.bullet[k].x     = boss.x;
                    boss_shot.bullet[k].y     = boss.y;
                    boss_shot.bullet[k].knd   = 7;
                    boss_shot.bullet[k].angle = angle;
                    boss_shot.bullet[k].flag  = 1;
                    boss_shot.bullet[k].cnt   = 0;
                    boss_shot.bullet[k].spd   = 4-1.6/3*j;
                    se_flag[0]=1;
                }
                angle-=PI2/36;
            }
        }
    }
//    for(i=0;i<BOSS_BULLET_MAX;i++){
//        if(boss_shot.bullet[i].flag>0){
//
//        }
//    }
    if(t==TM003-1)
        cnum++;
}

void boss_shot_bulletH004(){
#define TM004 200
    int i,j,k,n,t=boss_shot.cnt%TM004,t2=boss_shot.cnt;
    static int tm;
    double angle;
    if(t==0)
        tm=190+rang(30);
    angle=PI*1.5+PI/6*sin(PI2/tm*t2);
    if(t2%4==0){
        for(n=0;n<8;n++){
            if((k=search_boss_shot())!=-1){
                boss_shot.bullet[k].flag=1;
                boss_shot.bullet[k].state=0;
                boss_shot.bullet[k].cnt=0;
                boss_shot.bullet[k].knd=4;
                boss_shot.bullet[k].col=0;
                boss_shot.bullet[k].angle=0;
                boss_shot.bullet[k].eff_detail=1;
                boss_shot.bullet[k].x=boss.x;
                boss_shot.bullet[k].y=boss.y;
                boss_shot.bullet[k].vx = cos(angle-PI/8*4+PI/8*n+PI/16)*3;
                boss_shot.bullet[k].vy = sin(angle-PI/8*4+PI/8*n+PI/16)*3;
            }
        }
        se_flag[0]=1;
    }

    if(t%1==0 && t2>80){
        int num=1;
        if(t%2)
            num=2;
        for(n=0;n<num;n++){
            if((k=search_boss_shot())!=-1){
                angle=PI*1.5-PI/2+PI/12*(t2%13)+rang(PI/15);
                boss_shot.bullet[k].flag=1;
                boss_shot.bullet[k].state=1;
                boss_shot.bullet[k].cnt=0;
                boss_shot.bullet[k].knd=8;
                boss_shot.bullet[k].eff_detail=0;
                boss_shot.bullet[k].col=4;
                boss_shot.bullet[k].angle=0;
                boss_shot.bullet[k].x=boss.x;
                boss_shot.bullet[k].y=boss.y;
                boss_shot.bullet[k].vx = cos(angle)*1.4*1.2;
                boss_shot.bullet[k].vy = sin(angle)*1.4;
            }
        }
        se_flag[7]=1;
    }
    for(i=0;i<BOSS_BULLET_MAX;i++){
        if(boss_shot.bullet[i].flag>0){
            if(boss_shot.bullet[i].state==0){
                if(boss_shot.bullet[i].cnt<150)
                    boss_shot.bullet[i].vy+=0.03;
                boss_shot.bullet[i].x+=boss_shot.bullet[i].vx;
                boss_shot.bullet[i].y+=boss_shot.bullet[i].vy;
            }
            if(boss_shot.bullet[i].state==1){
                if(boss_shot.bullet[i].cnt<160)
                    boss_shot.bullet[i].vy+=0.03;
                boss_shot.bullet[i].x+=boss_shot.bullet[i].vx;
                boss_shot.bullet[i].y+=boss_shot.bullet[i].vy;
                boss_shot.bullet[i].angle=atan2(boss_shot.bullet[i].vy,boss_shot.bullet[i].vx);
            }
        }
    }
}


void boss_shot_bulletH005(){
#define TM005 820
#define RANGE005 100.0
#define LEM005 4
    int i,j,k,n,t=boss_shot.cnt%TM005,t2=boss_shot.cnt;
    static int sst,bnum;
    static double sx,sy,sangle;
    if(t==0){
        sst=0;
        sx=boss.x;
        sy=boss.y-RANGE005;
        sangle=PI/5/2+PI/2;
        bnum=0;
    }
    if(sst<=4){
        for(i=0;i<2;i++){
            sx+=cos(sangle)*LEM005;
            sy+=sin(sangle)*LEM005;
            if((sx-boss.x)*(sx-boss.x)+(sy-boss.y)*(sy-boss.y)>RANGE005*RANGE005){
                sangle-=(PI-PI/5);
                sst++;
                if(sst==5)break;
            }
            for(j=0;j<5;j++){
                if((k=search_boss_shot())!=-1){
                    boss_shot.bullet[k].flag=1;
                    boss_shot.bullet[k].state=j;
                    boss_shot.bullet[k].cnt=0;
                    boss_shot.bullet[k].spd=0;
                    boss_shot.bullet[k].knd=10;
                    boss_shot.bullet[k].col=j;
                    boss_shot.bullet[k].angle=-PI/2+PI2/5*j;
                    boss_shot.bullet[k].x=sx;
                    boss_shot.bullet[k].y=sy;
                    boss_shot.bullet[k].vx = cos(sangle)*1.4*1.2;
                    boss_shot.bullet[k].vy = sin(sangle)*1.4;
                    boss_shot.bullet[k].base_angle[0]=sangle-PI+PI/20*bnum;
                }
            }
            bnum++;
        }
        se_flag[0]=1;
    }
   for(i=0;i<BOSS_BULLET_MAX;i++){
        if(boss_shot.bullet[i].flag>0){
            int cnt=boss_shot.bullet[i].cnt;
            if(boss_shot.bullet[i].state<10){
                if(t==150){
                    boss_shot.bullet[i].spd=4;
                    boss_shot.bullet[i].cnt=0;
                    boss_shot.bullet[i].state+=10;
                }
            }
            else if(boss_shot.bullet[i].state<20){
                if(cnt<=80){
                    boss_shot.bullet[i].spd-=0.05;
                }
                if(cnt==100){
                    boss_shot.bullet[i].angle=boss_shot.bullet[i].base_angle[0];
                }
                if(cnt>=100 && cnt<160){
                    boss_shot.bullet[i].spd+=0.015;
                }
            }
        }
    }
}

void boss_shot_bulletH006(){
#define TM006 300
#define DNUMX 15
    int i,j,k,t=boss_shot.cnt%TM006,t2=boss_shot.cnt;
	double xlen=FMX/DNUMX;//要在画面上横向放置DNUM个子弹需要xlen的间隔
	int dnumy=FMY/xlen;//以xlen为间隔的话再竖直方向需要多少个子弹
	int cnum;
	if(dnumy==0){printfDx("boss_shot_bulletH006除以0\n"); return ;}
	double ylen=FMY/dnumy;
	double x,y,angle;
	static int num;
	if(t2==0)num=0;
	if(t==0){
		x=0,y=0,angle=0,cnum=0;
		for(j=0;j<4;j++){
			int to=j%2 ? dnumy: DNUMX ;
			for(i=0;i<=to;i++){
				if((k=search_boss_shot())!=-1){
					boss_shot.bullet[k].x     = x;
					boss_shot.bullet[k].y     = y;
					boss_shot.bullet[k].knd   = 4;
					boss_shot.bullet[k].flag  = 1;
					boss_shot.bullet[k].cnt   = 0;
					switch(num){
						case 0:
					boss_shot.bullet[k].col   = 0;
					boss_shot.bullet[k].angle = bossatan3(k,FMX/2,FMY/2);
					boss_shot.bullet[k].spd   = 1.3;
					boss_shot.bullet[k].state = 0;
						case 1:
					boss_shot.bullet[k].col   = 3;
					boss_shot.bullet[k].angle = bossatan3(k,FMX/2,FMY/2);
					boss_shot.bullet[k].spd   = 1.4+ ((j%2 ? -1 : 1) * ((cos(PI2/to*i-PI)+1)/2))*0.4;
					boss_shot.bullet[k].state = 1;
						break;
						case 2:
					boss_shot.bullet[k].col   = 6;
					boss_shot.bullet[k].angle = bossatan3(k,FMX/2,FMY/2);
					boss_shot.bullet[k].spd   = 1.3;
					boss_shot.bullet[k].state = 2;
					boss_shot.bullet[k].base_angle[0] 
					= PI/1000 * (j%2 ? -1 : 1) * ((cos(PI2/to*i-PI)+1)/2);
						break;
					}
					se_flag[0]=1;
					cnum++;
				}
				x+=cos(angle)*xlen;
				y+=sin(angle)*ylen;
			}
			angle+=PI/2;
		}
	}
    for(i=0;i<BOSS_BULLET_MAX;i++){
        if(boss_shot.bullet[i].flag>0){
			int cnt=boss_shot.bullet[i].cnt;
			switch(boss_shot.bullet[i].state){
				case 2:
					boss_shot.bullet[i].angle+=boss_shot.bullet[i].base_angle[0];
					break;
				default:
					break;
			}
        }
    }
	if(t==TM006-1)
		num=(++num)%3;
}

void boss_shot_bulletH007(){
#define TM007 300
#define DNUMX 9
    int i,j,k,s,t=boss_shot.cnt%TM007,t2=boss_shot.cnt;
    double xlen=FMX/DNUMX;//要在画面上横向放置DNUM个子弹需要xlen的间隔
    int dnumy=FMY/xlen;//以xlen为间隔的话再竖直方向需要多少个子弹
    int cnum;
    if(dnumy==0){printfDx("boss_shot_bulletH006除以0\n"); return ;}
    double ylen=FMY/dnumy;//需要ylen的放置区间
    double x,y,angle;
    static int num;
    if(t2==0)num=0;
    if(t==0){
        x=0,y=0,angle=0,cnum=0;
        for(j=0;j<4;j++){
            int to=j%2 ? dnumy: DNUMX ;
            for(i=0;i<=to;i++){
                for(s=0;s<2;s++){
                    if((k=search_boss_shot())!=-1){
                        boss_shot.bullet[k].x     = x;//坐标
                        boss_shot.bullet[k].y     = y;
                        boss_shot.bullet[k].knd   = 4;//子弹种类
                        boss_shot.bullet[k].flag  = 1;
                        boss_shot.bullet[k].cnt   = 0;
                        switch(num){
                            case 0://直线
                        boss_shot.bullet[k].col   = 0;//子弹颜色
                        boss_shot.bullet[k].angle = angle+PI/2;//角度
                        boss_shot.bullet[k].spd   = 1.1+0.5*s;//速度
                        boss_shot.bullet[k].state = 0;//状态
                            break;
                            case 1://斜向交叉
                        boss_shot.bullet[k].col   = 3;//子弹的颜色
                        boss_shot.bullet[k].angle = angle+PI/2-PI/14+PI/7*s;//角度
                        boss_shot.bullet[k].spd   = 1.3;//速度
                        boss_shot.bullet[k].state = 1;//状态
                            break;
                        }
                        se_flag[0]=1;
                        cnum++;
                    }
                }
                x+=cos(angle)*xlen;
                y+=sin(angle)*ylen;
            }
            angle+=PI/2;
        }
    }
    if(t==TM006-1)
        num=(++num)%2;
}

void boss_shot_bulletH008(){
#define TM008 420
#define DIST 60
    int i,j,k,t=boss_shot.cnt%TM008,t2=boss_shot.cnt;
    static int num;
    if(t2==0)num=4;
    if(t==0){
        for(j=0;j<2;j++){
            for(i=0;i<num;i++){
                int plmn=(j ? -1 : 1);
                if((k=search_lazer())!=-1){
                    lazer[k].col      = j;
                    lazer[k].knd      = 0;//抏偺庬椶
                    lazer[k].angle    = PI2/num*i+PI2/(num*2)*j+PI2/(num*4)*((num+1)%2);
                    lazer[k].startpt.x= boss.x+cos(lazer[k].angle)*DIST;
                    lazer[k].startpt.y= boss.y+sin(lazer[k].angle)*DIST;
                    lazer[k].flag     = 1;
                    lazer[k].cnt      = 0;
                    lazer[k].haba     = 2;
                    lazer[k].state    = j;
                    lazer[k].length   = 240;
                    lazer[k].hantei      = 0;
                    lazer[k].lphy.conv_flag=1;
                    lazer[k].lphy.conv_base_x=boss.x;
                    lazer[k].lphy.conv_base_y=boss.y;
                    lazer[k].lphy.conv_x=lazer[k].startpt.x;
                    lazer[k].lphy.conv_y=lazer[k].startpt.y;
                    input_lphy(&lazer[k],80,PI/num*plmn);
                }
            }
        }
        se_flag[33]=1;
    }

    for(i=0;i<LAZER_MAX;i++){
        if(lazer[i].flag>0){
            int cnt=lazer[i].cnt;
            int state=lazer[i].state;
            if(state==0 || state==1){
                if(cnt==80){
                    lazer[i].haba=30;
                    lazer[i].hantei=0.5;
                }
                if(cnt>=260 && cnt<=320){
                    if(cnt==280)
                        lazer[i].hantei=0;
                    lazer[i].haba=10*(60-(cnt-260))/60.0;
                    if(cnt==320)
                        lazer[i].flag=0;
                }
            }
        }
    }
    if(t==TM008-1)
        num=(++num);
}


void boss_shot_bulletH009(){
#define TM009 420
#define DIST 60
    int i,j,k,s,t=boss_shot.cnt%TM009,t2=boss_shot.cnt;
    double angle;
    static int num;
    if(t2==0)num=4;
    if(t==0){
        for(j=0;j<2;j++){
            for(i=0;i<num;i++){
                int plmn=(j ? -1 : 1);
                if((k=search_lazer())!=-1){
                    lazer[k].col      = j;//子弹的颜色
                    lazer[k].knd      = 0;//子弹的种类
                    lazer[k].angle    = PI2/num*i+PI2/(num*2)*j+PI2/(num*4)*((num+1)%2);//角度
                    lazer[k].startpt.x= boss.x+cos(lazer[k].angle)*DIST;//开始绘制的角度
                    lazer[k].startpt.y= boss.y+sin(lazer[k].angle)*DIST;
                    lazer[k].flag     = 1;//是否显示　0:否　1:是
                    lazer[k].cnt      = 0;
                    lazer[k].haba     = 2;//幅度
                    lazer[k].state    = j;//
                    lazer[k].length   = 240;//长度
                    lazer[k].hantei      = 0;//是否碰撞判定　0:是　1:否
                    lazer[k].lphy.conv_flag=1;//是否旋转　0:否　1：是
                    lazer[k].lphy.conv_base_x=boss.x;//旋转的基准坐标
                    lazer[k].lphy.conv_base_y=boss.y;
                    lazer[k].lphy.conv_x=lazer[k].startpt.x;//旋转的激光位置
                    lazer[k].lphy.conv_y=lazer[k].startpt.y;
                    input_lphy(&lazer[k],80,PI/num*plmn);//登录第k号激光在80次计数内只旋转PI/num*plmn角度的信息
                }
            }
        }
        se_flag[33]=1;
    }
	//60次计数一下每10次计数1次
    if(t==50){
        angle=rang(PI);//自机与Boss所成角度
        for(s=0;s<2;s++){
            for(t=0;t<3;t++){
                for(j=0;j<3;j++){
                    for(i=0;i<30;i++){
                        if((k=search_boss_shot())!=-1){
                            boss_shot.bullet[k].col   = s;//子弹的颜色
                            boss_shot.bullet[k].x     = boss.x;//坐标
                            boss_shot.bullet[k].y     = boss.y;
                            boss_shot.bullet[k].knd   = 11;//子弹的种类
                            boss_shot.bullet[k].angle = angle+PI2/30*i+PI2/60*s;//角度
                            boss_shot.bullet[k].flag  = 1;
                            boss_shot.bullet[k].cnt   = 0;
                            boss_shot.bullet[k].spd   = 1.8-0.2*j+0.1*s;//速度
                            boss_shot.bullet[k].eff   = 0;
                            boss_shot.bullet[k].state   = t;
                        }
                        se_flag[0]=1;
                    }
                }
            }
        }
    }
    if(t>=170 && t<310 && (t-170)%35==0){
        int div=((t-170)%70==0) ? -1 : 1;
        angle=rang(PI);//自机与Boss所成的角度
        for(s=0;s<2;s++){//有两类速度不同的子弹
            for(t=0;t<3;t++){//从一个地方一分为三
                for(i=0;i<30;i++){//1周30个
                    if((k=search_boss_shot())!=-1){
                        boss_shot.bullet[k].col   = 2;//子弹的颜色
                        boss_shot.bullet[k].x     = boss.x;//坐标
                        boss_shot.bullet[k].y     = boss.y;
                        boss_shot.bullet[k].knd   = 11;//子弹的种类
                        boss_shot.bullet[k].angle = angle+PI2/30*i;//角度
                        boss_shot.bullet[k].flag  = 1;
                        boss_shot.bullet[k].cnt   = 0;
                        boss_shot.bullet[k].spd   = 2-0.3*s;//速度
                        boss_shot.bullet[k].eff   = 0;
                        boss_shot.bullet[k].state = 10+t;
                        boss_shot.bullet[k].base_angle[0] = PI/300*div;
                    }
                }
            }
            se_flag[0]=1;
        }
    }
    if(t==360){
        angle=rang(PI);//自机与Boss所成的角度
        for(t=0;t<3;t++){//从一个地方一分为三
            for(i=0;i<30;i++){
                if((k=search_boss_shot())!=-1){
                    boss_shot.bullet[k].col   = 1;//子弹的颜色
                    boss_shot.bullet[k].x     = boss.x;//坐标
                    boss_shot.bullet[k].y     = boss.y;
                    boss_shot.bullet[k].knd   = 0;//子弹的种类
                    boss_shot.bullet[k].angle = angle+PI2/30*i;//角度
                    boss_shot.bullet[k].flag  = 1;
                    boss_shot.bullet[k].cnt   = 0;
                    boss_shot.bullet[k].spd   = 1.8;//速度
                    boss_shot.bullet[k].eff   = 1;
                    boss_shot.bullet[k].state = 20+t;
                }
            }
        }
        se_flag[0]=1;
    }
    for(i=0;i<BOSS_BULLET_MAX;i++){
        if(boss_shot.bullet[i].flag>0){
            int cnt=boss_shot.bullet[i].cnt;
            int state=boss_shot.bullet[i].state;
            if(state%10==0){
                if(cnt>90 && cnt<=100)
                    boss_shot.bullet[i].spd-=boss_shot.bullet[i].spd/220;
            }
            if(state%10==1){
                if(cnt>50)
                    boss_shot.bullet[i].spd+=boss_shot.bullet[i].spd/45;
            }
            if(state%10==2){
                if(cnt>65)
                    boss_shot.bullet[i].spd+=boss_shot.bullet[i].spd/90;
            }
            if(10<=state && state<=12){
                if(cnt>15 && cnt<=80)
                    boss_shot.bullet[i].angle+=boss_shot.bullet[i].base_angle[0];
            }
        }
    }
    for(i=0;i<LAZER_MAX;i++){
        if(lazer[i].flag>0){
            int cnt=lazer[i].cnt;
            int state=lazer[i].state;
            if(state==0 || state==1){
                if(cnt==80){
                    lazer[i].haba=30;
                    lazer[i].hantei=0.5;
                }
                if(cnt>=260 && cnt<=320){
                    if(cnt==280)
                        lazer[i].hantei=0;
                    lazer[i].haba=10*(60-(cnt-260))/60.0;
                    if(cnt==320)
                        lazer[i].flag=0;
                }
            }
        }
    }
    if(t==TM009-1)
        num=(++num);
}
void boss_shot_bulletH011(){
#define TM009 420
#define DIST 60
    int t=boss_shot.cnt%TM009,t2=boss_shot.cnt;
        if(t2==60){
                flash.flag=1;
                flash.knd=0;//逐渐变量、逐渐变暗
                flash.to_cnt=30;//在30次计数中变化
                flash.cnt=0;
        }
        if(t2==180){
                flash.flag=1;
                flash.knd=1;//闪！
                flash.to_cnt=90;// 90次计数中变化
                flash.cnt=0;
        }
        if(t2==260){
                flash.flag=1;
                flash.knd=0;//逐渐变亮，逐渐变暗
                flash.to_cnt=15;//1在15次计数中变化
                flash.cnt=0;
        }
        if(t2==380){
                flash.flag=1;
                flash.knd=1;//闪！
                flash.to_cnt=30;//在30次计数中变化
                flash.cnt=0;
        }

}