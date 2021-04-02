#include <stdio.h>
#include <time.h>

int main()
{
	int i = 2;
	int IsPrime = 1;
	clock_t start, finish;
	double Total_time;
	start = clock();
	for (i = 2; i <= 1000; i++)
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
			printf("%d\n", i);
		}
	}
	finish = clock();
	Total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f seconds\n", Total_time);
}