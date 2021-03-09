#include<stdio.h>
#include<math.h>
void AllPrimeIn100(int *Prime);
int main() {
	int a,n,i,j;
	int t = 1;
	int AllPrime[25];
	AllPrimeIn100(AllPrime);
	for (n = 4; n <= 100; n += 2) 
	{
		for (i = 0; i < 25; i++)
		{
			for (j = i ; j < 25; j++)
			{
				if (n == AllPrime[i] + AllPrime[j])
				{
					printf("%d = %d + %d\n", n, AllPrime[i] , AllPrime[j]);
				}
			}
		}
	}
}
void AllPrimeIn100(int *Prime) {
	int a,i;
	*Prime = 2;
	Prime++;
	for (a = 2; a <= 100; a++)
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
			*Prime = a;
			Prime++;
		}
	}
}


