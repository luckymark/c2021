#include "../include/GV.h"

#define OPTION_X 25
#define OPTION_Y 35

int cshot0num[2]={2,4};
int cshot0pos_x[4]={-10,10,-30,30};
int cshot0pos_y[4]={-30,-30,-10,-10};
double option0ang[4] = {-PI/2,-PI/2,-PI/2-PI/4,-PI/2+PI/4};//Option�ķ���Ƕ�

int search_cshot(){
	for(int i=0;i<CSHOT_MAX;i++){
		if(cshot[i].flag==0)
			return i;
	}
	return -1;
}

//ͨ�������¼
void ch0_shot_pattern(){
        int k;
        int n=cshot0num[ch.power<200?0:1];
        for(int i=0;i<n;i++){
                if((k=search_cshot())!=-1){
                        cshot[k].flag=1;
                        cshot[k].cnt=0;
                        cshot[k].angle=-PI/2;
                        cshot[k].spd=20;
                        cshot[k].x=ch.x+cshot0pos_x[i];
                        cshot[k].y=ch.y+cshot0pos_y[i];
                        cshot[k].power= (n<2 ? 20 : 12) + ch.power/100;//2���ӵ��Ļ�20,4���ӵ��Ļ�12 (50)
                        cshot[k].knd=0;
                        cshot[k].img=img_cshot[0];//ͼ���Ŵ���(49)
                }
        }
        se_flag[2]=1;//��������Ч
        if(ch.power>=100){
                for(int i=0;i<(ch.power<300?2:4);i++){
                        if((k=search_cshot())!=-1){
                                cshot[k].flag=1;
                                cshot[k].cnt=0;
                                cshot[k].angle=option0ang[i];
                                cshot[k].spd=20;
                                cshot[k].x=option_bb[i%2].x;
                                cshot[k].y=option_bb[i%2].y;
                                cshot[k].power=10-7*(i/2);//ע�ⲻҪΪ����(50)
                                cshot[k].knd=1;
                                cshot[k].img=img_cshot[1];//ͼ���Ŵ��� (49)
                        }
                }
        }
}
//������һ������ĵ�¼
void ch1_shot_pattern(){
        int k;
        int n=cshot0num[ch.power<200?0:1];
        for(int i=0;i<n;i++){
                if((k=search_cshot())!=-1){
                        cshot[k].flag=1;
                        cshot[k].cnt=0;
                        cshot[k].angle=-PI/2;
                        cshot[k].spd=20;
                        cshot[k].x=ch.x+cshot0pos_x[i]/3;//�����еĻ���λ��������ƫ��
                        cshot[k].y=ch.y+cshot0pos_y[i]/2;
                        cshot[k].power= (n<2 ? 20 : 12) + ch.power/100;//2���Ļ�20,4���Ļ�12(50)
                        cshot[k].knd=0;
                        cshot[k].img=img_cshot[0];//ͼ���Ŵ���(49)
                }
        }
        se_flag[2]=1;
        if(ch.power>=100){
                for(int i=0;i<(ch.power<300?2:4);i++){
                        if((k=search_cshot())!=-1){
                                cshot[k].flag=1;
                                cshot[k].cnt=0;
                                cshot[k].angle=option0ang[i];
                                cshot[k].spd=20;
                                cshot[k].x=option_bb[i%2].x;
                                cshot[k].y=option_bb[i%2].y;
                                cshot[k].power=10-7*(i/2);//ע�ⲻҪΪ����(50)
                                cshot[k].knd=1;
                                cshot[k].img=img_cshot[1];//ͼ���Ŵ���(49)
                        }
                }
        }
}

//Ѱ�Ҿͽ��ĵ��˲����ýǶ�
void calc_homing(int k){
        int i,d, num=-1, min=-1;
        double x,y;
        if(boss.flag==0){//Boss���ڵ�ʱ��
                for(i=0;i<ENEMY_MAX;i++){//���˵�������
                        if(enemy[i].flag==1){
                                x=(enemy[i].x-cshot[k].x);
                                y=(enemy[i].y-cshot[k].y);
                                d=(int)(x*x+y*y);//�ӵ�����˵ľ���
                                if(d<min || min==-1){//������Ϊ��Сֵ���߻�û�б����κ�ֵ
                                        num=i;//��ż�¼
                                        min=d;//�����¼
                                }
                        }
                }
        }
		//����ҵ��ͽ��ĵ��˵Ļ����ֻ���Boss������HP��Ϊ0��ʱ�����ýǶ�
        if(num!=-1 || boss.flag==1 && boss.hp>0){
                if(boss.flag==0){
                        x=enemy[num].x-cshot[k].x;
                        y=enemy[num].y-cshot[k].y;
                }
                else{
                        x=boss.x-cshot[k].x;
                        y=boss.y-cshot[k].y;
                }
                cshot[k].angle=atan2(y,x);
        }
}

//Option��Bonbon����
void calc_option_bb(){
        if(ch.power>=100){//power��100���ϵĻ�����Option
                for(int i=0;i<2;i++){
                        if(CheckStatePad(configpad.slow)==0){//������ǵ����ƶ��еĻ�
                                option_bb[i].x=ch.x+OPTION_X*(i==0 ? -1 : 1);
                                option_bb[i].y=ch.y+OPTION_Y+sin(PI2/150*option_bb[i].cnt)*20;
                        }
                        else{
                                option_bb[i].x=ch.x+OPTION_X/2*(i==0 ? -1 : 1);
                                option_bb[i].y=ch.y+OPTION_Y/2;
                        }
                        option_bb[i].cnt++;
                }
                if(option_bb[0].flag==0)
                        option_bb[0].flag = option_bb[1].flag = 1;
        }
        else{
                if(option_bb[0].flag==1)
                        option_bb[0].flag = option_bb[1].flag = 0;
        }
}

//�����¼����
void enter_shot(){
		//�����������ť��ʱ��
        if(CheckStatePad(configpad.shot)>0){
                ch.shot_cnt++;
                if(ch.shot_cnt%3==0){//ÿ3�μ������һ��
                        if(CheckStatePad(configpad.slow)>0)//������ڵ����ƶ��еĻ�
                                ch1_shot_pattern();
                        else
                                ch0_shot_pattern();
                }
        }
        else
                ch.shot_cnt=0;
}

//������ƶ�����
void calc_cshot(){
        for(int i=0;i<CSHOT_MAX;i++){
                if(cshot[i].flag==1){
                        int dranx=(int)(cshot[i].spd+11/2),drany=(int)(cshot[i].spd+55/2);
                        if(cshot[i].knd==1)
                                calc_homing(i);
                        cshot[i].x+=cos(cshot[i].angle)*cshot[i].spd;
                        cshot[i].y+=sin(cshot[i].angle)*cshot[i].spd;
                        cshot[i].cnt++;
                        if(cshot[i].x<-dranx || cshot[i].x>FMX+dranx ||
                                cshot[i].y<-drany || cshot[i].y>FMY+drany)//�ڻ����������ܵĻ�
                                cshot[i].flag=0;
                }
        }
}
//�ͽ�ɫ�����صĺ���
void cshot_main(){
	calc_option_bb();//Option��Bonon����
	calc_cshot();//�������ļ���
	enter_shot();//�����¼
}