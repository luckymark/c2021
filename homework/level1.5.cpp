/*节省时间:
- break；
- 只用奇数，排除偶数,n+=2
- i<sqrt(n)就可以结束了
- 用数组记录质数，然后直接循环除质数就可以了，不用把所有的数循环一遍
*/

#include <stdio.h>
#include <time.h>
#include <math.h>
void isprime_1()
{
	int x=0,isprime,n=3,a[1000]={2,0};
	
	while(n<1000)
	{
		isprime=1;
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
	
	
	for(int i=0;i<=x;i++)
	{
		printf("%d\t",a[i]);
		if((i+1)%10==0)
		{
			printf("\n");
		}
	}
	printf("\n"); 

}

void isprime_2()
{
	int n=0, i, j,isprime;
	for(i=2;i<=1000; i++)
	{
		isprime=1;
		for (j=2; j<=sqrt(i); j++)
		if (i%j==0)
		{
			isprime=0;
			break;
		}
		if (isprime)
		{
			n++;
			if (n%10==0) printf("%d\n",i);
			else printf("%d\t",i);
		}
	}
}

int main()
{
    clock_t start_t,finish_t;
	double total_t;

	start_t = clock();
	isprime_1();
	finish_t=clock();
	total_t = (double)(finish_t - start_t) / CLOCKS_PER_SEC;
	printf("\n质数数组法运行总时间是%f 秒\n",total_t);

	start_t = clock();
	isprime_2();
	finish_t = clock();
	total_t = (double)(finish_t - start_t) / CLOCKS_PER_SEC;
	printf("\n直接循环取余程序运行总时间是%f 秒\n",total_t);
	return 0;
}

