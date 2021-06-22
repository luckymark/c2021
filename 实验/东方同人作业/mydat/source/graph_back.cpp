#include "../include/GV.h"

extern int DrawGraphFd( int xd, int yd, int GrHandle, int TransFlag);

void graph_back00(){//通常背景
        SetDrawArea( FX , FY , FX+FMX , FY+FMY ) ;//设定可以绘制的区域
        DrawGraphFd(0,count%700-700,img_back[0],FALSE);
        DrawGraphFd(0,count%700    ,img_back[0],FALSE);
        SetDrawArea( 0, 0, 640, 480);//还原区域
}

void graph_back01(){//SC用背景
        SetDrawArea( FX , FY , FX+FMX , FY+FMY ) ;//设定可以绘制的区域
        DrawGraphFd(0,-count%480,img_back[11],FALSE);
        DrawGraphFd(0,-count%480+480,img_back[11],FALSE);
        DrawGraphFd(0,0,img_back[10],TRUE);
        SetDrawArea( 0, 0, 640, 480);//还原区域
}

void graph_back_main(){
        //Boss如果有效且为SC得话
        if(boss.flag==1 && boss.back_knd[boss.knd]==1)
                graph_back01();
        else//除此之外
                graph_back00();
}