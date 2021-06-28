#include "../include/GV.h"

void enter_dn(int size, int time){
        dn.flag=1;
        dn.cnt=0;
        dn.time=time;
        dn.size=size;
}

//咚绑！地摇动画面的处理
void dn_calc(){
    if(dn.flag==1){
        dn.x=(int)rang(dn.size);
        dn.y=(int)rang(dn.size);
        dn.cnt++;
        if(dn.cnt>dn.time){//如果超过指定的时间的话停止
            dn.flag=0;
            dn.x=0;
            dn.y=0;
        }
    }
}


