#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

const char W = 10, H = 8;
const unsigned char maze[H][W] = {
	{'#', '#', '#', '#', '#', '#', '#', '#', '!', '#'},
	{'#', '@', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
	{'#', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', '#'},
	{'#', ' ', ' ', '#', ' ', ' ', '#', '#', '#', '#'},
	{'#', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
	{'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
	{'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

COORD getCoord(SHORT x, SHORT y) {
	COORD crd = {x, y};
	return crd;
}

COORD getPos(unsigned char dat[][W]) {
	for (char y = 0; y < H; y++) {
		for (char x = 0; x < W; x++) {
			if (dat[y][x] == '@') {
				COORD pos = {x, y};
				return pos;
			}
		}
	}
	COORD err = {1, 1};
	return err;
}

bool move(unsigned char dat[][W], unsigned char ch) {
	COORD pos = getPos(dat), dest = pos;
	switch (ch) {
	case 'a':
		dest.X--;
		break;
	case 'd':
		dest.X++;
		break;
	case 'w':
		dest.Y--;
		break;
	case 's':
		dest.Y++;
		break;
	}
	switch (dat[dest.Y][dest.X]) {
	case ' ':
		dat[pos.Y][pos.X] = ' ';
		dat[dest.Y][dest.X] = '@';
		return false;
	case '!':
		dat[pos.Y][pos.X] = ' ';
		return true;
	default:
		return false;
	}
}

void draw(unsigned char dat[][W], short cnt) {
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hndl, getCoord(0, 0));
	for (char y = 0; y < H; y++) {
		for (char x = 0; x < W; x++) {
			unsigned char ch = dat[y][x];
			switch (ch) {
			case '@':
				SetConsoleTextAttribute(hndl, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				break;
			case '!':
				SetConsoleTextAttribute(hndl, FOREGROUND_RED | FOREGROUND_INTENSITY);
				break;
			default:
				SetConsoleTextAttribute(hndl, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				break;
			}
			putchar(ch);
			putchar(ch);
		}
		putchar('\n');
	}
	SetConsoleTextAttribute(hndl, FOREGROUND_RED | FOREGROUND_GREEN);
	SetConsoleCursorPosition(hndl, getCoord(W * 2 + 1, 0));
	puts("Steps");
	SetConsoleCursorPosition(hndl, getCoord(W * 2 + 2, 1));
	printf("%04d", cnt);
}

int main() {
	unsigned char (*dat)[W] = (unsigned char(*)[W])malloc(W * H);
	memcpy(dat, maze, W * H);
	short cnt = 0;
	bool f = false;
	while (true) {
		draw(dat, cnt);
		unsigned char ch = _getch();
		switch (ch) {
		case 'w':
		case 'a':
		case 's':
		case 'd':
			f = move(dat, ch);
			break;
		case 0x00:
		case 0xE0:
			ch = _getch();
			switch (ch) {
			case 0x48:
				f = move(dat, 'w');
				break;
			case 0x4B:
				f = move(dat, 'a');
				break;
			case 0x4D:
				f = move(dat, 'd');
				break;
			case 0x50:
				f = move(dat, 's');
				break;
			}
			break;
		}
		cnt++;
		if (f) {
			char txt[W * 2 + 7];
			memset(txt, '!', W * 2 + 6);
			memcpy(txt, " YOU WIN ", 9);
			txt[W * 2 + 6] = '\0';
			draw(dat, cnt);
			HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hndl, BACKGROUND_RED |FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			while (true) {
				SetConsoleCursorPosition(hndl, getCoord(0, 2));
				for (int y = 0; y < H - 4; y++) {
					puts(txt);
				}
				Sleep(250);
				char ch = txt[W * 2 + 5];
				memmove(txt + 1, txt, W * 2 + 5);
				txt[0] = ch;
			}
		}
	}
	return 0;
}
