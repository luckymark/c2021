#ifndef bullet
#define bullet
#define bullet_x 5
#define bullet_y 11
#include<graphics.h>
#include"easy_draw.h"
typedef struct Bullet {
  int x;
  int y;
} Bullet;
void draw_bullet(Bullet cur, IMAGE PNG);
#endif  // !bullet
