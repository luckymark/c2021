//enemy.cpp
	GLOBAL void enemy_main();//敌人处理

//char.cpp
	GLOBAL void calc_ch();//角色计算
	GLOBAL void ch_move();//控制角色的移动

//graph.cpp
	GLOBAL void graph_main();//绘制main

//ini.cpp
	GLOBAL void first_ini();//开始前的初始化
	GLOBAL void ini();//游戏初始化

//key.cpp
	GLOBAL int GetHitKeyStateAll_2();//键盘按键传入
	GLOBAL int CheckStateKey(unsigned char Handle);//返回按键状态

	GLOBAL void GetHitPadStateAll();//手柄按键传入
	GLOBAL int CheckStatePad(unsigned int Handle);//返回手柄状态

//laod.cpp
	GLOBAL void load();//载入数据
	GLOBAL void load_story();//将敌人信息从excel读取并保存

//shot.cpp
    GLOBAL double shotatan2(int n);//返回登录了的第n号射击的敌人和自机的之间的夹角
    GLOBAL int shot_search(int n);////搜索空着的子弹
    GLOBAL void shot_main();//弹幕制作

//music.cpp
    GLOBAL void music_ini();//音乐初始化
    GLOBAL void music_play();//音乐读取播放
//enemy_act_pattern.cpp
	GLOBAL double rang(double);//返回随即角度
//cshot.cpp
	GLOBAL void cshot_main();//自机射击
//out.cpp
	GLOBAL void out_main();//碰撞判定
//effect.cpp
	GLOBAL void effect_main();//制作消灭特效
//boss_shot.cpp
	GLOBAL void boss_shot_main();//boss弹幕
//calc.cpp
        GLOBAL void calc_main();//道具制作
//fps.cpp
	GLOBAL void fps_wait();//fps控制
	GLOBAL void draw_fps(int x,int y);//fps显示
//dn.cpp
	GLOBAL void enter_dn(int size,int time);//屏幕晃动的登录
//check_time.cpp
	GLOBAL void enter_func_tm(char st[], int flag = 0);//监测运行时间
	GLOBAL void draw_func_tm(int x, int y);//显示运行时间
