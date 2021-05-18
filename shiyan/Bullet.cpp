#include <SFML/Graphics.hpp>
#include"Player.h"
#include"Enemy.h"

using namespace sf;

extern int WindowHeight;
extern int SpeedOfEnemy1;

int LastNumberOfBullet;
int BulletPosition[50][2] = {0};

int LastNumberOfEnemyBullet;
Vector2f EnemyBulletPosition[50];


static int SpeedOfBullet = 10;
void BulletMove() 
{
	LastNumberOfBullet = 0;
	for (int i = 0;i < 50;i++)
	{
		if (BulletPosition[i][1] > 0)
			BulletPosition[i][1] -= SpeedOfBullet;
		else LastNumberOfBullet++;
	}
}

float SpeedOfEnemyBullet = 4.0f;
void EnemyBulletMove()
{
	LastNumberOfEnemyBullet = 0;
	for (int i = 0;i < 50;i++) 
	{
		if (EnemyBulletPosition[i].y > 0 && EnemyBulletPosition[i].y < WindowHeight + 200)
			EnemyBulletPosition[i].y += SpeedOfEnemyBullet;
		else LastNumberOfEnemyBullet++;
	}
}