#include<stdio.h>
#include<math.h>

int main() 
{
	int n = 100;
	while (n <= 999)
	{
		if (n == pow(n / 100, 3) + pow(n % 100 / 10, 3) + pow(n % 10, 3))
			printf("%d\n", n);
		n++;
	}
}