#include <stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=2;i<n;i++)
	{
		if(n%i)
		{
			break;
		}
	}
	if(i==n)
	printf("%d������",n);
	else
	printf("%d��������",n);
	return 0; 
}
