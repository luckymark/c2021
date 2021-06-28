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
        if(enemy[shot[n].num].flag!=1)//������˱��򵹵Ļ�
                shot[n].flag=2;//��֮ǰ��¼�������flag����Ϊ��Ч
        for(i=0;i<SHOT_BULLET_MAX;i++){//�����n�ŵ�Ļ���ݵ��ӵ�
                if(shot[n].bullet[i].flag>0){//������ӵ���û�б���¼
                        shot[n].bullet[i].x+=cos(shot[n].bullet[i].angle)*shot[n].bullet[i].spd;
                        shot[n].bullet[i].y+=sin(shot[n].bullet[i].angle)*shot[n].bullet[i].spd;
                        shot[n].bullet[i].cnt++;
                        if(shot[n].bullet[i].x<-50 || shot[n].bullet[i].x>FMX+50 ||
                                shot[n].bullet[i].y<-50 || shot[n].bullet[i].y>FMY+50){//����ܵ���������Ļ�
                                if(shot[n].bullet[i].till<shot[n].bullet[i].cnt)//�ұ���ͳ̶Ȳ������ٵ�ʱ�仹Ҫ�ܳ�
                                        shot[n].bullet[i].flag=0;//����֮
                        }
                }
        }
        //��ѯ��ǰ��ʾ�е��ӵ��������Ƿ����ٻ���һ��
        for(i=0;i<SHOT_BULLET_MAX;i++)
                if(shot[n].bullet[i].flag>0)
                        return;
        if(enemy[shot[n].num].flag!=1){
                shot[n].flag=0;//�K��
                enemy[shot[n].num].flag=0;
        }
}
void shot_main(){
        int i;
        for(i=0;i<SHOT_MAX;i++){//��Ļ���ݼ���
				//���flagΪ��Ч���趨������û�д�����������ֹ�����
                if(shot[i].flag!=0 && 0<=shot[i].knd && shot[i].knd<SHOT_KND_MAX){
                        shot_bullet[shot[i].knd](i);//����.knd�ĵ�Ļ���㺯���ĺ���ָ��
                        shot_calc(i);//�����i�ŵ�Ļ
                        shot[i].cnt++;
                }
        }
}

