#include "../include/GV.h"

#define ENEMY_RANGE_MAX 4
#define CSHOT_RANGE_MAX 2
#define CRANGE 2.0
#define BRANGE 40.0

//���˵���ײ�ж���Χ
int enemy_range[ENEMY_RANGE_MAX]={16,30,16,50};
//�Ի���Ƶ���ײ�ж���Χ
int cshot_range[CSHOT_RANGE_MAX]={6,};

//��ײ�ж�
//��������꣺1 ������ײ�ж������壺2
int out_judge(double x1, double y1, double x2, double y2,
              double range1, double range2, double spd1,double angle1){
    int j;
    double x=x1-x2;//���˺��Ի�������ӵ��ľ���
    double y=y1-y2;
    //���˵���ײ�ж����Ի���Ƶ���ײ�ж��ĺϼƷ�Χ
    double r=range1+range2;
//����б�Ҫ�����м�Ļ�
    if(spd1>r){
		//��¼1֮֡ǰ��λ��
        double pre_x=x1+cos(angle1+PI)*spd1;
        double pre_y=y1+sin(angle1+PI)*spd1;
        double px,py;
        for(j=0;j<spd1/r;j++){//ǰ�����֡���ײ�ж����ִ�ѭ��
            px=pre_x-x2;
            py=pre_y-y2;
            if(px*px+py*py<r*r)
                return 1;
            pre_x+=cos(angle1)*r;
            pre_y+=sin(angle1)*r;
        }
    }
    if(x*x+y*y<r*r)//�������ײ�ж���
        return 1;//��ײ
    return 0;
}

//�жϵ��˺��Ի�����Ƿ�����
int out_judge_cshot(int i,int s){
    if(cshot[i].cnt>0){ //������ӵ��Ĺ��������ټ����һ��
        if(out_judge(cshot[i].x,cshot[i].y,enemy[s].x,enemy[s].y,
            cshot_range[cshot[i].knd],enemy_range[enemy[s].knd],
            cshot[i].spd,cshot[i].angle)){
                return 1;
        }
    }
    return 0;
}

//�ж�Boss�Ƿ���Ի������ײ
int out_judge_cshot_boss(int i){
    if(cshot[i].cnt>0){//���������ӵ��Ĺ�����ټ����һ��
        if(out_judge(cshot[i].x,cshot[i].y,boss.x,boss.y,
            cshot_range[cshot[i].knd],BRANGE,cshot[i].spd,cshot[i].angle)){
                return 1;
        }
    }
    return 0;
}

