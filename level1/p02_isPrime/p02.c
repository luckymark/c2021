#include <stdio.h>

void isPrime(int n)
{
    if (n==2) printf("%d是素数。\n",n);
    else
    {
        for (int i=2; i<=n/2; i++)
        {
            if (n%i==0)
            {
                printf("%d不是素数。\n",n);
                break;
            }
            if (i==n/2) printf("%d是素数。\n",n);
        }
    }
}

int main(int argc, const char * argv[])
{
    int n;
    printf("请输入一个正整数：");
    scanf("%d",&n);
    isPrime(n);
}
