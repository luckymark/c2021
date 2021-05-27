#include<bits/stdc++.h>
#include "game.h"
using namespace std;
game g(chess::black, chess::white);
int main(){

	/* TODO maybe can choose sente or gote */
	/* TODO maybe can PVP/CVC */

	for (chess now = chess::black;;now = opposite(now)){
		assert(now != chess::empty);
		if (now == g.player){
			/* TODO get the input of player */

		}
		else if (now == g.ai){
			/* TODO get the next step of AI */

		}
		g.show();
		/* TODO check if black or white wins */
	}

	return 0;
}

void game::show(){
	/*TODO maybe there will be a GUI */

	for (int i = 1;i <= 15;++i){
		for (int j = 1;j <= 15;++j){
			switch (now.getboard(pos(i, j))){
				case chess::empty:
					putchar(' ');
					break;
				case chess::black:
					putchar('B');
					break;
				case chess::white:
					putchar('W');
					break;
			}
		}
		putchar('\n');
	}
}