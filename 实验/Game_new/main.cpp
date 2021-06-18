#include<graphics.h>
#include<Windows.h>
#include<conio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include"src\easy_draw.h"
#include"src\hero.h"
#include"src\bullet.h"
#include"src\enemy.h"
#include"src\function.h"
#pragma comment(lib, "winmm.lib")
#define High 700
#define Width 480
using namespace std;

IMAGE img_bk;//背景
IMAGE img_bullet;
IMAGE img_enemy1[6];
IMAGE img_hero[6];
IMAGE img_enemy2[6];
IMAGE img_enemy3[8];
IMAGE img_life;
IMAGE img_again;//重来
IMAGE img_inter;//封面

Hero me;
vector<Bullet> bullets;
vector<Enemy1> enemy1s;
vector<Enemy2> enemy2s;
vector<Enemy3> enemy3s;

//enemy3运动性质
int enemy3_m;
int enemy3_do_up;

//分数
int score;
TCHAR s[40];
RECT pr_score = {0,life_y+1,life_x+150,life_y+45};
RECT ed_score = {200,180,280,210};

void start_inter(void);
void start_initial(void);
void startup(void);
void show(void);
void updateWithoutInput(void);
void updateWithInput(void);
void gameover(void);
bool start_again(void);

int main() {
  startup();
  start_inter();
  start_initial();
  while (start_again()) {
    show();
    updateWithoutInput();
    updateWithInput();
  }
  gameover();
  return 0;
}

