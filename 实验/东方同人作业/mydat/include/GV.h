#include "../../../include/DxLib.h"
#include "define.h"
#include"math.h"


#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else 
#define GLOBAL extern
#endif

#include "function.h"

GLOBAL int img_ch[2][12];

GLOBAL ch_t ch;

GLOBAL int img_board[40];

GLOBAL configpad_t configpad;

void input_pad_or_key(int *p,int k);
GLOBAL int img_enemy[3][9];
GLOBAL enemy_t enemy[ENEMY_MAX];
GLOBAL enemy_order_t enemy_order[ENEMY_ORDER_MAX];
GLOBAL int img_bullet[10][10];
GLOBAL int sound_se[SE_MAX];
GLOBAL shot_t shot[SHOT_MAX];
GLOBAL cshot_t cshot[CSHOT_MAX];//�Ի�����õı���
GLOBAL int img_del_effect[5];
GLOBAL del_effect_t del_effect[DEL_EFFECT_MAX];
GLOBAL effect_t effect[EFFECT_MAX];
GLOBAL int img_back[10];
GLOBAL int func_state,stage_count,count,stage;
GLOBAL int se_flag[SE_MAX];
GLOBAL int stage_title_count[STAGE_NUM];
GLOBAL bullet_info_t bullet_info[10];
GLOBAL int img_eff_bom[5];      //Boom����Чͼ��
GLOBAL bom_t bom;               //Boom
GLOBAL bright_set_t bright_set; //���Ƶ�����
GLOBAL dn_t dn;                 //�˵�ҡ��
GLOBAL int img_dot_riria[8];
GLOBAL boss_shot_t boss_shot;// Boss�������Ϣ
GLOBAL boss_t boss;          //Boss����Ϣ
GLOBAL int img_chetc[10];       //�ͽ�ɫ��ص�����ͼ��
GLOBAL int img_etc[50];//����ͼ��
GLOBAL child_t child[CHILD_MAX];
GLOBAL lazer_t lazer[LAZER_MAX];
GLOBAL int img_lazer[10][10],img_lazer_moto[10][10];
GLOBAL stage_title_t stage_title;
GLOBAL int img_item[6][2];//���ߵ�ͼ��

GLOBAL item_t item[ITEM_MAX];//����
GLOBAL int img_num[3][12];//���ֵ�ͼ��
GLOBAL int color[20];//��ɫ
GLOBAL flash_t flash;
GLOBAL int font[20];
GLOBAL int img_cshot[3];        //�Ի������ͼ��
GLOBAL option_bb_t option_bb[2];//Option�ķ���ԴBonbon