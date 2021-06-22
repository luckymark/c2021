#include "../include/GV.h"

extern void dn_calc();

int search_effect(){
    for(int i=0;i<EFFECT_MAX;i++){
        if(effect[i].flag==0)
            return i;
    }
    return -1;
}

void calc_effect(){
    for(int i=0;i<EFFECT_MAX;i++){
        if(effect[i].flag>0){
            effect[i].x+=cos(effect[i].mvang)*effect[i].spd;
            effect[i].y+=sin(effect[i].mvang)*effect[i].spd;
            switch(effect[i].knd){
                case 0:
                    effect[i].cnt++;
                    effect[i].r+=0.08;
                    if(effect[i].cnt>10)
                        effect[i].brt-=25;
                    if(effect[i].cnt>20)
                        effect[i].flag=0;
                    break;
                case 1:
                    if(effect[i].cnt<60)
                        effect[i].spd-=(0.2+effect[i].cnt*effect[i].cnt/3000.0);
                    if(effect[i].cnt==60){
                        effect[i].spd=0;
                        se_flag[15]=1;
						enter_dn(11,20);//(45)
                    }
                    effect[i].r+=0.015;
                    if(effect[i].cnt<51)
                        effect[i].brt+=5;
                    if(effect[i].cnt>=60){
                        effect[i].r+=0.04;
                        effect[i].brt-=255/30.0;
                    }
                    effect[i].cnt++;
                    if(effect[i].cnt>=90)
                        effect[i].flag=0;
                    break;
                case 2:
                    if(effect[i].cnt<51)
                        effect[i].brt+=4;
                    if(effect[i].cnt>130-51)
                        effect[i].brt-=4;
                    effect[i].cnt++;
                    if(effect[i].cnt>=130)
                        effect[i].flag=0;
                    break;
                case 3:
                    if(effect[i].cnt<51)
                        effect[i].brt+=2;
                    if(effect[i].cnt>130-51)
                        effect[i].brt-=2;
                    effect[i].cnt++;
                    if(effect[i].cnt>=130)
                        effect[i].flag=0;
                    break;                
                case 4:
                    if(effect[i].cnt>=6)
                        effect[i].brt-=255/6;
                    effect[i].r+=0.12;
                    effect[i].cnt++;
                    if(effect[i].cnt>=12 || ch.flag!=1)
                        effect[i].flag=0;
                    break;                
                default:
                    printfDx("effect\n");
                    break;
            }
        }
    }
}

int search_del_effect(){
    for(int i=0;i<DEL_EFFECT_MAX;i++){
        if(del_effect[i].flag==0)
            return i;
    }
    return -1;
}

void enter_del_effect(int s){
    int k=search_del_effect();
    if(k!=-1){
        del_effect[k].flag=1;
        del_effect[k].cnt=0;
        del_effect[k].col=enemy[s].back_col;
        del_effect[k].x=enemy[s].x;
        del_effect[k].y=enemy[s].y;
    }
}

void calc_del_effect(){
    int k;
    for(int i=0;i<DEL_EFFECT_MAX;i++){
        if(del_effect[i].flag>0){
            if(del_effect[i].cnt%2==0){
                if((k=search_effect())!=-1){
                    memset(&effect[k],0,sizeof(effect_t));
                    effect[k].flag=1;
                    effect[k].brt=255;
                    effect[k].ang=rang(PI);
                    effect[k].col=del_effect[i].col;
                    effect[k].eff=1;
                    effect[k].img=img_del_effect[effect[k].col];
                    effect[k].knd=0;
                    effect[k].x=del_effect[i].x;
                    effect[k].y=del_effect[i].y;
                    effect[k].spd=0;
                }
            }
            if(del_effect[i].cnt>8){
                del_effect[i].flag=0;
            }
            del_effect[i].cnt++;
        }
    }
}

void enter_bom(){
    int k;
    bom.flag=1;
    bom.cnt=0;
    bom.knd=0;
    ch.flag=0;
    ch.mutekicnt=1;
    se_flag[14]=1;
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=3;
        effect[k].brt=0;
        effect[k].ang=PI/2;
        effect[k].mvang=-PI/2;
        effect[k].spd=1;
        effect[k].r=1;
        effect[k].eff=2;
        effect[k].img=img_eff_bom[3];
        effect[k].x=70;
        effect[k].y=300;
    }
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=3;
        effect[k].brt=0;
        effect[k].ang=0;
        effect[k].mvang=0;
        effect[k].spd=1;
        effect[k].r=1;
        effect[k].eff=2;
        effect[k].img=img_eff_bom[3];
        effect[k].x=100;
        effect[k].y=350;
    }
    if((k=search_effect())!=-1){
        effect[k].flag=1;
        effect[k].cnt=0;
        effect[k].knd=2;
        effect[k].brt=0;
        effect[k].ang=0;
        effect[k].mvang=-PI/2;
        effect[k].spd=0.7;
        effect[k].r=1;
        effect[k].eff=2;
        effect[k].img=img_eff_bom[2];
        effect[k].x=260;
        effect[k].y=300;
    }
}

void bom_calc(){
    int n,k;
	double shot_angle[4]={0,PI,PI/2,PI*1.5};
    if((ch.flag==0||ch.flag==1) && bom.flag==0){
        if(CheckStatePad(configpad.bom)==1){
            enter_bom();
        }
    }
    if(bom.flag==1){
        if(bom.cnt%10==0){
            n=(bom.cnt/10);
            if(n<4 && (k=search_effect())!=-1){
                effect[k].flag=1;
                effect[k].cnt=0;
                effect[k].knd=1;
                effect[k].brt=0;
                effect[k].ang=rang(PI);
                effect[k].mvang=shot_angle[n]-PI/4;
                effect[k].spd=13+rang(2);
                effect[k].r=0.5;
                effect[k].eff=2;
                effect[k].img=img_eff_bom[(bom.cnt/10)/3];
                effect[k].x=ch.x;
                effect[k].y=ch.y;
            }
        }
        bom.cnt++;
        if(bom.cnt<40)
            bright_set.brt=255-bom.cnt*5;
        if(bom.cnt>90)
            bright_set.brt=255-40*5+(bom.cnt-90)*5;
        if(bom.cnt>130){
            bom.flag=0;
            bright_set.brt=255;
        }
    }
}


void enter_crybom_effect(){
    int k;
    if(ch.flag==1){
        if(ch.cnt%2==0){
            if((k=search_effect())!=-1){
                effect[k].flag=1;
                effect[k].cnt=0;
                effect[k].knd=4;
                effect[k].brt=255;
                effect[k].ang=rang(PI);
                effect[k].spd=0;
                effect[k].r=0;
                effect[k].eff=2;
                effect[k].img=img_del_effect[GetRand(4)];
                effect[k].x=ch.x;
                effect[k].y=ch.y;
            }
        }
    }
}

void effect_main(){
    dn_calc();
    calc_del_effect();
    calc_effect();
    bom_calc();
    enter_crybom_effect();
}