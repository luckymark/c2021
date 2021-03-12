#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[]) {
	for (int age = 0; ; age++) {
		float i = age;
		if (fabs((i / 6 + i / 12 + i / 7 + 5 + i / 2 + 4) - i) <= 0.00001) {
			printf("%d", age - 4);
			break;
		}
	}
	return 0;
}
