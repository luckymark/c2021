#include <stdio.h>

#define cube(i) ((i) * (i) * (i))

int main() {
	for (int i = 105; i < 970; i++) {
		int a = i / 100, b = i % 100 / 10, c = i % 10;
		if (i == cube(a) + cube(b) + cube(c))
			printf("%d ", i);
	}
	return 0;
}
