#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Player.h"
#include"Enemy.h"

//WASD移动，J或者空格攻击，K防御

using namespace sf;

extern int PlayerPositionX;
extern int PlayerPositionY;
extern int BulletPosition[50][2];
extern Vector2f Enemy1Position[50];
extern Vector2f EnemyBulletPosition[50];
extern int PlayerHP;
extern float PlayerSP;
extern int Score;
//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN//test
//#include"doctest.h"

//TEST_CASE("test test") {
//	CHECK(WindowHeight == 900);
//};
int WindowWidth = 500;
int WindowHeight = 900;

bool CheckCollision(Sprite a, Sprite b, int left, int right, int up, int down);
bool CheckCollision(int positionX, int positionY, Sprite b, int left, int right, int up, int down);
bool CheckCollision(CircleShape a, Sprite b, float radius);

int main(int argc, char const* argv[])
{

	RenderWindow window(VideoMode(WindowWidth, WindowHeight), "airplane");
	window.setFramerateLimit(60);

	Music BGM;
	BGM.openFromFile("Sound/BGM.wav");
	BGM.setLoop(true);
	BGM.play();
	
	//背景图形生成
	Texture Background;
	Background.loadFromFile("Texture/背景.jpg");
	Sprite background(Background);

	//UI图形、文字生成
	CircleShape DefenseAera(70);
	DefenseAera.setOrigin(70,70);
	DefenseAera.setFillColor(Color(50,255,175,120));
	RectangleShape HPUIPic,SPUIPic;
	HPUIPic.setFillColor(Color::Red);
	HPUIPic.setPosition(100, 846);
	SPUIPic.setFillColor(Color::Green);
	SPUIPic.setPosition(100,806);
	Font Font;
	Font.loadFromFile("Font/consola.ttf");
	Text HPUIText("HP",Font,50),SPUIText("SP",Font,50), ScoreUI("",Font,50), GameOverText("Gameover",Font,50);
	HPUIText.setPosition(30, 820);
	HPUIText.setFillColor(Color::Red);
	SPUIText.setPosition(30, 780);
	SPUIText.setFillColor(Color::Green);
	GameOverText.setStyle(Text::Bold);
	GameOverText.setPosition(150, 420);
	GameOverText.setFillColor(Color::Black);
	ScoreUI.setPosition(30, 30);
	ScoreUI.setFillColor(Color::Yellow);

	//玩家、敌人图形生成
	Sprite player,playerBullet,enemy1,enemyBullet;
	player = PlayerBasic();
	playerBullet = PlayerBulletBasic();
	enemy1 = EnemyBasic();
	enemyBullet = EnemyBulletBasic();

	PlayerSound();
	SoundBuffer CollisionBullet,CollisionEnemyDie;
	CollisionBullet.loadFromFile("Sound/BulletCollision.wav");
	CollisionEnemyDie.loadFromFile("Sound/EnemyDie.wav");
	Sound collisionBullet(CollisionBullet),collisionEnemyDie(CollisionEnemyDie);
	collisionBullet.setVolume(25);
	collisionEnemyDie.setVolume(50);
	

	//游戏逻辑处理

	Event event;
	static bool isDefense = false;
	static int hurtFrameReport = 0;
	static bool collisionEnemyDieSoundHavePlayed = false;
	while (window.isOpen()) 
	{
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed
				or (event.type == Event::KeyPressed
					and event.key.code == Keyboard::Escape)) 
			{

				window.close();
				window.display();
				return 0;
			}
		}

		if (PlayerHP > 0)
		{
			PlayerMove();
			player.setPosition(PlayerPositionX, PlayerPositionY);
			PlayerAttack();
			isDefense = PlayerDefense();
			if (isDefense)
				DefenseAera.setPosition(PlayerPositionX, PlayerPositionY);
			else
				SPUpWithTime();
			BulletMove();
			EnemyAppear();
			Enemy1Attack();
			EnemyMove();
			EnemyBulletMove();
			ScoreUpWithTime();
			DifficultyUp();

			if (hurtFrameReport == 30)
				player.setColor(Color(255, 120, 120));
			else if (hurtFrameReport == 1)
				player.setColor(Color(255, 255, 255));
			hurtFrameReport = hurtFrameReport > 0 ? --hurtFrameReport : 0;

			char score[10] = { 0 };
			_itoa_s(Score, score, 10);
			char scoreText[20] = "Score: ";
			strcat_s(scoreText, score);
			ScoreUI.setString(scoreText);
		}
		else
		{
			BGM.stop();
		}


		window.clear();
		window.draw(background);

		//bullet
		for (int i = 0;i < 50;i++) 
		{
			if (BulletPosition[i][1] > 0) 
			{
				playerBullet.setPosition(BulletPosition[i][0], BulletPosition[i][1]);
				window.draw(playerBullet);
			}
		}
		for (int i = 0;i < 50;i++) 
		{
			if (EnemyBulletPosition[i].y > 0) 
			{
				enemyBullet.setPosition(EnemyBulletPosition[i].x, EnemyBulletPosition[i].y);
				window.draw(enemyBullet);
				for (int j = 0;j < 50;j++)
				{
					if (BulletPosition[j][1] > 0) 
					{
						if (CheckCollision(BulletPosition[j][0], BulletPosition[j][1], enemyBullet, 8 ,8, 10, 10))
						{
							collisionBullet.play();
							EnemyBulletPosition[i].x = 0;
							EnemyBulletPosition[i].y = 0;
							BulletPosition[j][0] = 0;
							BulletPosition[j][1] = 0;
						}
					}
				}
				if (isDefense && CheckCollision(DefenseAera, enemyBullet, 74))
				{
					EnemyBulletPosition[i].x = 0;
					EnemyBulletPosition[i].y = 0;
					EnemyHurt(EnemyKind::Enemy1,HurtWay::Bullet,DamageTarget::DefenseAera);
				}
				else if (CheckCollision(player, enemyBullet, 42, 42, 60, 60)) 
				{
					EnemyBulletPosition[i].x = 0;
					EnemyBulletPosition[i].y = 0;
					EnemyHurt(EnemyKind::Enemy1, HurtWay::Bullet, DamageTarget::Player);
					hurtFrameReport = 30;
				}
			}
		}

		//enemy1
		for (int i = 0;i < 50;i++)
		{
			if (Enemy1Position[i].y > 0)
			{
				enemy1.setPosition(Enemy1Position[i].x, Enemy1Position[i].y);
				window.draw(enemy1);
				for (int j = 0;j < 50;j++)
				{
					if (BulletPosition[j][1] > 0)
					{
						if (CheckCollision(BulletPosition[j][0], BulletPosition[j][1], enemy1, 24, 24, 18, 18))
						{
							collisionEnemyDie.play();
							BulletPosition[j][0] = 0;
							BulletPosition[j][1] = 0;
							Enemy1Position[i].x = 0;
							Enemy1Position[i].y = 0;
							Score += 10;
						}
					}
				}
				if (isDefense && CheckCollision(DefenseAera, enemy1, 87))
				{
					collisionEnemyDie.play();
					Enemy1Position[i].x = 0;
					Enemy1Position[i].y = 0;
					EnemyHurt(EnemyKind::Enemy1, HurtWay::Enemy, DamageTarget::DefenseAera);
				}
				else if (CheckCollision(player, enemy1, 42, 42, 76, 60))
				{
					collisionEnemyDie.play();
					Enemy1Position[i].x = 0;
					Enemy1Position[i].y = 0;
					EnemyHurt(EnemyKind::Enemy1, HurtWay::Enemy, DamageTarget::Player);
					hurtFrameReport = 30;
				}
			}
		}

		//Player
		if (PlayerHP > 0)
		{
			window.draw(player);
			if (isDefense) 
				window.draw(DefenseAera);
		}
		else
		{
			if (!collisionEnemyDieSoundHavePlayed)
			{
				collisionEnemyDie.play();
				collisionEnemyDieSoundHavePlayed = true;
			}
			window.draw(GameOverText);
		}

		//UI
		window.draw(HPUIText);
		HPUIPic.setSize(Vector2f((PlayerHP > 0 ? PlayerHP * 3 : 0), 16));
		window.draw(HPUIPic);
		window.draw(SPUIText);
		SPUIPic.setSize(Vector2f((PlayerSP > 0 ? PlayerSP * 3 : 0), 16));
		window.draw(SPUIPic);
		window.draw(ScoreUI);


		window.display();
	}
	return 0;
}


bool CheckCollision(Sprite a, Sprite b, int left, int right, int up, int down)
{
	sf::Vector2f player = a.getPosition();
	sf::Vector2f enemy = b.getPosition();
	if (enemy.y<player.y - up || enemy.x>player.x + right || enemy.x<player.x - left || enemy.y>player.y + down)
		return false;
	else return true;
}
bool CheckCollision(int positionX, int positionY, Sprite b, int left, int right, int up, int down) 
{
	sf::Vector2f enemy = b.getPosition();
	if (enemy.y<positionY - up || enemy.x>positionX + right || enemy.x<positionX - left || enemy.y>positionY + down)
		return false;
	else return true;
}
bool CheckCollision(CircleShape a, Sprite b, float radius)
{
	sf::Vector2f DefenseAera = a.getPosition();
	sf::Vector2f enemy = b.getPosition();
	float x = DefenseAera.x - enemy.x;
	float y = DefenseAera.y - enemy.y;
	if (x * x + y * y > radius * radius) 
		return false;
	else return true;
}