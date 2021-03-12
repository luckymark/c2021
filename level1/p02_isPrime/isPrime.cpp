#include<stdio.h>
#include<math.h>

typedef long long int ultra;

char isPrime(ultra num) {
	if (num < 2 || num % 2 == 0)
		return 0;
	ultra i = (ultra)sqrt((double)num);
	for (ultra j = 3; j <= i; j += 2) {
		if (num % j == 0)
			return 0;
	}
	return 1;
}

int main(int argc, char* argv[]) {
	ultra num;
	scanf("%lld", &num);
	puts(isPrime(num) ? "yes" : "no");
	return 0;
}
