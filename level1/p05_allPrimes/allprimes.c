#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <math.h>
int main()
{
    int a, b, i;
    printf("2 3 ");
    for (a = 3; a < 1000; a = a + 2)
    {
        if (a % 6 != 1 && a % 6 != 5)
            continue;
        b = (int)sqrt(double(a));
        for (i = 3; i <= b; i = i + 2)
        {
            if (a % i == 0)
                break;
            else if (i == b)
                printf("%d ", a);
        }
    }
    printf("\n Time used=%.2fs", (double)clock() / CLOCKS_PER_SEC);
    system("PAUSE");
    return 0;
}