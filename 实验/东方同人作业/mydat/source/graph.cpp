#include "../include/GV.h"


extern void graph_back_main();
extern void draw_fps(int,int);
extern void draw_func_tm(int,int);


int DrawRotaGraphF( double xd, double yd, double ExRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) {
        return DrawRotaGraphF((float)xd,(float)yd,ExRate,Angle,GrHandle,TransFlag,TurnFlag);
}
int DrawModiGraphF( double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, int GrHandle, int TransFlag ){
        return DrawModiGraphF( (float)x1, (float)y1, (float)x2, (float)y2, (float)x3, (float)y3, (float)x4, (float)y4, GrHandle, TransFlag ) ;
}

int DrawRotaGraphFdF( double xd, double yd, double ExRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) {
        return DrawRotaGraphF((float)xd+FX+dn.x,(float)yd+FY+dn.y,ExRate,Angle,GrHandle,TransFlag,TurnFlag);
}
int DrawModiGraphFdF( double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, int GrHandle, int TransFlag ){
        return DrawModiGraphF( (float)x1+FX+dn.x, (float)y1+FY+dn.y, (float)x2+FX+dn.x, (float)y2+FY+dn.y, 
                (float)x3+FX+dn.x, (float)y3+FY+dn.y, (float)x4+FX+dn.x, (float)y4+FY+dn.y, GrHandle, TransFlag ) ;
}
int DrawGraphFd( int xd, int yd, int GrHandle, int TransFlag) {
        return DrawGraph(xd+FX+dn.x,yd+FY+dn.y,GrHandle,TransFlag);
}

//Title的显示
void graph_stage_title(){
        if(stage_title.flag>0){
                SetDrawBlendMode( DX_BLENDMODE_ALPHA, stage_title.brt );
                DrawGraph(120,10,stage_title.img,TRUE);
                SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
        }
}

void graph_lazer(){
	int i;
	SetDrawMode( DX_DRAWMODE_BILINEAR ) ;
	for(i=0;i<LAZER_MAX;i++){
		if(lazer[i].flag>0){
			SetDrawBlendMode( DX_BLENDMODE_ADD, 255) ;
			DrawRotaGraphFdF(
				lazer[i].startpt.x,lazer[i].startpt.y,1.0,0,
				img_lazer_moto[lazer[i].knd][lazer[i].col],TRUE
			);
			DrawModiGraphFdF(
				lazer[i].disppt[0].x, lazer[i].disppt[0].y, 
				lazer[i].disppt[1].x, lazer[i].disppt[1].y, 
				lazer[i].disppt[2].x, lazer[i].disppt[2].y, 
				lazer[i].disppt[3].x, lazer[i].disppt[3].y, 
				img_lazer[lazer[i].knd][lazer[i].col],TRUE
			);
			SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
/*			myDrawSquare(
				lazer[i].outpt[0].x,lazer[i].outpt[0].y,
				lazer[i].outpt[1].x,lazer[i].outpt[1].y,
				lazer[i].outpt[2].x,lazer[i].outpt[2].y,
				lazer[i].outpt[3].x,lazer[i].outpt[3].y
			);*/
		}
	}
}
void graph_child(){
	int i;
	for(i=0;i<CHILD_MAX;i++){
		if(child[i].flag==1){
			DrawRotaGraphFdF(child[i].x,child[i].y,child[i].range,PI2*(count%60)/60,img_etc[6],TRUE);
		}
	}
}
void graph_enemy(){
	int i;
	for (i=0;i<ENEMY_MAX;i++){
		if(enemy[i].flag==1){
			DrawRotaGraphFdF(enemy[i].x,enemy[i].y,1.0f,0.0f,img_enemy[0][enemy[i].img],TRUE);
		}
	}
}

