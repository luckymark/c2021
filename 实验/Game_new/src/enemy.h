#ifndef enemy
#define enemy
#define enemy1_x 57
#define enemy1_y 43
#define enemy2_x 69
#define enemy2_y 99
#define enemy3_x 169
#define enemy3_y 258
#include<graphics.h>
#include"easy_draw.h"
typedef struct Enemy1 {
  int x;
  int y;
  int id;
  bool exist;
} Enemy1;
typedef struct Enemy2 {
  int x;
  int y;
  int id;
  int blood;
} Enemy2;
typedef struct Enemy3 {
  int x;
  int y;
  int id;
  int blood;
} Enemy3;
void draw_enemy1(Enemy1 cur, IMAGE PNG);
void draw_enemy2(Enemy2 cur, IMAGE PNG);
void draw_enemy3(Enemy3 cur, IMAGE PNG);
#endif  // !enemy
