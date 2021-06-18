#pragma once
#include<graphics.h>
#include<Windows.h>
typedef std::pair<int, int> pos;
namespace gui{
	void init(){
		initgraph(30 * 16, 30 * 16, EW_SHOWCONSOLE);
		setbkcolor(LIGHTGRAY);
		cleardevice();
		for(int i = 1; i <= 15; ++i){
			line(i * 30, 30, i * 30, 30 * 15);
			line(30, i * 30, 30 * 15, i * 30);
		}
	}
	char str[5];
	wchar_t wstr[5];
	wchar_t *numtostr(int x){
		sprintf(str, "%d", x);
		int need = MultiByteToWideChar(CP_UTF8, 0, str, strlen(str), NULL, 0);
		MultiByteToWideChar(CP_UTF8, 0, str, strlen(str), wstr, need);
		return wstr;
	}
	void setchess(int color, int x, int y, int cnt){
		setlinecolor(LIGHTGRAY);
		if(color)setfillcolor(WHITE);
		else setfillcolor(BLACK);
		fillcircle(x * 30, y * 30, 15);
		RECT word = {x * 30 - 10,y * 30 - 10,x * 30 + 10,y * 30 + 10};
		setbkmode(TRANSPARENT);
		settextcolor(LIGHTBLUE);
		drawtext(numtostr(cnt), &word, DT_CENTER);
	}
	MOUSEMSG m;
	pos getplayerinput(){
		while(true){
			m = GetMouseMsg();
			if(m.mkLButton)
				return {(m.x + 15) / 30,(m.y + 15) / 30};
		}
	}
	void close(){
		closegraph();
	}
}
