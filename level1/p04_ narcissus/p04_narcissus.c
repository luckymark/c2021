#include<stdio.h>
#include<math.h>
int main(){
	int n;
	double a,b,c;
	for(n=100;n<1000;n++)
	{
		a=n/100;
		b=n%100/10;
		c=n%10;
		if(pow(a,3)+pow(b,3)+pow(c,3)==n)
		{
			printf("%d\n",n);
		}
	}
	return 0;
} 
