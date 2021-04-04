#include<stdio.h>
#include<time.h>
#include<math.h>
int main() {
	int a, i;
	clock_t start, finish;
	double duration;
	start = clock();
	printf("2	");

	for (a = 3; a <= 1000; a++)
	{
		if (a % 2 == 0) 
		{
			continue;
		}
		int t = 1;
		for (i = 2; i <= sqrt(a); i++)
		{
			if (a % i == 0)
			{
				t = 0;
			}
			if (t == 0)
			{
				break;
			}
		}
		if (t == 1)
		{
			printf("%d	", a);
		}
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\n%lf secconds", duration);

}
	
