//哥德巴赫猜想：任一大于2的偶数都可写成两个素数之和
#include <stdio.h>
#include <math.h>

void prime(int a[]);//先做一个 数组存放100以内的质数 
int isprime(int q,int a[]);//与质数表比对判断是不是质数

//n减去一个质数判断是否有差值为质数，若有，则得证 
int main()
{
	int t,n=4;
	int p[100]={0};
	prime(p);
	while(n<=100)
	{
		for(int i=0;p[i]>0;i++)
		{
			if(isprime(n-p[i],p))
			{
				printf("%d=%d+%d\n",n,p[i],n-p[i]);
				break;
			}
			if(p[i]==0)
			{
				printf("Error");
			} 
		}
		n+=2;		
	}
	printf("If there is no error,Goldbach conjecture has been proved."); 
	return 0;	
	
}

void prime(int a[])
{
	int x=0,isprime,n=3;
	while(n<100)
	{
		isprime=1;
		a[0]=2;
	    for(int i=0;a[i]<sqrt(n);i++)
	    {
		    if(n%a[i]==0)
	    	{
		    	isprime=0;
		    	break;
		    }
	    }
	    if(isprime)
	    {
		    a[x+1]=n;
		    x+=1;
	    }	
		n+=2;		
	}
}
 
int isprime(int q,int a[])
{
	int isprime=0;
    for(int i=0;a[i]>0;i++)
    {
    	if(q==a[i])
    	{
    		isprime=1;
		} 
    }
    return isprime;
}
