#ifndef hero
#define hero
#include<graphics.h>
#include"easy_draw.h"
#define hero_x 102
#define hero_y 126
#define life_x 46
#define life_y 57
typedef struct Hero {
  int x;
  int y;
  int status;
  bool exist;
  int life;
  int inf_time;//ÎÞµÐÊ±¼ä
} Hero;
void draw_hero(Hero me,IMAGE PNG);
void draw_life(int x, IMAGE PNG);
#endif  // !hero