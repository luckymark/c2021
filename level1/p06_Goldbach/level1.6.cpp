//��°ͺղ��룺��һ����2��ż������д����������֮��
#include <stdio.h>
#include <math.h>

void prime(int a[]);//����һ�� ������100���ڵ����� 
int isprime(int q,int a[]);//��������ȶ��ж��ǲ�������

//n��ȥһ�������ж��Ƿ��в�ֵΪ���������У����֤ 
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
