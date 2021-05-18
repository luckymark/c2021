#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<stdlib.h>
#include<time.h>
#include"Enemy.h"

using namespace sf;

extern int WindowWidth;
extern int WindowHeight;
extern int PlayerPositionX;
extern int PlayerPositionY;
extern int PlayerHP;
extern float PlayerSP;
extern int Score;
extern int LastNumberOfEnemyBullet;
extern float SpeedOfEnemyBullet;
extern Vector2f EnemyBulletPosition[50];

float SpeedOfEnemy1 = 1.0f;
Vector2f Enemy1Position[50];

Texture Enemy1st;
Sprite EnemyBasic()
{
	Enemy1st.loadFromFile("Texture/µÐÈË1.png");
	Sprite enemy1(Enemy1st);
	enemy1.setOrigin(29, 20);
	return enemy1;
}

Texture EnemyBullet;
SoundBuffer EnemyBulletAppear;
Sound enemyBulletAppear(EnemyBulletAppear);
Sprite EnemyBulletBasic()
{
	EnemyBullet.loadFromFile("Texture/×Óµ¯.png");
	Sprite enemyBullet(EnemyBullet);
	enemyBullet.setOrigin(7, 15);
	EnemyBulletAppear.loadFromFile("Sound/EnemyAttack.wav");
	enemyBulletAppear.setVolume(30);
	return enemyBullet;
}

int LastEnemy1AppearTime = 135;
static int lastEnemy1AppearTime = 0;
void EnemyAppear()
{
	if (lastEnemy1AppearTime == 0)
	{
		lastEnemy1AppearTime = LastEnemy1AppearTime;
		srand(rand());
		int a = rand() % 5;
		switch (a)
		{
		case 0:a = rand() % (WindowWidth / 5) + 20;break;
		case 1:a = rand() % (WindowWidth / 5) + (WindowWidth / 5 + 20);break;
		case 2:a = rand() % (WindowWidth / 5) + (WindowWidth * 2 / 5 + 20);break;
		case 3:a = rand() % (WindowWidth / 5) + (WindowWidth * 3 / 5 + 20);break;
		case 4:a = rand() % (WindowWidth / 5) + (WindowWidth * 4 / 5 - 20);break;
		}
		for (int i = 0;i < 50;i++) 
		{
			if (Enemy1Position[i].y == 0 || Enemy1Position[i].y >= WindowHeight + 200)
			{
				Enemy1Position[i].x = a;
				Enemy1Position[i].y = 1;
				break;
			}
		}
	}
	lastEnemy1AppearTime = lastEnemy1AppearTime > 0 ? --lastEnemy1AppearTime : 0;
}

void EnemyMove() 
{
	for (int i = 0;i < 50;i++) 
	{
		if (Enemy1Position[i].y > 0 && Enemy1Position[i].y < WindowHeight + 200)
			Enemy1Position[i].y += SpeedOfEnemy1;
	}
}

int LastEnemy1AttackTime = 120;
static int lastEnemy1AttackTime[50] = {0};
void Enemy1Attack() 
{
	for (int i = 0;i < 50;i++) 
	{
		lastEnemy1AttackTime[i] = lastEnemy1AttackTime[i] > 0 ? --lastEnemy1AttackTime[i] : 0;
		if (Enemy1Position[i].x < PlayerPositionX + 10 && Enemy1Position[i].x > PlayerPositionX - 10
			&& Enemy1Position[i].y > 0 && Enemy1Position[i].y + 200 < PlayerPositionY
			&& LastNumberOfEnemyBullet > 0 && lastEnemy1AttackTime[i] == 0) 
		{
			lastEnemy1AttackTime[i] = LastEnemy1AppearTime;
			for (int j = 0;j < 50;j++)
			{
				if (EnemyBulletPosition[j].y == 0 || EnemyBulletPosition[j].y > WindowHeight) 
				{
					enemyBulletAppear.play();
					EnemyBulletPosition[j].x = Enemy1Position[i].x;
					EnemyBulletPosition[j].y = Enemy1Position[i].y + 15;
					return;
				}
			}
		}
	}
}

#define Enemy1Damage 50;
#define Enemy1DefenseAeraDamage 50;
#define Enemy1BulletDefenseAeraDamage 10;
#define Enemy1BulletDamage 10;
void EnemyHurt(enum EnemyKind enemy,enum HurtWay hurtWay,enum DamageTarget target) 
{
	if (enemy == Enemy1) 
	{
		if (hurtWay == Enemy) 
		{
			if (target == Player)
			{
				PlayerHP -= Enemy1Damage;
			}
			else if (target == DefenseAera) 
			{
				PlayerSP -= Enemy1DefenseAeraDamage;
			}
		}
		else if (hurtWay == Bullet) 
		{
			if (target == Player)
			{
				PlayerHP -= Enemy1BulletDamage;
			}
			else if (target == DefenseAera)
			{
				PlayerSP -= Enemy1BulletDefenseAeraDamage;
			}
		}
	}
}

static bool haveUpped = false;
void DifficultyUp() 
{
	if (Score % 100 < 10) 
	{
		if (!haveUpped) 
		{
			SpeedOfEnemy1 += 0.5f;
			SpeedOfEnemyBullet += 0.5f;
			if (LastEnemy1AppearTime > 80)
				LastEnemy1AppearTime -= 15;
			haveUpped = true;
		}
	}
	else haveUpped = false;
}
