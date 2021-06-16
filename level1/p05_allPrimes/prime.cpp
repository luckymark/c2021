#include<stdio.h>
#include<math.h>
int main()
{
	printf("2\t");
	for (int i = 3; i <= 1000; ++i)
	{
		int k = 0;
		for (int j = 2; j <= sqrt(i); ++j)
		{
			if (i % j == 0)
				k = 1;
			
		}
		if (k == 0)
			printf("%d\t", i);

	}
}