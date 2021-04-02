#include <stdio.h>

bool isPrime(int num)
{
	if(num==1)
	{
		return false;
	}
	for(int i =2;i*i<=num;i++)
	{
		if(num%i==0)return false;
	}
	return true;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	if (isPrime(n))
	{
		printf("%d是素数", n);
	}
	else
	{
		printf("%d不是素数", n);
	}

}