void startup() {
  srand(time(NULL));
  initgraph(Width, High);
  setbkmode(TRANSPARENT);
  settextstyle(30, 0, _T("Consolas"));

  loadimage(&img_bk, _T("images\\background.png"));

  // life
  loadimage(&img_life, _T("images\\life.png"));
  // hero
  loadimage(&img_hero[0], _T("images\\hero.png"));
  loadimage(&img_hero[1], _T("images\\me_destroy_1.png"));
  loadimage(&img_hero[2], _T("images\\me_destroy_2.png"));
  loadimage(&img_hero[3], _T("images\\me_destroy_3.png"));
  loadimage(&img_hero[4], _T("images\\me_destroy_4.png"));
  //bullet
  loadimage(&img_bullet, _T("images\\bullet1.png"));
  // enemy1-load
  loadimage(&img_enemy1[0], _T("images\\enemy1.png"));
  loadimage(&img_enemy1[1], _T("images\\enemy1_down1.png"));
  loadimage(&img_enemy1[2], _T("images\\enemy1_down2.png"));
  loadimage(&img_enemy1[3], _T("images\\enemy1_down3.png"));
  loadimage(&img_enemy1[4], _T("images\\enemy1_down4.png"));
  //enemy2-load
  loadimage(&img_enemy2[0], _T("images\\enemy2.png"));
  loadimage(&img_enemy2[1], _T("images\\enemy2_down1.png"));
  loadimage(&img_enemy2[2], _T("images\\enemy2_down2.png"));
  loadimage(&img_enemy2[3], _T("images\\enemy2_down3.png"));
  loadimage(&img_enemy2[4], _T("images\\enemy2_down4.png"));
  //enemy3-load
  loadimage(&img_enemy3[0], _T("images\\enemy3_n1.png"));
  loadimage(&img_enemy3[1], _T("images\\enemy3_down1.png"));
  loadimage(&img_enemy3[2], _T("images\\enemy3_down2.png"));
  loadimage(&img_enemy3[3], _T("images\\enemy3_down3.png"));
  loadimage(&img_enemy3[4], _T("images\\enemy3_down4.png"));
  loadimage(&img_enemy3[5], _T("images\\enemy3_down5.png"));
  loadimage(&img_enemy3[6], _T("images\\enemy3_down6.png"));
  // function again-gameover load
  loadimage(&img_again, _T("images\\play_again.png"));

  // inter
  loadimage(&img_inter, _T("images\\inter.png"));

  BeginBatchDraw();
}
void start_inter() {
  mciSendString(L"close infermusic", NULL, 0, NULL);
  mciSendString(L"open \"music\\first_1.mp3\" alias infermusic", NULL, 0, NULL);
  mciSendString(L"play infermusic", NULL, 0, NULL);
  bool flag = true;
  while (flag) {
    putimage(0, 0, &img_inter); 
    FlushBatchDraw();
    Sleep(2);
    MOUSEMSG m;
    while (MouseHit()) {
      m = GetMouseMsg();
      if (m.uMsg == WM_LBUTTONDOWN) {
        if (Width / 2 - 60 <= m.x && Width / 2 + 60 >= m.x && High/2-100 <= m.y && High/2 + 20 >= m.y ) {
          flag = false;
        }
      }
    }
  }
  
  //while(1);
}
void start_initial() {
  mciSendString(L"open \"music\\game_music.mp3\" alias bkmusic", NULL, 0, NULL);
  mciSendString(L"play bkmusic repeat", NULL, 0, NULL);
  Sleep(1000);
  me.life = 3;
  score = 10;
  me.x = int(Width * 0.5);
  me.y = int(High * 0.7);
}
void show() {
  putimage(0, 0, &img_bk);  //背景
  draw_life(me.life, img_life);

  if (me.life >= 0) {
    //英雄被击中了
    if (me.exist) {
      //描述被击中状态
      if (++me.status >= 199) {
        me.status = 0;
        me.exist = 0;
        me.inf_time = 1;
      }
      draw_hero(me, img_hero[(me.status / 40)]);
    } else {
      //无敌时间设定
      if (me.inf_time) {
        if (++me.inf_time >= 799) {
          me.inf_time = 0;
        }
        if (!((me.inf_time / 80) % 2)) {
          draw_hero(me, img_hero[0]);
        }
      } else {
        draw_hero(me, img_hero[0]);
      }
    }
    //子弹
    for (auto& i : bullets) {
      draw_bullet(i, img_bullet);
    }
    // enemy1
    for (auto& i : enemy1s) {
      draw_enemy1(i, img_enemy1[i.id / 20]);
    }
    // enemy2
    for (auto& i : enemy2s) {
      draw_enemy2(i, img_enemy2[i.id / 20]);
    }
    // enmey3
    for (auto& i : enemy3s) {
      draw_enemy3(i, img_enemy3[i.id / 20]);//id值
    }
  } 
  else {
    if (me.exist) {
      if (++me.status >= 799) {
        mciSendString(L"close gavmusic", NULL, 0, NULL);
        mciSendString(L"open \"music\\gameover.mp3\" alias gavmusic", NULL, 0,
                      NULL);
        mciSendString(L"play gavmusic", NULL, 0, NULL);
        me.status = 0;
        me.exist = 0;
      }
      draw_hero(me, img_hero[(me.status) / 160]);
    }
  }
  // score show
  wsprintf(s, _T("SCORE:%d"), score);
  drawtext(s, &pr_score, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
  FlushBatchDraw();
  Sleep(2);
}
void updateWithoutInput() {
  if (me.life >= 0) {

    //增加enemy1
    while (enemy1s.size() <= 8 && rand() % 100 < 2) {
      enemy1s.push_back({rand() % (Width - enemy1_x / 2) + enemy1_x / 2,
                         enemy1_y / 2 + 1, 0, 0});
    }

    //增加enemy2
    while (enemy2s.size()<3 && rand() % 1000 < 2) {
      enemy2s.push_back({rand() % (Width - enemy2_x / 2) + enemy2_x / 2,
                         enemy2_y / 2 + 1, 0, 2});
    }

    //增加enemy3
    while (!enemy3s.size() && rand() % 5000 < 2) {
      enemy3s.push_back({rand() % (Width - enemy3_x / 2) + enemy3_x / 2,
                         enemy3_y / 2 + 1, 0, 14});
    }

    //子弹运动
    for (int i = 0; i < bullets.size(); i++) {
      bullets[i].y -= 1;
      if (bullets[i].y - bullet_y / 2 <= 0)
        bullets.erase(bullets.begin() + i);
    }

    // enemy1运动
    for (int i = 0; i < enemy1s.size(); i++) {
      if (enemy1s[i].exist) {
        //被击中了
        if (++enemy1s[i].id > 99) {
          score += 5;
          enemy1s.erase(enemy1s.begin() + i);
          mciSendString(L"close scmusic", NULL, 0, NULL);
          mciSendString(L"open \"music\\gotEnemy.mp3\" alias scmusic", NULL, 0,
                        NULL);
          mciSendString(L"play scmusic", NULL, 0, NULL);
          continue;
        }
      } else {
        //运动函数
        enemy1s[i].y += 1;
      }
      //运动出界
      if (enemy1s[i].y - enemy1_y / 2 >= High)
        enemy1s.erase(enemy1s.begin() + i);
    }

    //enemy2运动
    for (int i = 0; i < enemy2s.size(); i++) {
      if (enemy2s[i].blood<0) {
        //被击中了
        if (++enemy2s[i].id > 99) {
          score += 30;
          enemy2s.erase(enemy2s.begin() + i);
          mciSendString(L"close scmusic", NULL, 0, NULL);
          mciSendString(L"open \"music\\gotEnemy.mp3\" alias scmusic", NULL, 0,
                        NULL);
          mciSendString(L"play scmusic", NULL, 0, NULL);
          continue;
        }
      } else {
        //运动函数
        enemy2s[i].y += rand()%2<1?1:0;
        enemy2s[i].x += enemy2s[i].x > me.x ? (rand() % 4 < 1 ? -1 : 0) : (rand()%4<1?1:0);
      }
      //运动出界
      if (enemy2s[i].y - enemy2_y / 2 >= High)
        enemy2s.erase(enemy2s.begin() + i);
    }

    // enemy3运动
    for (int i = 0; i < enemy3s.size(); i++) {
      if (enemy3s[i].blood < 0) {
        //被击中了
        if (++enemy3s[i].id > 139) {
          score += 150;
          enemy3s.erase(enemy3s.begin() + i);
          mciSendString(L"close scmusic", NULL, 0, NULL);
          mciSendString(L"open \"music\\gotEnemy.mp3\" alias scmusic", NULL, 0,
                        NULL);
          mciSendString(L"play scmusic", NULL, 0, NULL);
          continue;
        }
      } else {
        if (enemy3_do_up == 1) {
          enemy3s[i].y += 3;
          if (enemy3s[i].y + enemy3_y / 2 >= High)
            enemy3_do_up = -1;
        } 
        else if (enemy3_do_up == -1) {
          enemy3s[i].y -= 1;
          if (enemy3s[i].y - enemy3_y / 2 <= 1) {
            enemy3_do_up = 0;
            enemy3_m = 0;
          }
            
        }
        else {
           enemy3s[i].x += enemy3s[i].x > me.x ? (rand() % 4 < 1 ? -1 : 0) : (rand()%4<1?1:0);
          if (abs(enemy3s[i].x - me.x) <= 40) {
            enemy3_m++;
            if (enemy3_m>=500) {
              enemy3_do_up = 1;
            }
          }
        }
        //enemy3s[i].y += 1;
      }
      //运动出界
      if (enemy3s[i].y - enemy3_y / 2 >= High)
        enemy3s.erase(enemy3s.begin() + i);
    }

    //判断enemy1子弹的攻击
    for (int i = 0; i < enemy1s.size(); i++) {
      for (int j = 0; j < bullets.size(); j++) {
        if (abs(bullets[j].x - enemy1s[i].x) <= enemy1_x / 2 &&
            abs(bullets[j].y - enemy1s[i].y) <= enemy1_y / 2 &&
            !enemy1s[i].exist) {
          //子弹接触敌机，敌机未被接触过
          enemy1s[i].exist = 1;
          bullets.erase(bullets.begin() + j);
        }
      }
    }

    //判断enmey2子弹的攻击
    for (int i = 0; i < enemy2s.size(); i++) {
      for (int j = 0; j < bullets.size(); j++) {
        if (abs(bullets[j].x - enemy2s[i].x) <= enemy2_x / 2 &&
            abs(bullets[j].y - enemy2s[i].y) <= enemy2_y / 2 &&
            enemy2s[i].blood>=0) {
          //子弹接触enemy2,enemy2还有血
          enemy2s[i].blood--;
          bullets.erase(bullets.begin() + j);
        }
      }
    }

    //判断enmey3子弹的攻击
    for (int i = 0; i < enemy3s.size(); i++) {
      for (int j = 0; j < bullets.size(); j++) {
        if (abs(bullets[j].x - enemy3s[i].x) <= enemy3_x / 2 &&
            abs(bullets[j].y - enemy3s[i].y) <= enemy3_y / 2 &&
            enemy3s[i].blood >= 0) {
          //子弹接触enemy3,enemy3还有血
          enemy3s[i].blood--;
          bullets.erase(bullets.begin() + j);
        }
      }
    }
    //碰撞函数
    if (!me.exist) {

      //enemy1碰撞
      for (int i = 0; i < enemy1s.size(); i++) {
        if (abs(enemy1s[i].x - me.x) < enemy1_x / 2 + hero_x / 2 - 20 &&
            abs(enemy1s[i].y - me.y) < enemy1_y / 2 + hero_y / 2 - 20 &&
            !enemy1s[i].exist) {
          enemy1s[i].exist = 1;
          if (!me.inf_time) {
            //英雄没有处在无敌时间
            me.exist = 1;
            me.life--;
            mciSendString(L"close exmusic", NULL, 0, NULL);
            mciSendString(L"open \"music\\explode.mp3\" alias exmusic", NULL, 0,
                          NULL);
            mciSendString(L"play exmusic", NULL, 0, NULL);
          }
        }
      }

      //enemy2碰撞
      for (int i = 0; i < enemy2s.size(); i++) {
        if (abs(enemy2s[i].x - me.x) < enemy2_x / 2 + hero_x / 2 - 20 &&
            abs(enemy2s[i].y - me.y) < enemy2_y / 2 + hero_y / 2 - 20 &&
            enemy2s[i].blood>=0) {
          enemy2s[i].blood--;
          if (!me.inf_time) {
            //英雄没有处在无敌时间
            me.exist = 1;
            me.life--;
            mciSendString(L"close exmusic", NULL, 0, NULL);
            mciSendString(L"open \"music\\explode.mp3\" alias exmusic", NULL, 0,
                          NULL);
            mciSendString(L"play exmusic", NULL, 0, NULL);
          }
        }
      }

      // enemy3碰撞
      for (int i = 0; i < enemy3s.size(); i++) {
        if (abs(enemy3s[i].x - me.x) < enemy3_x / 2 + hero_x / 2 - 20 &&
            abs(enemy3s[i].y - me.y) < enemy3_y / 2 + hero_y / 2 - 20 &&
            enemy3s[i].blood >= 0) {
          enemy3s[i].blood--;
          if (!me.inf_time) {
            //英雄没有处在无敌时间
            me.exist = 1;
            me.life--;
            mciSendString(L"close exmusic", NULL, 0, NULL);
            mciSendString(L"open \"music\\explode.mp3\" alias exmusic", NULL, 0,
                          NULL);
            mciSendString(L"play exmusic", NULL, 0, NULL);
          }
        }
      }

    }
  }
}
void updateWithInput() {
  MOUSEMSG m;
  if (!me.exist && me.life >= 0) {
    while (MouseHit()) {
      m = GetMouseMsg();
      me.x = m.x;
      me.y = m.y > hero_y / 2 + 1 ? m.y : hero_y / 2 + 1;
      //发射子弹
      if (m.uMsg == WM_LBUTTONDOWN && score > 0) {
        score -= 1;
        bullets.push_back({me.x, me.y - hero_y / 2 + bullet_y / 2});
        mciSendString(L"close fgmusic", NULL, 0, NULL);
        mciSendString(L"open \"music\\shoot.mp3\" alias fgmusic", NULL, 0, NULL);
        mciSendString(L"play fgmusic", NULL, 0, NULL);
      }
      //鼠标右键按下暂停
      if (m.uMsg == WM_RBUTTONDOWN && score >= 50) {
        score -= 50;
        m = GetMouseMsg();
        while (m.uMsg != WM_RBUTTONDOWN) {
          m = GetMouseMsg();
        }
        //瞬移音效
        mciSendString(L"close tpmusic", NULL, 0, NULL);
        mciSendString(L"open \"music\\teleport.mp3\" alias tpmusic", NULL, 0,
                      NULL);
        mciSendString(L"play tpmusic", NULL, 0, NULL);
      }
    }
  }
}
void gameover() {
  EndBatchDraw();
  closegraph();
  exit(0);
}
bool start_again() {
  if (me.life >= 0 || me.exist) {
    return true;
  }
  else {
    while (1) {
      putimage(0, 0, &img_again);
      wsprintf(s, _T("%d"), score);
      drawtext(s, &ed_score, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
      FlushBatchDraw();
      Sleep(2);
      MOUSEMSG m;
      while (MouseHit()) {
        m = GetMouseMsg();
        if (m.uMsg == WM_LBUTTONDOWN) {
          if (Width / 2 - 60 <= m.x && Width / 2 + 60 >= m.x &&
              High / 2 - 100 <= m.y && High / 2 + 20 >= m.y) {
            start_initial();
            return true;
          }
          if (Width / 2 - 60 <= m.x && Width / 2 + 60 >= m.x &&
              High / 2 + 100 <= m.y && High / 2 + 220 >= m.y) {
            return false;
          }
        }
      }
    }
  }
}