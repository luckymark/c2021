#include<stdio.h>

int main()
{
	int i = 2;
	int IsPrime = 1;
	int a[50] = { 0 };
	int k = 0;
	for (i = 2; i <= 100; i++)
	{
		IsPrime = 1;
		for (int j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
			{
				IsPrime = 0;
				break;
			}
		}
		if (IsPrime == 1)
		{
			a[k] = i;
			k++;
		}
	}
	int sum = 0;
	int h = 4;
	for (h = 4; h <= 100; h = h + 2)
	{
		int s = 1;
		for (int x = 0; x < k; x++)
		{
			for (int y = 0; y <= x; y++)
			{
				if (a[x] + a[y] == h)
				{
					s = 0;
					break;
				}
			}
			if (s == 0)
			{
				break;
			}
		}
		if (s == 0)
		{
			sum++;
		}
	}
	if (sum == 49)
	{
		printf("哥德巴赫猜想在100范围内是正确的");
	}
	else
	{
		printf("哥德巴赫猜想在100范围内不是正确的");
	}
}