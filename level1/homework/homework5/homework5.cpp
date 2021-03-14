#include<stdio.h>
#include<math.h>
#include<time.h>

int main()
{
	clock_t start, finish;
	start = clock();
	printf("2\n");
	int n = 3,i=3;
	bool isPrime;
	while (n <= 1000)
	{
		i = 3;
		isPrime = 1;
		while (i <= sqrt(n))
		{
			if (n % i == 0)
			{
				isPrime = 0;
				break;
			}
			i += 2;
		}
		if(isPrime)
			printf("%d\n", n);
		n += 2;
	}
	finish = clock();
	printf("计算时间%f", (float)(finish - start) * 1000 / CLOCKS_PER_SEC);
}
