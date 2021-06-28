#ifndef ENEMY_H
#define ENEMY_H

sf::Sprite EnemyBasic();
void EnemyAppear();
void EnemyMove();
void EnemyHurt(enum EnemyKind enemy, enum HurtWay hurtWay, enum DamageTarget target);
void Enemy1Attack();
sf::Sprite EnemyBulletBasic();
void EnemyBulletMove();
void DifficultyUp();

enum EnemyKind {
	Enemy1=0
};
enum HurtWay {
	Enemy=0,
	Bullet=1
};
enum DamageTarget {
	Player = 0,
	DefenseAera = 1
};
#endif
