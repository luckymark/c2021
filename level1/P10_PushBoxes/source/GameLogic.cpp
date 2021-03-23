#include "Common.h"

static const COORD COORD_ORIGIN = {0, 0};

static COORD getCoord(short x, short y) {
	COORD crd = {x, y};
	return crd;
}

LEVEL *readLevel(FILE *pf) {
	LEVEL *plvl = (LEVEL*)malloc(sizeof(LEVEL));
	fread(&plvl->id, 4, 1, pf);
	fread(&plvl->size, 2, 2, pf);
	int s = plvl->size.X * plvl->size.Y;
	char *map = (char*)malloc(s + 1);
	plvl->map = map;
	fread(map, 1, s, pf);
	map[s] = '\0';
	int pos = strchr(map, '@') - map;
	map[pos] = ' ';
	plvl->pos.X = pos % plvl->size.X;
	plvl->pos.Y = pos / plvl->size.X;
	return plvl;
}

void loadLevel(LEVEL *plvl) {
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD s = plvl->size;
	s.X = max(s.X * 2 + 5, 16);
	s.Y = max(s.Y, 6);
	CONSOLE_SCREEN_BUFFER_INFOEX inf = {96};
	GetConsoleScreenBufferInfoEx(hndl, &inf);
	inf.dwSize = s;
	inf.dwCursorPosition = COORD_ORIGIN;
	inf.srWindow.Left = 0;
	inf.srWindow.Top = 0;
	inf.srWindow.Right = s.X - 1;
	inf.srWindow.Bottom = s.Y;
	inf.dwMaximumWindowSize = s;
	inf.bFullscreenSupported = FALSE;
	SetConsoleScreenBufferInfoEx(hndl, &inf);
	CONSOLE_CURSOR_INFO cur = {1, FALSE};
	SetConsoleCursorInfo(hndl, &cur);
	SetConsoleTextAttribute(hndl, COLOR_TEXT);
	char *buf = (char*)malloc(s.X * s.Y);
	memset(buf, ' ', s.X * s.Y);
	WriteConsole(hndl, buf, s.X * s.Y, NULL, NULL);
	free(buf);
	SetConsoleCursorPosition(hndl, COORD_ORIGIN);
	FlushConsoleInputBuffer(hndl);
}

void draw(LEVEL *plvl, int cnt, int min) {
	COORD s = plvl->size, pos = plvl->pos;
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	for (short y = 0; y < s.Y; y++) {
		SetConsoleCursorPosition(hndl, getCoord(0, y));
		for (short x = 0; x < s.X; x++) {
			char ch = plvl->map[s.X * y + x];
			switch (ch) {
			case ' ':
			case '#':
				SetConsoleTextAttribute(hndl, ch == ' ' ? COLOR_VOID : COLOR_WALL);
				WriteConsole(hndl, "  ", 2, NULL, NULL);
				break;
			case 'O':
			case 'Q':
				SetConsoleTextAttribute(hndl, COLOR_BLOCK);
				WriteConsole(hndl, ch == 'O' ? "  " : "[]", 2, NULL, NULL);
				break;
			case '.':
				SetConsoleTextAttribute(hndl, COLOR_TARGET);
				WriteConsole(hndl, "><", 2, NULL, NULL);
				break;
			case '=':
				SetConsoleTextAttribute(hndl, COLOR_BUMP);
				WriteConsole(hndl, "==", 2, NULL, NULL);
				break;
			default:
				SetConsoleTextAttribute(hndl, COLOR_TEXT);
				putchar(ch);
				putchar(ch);
				break;
			}
		}
	}
	SetConsoleCursorPosition(hndl, getCoord(pos.X * 2, pos.Y));
	SetConsoleTextAttribute(hndl, COLOR_DANGER);
	WriteConsole(hndl, "AA", 2, NULL, NULL);
	SetConsoleTextAttribute(hndl, COLOR_TEXT);
	SetConsoleCursorPosition(hndl, getCoord(s.X * 2 + 1, 0));
	WriteConsole(hndl, "LV", 2, NULL, NULL);
	printf("%02d", plvl->id);
	SetConsoleCursorPosition(hndl, getCoord(s.X * 2 + 1, 1));
	WriteConsole(hndl, "STEP", 4, NULL, NULL);
	SetConsoleCursorPosition(hndl, getCoord(s.X * 2 + 1, 2));
	printf("%04d", cnt);
	SetConsoleCursorPosition(hndl, getCoord(s.X * 2 + 1, 3));
	WriteConsole(hndl, "HIGH", 4, NULL, NULL);
	SetConsoleCursorPosition(hndl, getCoord(s.X * 2 + 1, 4));
	printf("%04d", min);
	SetConsoleCursorPosition(hndl, getCoord(s.X * 2 + 1, 5));
	SetConsoleTextAttribute(hndl, COLOR_WALL);
	WriteConsole(hndl, "[?]", 3, NULL, NULL);
}

bool move(LEVEL *plvl, char k) {
	COORD s = plvl->size;
	char *map = plvl->map;
	short d;
	switch (k) {
	case 'a':
		d = -1;
		break;
	case 'd':
		d = +1;
		break;
	case 'w':
		d = -s.X;
		break;
	case 's':
		d = +s.X;
		break;
	default:
		return false;
	}
	int pos = s.X * plvl->pos.Y + plvl->pos.X, dest = pos + d;
	switch (map[dest]) {
	case ' ':
	case '.':
	case '=':
		plvl->pos.X = dest % s.X;
		plvl->pos.Y = dest / s.X;
		Beep(220, 40);
		return true;
	case 'O':
	case 'Q':
		switch (map[dest + d]) {
		case ' ':
		case '.':
			map[dest] = map[dest] == 'O' ? ' ' : '.';
			if (map[dest + d] == ' ') {
				map[dest + d] =  'O';
				Beep(220, 40);
			} else {
				map[dest + d] =  'Q';
				Beep(247, 60);
			}
			plvl->pos.X = dest % s.X;
			plvl->pos.Y = dest / s.X;
			return true;
		default:
			Beep(175, 40);
			return false;
		}
	default:
		Beep(175, 40);
		return false;
	}
}

bool checkLevel(LEVEL *plvl) {
	return strchr(plvl->map, '.') == NULL;
}
