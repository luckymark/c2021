extern void boss_shot_bulletH000();
extern void boss_shot_bulletH001();
extern void boss_shot_bulletH002();
extern void boss_shot_bulletH003();
extern void boss_shot_bulletH004();
extern void boss_shot_bulletH005();
extern void boss_shot_bulletH006();
extern void boss_shot_bulletH007();
extern void boss_shot_bulletH008();
extern void boss_shot_bulletH009();
extern void boss_shot_bulletH011();

void (*boss_shot_bullet[DANMAKU_MAX])() =
{
//��·Boss
	boss_shot_bulletH003,
	boss_shot_bulletH002,
	
//��·Boss
	boss_shot_bulletH001,
	boss_shot_bulletH004,
	boss_shot_bulletH009,
	
//��ֹ

	boss_shot_bulletH000,//��ֹ����NullPointrException
};