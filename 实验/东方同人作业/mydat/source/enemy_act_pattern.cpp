#include "../include/GV.h"

double rang(double ang){
	return (-ang+ang*2*GetRand(10000)/10000.0);
}

//�ƶ�ģʽ0
//�����ƶ���ֹͣȻ�������ƶ�
void enemy_pattern0(int i){
	int t=enemy[i].cnt;
	if(t==0)
		enemy[i].vy=3;
	if(t==40)
		enemy[i].vy=0;
	if(t==40+enemy[i].wait)
		enemy[i].vy=-3;
}

//�ƶ�ģʽ1
//�����ƶ�Ȼ��ֹͣ�������ƶ�
void enemy_pattern1(int i){
	int t=enemy[i].cnt;
	if(t==0)
        enemy[i].vy=3;//�����ƶ�
    if(t==40)
        enemy[i].vy=0;//ֹͣ
    if(t==40+enemy[i].wait){//�ڵ�¼��ʱ��������ֹͣ
        enemy[i].vx=-1;//����
        enemy[i].vy=2;//�����ƶ�
        enemy[i].muki=0;//���÷���Ϊ��
	}
}

//�ƶ�ģʽ2
//�����ƶ�Ȼ��ֹͣȻ���������ƶ�
void enemy_pattern2(int i){
    int t=enemy[i].cnt;
    if(t==0)
        enemy[i].vy=3;//�����ƶ�
    if(t==40)
        enemy[i].vy=0;//ֹͣ
    if(t==40+enemy[i].wait){// �ڵ�¼��ʱ��������ֹͣ
        enemy[i].vx=1;//����
        enemy[i].vy=2;//�����ƶ�
        enemy[i].muki=2;//���÷���Ϊ��
    }
}

//�ƶ�ģʽ3
//Ѹ�ٵ��½�Ȼ�������ƶ�
void enemy_pattern3(int i){
    int t=enemy[i].cnt;
    if(t==0)
        enemy[i].vy=5;//�����ƶ�
    if(t==30){//;�з�������
        enemy[i].muki=0;
    }
    if(t<100){
        enemy[i].vx-=5/100.0;//�������
        enemy[i].vy-=5/100.0;//����
    }
}

//�ƶ�ģʽ4
//Ѹ�ٵ��½�Ȼ�������ƶ�
void enemy_pattern4(int i){
    int t=enemy[i].cnt;
    if(t==0)
        enemy[i].vy=5;//�����ƶ�
    if(t==30){//;�з�������
        enemy[i].muki=2;
    }
    if(t<100){
        enemy[i].vx+=5/100.0;//�ҷ������
        enemy[i].vy-=5/100.0;//�p��
    }
}

//�ƶ�ģʽ5
//б���������ƶ�
void enemy_pattern5(int i){
    int t=enemy[i].cnt;
    if(t==0){
        enemy[i].vx-=1;
        enemy[i].vy=2;
        enemy[i].muki=0;
    }
}

//�ƶ�ģʽ6
//б���������ƶ�
void enemy_pattern6(int i){
    int t=enemy[i].cnt;
    if(t==0){
        enemy[i].vx+=1;
        enemy[i].vy=2;
        enemy[i].muki=2;
    }
}

//�ƶ�ģʽ7
//ֹͣȻ��������������ƶ�
void enemy_pattern7(int i){
    int t=enemy[i].cnt;
    if(t==enemy[i].wait){//�ڵ�¼��ʱ��������ֹͣ
        enemy[i].vx=-0.7;//����
        enemy[i].vy=-0.3;//�����ƶ�
        enemy[i].muki=0;//���÷���Ϊ��
    }
}

//�ƶ�ģʽ8
//ֹͣȻ��������������ƶ�
void enemy_pattern8(int i){
    int t=enemy[i].cnt;
    if(t==enemy[i].wait){//�ڵ�¼��ʱ��������ֹͣ
        enemy[i].vx=+0.7;//����
        enemy[i].vy=-0.3;//�����ƶ�
        enemy[i].muki=2;//���÷���Ϊ��
    }
}

//�ƶ�ģʽ9
//ֹͣȻ������������ƶ�
void enemy_pattern9(int i){
    int t=enemy[i].cnt;
    if(t==enemy[i].wait)//�ڵ�¼��ʱ��������ֹͣ
        enemy[i].vy=-1;//�����ƶ�
}


//�ƶ�ģʽ10
//�½�Ȼ��ת��Ȧ�����ƶ�
void enemy_pattern10(int i){
    int t=enemy[i].cnt;
    if(t==0) enemy[i].vy=4;//�����ƶ�
    if(t==40)enemy[i].vy=0;//ֹͣ
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