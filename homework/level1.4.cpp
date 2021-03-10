#include <stdio.h>
#include <math.h>
int main()
{
	int m,s,t=0,k,i;
	printf("三位的水仙花数有："); 
	for(m=100;m<1000;m++)
	{
	    k=m;
		s=0;//s，i，k都要初始化，注意初始化的位置应该在循环内还是外	
		for(i=0;k>0;i++)
		{ 
			t=k%10;
			s+=pow(t,3);
			k=k/10;	
		}
		if(m==s)
		{
			printf("%d\t",m);
		}
	}
	
	return 0;
} 
