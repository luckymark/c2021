#include "enemy.h"
#include"enemy.h"
void draw_enemy1(Enemy1 cur, IMAGE PNG) {
  drawAlpha(&PNG, cur.x-enemy1_x/2, cur.y-enemy1_y/2);
}

void draw_enemy2(Enemy2 cur, IMAGE PNG) {
  drawAlpha(&PNG, cur.x - enemy2_x / 2, cur.y - enemy2_y / 2);
}

void draw_enemy3(Enemy3 cur, IMAGE PNG) {
  drawAlpha(&PNG, cur.x - enemy3_x / 2, cur.y - enemy3_y / 2);
}
