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
				enter_func_tm("���");
            	calc_ch();       enter_func_tm("��ɫӋ��");
            	ch_move();       enter_func_tm("��ɫ�ƶ�");
            	cshot_main();    enter_func_tm("�Ի����main");
            	enemy_main();    enter_func_tm("���˴���main");
            	boss_shot_main();enter_func_tm("Boss���main");
            	shot_main();     enter_func_tm("���main");
            	out_main();      enter_func_tm("��ײ�ж�");
            	effect_main();   enter_func_tm("��Чmain");
            	calc_main();     enter_func_tm("����main");
            	graph_main();    enter_func_tm("����main");
            	if(boss.flag==0)
            	        stage_count++;
            	break;
            default:
                printfDx("�����func_state\n");
                break;
        }
		music_play();			enter_func_tm("���ֲ���");
        fps_wait();             enter_func_tm("������ʱ��",1);
        if(CheckStateKey(KEY_INPUT_ESCAPE)==1)break;
        ScreenFlip();
		count++;
    }

    DxLib_End();
    return 0;
}

