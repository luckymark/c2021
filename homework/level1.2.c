#include <stdio.h>
int main()
{
	int n, i;
	scanf_s("%d", &n);
	for (i = 2;i < n;i++)
	{
		if (0==n%i)break;
	}
	if (i == n)
		printf(" %d ������ ", n);
	else
		printf(" %d �������� ", n);
	return 0;
}