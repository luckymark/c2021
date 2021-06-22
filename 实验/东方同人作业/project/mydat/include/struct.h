typedef struct{
	int flag;               //flag
	int cnt;                //计数器
	int power;              //power
	int point;              //point
	int score;              //score
	int num;                //残机数
	int mutekicnt;          //无敌状态与计数器
	int shot_mode;          //射击模式
	int money;              //钱
	int img;
	int slow;               //是否缓慢移动
	double x,y;             //坐标
	int shot_cnt;           //射击计数
	int graze;              //擦弹 (41)
}ch_t;

typedef struct{
	double x,y;
}pt_t;

typedef struct{
	//flag、计数器、移动模式、方向、敌人的种类、HP最大值、掉落道具、图像、背景
	int flag,cnt,pattern,muki,knd,hp,hp_max,item_n[6],img,back_col;
	//坐标、速度x分量、速度y分量、速度、角度
	double x,y,vx,vy,sp,ang;
	//弹幕开始时间、弹幕的种类、子弹的种类、颜色、状态、待机时间、停止时间
	int bltime,blknd,blknd2,col,state,wtime,wait;
}enemy_t;

typedef struct{
	int cnt,pattern,knd;
	double x,y,sp;
	int bltime,blknd,col,hp,blknd2,wait,item_n[6];
}enemy_order_t;

typedef struct{
	int key[PAD_MAX];
}pad_t;

typedef struct{
	int left,up,right,down,shot,bom,slow,start,change;
}configpad_t;

typedef struct{
	int flag,knd,cnt,col,state,till,eff,kaiten,eff_detail;
	double x,y,vx,vy,angle,spd,base_angle[1],rem_spd[1];
}bullet_t;

typedef struct{
	int flag,knd,cnt,num;
	double base_angle[1],base_spd[1];
	bullet_t bullet[SHOT_BULLET_MAX];
}shot_t;


typedef struct{
	int flag,knd,cnt,num;
	double base_angle[10],base_spd[1];
	bullet_t bullet[BOSS_BULLET_MAX];
}boss_shot_t;


typedef struct{
        int flag;               //flag
        int power;              //power
        int cnt;                //计数器
        int knd;                //种类
        int img;                //图像
        double x,y;             //坐标
        double angle;           //角度
        double spd;             //速度
}cshot_t;

typedef struct{
	int flag,cnt,col,knd,img,eff;
	double x,y,r,ang,spd,mvang,brt;
}effect_t;

typedef struct{
	int flag,cnt,col;
	double x,y;
}del_effect_t;

typedef struct{
	int size_x,size_y,col_num,kaiten;
	double range;
}bullet_info_t;

typedef struct{
	int flag,cnt,knd;
	double x,y;
}bom_t;

typedef struct{
	unsigned char brt;
}bright_set_t;

typedef struct{
	int flag,cnt,time,size;
	int x,y;
}dn_t;

typedef struct{
	int flag,cnt,set_t;
	double ax,v0x,ay,v0y,vx,vy,prex,prey;
}phy_t;

typedef struct{
	int conv_flag;
	double time,base_ang,angle;
	double conv_x,conv_y,conv_base_x,conv_base_y;
}lphy_t;

typedef struct{
        int flag,cnt,knd,wtime,state,endtime,hagoromo,graph_flag;
        int hp,hp_max;
        int 
appear_count[2],set_hp[DANMAKU_MAX],back_knd[DANMAKU_MAX],danmaku_num[2];
        double x,y,dx,dy,ang,spd;
        phy_t phy;
}boss_t;

typedef struct{
	int flag,cnt,knd,col,state;
	double haba,angle,length,hantei;
	pt_t startpt,disppt[4],outpt[4];
	lphy_t lphy;
}lazer_t;

typedef struct{
	int flag,cnt,knd,col,state;
	double x,y,angle,spd,range;
}child_t;

typedef struct{
        int flag,img,cnt,brt,appear_cnt;
}stage_title_t;

typedef struct{
        int flag,cnt,knd,state;
        double v,x,y,r;
}item_t;

typedef struct{
        int flag,cnt,knd,to_cnt;
        double brt;
}flash_t;
typedef struct{
        int flag;       //flag
        int img;        //图像
        int cnt;        //计数器
        double x,y;     //坐标
}option_bb_t;