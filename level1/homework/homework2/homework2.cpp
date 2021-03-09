#include <stdio.h>

int main()
{
    int x = 0, i = 2;
    bool suShu = true;
    scanf("%d", &x);
    if (x <= 1)
    {
        printf("不是素数");
        return 0;
    }
    while (i <= x / 2)
    {
        if (x % i == 0)
        {
            suShu = false;
            break;
        }
        i++;
    }
    if (suShu) printf("是素数");
    else printf("不是素数");
}

