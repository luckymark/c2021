#include <stdio.h>
#include <math.h>

int main() {
	int a, i;
	int t = 1;
	scanf_s("%d", &a);
	for (i = 2; i <= sqrt(a); i++) {
		if (a % i == 0 && a != 2) {
			t = 0;
		}
		if (t == 0) {
			printf("no");
			break;
		}
	}
	if (t == 1) {
		printf("yes");
	}
}
