#include <stdio.h>
#include <math.h>
#include <time.h>

void allPrimes()
{
    printf("2~1000的所有素数为：\n2\t");
    for (int i=3; i<=1000; i++)
    {
        int k=(int)sqrt(i),stauts=1;
        for (int j=2; j<=k; j++)
        {
            if (i%j==0)
            {
                stauts=0;
                break;
            }
        }
        if (stauts==1) printf("%d\t",i);
    }
}

int main(int argc, const char * argv[])
{
    unsigned long a=clock();
    allPrimes();
    unsigned long b=clock();
    printf("\n程序计算时间为%lums。\n",b-a);
}
