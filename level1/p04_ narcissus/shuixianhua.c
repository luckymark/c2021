#include <stdio.h>
#include <windows.h>
int triple(int x)
{
    int y;
    y = x * x * x;
    return y;
}
int main()
{
    int y;
    for (y = 115; y < 1000; y++)
        if (triple(y % 10) + triple(y / 10 % 10) + triple(y / 100) == y)
            printf("%d\n", y);
    system("Pause");
    return 0;
}