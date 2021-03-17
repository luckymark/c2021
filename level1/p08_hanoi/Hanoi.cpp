#include <stdio.h>

void solve(int, int, int);

int main(void) {
	int n;
	scanf("%d", &n);
	if (n < 1)
		return 1;
	solve(n, 1, 3);
	return 0;
}

void solve(int n, int src, int dest) {
	int tmp = 6 - src - dest;
	if (n > 1)
		solve(n - 1, src, tmp);
	printf("%d(%d) -> %d\n", src, n, dest);
	if (n > 1)
		solve(n - 1, tmp, dest);
}