//自机绘制
void graph_ch(){
        double sx,sy,ny=(sin(2.0*PI*(count%50)/50)*3),ang=2.0*PI*(count%120)/120;

        if(CheckStatePad(configpad.slow)>0)//低速移动中的话
                sx=15,sy=15+ny;//拉近
        else
                sx=30,sy=30+ny;//在普通的位置

//      DrawRotaGraphFdF( ch.x-sx, ch.y+sy, 1.0f,  ang, img_chetc[2], TRUE );
//      DrawRotaGraphFdF( ch.x+sx, ch.y+sy, 1.0f, -ang, img_chetc[2], TRUE );

        if(ch.mutekicnt%2==0){//无敌状态的话亮灭
                //自机显示
                DrawRotaGraphFdF(ch.x,ch.y,1.0f,0.0f,img_ch[0][ch.img],TRUE);
                if(CheckStatePad(configpad.slow)>0)//低速移动中的话显示碰撞判定
                        DrawRotaGraphFdF( ch.x, ch.y, 1.0f, 2.0*PI*(count%120)/120, img_chetc[0], TRUE );
        }
}
void graph_boss_effect(){
        SetDrawBlendMode( DX_BLENDMODE_ALPHA, 150) ;
        DrawRotaGraphFdF(boss.dx,   boss.dy,
                                   (0.4+0.05*sin(PI2/360*(count%360)))*3,
                                   2*PI*(count%580)/580,
                                   img_etc[5], TRUE);
        DrawRotaGraphFdF(boss.dx,   boss.dy,
                                   (0.5+0.1*sin(PI2/360*(count%360)))*2,
                                   2*PI*(count%340)/340,img_etc[2],     TRUE);
        DrawRotaGraphFdF(boss.dx+60*sin(PI2/153*(count%153)),
                                   boss.dy+80*sin(PI2/120*(count%120)),
                                   0.4+0.05*sin(PI2/120*(count%120)),
                                   2*PI*(count%30)/30,img_etc[6],       TRUE);
        DrawRotaGraphFdF(boss.dx+60*sin(PI2/200*((count+20)%200)),
                                   boss.dy+80*sin(PI2/177*((count+20)%177)),
                                   0.3+0.05*sin(PI2/120*(count%120)), 
                                   2*PI*(count%35)/35,img_etc[6],       TRUE);
        SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
        DrawRotaGraphFdF(boss.dx+60*sin(PI2/230*((count+40)%230)),
                                   boss.dy+80*sin(PI2/189*((count+40)%189)),
                                   0.6+0.05*sin(PI2/120*(count%120)),
                                   2*PI*(count%40)/40,img_etc[6],       TRUE);
}

void graph_boss(){
        int i;
        if(boss.flag==0)return;
		graph_boss_effect();
        DrawRotaGraphFdF(boss.x,boss.y,1.0f,0.0f,img_dot_riria[0],TRUE);
        if(boss.hp_max==0){printfDx("graph_boss的0%\n");return;}
        for(i=0;i<FMX*0.98*boss.hp/boss.hp_max;i++){
                if(boss.back_knd[boss.knd]==1)
                        DrawGraphFd(3+i,2,img_etc[7],FALSE);
                else
                        DrawGraphFd(3+i,2,img_etc[1],FALSE);
        }
}

//绘制子弹
void graph_bullet(){
	 int i,j;
	 SetDrawMode( DX_DRAWMODE_BILINEAR ) ;//线性插值绘制
	 for(i=0;i<SHOT_MAX;i++){//敌人弹幕数次循环
	 	if(shot[i].flag>0){//如果弹幕数据为有效
	 		for(j=0;j<SHOT_BULLET_MAX;j++){//弹幕所有的子弹的最大数次循环
	 			if(shot[i].bullet[j].flag!=0){//如果子弹数据为有效
	 				if(shot[i].bullet[j].eff==1)
	 					SetDrawBlendMode( DX_BLENDMODE_ADD, 255) ;

	 				DrawRotaGraphFdF(
	 					shot[i].bullet[j].x, shot[i].bullet[j].y,
	 					1.0, shot[i].bullet[j].angle+PI/2,
	 					img_bullet[shot[i].bullet[j].knd][shot[i].bullet[j].col],TRUE);

	 				if(shot[i].bullet[j].eff==1)
	 					SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
	 			}
	 		}
	 	}
	 }
	//Boss
	 if(boss_shot.flag>0){//弹幕数据有效的话
	 	for(j=0;j<BOSS_BULLET_MAX;j++){//弹幕所有的子弹的最大数次循环
	 		if(boss_shot.bullet[j].flag!=0){//子弹数据有效的话
	 			if(boss_shot.bullet[j].eff==1)
	 				SetDrawBlendMode( DX_BLENDMODE_ADD, 255) ;

	 			DrawRotaGraphFdF(
	 				boss_shot.bullet[j].x, boss_shot.bullet[j].y,
	 				1.0, boss_shot.bullet[j].angle+PI/2,
	 				img_bullet[boss_shot.bullet[j].knd][boss_shot.bullet[j].col],TRUE);

	 			if(boss_shot.bullet[j].eff==1)
	 				SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
	 		}
	 	}
	 }
	 SetDrawMode(DX_DRAWMODE_NEAREST);//恢复绘制状态
}

void graph_develop(){
	DrawFormatString(0,0,GetColor(255,255,255),"%d",stage_count);
}

void graph_cshot(){
        for(int i=0;i<CSHOT_MAX;i++){
                if(cshot[i].flag>0){
                        DrawRotaGraphFdF(cshot[i].x,cshot[i].y,1,cshot[i].angle+PI/2,cshot[i].img,TRUE);
                }
        }
        for(int i=0;i<2;i++){
                if(option_bb[i].flag>0){
                        DrawRotaGraphFdF(option_bb[i].x,option_bb[i].y,1,0,option_bb[i].img,TRUE);
                }
        }
}

