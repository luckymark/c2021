#include <stdio.h>

int main()
{
    for(int i=1;i<100;++i)
    {
        if(i/2==i-(1.0/6*i+1.0/12*i+1.0/7*i+5+4))
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}