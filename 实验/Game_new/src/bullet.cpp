#include "bullet.h"

void draw_bullet(Bullet cur, IMAGE PNG) {
  drawAlpha(&PNG, cur.x - bullet_x / 2, cur.y - bullet_y / 2);
}

