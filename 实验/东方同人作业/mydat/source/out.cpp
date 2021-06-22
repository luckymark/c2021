#include "../include/GV.h"

#define ENEMY_RANGE_MAX 4
#define CSHOT_RANGE_MAX 2
#define CRANGE 2.0
#define BRANGE 40.0

//敌人的碰撞判定范围
int enemy_range[ENEMY_RANGE_MAX]={16,30,16,50};
//自机设计的碰撞判定范围
int cshot_range[CSHOT_RANGE_MAX]={6,};

//碰撞判定
//射击的坐标：1 进行碰撞判定的物体：2
int out_judge(double x1, double y1, double x2, double y2,
              double range1, double range2, double spd1,double angle1){
    int j;
    double x=x1-x2;//敌人和自机射击的子弹的距离
    double y=y1-y2;
    //敌人的碰撞判定和自机设计的碰撞判定的合计范围
    double r=range1+range2;
//如果有必要计算中间的话
    if(spd1>r){
		//记录1帧之前的位置
        double pre_x=x1+cos(angle1+PI)*spd1;
        double pre_y=y1+sin(angle1+PI)*spd1;
        double px,py;
        for(j=0;j<spd1/r;j++){//前进部分÷碰撞判定部分次循环
            px=pre_x-x2;
            py=pre_y-y2;
            if(px*px+py*py<r*r)
                return 1;
            pre_x+=cos(angle1)*r;
            pre_y+=sin(angle1)*r;
        }
    }
    if(x*x+y*y<r*r)//如果在碰撞判定内
        return 1;//碰撞
    return 0;
}

//判断敌人和自机射击是否碰上
int out_judge_cshot(int i,int s){
    if(cshot[i].cnt>0){ //射击的子弹的轨道如果至少计算过一次
        if(out_judge(cshot[i].x,cshot[i].y,enemy[s].x,enemy[s].y,
            cshot_range[cshot[i].knd],enemy_range[enemy[s].knd],
            cshot[i].spd,cshot[i].angle)){
                return 1;
        }
    }
    return 0;
}

//判定Boss是否和自机射击碰撞
int out_judge_cshot_boss(int i){
    if(cshot[i].cnt>0){//如果射击的子弹的轨道至少计算过一次
        if(out_judge(cshot[i].x,cshot[i].y,boss.x,boss.y,
            cshot_range[cshot[i].knd],BRANGE,cshot[i].spd,cshot[i].angle)){
                return 1;
        }
    }
    return 0;
}

//判定自机是否和敌人射击碰上
int out_judge_enemyshot(int s,int n){
    if(shot[s].bullet[n].cnt>0){//如果射击的子弹的轨道至少计算过一次
        if(out_judge(
            shot[s].bullet[n].x,shot[s].bullet[n].y,ch.x,ch.y,
            bullet_info[shot[s].bullet[n].knd].range,CRANGE,
            shot[s].bullet[n].spd,shot[s].bullet[n].angle
            )){
                return 1;
        }
    }
    return 0;
}

//是否自机是否和Boss射击碰上
int out_judge_bossshot(int n){
    if(boss_shot.bullet[n].cnt>0){//射击的子弹的轨道至少计算过一次的话
        if(out_judge(
            boss_shot.bullet[n].x,boss_shot.bullet[n].y,ch.x,ch.y,
            bullet_info[boss_shot.bullet[n].knd].range,CRANGE,
            boss_shot.bullet[n].spd,boss_shot.bullet[n].angle
            )){
                return 1;
        }
    }
    return 0;
}

int search_item(){
	for(int i=0;i<ITEM_MAX;i++)
		if(item[i].flag==0)
			return i;
	return -1;
}

//道具登录
//道具　0:小power 1:小点 2:弹点 3:小金 4:大power 5:大金
void enter_item(double x, double y, int item_n[], int num){//x,y,道具的种类，数量
        int k;
        double r[6]={0.6,0.6,1.0,0.6,1.0,1.0};//dat/img/item的图像放大率
        for(int i=0;i<num;i++){//1个敌人掉落的道具最大数为6个
                if(item_n[i]!=-1){//如果在Excel中指定的道具是-1（空）的话就终止
                        if((k=search_item())!=-1){//查询可以登录的编号
                                item[k].flag=1;
                                item[k].v    =-3.5;     //速度
                                item[k].cnt  =0;
                                item[k].state=0;
                                item[k].x    =x;
                                item[k].y    =y;
                                if(i>0){//如果不止一个的话就适当地分散一下
                                        item[k].x+=rang(40);
                                        item[k].y+=rang(40);
                                }
                                item[k].knd =item_n[i];//指定了的道具掉落
                                item[k].r   =r[item[k].knd];
                        }
                }
        }
}

//敌人掉落的道具
void enter_enemy_item(int s){
        enter_item(enemy[s].x,enemy[s].y,enemy[s].item_n, sizeof(enemy[s].item_n)/sizeof(int));
}

//角色掉落的道具
void enter_char_item(){
        int item_n[4]={4,4,4,4};
        enter_item(ch.x, ch.y, item_n, 4);
}

