#include"hero.h"
void draw_hero(Hero me,IMAGE PNG) {
  drawAlpha(&PNG, me.x-hero_x/2, me.y-hero_y/2);
}

void draw_life(int x, IMAGE PNG) {
  //����x����
  for (int i = 1; i <= x; i++) {
    drawAlpha(&PNG, (i - 1) * life_x+10 , 10);
  }
}
