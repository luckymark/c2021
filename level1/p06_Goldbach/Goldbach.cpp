#include <math.h>
#include <stdio.h>

int primes[] = {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
};

bool isPrime(int num) {
	for (int i = 0; primes[i] <= 100; i++) {
		if (primes[i] == num)
			return true;
	}
	return false;
}

int main() {
	for (int i = 4; i <= 100; i += 2) {
		bool f = false;
		for (int j = 0; primes[j] <= i; j++) {
			if (f = isPrime(i - primes[j]))
				break;
		}
		if (!f) {
			printf("Holy crap! %d destroys mathematics!\n", i);
			return 1;
		}
	}
	// Odd numbers can be gotten by adding 3 to even numbers. Proven.
	puts("Success!");
	return 0;
}
