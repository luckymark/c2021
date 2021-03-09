#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
    int a, i;
    scanf("%d", &a);
    if (a == 2 || a == 3)
        printf("yes");
    else if (a % 6 != 1 && a % 6 != 5)
        puts("no");
    else
        for (i = 3; i <= (int)sqrt(double(a)) + 1; i = i + 2)
        {
            if (a % i == 0)
                printf("no");
            else if (i > (int)sqrt(double(a)))
                printf("yes");
        }

    system("PAUSE");
    return 0;
}