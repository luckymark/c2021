//enemy.cpp
	GLOBAL void enemy_main();//���˴���

//char.cpp
	GLOBAL void calc_ch();//��ɫ����
	GLOBAL void ch_move();//���ƽ�ɫ���ƶ�

//graph.cpp
	GLOBAL void graph_main();//����main

//ini.cpp
	GLOBAL void first_ini();//��ʼǰ�ĳ�ʼ��
	GLOBAL void ini();//��Ϸ��ʼ��

//key.cpp
	GLOBAL int GetHitKeyStateAll_2();//���̰�������
	GLOBAL int CheckStateKey(unsigned char Handle);//���ذ���״̬

	GLOBAL void GetHitPadStateAll();//�ֱ���������
	GLOBAL int CheckStatePad(unsigned int Handle);//�����ֱ�״̬

//laod.cpp
	GLOBAL void load();//��������
	GLOBAL void load_story();//��������Ϣ��excel��ȡ������

//shot.cpp
    GLOBAL double shotatan2(int n);//���ص�¼�˵ĵ�n������ĵ��˺��Ի���֮��ļн�
    GLOBAL int shot_search(int n);////�������ŵ��ӵ�
    GLOBAL void shot_main();//��Ļ����

//music.cpp
    GLOBAL void music_ini();//���ֳ�ʼ��
    GLOBAL void music_play();//���ֶ�ȡ����
//enemy_act_pattern.cpp
	GLOBAL double rang(double);//�����漴�Ƕ�
//cshot.cpp
	GLOBAL void cshot_main();//�Ի����
//out.cpp
	GLOBAL void out_main();//��ײ�ж�
//effect.cpp
	GLOBAL void effect_main();//����������Ч
//boss_shot.cpp
	GLOBAL void boss_shot_main();//boss��Ļ
//calc.cpp
        GLOBAL void calc_main();//��������
//fps.cpp
	GLOBAL void fps_wait();//fps����
	GLOBAL void draw_fps(int x,int y);//fps��ʾ
//dn.cpp
	GLOBAL void enter_dn(int size,int time);//��Ļ�ζ��ĵ�¼
//check_time.cpp
	GLOBAL void enter_func_tm(char st[], int flag = 0);//�������ʱ��
	GLOBAL void draw_func_tm(int x, int y);//��ʾ����ʱ��
