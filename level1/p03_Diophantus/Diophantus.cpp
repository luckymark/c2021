#include<stdio.h>

int main()
{
	float Diophantus_age = 1;
	for (Diophantus_age = 1; 1; Diophantus_age++)
	{
		
		if (Diophantus_age / 12 + Diophantus_age / 6 + Diophantus_age / 7 + 5 + Diophantus_age / 2 + 4 == Diophantus_age)
		{
			break;
		}
	}
	printf("%d", (int)Diophantus_age-4);
	return 0;
}