#include <stdio.h>

int main()
{
	int n = 0;
	scanf_s("%d", &n);
	int Isprime = 1;
	for (int j = 2; j <= n / 2; j++)
	{
		if (n % j  == 0)
		{
			Isprime = 0;
			break;
		}
	}
	if (n == 1)
	{
		printf("%d不是素数", n);
	}
	else
	{
		if (Isprime == 1)
		{
			printf("%d是素数", n);
		}
		if (Isprime == 0)
		{
			printf("%d不是素数", n);
		}
	}
}