#include <stdio.h>
#include <windows.h>
int main() {
	char a[1000];
	int i, n = 0,d=1;
	int N = 10;
	while (1) {
			for (i = 0; i < n; i++) {
				*(a + i) = ' ';
			}
			*(a + i) = 'A';
			*(a + i + 1) = '\0';
			printf("%s", a);
			system("cls");
			n += d;
			if (n == N||n==0) {
				d = -d;
			}
	}
}
