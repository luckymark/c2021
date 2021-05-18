#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"

using namespace sf;

extern int WindowWidth;
extern int WindowHeight;
extern int LastNumberOfBullet;
extern int BulletPosition[50][2];

int PlayerPositionX= WindowWidth /2;
int PlayerPositionY= WindowHeight * 4 / 5;
int PlayerSpeed = 4;
int PlayerHP = 100;
float PlayerSP = 100;
int Score = 0;

Texture Player;
Sprite PlayerBasic()
{
	Player.loadFromFile("Texture/·É»ú.png");
	Sprite player(Player);
	player.setOrigin(53, 65);
	return player;
}

Texture PlayerBullet;
Sprite PlayerBulletBasic()
{
	PlayerBullet.loadFromFile("Texture/×Óµ¯.png");
	Sprite playerBullet(PlayerBullet);
	playerBullet.setOrigin(7, 15);
	playerBullet.setColor(Color(102, 204, 255,120));
	return playerBullet;
}

SoundBuffer PlayerBulletAppear,DefenseAreaDie;
Sound playerBulletAppear(PlayerBulletAppear),defenseAreaDie(DefenseAreaDie);
void PlayerSound()
{
	DefenseAreaDie.loadFromFile("Sound/DefenseAreaDie.wav");
	PlayerBulletAppear.loadFromFile("Sound/PlayerAttack.wav");
	playerBulletAppear.setVolume(28);
	defenseAreaDie.setVolume(30);
}

Keyboard _keyboard;

static int moveKeyTime = 0;
static bool LastKeyIsA;
void PlayerMove() 
{
	if (_keyboard.isKeyPressed(Keyboard::Key::A) || (LastKeyIsA && moveKeyTime != 0)) 
	{
		moveKeyTime = moveKeyTime == 0 ? 6 : moveKeyTime;
		LastKeyIsA = true;
		if (PlayerPositionX >= 20)
			PlayerPositionX -= PlayerSpeed;
	}
	if (_keyboard.isKeyPressed(Keyboard::Key::D) || (!LastKeyIsA && moveKeyTime != 0)) 
	{
		moveKeyTime = moveKeyTime == 0 ? 6 : moveKeyTime;
		LastKeyIsA = false;
		if (PlayerPositionX <= WindowWidth - 20)
			PlayerPositionX += PlayerSpeed;
	}

	moveKeyTime = moveKeyTime > 0 ? --moveKeyTime : 0;
	
	if (_keyboard.isKeyPressed(Keyboard::Key::W)) 
	{
		if (PlayerPositionY >= 78)
			PlayerPositionY -= PlayerSpeed;
	}
	if (_keyboard.isKeyPressed(Keyboard::Key::S)) 
	{
		if (PlayerPositionY <= WindowHeight - 40)
			PlayerPositionY += PlayerSpeed;
	}
}

static int lastAttackTime;
void PlayerAttack()
{
	if (_keyboard.isKeyPressed(Keyboard::Key::F)
		|| _keyboard.isKeyPressed(Keyboard::Key::J)
		|| _keyboard.isKeyPressed(Keyboard::Key::Space))
		if (LastNumberOfBullet > 0&&lastAttackTime==0) 
		{
			lastAttackTime = 20;
			for (int i = 0;i < 50;i++)
			{
				if (BulletPosition[i][1] <= 0)
				{
					playerBulletAppear.play();
					BulletPosition[i][0] = PlayerPositionX;
					BulletPosition[i][1] = PlayerPositionY-45;
					break;
				}
			}
		}
	lastAttackTime = lastAttackTime > 0 ? --lastAttackTime : 0;
}

static int defenseKeyTime = 0;
bool PlayerDefense() 
{
	defenseKeyTime = defenseKeyTime > 0 ? --defenseKeyTime : 0;
	if (_keyboard.isKeyPressed(Keyboard::Key::K) && PlayerSP > 0||defenseKeyTime!=0) 
	{
		defenseKeyTime = defenseKeyTime == 0 ? 10 : defenseKeyTime;
		PlayerSP -= 0.5f;
		return true;
	}
	else
		return false;
}

static int SPUpFrameReport = 1;
static bool DefenseAreaDieSoundHavePlayed = false;
void SPUpWithTime() 
{
	if (PlayerSP <= 99.5f) 
	{
		if (PlayerSP <= 0 && SPUpFrameReport < 120) 
		{
			if (!DefenseAreaDieSoundHavePlayed)
			{
				defenseAreaDie.play();
				DefenseAreaDieSoundHavePlayed = true;
			}
			PlayerSP = 0;
			SPUpFrameReport++;
		}
		else
		{
			DefenseAreaDieSoundHavePlayed = false;
			PlayerSP += 0.5f;
			SPUpFrameReport = 1;
		}
	}
}

static int scoreUpFrameReport = 1;
void ScoreUpWithTime()
{
	if (scoreUpFrameReport == 60) 
	{
		scoreUpFrameReport = 1;
		Score++;
	}
	else scoreUpFrameReport++;
}
