#include "../include/GV.h"

//Title����
void calc_stage_title(){

        if(stage_title.appear_cnt==stage_count){//��������ǿ�ʼ��ʾ��ʱ�̵Ļ�
                stage_title.flag=1;
                stage_title.img = LoadGraph("../dat/img/board/subject0.png");
        }

        if(stage_title.flag==0)return;

        if(stage_title.cnt<128)//�������128�μ������𽥱���
                stage_title.brt+=2;
        if(stage_title.cnt>128+128)//�𽥱䰵
                stage_title.brt-=2;
        if(stage_title.cnt>128+128+128){//����
                stage_title.cnt=0;
                stage_title.brt=0;
                stage_title.flag=0;
                DeleteGraph(stage_title.img);//�ͷ�ͼ��
                return ;
        }

        stage_title.cnt++;
		//ǿ�ƽ�����ʱ����Ҫ�ͷ�ͼ��
}

//���ߵ���ȡ����
void calc_item_indraw(int i){
        double v = item[i].state ? 8 : 3;//state�����1�Ļ��ٶ�Ϊ8����Ϊ3
        double angle=atan2(ch.y-item[i].y,ch.x-item[i].x);//�������Ի��ĽǶ�
        item[i].x += cos(angle)*v;
        item[i].y += sin(angle)*v;
}

//������ߵ��ƶ���
void calc_item(){
        for(int i=0;i<ITEM_MAX;i++){
                if(item[i].flag>0){
                        if(item[i].state==0)
                                if(ch.y<ITEM_GET_BORDER_LINE)//�������ȡ״̬�Ļ�
                                        item[i].state=1;
                        if(item[i].state==0){//�������ͨ״̬�Ļ�
                                double x=ch.x-item[i].x,y=ch.y-item[i].y;
                                //����ڵ���״̬�е��Ի������Ļ�
                                if(CheckStatePad(configpad.slow)>0 &&
                                                x*x+y*y<ITEM_INDRAW_RANGE*ITEM_INDRAW_RANGE){
                                        calc_item_indraw(i);//��ȡһ����
                                }
                                else{
                                        if(item[i].v<2.5)//�����ٶ�
                                                item[i].v+=0.06;
                                        item[i].y+=item[i].v;//�ƶ�
                                }
                        }
                        else{//�������ȡ״̬�Ļ�
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
        calc_flash();//����(42)
}

