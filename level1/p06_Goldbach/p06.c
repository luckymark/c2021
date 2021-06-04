#include <stdio.h>

int isPrime(int n)
{
    int key=0;
    if (n==2) key=1;
    else
    {
        for (int i=2; i<=n/2+1; i++)
        {
            if (n%i==0) break;
            if (i==n/2+1) key=1;
        }
    }
    return key;
}

void EVENprove(int i)
{
    int flag=1;
    for (int j=2; j<=i/2; j++)
    {
        int k=i-j;
        if (isPrime(j)==1&&isPrime(k)==1)
        {
            switch (flag)
            {
                case 1:
                    printf("%3d=%d+%d",i,j,k);
                    flag=0;
                    break;
                case 0:
                    printf("\n   =%d+%d",j,k);
                    break;
            }
        }
    }
    printf("\n\n");
}

void ADDprove(int i)
{
    int flag=1;
    for (int j=2; j<=i/2; j++)
    {
        if (isPrime(j)==1)
        {
            int p=i-j;
            for (int k=j; k<=p/2; k++)
            {
                int l=p-k;
                if (isPrime(k)==1&&isPrime(l)==1)
                {
                    switch (flag)
                    {
                        case 1:
                            printf("%3d=%d+%d+%d",i,j,k,l);
                            flag=0;
                            break;
                        case 0:
                            printf("\n   =%d+%d+%d",j,k,l);
                            break;
                    }
                }
            }
        }
    }
    printf("\n\n");
}

void GoldbachProve(int n)
{
    for (int i=4; i<=n; i++)
    {
        if (i%2==0) EVENprove(i);
        if (i==5) continue;
        if (i%2!=0) ADDprove(i);
    }
}

int main(int argc, const char * argv[])
{
    printf("哥德巴赫猜想：\n");
    printf("（1）每个大于2的偶数都是两个素数之和\n");
    printf("（2）每个大于5的奇数都是三个素数之和\n");
    printf("在100以内的证明：\n");
    GoldbachProve(100);
}
