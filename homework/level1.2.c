#include <stdio.h>
int main()
{
	int n, i;
	scanf_s("%d", &n);
	for (i = 2;i < n;i++)
	{
		if (0==n%i)break;
	}
	if (i == n)
		printf(" %d 是素数 ", n);
	else
		printf(" %d 不是素数 ", n);
	return 0;
}