#include "../include/GV.h"
//���Ƶ��������
#define STR_MAX 64
//���Լ��ĺ����������
#define FUNC_MAX 30
//������ǰ�ǵڼ���
int func_count;
//������һ�βⶨ��ʱ��
LONGLONG lt;
//����ⶨ�����õı���
typedef struct{
        int tm;
        char str[STR_MAX];
}func_tm_t;
func_tm_t func_tm[FUNC_MAX];

//��¼��st�����н��ܵ������ݡ����flagΪ1�Ļ�������
void enter_func_tm(char st[], int flag){
        int i;
        LONGLONG nowtm;
        if(func_count>=FUNC_MAX){
                printfDx("func_count��ֵ%d�쳣\n",func_count);
                return ;
        }
        nowtm=GetNowHiPerformanceCount() ;
        if(nowtm-lt<INT_MAX){//�����int���Ա�ʾ�ķ�Χ�ڵĻ�
                func_tm[func_count].tm=(int)(nowtm-lt);//���洦��ʱ��
                memcpy(func_tm[func_count].str,st,STR_MAX-1);//�����ַ���
                func_tm[func_count].str[STR_MAX-1]=0;//������ֹ����\0��
        }
        else//��������Ļ�
                func_tm[func_count].tm=-1;//����

        lt=nowtm ;//������һ�μ�¼��ʱ��

        if(flag==1){//����
                for(i=func_count+1;i<FUNC_MAX;i++)
                        func_tm[i].str[0]=0;
                func_count=0;
        }
        else
                func_count++;
}

//��������
void draw_func_tm(int x, int y){
        int i;
        unsigned int total=0;
        for(i=0;i<FUNC_MAX;i++){
                if(func_tm[i].str[0]==0)break;
                DrawFormatStringToHandle(x,y+14*i,color[0],font[0],"%05.2f:%s",func_tm[i].tm/1000.0,func_tm[i].str );
                total+=func_tm[i].tm;
        }
        DrawFormatStringToHandle(x,y+14*i,color[0],font[0],"�ϼ�:%05.2f",total/1000.0);
}