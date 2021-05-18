#include<stdio.h>

int Prime(int lastPrime)
{
	int n = lastPrime + 1, i = 3;
	bool isPrime;
	while (n <= 100)
	{
		i = 3;
		isPrime = 1;
		while (i < n / 3)
		{
			if (n % i == 0)
			{
				isPrime = 0;
				break;
			}
			i += 2;
		}
		if (isPrime && n % 2 != 0)
			return n;
		n++;
	}
}
int main()
{
	int n = 4, a, b, c;
	while (n<=100) 
	{
		a = 2, b = 2, c = 2;
		if (n % 2 == 0)
		{
			for (;b < n;b = Prime(b))
			{
				a = b;
				for (; a < n;a = Prime(a))
				{
					if (n == a + b)
						break;
				}
				if (n == a + b)
				{
					printf("%d = %d + %d\n", n, a, b);
					break;
				}
			}
		}
		else
		{
			for (;c < n;c = Prime(c))
			{
				b = c;
				for (;b < n;b = Prime(b))
				{
					a = b;
					for (; a < n;a = Prime(a))
					{
						if (n == a + b + c)
							break;
					}
					if (n == a + b + c)
						break;
				}
				if (n == a + b + c)
				{
					printf("%d = %d + %d + %d\n", n, a, b, c);
					break;
				}
			}
		}
		n++;
	}
}

