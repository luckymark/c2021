#include <stdio.h>
#include <math.h>
int isPrime(int x)
{
    int flag=1;
	if(x>2)
    {
        for(int i=2;i<x;++i)
        {
            if(x%i==0) {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

int main()
{
    for(int i=4;i<=100;i=i+2)
    {
        for(int j=2;j<i;++j)
        {
            if(isPrime(j)==1)
            {
                if(isPrime(i-j)==1)
                {
                    printf("%d=%d+%d",i,j,i-j);
                    //printf("\t");
                    break;
                }
            }
        }
        printf("\n\n");
    }
    return 0;
}
