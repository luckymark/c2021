#include "../include/GV.h"

extern void enter_char_item();

void calc_ch(){
    if(ch.flag==1){//���ڴ������
        bright_set.brt=80;//�䰵
        if(ch.cnt>20){//0.33�봦�����
            ch.flag   =2;    //1:���ڴ��������2:�Ի������������ϸ�
            ch.cnt    =0;
            bright_set.brt=255;
        }
    }
    if(ch.cnt==0 && ch.flag==2){//��ǰ˲�䱻���ٵĻ�
        enter_char_item();//��¼�Ի��ĵ���(39��)
        ch.x=FMX/2;//��������
        ch.y=FMY+30;
        ch.mutekicnt++;//�����޵�״̬
    }
    if(ch.flag==2){//��������������ϸ��Ļ�
        unsigned int push=CheckStatePad(configpad.left)+CheckStatePad(configpad.right)
            +CheckStatePad(configpad.up)+CheckStatePad(configpad.down);
        ch.y-=1.5;//����ɫ�����ƶ�
		//1�������ϣ����߽�ɫ�Ѿ�����ĳ��λ�ò��Ұ���ĳ��
        if(ch.cnt>60 || (ch.y<FMY-20 && push)){
            ch.cnt=0;
            ch.flag=0;//����ɫ״̬��ԭ
        }
    }
    if(ch.mutekicnt>0){//����޵м�����Ϊ0�Ļ�
        ch.mutekicnt++;
        if(ch.mutekicnt>150)//��150����
            ch.mutekicnt=0;//��ԭ
    }
    ch.cnt++;//��ɫ����������
    ch.img=(ch.cnt%24)/6;//������ǰ��ͼ��
}

void ch_move(){
	int i,sayu_flag=0,joge_flag=0;
	double x,y,mx,my,naname=1;
	double move_x[4]={-4.0,4.0,0,0},move_y[4]={0,0,4.0,-4.0};
	int inputpad[4];
	inputpad[0]=CheckStatePad(configpad.left);
	inputpad[1]=CheckStatePad(configpad.right);
	inputpad[2]=CheckStatePad(configpad.down);
	inputpad[3]=CheckStatePad(configpad.up);

	if(ch.flag==1)
		return;

	if(CheckStatePad(configpad.left)>0)
		ch.img+=4*2;
	if(CheckStatePad(configpad.right)>0)
		ch.img+=4*1;

	for(i=0;i<2;i++)
		if(inputpad[i]>0)
			sayu_flag=1;
	for(i=2;i<4;i++)
		if(inputpad[i]>0)
			joge_flag=1;
	if(sayu_flag==1&&joge_flag==1)
		naname=sqrt(2.0);
	for(int i=0;i<4;i++){
		if(inputpad[i]>0){
			x=ch.x,y=ch.y;
			mx=move_x[i];
			my=move_y[i];
			if(CheckStatePad(configpad.slow)>0){
				mx=move_x[i]/3;
				my=move_y[i]/3;
			}
			x+=mx/naname,y+=my/naname;
			if(!(x<10||x>FMX-10||y<5||y>FMY-5)){
				ch.x=x,ch.y=y;
			}
		}
	}
}


