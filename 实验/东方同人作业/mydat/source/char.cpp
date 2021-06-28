#include "../include/GV.h"

extern void enter_char_item();

void calc_ch(){
    if(ch.flag==1){//正在处理决死
        bright_set.brt=80;//变暗
        if(ch.cnt>20){//0.33秒处理决死
            ch.flag   =2;    //1:正在处理决死　2:自机被击毁正在上浮
            ch.cnt    =0;
            bright_set.brt=255;
        }
    }
    if(ch.cnt==0 && ch.flag==2){//当前瞬间被击毁的话
        enter_char_item();//登录自机的道具(39章)
        ch.x=FMX/2;//设置坐标
        ch.y=FMY+30;
        ch.mutekicnt++;//进入无敌状态
    }
    if(ch.flag==2){//如果被击毁正在上浮的话
        unsigned int push=CheckStatePad(configpad.left)+CheckStatePad(configpad.right)
            +CheckStatePad(configpad.up)+CheckStatePad(configpad.down);
        ch.y-=1.5;//将角色往上移动
		//1秒钟以上，或者角色已经到达某个位置并且按下某键
        if(ch.cnt>60 || (ch.y<FMY-20 && push)){
            ch.cnt=0;
            ch.flag=0;//将角色状态还原
        }
    }
    if(ch.mutekicnt>0){//如果无敌计数不为0的话
        ch.mutekicnt++;
        if(ch.mutekicnt>150)//在150以上
            ch.mutekicnt=0;//还原
    }
    ch.cnt++;//角色计数器自增
    ch.img=(ch.cnt%24)/6;//决定当前的图像
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