extern void enter_del_effect(int);

void enemy_death_judge(int s){
    int i;
    se_flag[8]=1;//敌人被击中的声音
    if(enemy[s].hp<0){//如果敌人的HP小于0
        enemy[s].flag=0;//消灭敌人
        se_flag[1]=1;//敌人的击毁声
        enter_del_effect(s);
		enter_enemy_item(s);//s号敌人掉落道具
        for(i=0;i<SHOT_MAX;i++){//敌人的总次数
            if(shot[i].flag!=0){
                if(s==shot[i].num){
                    shot[i].flag=2;
                    break;
                }
            }
        }
    }
}
//让s号敌人承受power伤害
void hit_enemy(int s,int power){
    enemy[s].hp-=power;//减少子弹所持有的power量的HP
    enemy_death_judge(s);//决定敌人是否击毁
}

//让Boss承受power伤害
void hit_boss(int power){
    boss.hp-=power;//让HP减少子弹所持有的power的量的
}


//自机射击和敌人的处理
void cshot_and_enemy(){
    int i,s;
    for(i=0;i<CSHOT_MAX;i++){//自机射击的子弹总数
        if(cshot[i].flag>0){
            for(s=0;s<ENEMY_MAX;s++){//敌人总数
                if(enemy[s].flag>0){
                    if(out_judge_cshot(i,s)){//如果自机射击的子弹和敌人碰上
                        cshot[i].flag=0;//将自己子弹销毁
                        hit_enemy(s,cshot[i].power);
                        break;
                    }
                }
            }
			//Boss出现且其不描绘flag为无效且在射击中
            if(boss.flag==1 && boss.graph_flag==0 && boss.state==2){
                if(out_judge_cshot_boss(i)){
                    cshot[i].flag=0;
                    hit_boss(cshot[i].power);
                }
            }
        }
    }
}

//敌人射击和自机的处理
void enemyshot_and_ch(){
    int s,n;
	//杂兵的射击
    for(s=0;s<SHOT_MAX;s++){//敌人的射击的子弹总数
        if(shot[s].flag>0){//如果射击已经登录
            for(n=0;n<SHOT_BULLET_MAX;n++){//子弹总数
                if(shot[s].bullet[n].flag==1){//如果子弹已经登录的话
                    if(out_judge_enemyshot(s,n)==1){//且自机与子弹接触
                        shot[s].bullet[n].flag=0;//销毁子弹
                        if(ch.flag==0 && ch.mutekicnt==0){
                            ch.cnt=0;
                            ch.flag=1;
                            se_flag[3]=1;
                        }
                    }
                }
            }
        }
    }
//Boss射击
    if(boss_shot.flag>0){//如果射击已经登录
        for(n=0;n<BOSS_BULLET_MAX;n++){//子弹总数
            if(boss_shot.bullet[n].flag==1){//如果子弹已经登录
                if(out_judge_bossshot(n)==1){//如果子弹已经和自机接触
                    boss_shot.bullet[n].flag=0;//销毁子弹
                    if(ch.flag==0 && ch.mutekicnt==0){
                        ch.cnt=0;
                        ch.flag=1;
                        se_flag[3]=1;
                    }
                }
            }
        }
    }
}

//让敌人承受Boom的伤害
void cbom_and_enemy(){
    int s;
    if(bom.flag!=1)return;
    for(s=0;s<ENEMY_MAX;s++){//敌人总数
        if(enemy[s].flag>0)//如果敌人是存在的
            hit_enemy(s,ch.power/20);//给予伤害
    }
//Boss存在且其不绘制flag为无效且在射击中
    if(boss.flag==1 && boss.graph_flag==0 && boss.state==2)
        hit_boss(ch.power/20);//承受伤害
}

//与道具接触
//道具　0:小power 1:小点 2:弹点 3:小金 4:大power 5:大金
void ch_and_item(){
        for(int i=0;i<ITEM_MAX;i++){
                if(item[i].flag>0){
                        double x=item[i].x-ch.x,y=item[i].y-ch.y;
                        if(x*x+y*y<ITEM_HIT_BOX*ITEM_HIT_BOX){//如果在碰撞判定内的话
                                switch(item[i].knd){//根据种类变更
                                        case 0: ch.power+=3; break;
                                        case 1: ch.point+=1; break;
                                        case 2: ch.score+=1; break;
                                        case 3: ch.money+=1; break;
                                        case 4: ch.power+=50;break;
                                        case 5: ch.money+=10;break;
                                }
                                if(ch.power>500)ch.power=500;
                                if(ch.point>9999)ch.point=9999;
                                if(ch.money>999999)ch.money=999999;
                                if(ch.score>999999999)ch.score=999999999;
                                item[i].flag=0;
                                se_flag[34]=1;//获取音
                        }
                }
        }
}

//碰撞判定main
void out_main(){
    cbom_and_enemy();//让敌人承受Boom的伤害
    cshot_and_enemy();//自机射击与敌人的处理
    enemyshot_and_ch();//敌人射击与自机的处理
    ch_and_item();//道具接触处理
}