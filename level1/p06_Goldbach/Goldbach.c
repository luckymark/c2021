#include <stdio.h>
#include <windows.h>
#include <math.h>
int Primer(int x)
{
    int i;
    if (x == 2 || x == 3)
        return 1;
    else if (x % 6 == 1 || x % 6 == 5)
        for (i = 3; i <= (int)sqrt(double(x)) + 1; i = i + 2)
        {
            if (x % i == 0)
                return 0;
            else if (i > (int)sqrt(double(x)))
                return 1;
        }
    else
        return 0;
}
void Goldbach(int y)
{
    int a, b;
    for (a = 1; a <= y; a = a + 2)
        if (Primer(a))
        {
            for (b = 1; b <= y; b = b + 2)
                if (Primer(b) && a + b == y)
                {
                    printf("%d=%d+%d \n", y, a, b);
                    return;
                }
                else
                    continue;
        }
        else
            continue;
}
int main()
{
    //100以内的哥德巴赫猜想
    int a, b;
    for (a = 4; a <= 100; a = a + 2)
        Goldbach(a);
    system("Pause");
    return 0;
}