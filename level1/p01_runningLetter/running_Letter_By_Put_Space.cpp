#include <stdio.h>
#include <windows.h>
int main() {
	int n = 0, space_N = 10;
	int d = 0;
	do {
		if (n < space_N) {
			for (int i = 0; i < n; i++) {
				putchar(' ');
			}
			printf("A");
			n++;
			system("cls");
			if (n == space_N) {
				d = n;
			}
		} else {

			for (int i = 0; i < d; i++) {
				putchar(' ');
			}
			printf("A");
			d--;
			system("cls");
			if (d == 0) {
				n = 0;
			}
		}
	} while (1);
}
