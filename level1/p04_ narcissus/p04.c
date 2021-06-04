#include <stdio.h>

int main(int argc, const char * argv[])
{
    printf("所有的3位水仙花数为：");
    for (int num=100; num<=999; num++)
    {
        int a=num/100,b=(num-a*100)/10,c=num-a*100-b*10;
        if (num==a*a*a+b*b*b+c*c*c) printf("%d ",num);
    }
    printf("\n");
}
