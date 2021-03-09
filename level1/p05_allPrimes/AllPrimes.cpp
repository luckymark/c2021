#include <math.h>
#include <stdio.h>
#include <Windows.h>
#pragma comment(lib, "winmm.lib")

// Tested on Ryzen 7 4800H with Visual Studio compiler.
// Average time: 0.029ms (debug), 0.013ms (release).
int primes[1000 / 2];

int main() {
	INT64 f, st, ed;
	timeBeginPeriod(1);
	QueryPerformanceFrequency((LARGE_INTEGER*)&f);
	QueryPerformanceCounter((LARGE_INTEGER*)&st);
	
	//Main code
	int cnt = 1;
	primes[0] = primes[1] = 2;
	for (int i = 3; i <= 1000; i += 2) {
		int lim = i >= 200 ? (int)sqrt((float)i) : (i >> 1);
		bool f = true;
		for (int j = 1; f && primes[j] <= lim; j++) {
			if (i % primes[j] == 0)
				f = false;
		}
		if (f) {
			primes[cnt] = i;
			cnt++;
		}
	}
	
	QueryPerformanceCounter((LARGE_INTEGER*)&ed);
	timeEndPeriod(1);
	
	for (int i = 0; i < cnt; i++)
		printf("%d\t", primes[i]);
	putchar('\n');
	printf("Elapsed: %.3lfms\n", (double)(ed - st) / f * 1000);
	return 0;
}
