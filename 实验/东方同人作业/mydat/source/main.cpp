#define GLOBAL_INSTANCE 
#include "../include/GV.h"

int ProcessLoop(){
    if(ProcessMessage()!=0)return -1;
    if(ClearDrawScreen()!=0)return -1;
    GetHitKeyStateAll_2();
    GetHitPadStateAll();  
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
    ChangeWindowMode(TRUE);
    if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;
    while(ProcessLoop()==0){
		music_ini();
        switch(func_state){
            case 0:
                load();       
                first_ini();
                func_state=99;
                break;
            case 99:
                ini();
				load_story();
                func_state=100;
                break;
            case 100:
				enter_func_tm("最初");
            	calc_ch();       enter_func_tm("角色計算");
            	ch_move();       enter_func_tm("角色移动");
            	cshot_main();    enter_func_tm("自机射击main");
            	enemy_main();    enter_func_tm("敌人处理main");
            	boss_shot_main();enter_func_tm("Boss射击main");
            	shot_main();     enter_func_tm("射击main");
            	out_main();      enter_func_tm("碰撞判定");
            	effect_main();   enter_func_tm("特效main");
            	calc_main();     enter_func_tm("计算main");
            	graph_main();    enter_func_tm("绘制main");
            	if(boss.flag==0)
            	        stage_count++;
            	break;
            default:
                printfDx("错误的func_state\n");
                break;
        }
		music_play();			enter_func_tm("音乐播放");
        fps_wait();             enter_func_tm("待机的时间",1);
        if(CheckStateKey(KEY_INPUT_ESCAPE)==1)break;
        ScreenFlip();
		count++;
    }

    DxLib_End();
    return 0;
}

