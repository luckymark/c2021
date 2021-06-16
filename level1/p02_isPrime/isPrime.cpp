#include<stdio.h>
#include<math.h>
int main()
{
	int n,flag=0;
	scanf("%d", &n);
	if (n == 2||n==1)
		printf("yes\n");
	else
		{
			for (int i=2; i <=sqrt(n); i++)
		{
			if (n % i == 0)
			{
				flag = 1;
				break;
			}
			
		}
			if (flag == 1)
				printf("no\n");
			else
				printf("yes\n");
		}
		
	return 0;
}
