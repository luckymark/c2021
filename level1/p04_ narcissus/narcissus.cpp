#include<stdio.h>

int main()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (i * i * i + j * j * j + k * k * k == 100 * i + 10 * j + k)
				{
					printf("%d\n", 100 * i + 10 * j + k);
				}
			}
		}
	}
	return 0;
}