void graph_effect(int knd){
        for(int i=0;i<EFFECT_MAX;i++){
                if(effect[i].flag>0 && effect[i].knd==knd){
                        if(effect[i].eff==1)//特效是闪光特效的情况下
                                SetDrawBlendMode( DX_BLENDMODE_ADD, effect[i].brt) ;
                        if(effect[i].eff==2)//特效是α特效的情况下
                                SetDrawBlendMode(DX_BLENDMODE_ALPHA, effect[i].brt) ;
                        DrawRotaGraphFdF(effect[i].x,effect[i].y,effect[i].r,effect[i].ang,effect[i].img,TRUE);
                        if(effect[i].eff==1 || effect[i].eff==2)
                                SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0) ;
                }
        }
}


void graph_item(){
        int i;
        for(i=0;i<ITEM_MAX;i++){
                if(item[i].flag==1){
                        DrawRotaGraphFdF(item[i].x,item[i].y,
                            item[i].r,PI2*(count%120)/120,img_item[item[i].knd][1],TRUE);
                        DrawRotaGraphFdF(item[i].x,item[i].y,
                            item[i].r*0.8,-PI2*(count%120)/120,img_item[item[i].knd][1],TRUE);
                        DrawRotaGraphFdF(item[i].x,item[i].y,
                            item[i].r,0,img_item[item[i].knd][0],TRUE);
                }
        }
}
//显示Score面板(41)
void graph_board_states(){
        int i;
        int score=ch.score;
        int power=ch.power;
        int graze=ch.graze;
        int point=ch.point;
        int money=ch.money;
        
        for(i=0;i<9;i++){//显示Score
                DrawRotaGraph(625-15*i,30,1.0f,0.0f,img_num[0][score%10],TRUE);
                DrawRotaGraph(625-15*i,50,1.0f,0.0f,img_num[0][score%10],TRUE);
                score/=10;
        }
        
        for(i=0;i<ch.num;i++)//显示残机数
                DrawGraph(499+12*i,63,img_etc[8],TRUE);
        DrawRotaGraph(547,91,0.9f,0.0f,img_num[0][power%10],TRUE);power/=10;
        DrawRotaGraph(536,91,0.9f,0.0f,img_num[0][power%10],TRUE);power/=10;
        DrawRotaGraph(513,91,1.0f,0.0f,img_num[0][power%10],TRUE);
        DrawString(522,82,".",color[0]);

        for(i=0;i<6;i++){//擦弹显示
                DrawRotaGraph(578-14*i,111,1.0f,0.0f,img_num[0][graze%10],TRUE);
                graze/=10;
        }
        
        for(i=0;i<4;i++){//point表示
                DrawRotaGraph(550-14*i,131,1.0f,0.0f,img_num[0][point%10],TRUE);
                point/=10;
        }
        
        for(i=0;i<6;i++){//金钱显示
                DrawRotaGraph(578-14*i,154,1.0f,0.0f,img_num[0][money%10],TRUE);
                money/=10;
        }
}

//面板绘制
void graph_board(){
        DrawGraph(      0,      0,img_board[10],FALSE);
        DrawGraph(      0, 16,img_board[11],FALSE);
        DrawGraph(      0,464,img_board[12],FALSE);
        DrawGraph(416,  0,img_board[20],FALSE);

        graph_board_states();//(41)
}
void graph_flash(){
        if(flash.flag>0){
                SetDrawBlendMode( DX_BLENDMODE_ALPHA, (int)(flash.brt) );
                DrawBox(FX,FY,FX+FMX,FY+FMY,color[0],TRUE);
                SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
        }
}
void graph_main(){

        if(bright_set.brt!=255)SetDrawBright(bright_set.brt,bright_set.brt,bright_set.brt);

        graph_back_main();//背景绘制main
        graph_effect(0);//敌人的消灭特效

        if(bright_set.brt!=255)SetDrawBright(255,255,255);

        graph_effect(4);//决死特效

        if(bright_set.brt!=255)SetDrawBright(bright_set.brt,bright_set.brt,bright_set.brt);

        graph_child();
        graph_item();//绘制道具
        graph_boss();
        graph_enemy();//敌人的绘制
        graph_cshot();//自机射击的绘制

        if(bright_set.brt!=255)SetDrawBright(255,255,255);

        graph_ch();//自机的绘制

        if(bright_set.brt!=255)SetDrawBright(bright_set.brt,bright_set.brt,bright_set.brt);
        
        graph_lazer();//激光的绘制
        graph_bullet();//子弹的绘制

        if(bright_set.brt!=255)SetDrawBright(255,255,255);

        graph_effect(1);//Boom的特效
        graph_effect(2);//Boom线的特效
        graph_effect(3);//Boom角色的特效
        graph_stage_title();//Title的显示
        graph_board();//面板的绘制
        graph_flash();//闪屏的绘制

        graph_develop();
        draw_fps(0,465);//fps绘制
        draw_func_tm(450,250);//处理时间绘制
}