//�ж��Ի��Ƿ�͵����������
int out_judge_enemyshot(int s,int n){
    if(shot[s].bullet[n].cnt>0){//���������ӵ��Ĺ�����ټ����һ��
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

//�Ƿ��Ի��Ƿ��Boss�������
int out_judge_bossshot(int n){
    if(boss_shot.bullet[n].cnt>0){//������ӵ��Ĺ�����ټ����һ�εĻ�
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

//���ߵ�¼
//���ߡ�0:Сpower 1:С�� 2:���� 3:С�� 4:��power 5:���
void enter_item(double x, double y, int item_n[], int num){//x,y,���ߵ����࣬����
        int k;
        double r[6]={0.6,0.6,1.0,0.6,1.0,1.0};//dat/img/item��ͼ��Ŵ���
        for(int i=0;i<num;i++){//1�����˵���ĵ��������Ϊ6��
                if(item_n[i]!=-1){//�����Excel��ָ���ĵ�����-1���գ��Ļ�����ֹ
                        if((k=search_item())!=-1){//��ѯ���Ե�¼�ı��
                                item[k].flag=1;
                                item[k].v    =-3.5;     //�ٶ�
                                item[k].cnt  =0;
                                item[k].state=0;
                                item[k].x    =x;
                                item[k].y    =y;
                                if(i>0){//�����ֹһ���Ļ����ʵ��ط�ɢһ��
                                        item[k].x+=rang(40);
                                        item[k].y+=rang(40);
                                }
                                item[k].knd =item_n[i];//ָ���˵ĵ��ߵ���
                                item[k].r   =r[item[k].knd];
                        }
                }
        }
}

//���˵���ĵ���
void enter_enemy_item(int s){
        enter_item(enemy[s].x,enemy[s].y,enemy[s].item_n, sizeof(enemy[s].item_n)/sizeof(int));
}

//��ɫ����ĵ���
void enter_char_item(){
        int item_n[4]={4,4,4,4};
        enter_item(ch.x, ch.y, item_n, 4);
}

extern void enter_del_effect(int);

void enemy_death_judge(int s){
    int i;
    se_flag[8]=1;//���˱����е�����
    if(enemy[s].hp<0){//������˵�HPС��0
        enemy[s].flag=0;//�������
        se_flag[1]=1;//���˵Ļ�����
        enter_del_effect(s);
		enter_enemy_item(s);//s�ŵ��˵������
        for(i=0;i<SHOT_MAX;i++){//���˵��ܴ���
            if(shot[i].flag!=0){
                if(s==shot[i].num){
                    shot[i].flag=2;
                    break;
                }
            }
        }
    }
}
//��s�ŵ��˳���power�˺�
void hit_enemy(int s,int power){
    enemy[s].hp-=power;//�����ӵ������е�power����HP
    enemy_death_judge(s);//���������Ƿ����
}

//��Boss����power�˺�
void hit_boss(int power){
    boss.hp-=power;//��HP�����ӵ������е�power������
}


//�Ի�����͵��˵Ĵ���
void cshot_and_enemy(){
    int i,s;
    for(i=0;i<CSHOT_MAX;i++){//�Ի�������ӵ�����
        if(cshot[i].flag>0){
            for(s=0;s<ENEMY_MAX;s++){//��������
                if(enemy[s].flag>0){
                    if(out_judge_cshot(i,s)){//����Ի�������ӵ��͵�������
                        cshot[i].flag=0;//���Լ��ӵ�����
                        hit_enemy(s,cshot[i].power);
                        break;
                    }
                }
            }
			//Boss�������䲻���flagΪ��Ч���������
            if(boss.flag==1 && boss.graph_flag==0 && boss.state==2){
                if(out_judge_cshot_boss(i)){
                    cshot[i].flag=0;
                    hit_boss(cshot[i].power);
                }
            }
        }
    }
}

//����������Ի��Ĵ���
void enemyshot_and_ch(){
    int s,n;
	//�ӱ������
    for(s=0;s<SHOT_MAX;s++){//���˵�������ӵ�����
        if(shot[s].flag>0){//�������Ѿ���¼
            for(n=0;n<SHOT_BULLET_MAX;n++){//�ӵ�����
                if(shot[s].bullet[n].flag==1){//����ӵ��Ѿ���¼�Ļ�
                    if(out_judge_enemyshot(s,n)==1){//���Ի����ӵ��Ӵ�
                        shot[s].bullet[n].flag=0;//�����ӵ�
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
//Boss���
    if(boss_shot.flag>0){//�������Ѿ���¼
        for(n=0;n<BOSS_BULLET_MAX;n++){//�ӵ�����
            if(boss_shot.bullet[n].flag==1){//����ӵ��Ѿ���¼
                if(out_judge_bossshot(n)==1){//����ӵ��Ѿ����Ի��Ӵ�
                    boss_shot.bullet[n].flag=0;//�����ӵ�
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

//�õ��˳���Boom���˺�
void cbom_and_enemy(){
    int s;
    if(bom.flag!=1)return;
    for(s=0;s<ENEMY_MAX;s++){//��������
        if(enemy[s].flag>0)//��������Ǵ��ڵ�
            hit_enemy(s,ch.power/20);//�����˺�
    }
//Boss�������䲻����flagΪ��Ч���������
    if(boss.flag==1 && boss.graph_flag==0 && boss.state==2)
        hit_boss(ch.power/20);//�����˺�
}

//����߽Ӵ�
//���ߡ�0:Сpower 1:С�� 2:���� 3:С�� 4:��power 5:���
void ch_and_item(){
        for(int i=0;i<ITEM_MAX;i++){
                if(item[i].flag>0){
                        double x=item[i].x-ch.x,y=item[i].y-ch.y;
                        if(x*x+y*y<ITEM_HIT_BOX*ITEM_HIT_BOX){//�������ײ�ж��ڵĻ�
                                switch(item[i].knd){//����������
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
                                se_flag[34]=1;//��ȡ��
                        }
                }
        }
}

//��ײ�ж�main
void out_main(){
    cbom_and_enemy();//�õ��˳���Boom���˺�
    cshot_and_enemy();//�Ի��������˵Ĵ���
    enemyshot_and_ch();//����������Ի��Ĵ���
    ch_and_item();//���߽Ӵ�����
}