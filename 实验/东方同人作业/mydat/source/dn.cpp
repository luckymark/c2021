#include "../include/GV.h"

void enter_dn(int size, int time){
        dn.flag=1;
        dn.cnt=0;
        dn.time=time;
        dn.size=size;
}

//�˰󣡵�ҡ������Ĵ���
void dn_calc(){
    if(dn.flag==1){
        dn.x=(int)rang(dn.size);
        dn.y=(int)rang(dn.size);
        dn.cnt++;
        if(dn.cnt>dn.time){//�������ָ����ʱ��Ļ�ֹͣ
            dn.flag=0;
            dn.x=0;
            dn.y=0;
        }
    }
}


