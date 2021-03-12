#include "Common.h"

extern LEVEL *readLevel(FILE*);
extern void loadLevel(LEVEL*);
extern void draw(LEVEL*, int, int);
extern bool move(LEVEL*, char);
extern bool checkLevel(LEVEL*);

int gameLoop(LEVEL*, int);
void gameWin(int);

int main(void) {
	FILE *pf;
	int cnt, *min;
	if (fopen_s(&pf, "levels.dat", "rb"))
		return 1;
	fread(&cnt, sizeof(int), 1, pf);
	if (cnt <= 0 || cnt >= 100)
		return -1;
	LEVEL **plvls = (LEVEL**)malloc(sizeof(LEVEL*) * cnt);
	min = (int*)malloc(sizeof(int) * cnt);
	for (int i = 0; i < cnt; i++) {
		plvls[i] = readLevel(pf);
		min[i] = 2333;
	}
	fclose(pf);
	if (fopen_s(&pf, "score.dat", "rb") == 0) {
		fread(min, sizeof(int), cnt, pf);
		fclose(pf);
	}
	if (fopen_s(&pf, "score.dat", "wb"))
		return 2;
	int tot = 0;
	for (int i = 0; i < cnt; ) {
		LEVEL lvl = *plvls[i];
		int s = lvl.size.X * lvl.size.Y;
		char *map = (char*)malloc(s);
		memcpy(map, lvl.map, s);
		lvl.map = map;
		int scr = gameLoop(&lvl, min[i]);
		free(map);
		if (scr != -1) {
			int j = scr < min[i] ? scr : min[i];
			fwrite(&j, sizeof(int), 1, pf);
			fflush(pf);
			tot += scr;
			i++;
		}
	}
	fclose(pf);
	gameWin(tot);
	return 0;
}

static int gameLoop(LEVEL *plvl, int min) {
	loadLevel(plvl);
	int cnt = 0;
	while (true) {
		draw(plvl, cnt, min);
		unsigned char k = getkey();
		switch (k) {
		case 'a':
		case 'd':
		case 'w':
		case 's':
			cnt += move(plvl, k);
			break;
		case 0x00:
		case 0xE0:
			k = getkey();
			switch (k) {
			case 0x48:
				cnt += move(plvl, 'w');
				break;
			case 0x4B:
				cnt += move(plvl, 'a');
				break;
			case 0x4D:
				cnt += move(plvl, 'd');
				break;
			case 0x50:
				cnt += move(plvl, 's');
				break;
			}
			break;
		case 'r':
			return -1;
		case '~':
			return 2333;
		case '?':
			char *txt = " AA - Player\n >< - Target\n == - Bump\nUse [W][A][S][D] or arrow keys to move.\nUse [R] to reset.";
			MessageBox(NULL, txt, "Help", MB_OK);
			break;
		}
		if (checkLevel(plvl)) {
			draw(plvl, cnt, min(cnt, min));
			Sleep(300);
			Beep(262, 80);
			Beep(330, 60);
			Beep(392, 120);
			Sleep(300);
			return cnt;
		}
	}
}

static void gameWin(int tot) {
	LEVEL lvl = {0, 6, 5, NULL};
	loadLevel(&lvl);
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hndl, COLOR_BUMP);
	WriteConsole(hndl, "  !! YOU WIN !!\nCongratulations!\n", 33, NULL, NULL);
	printf("Tot. steps: %05d", tot);
	Sleep(300);
	Beep(440, 120);
	Sleep(60);
	Beep(440, 120);
	Sleep(60);
	Beep(440, 80);
	Beep(392, 80);
	Beep(440, 80);
	Sleep(60);
	Beep(349, 180);
	Sleep(1500);
}
