#include "../include/GV.h"

//fps
#define FLAME 60

//fps�ļ�������60֡1�μ�¼��Ϊ��׼��ʱ��
int fps_count,count0t;
//Ϊ�˽���ƽ������,��¼60��1�����ڵ�ʱ��
int f[FLAME];
//ƽ��fps
double ave;

//��FLAME fpsΪĿ�����fps�ļ���Ϳ���
void fps_wait(){
    int term,i,gnt;
    static int t=0;
    if(fps_count==0){//60֡1�εĻ�
        if(t==0)//������ʼ�Ļ����ȴ�
            term=0;
        else//������һ�μ�¼�˵�ʱ�����
            term=count0t+1000-GetNowCount();
    }
    else    //Ӧ�õȴ���ʱ��=��ǰ������ʱ��-��ǰ��ʵ��ʱ��
        term = (int)(count0t+fps_count*(1000.0/FLAME))-GetNowCount();

    if(term>0)//ֻ�ȴ�Ӧ�õȴ���ʱ��
        Sleep(term);

    gnt=GetNowCount();

    if(fps_count==0)// 60֡����1�λ�׼���
        count0t=gnt;
    f[fps_count]=gnt-t;//��¼1�����ڵ�ʱ��
    t=gnt;
    //ƽ������
    if(fps_count==FLAME-1){
        ave=0;
        for(i=0;i<FLAME;i++)
            ave+=f[i];
        ave/=FLAME;
    }
    fps_count = (++fps_count)%FLAME ;
}

//��x,y��λ����ʾfps
void draw_fps(int x, int y){
    if(ave!=0){
        DrawFormatString(x, y,color[0],"[%.1f]",1000/ave);
    }
    return;
}