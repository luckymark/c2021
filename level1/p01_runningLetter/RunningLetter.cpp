#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

const int WIDTH = 80;

int main(int argc, char* argv[]) {
	int pos = 0;
	char d = +1;
	system("mode con lines=2 cols=80");
	system("color 1a");
	while (1) {
		putchar('\r');
		for (int x = 0; x < WIDTH; x++)
			putchar(x == pos ? '#' : ' ');
		Sleep(20);
		pos += d;
		if (pos == WIDTH - 1 || pos == 0)
			d = -d;
	}
	return 0;
}
