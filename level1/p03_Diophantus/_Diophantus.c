#include <stdio.h>
#include <windows.h>
int main()
{
    int a = 1;
    while (1)
    {

        if (2 * a - 4 - a - 5 == 2 * a * (1.0 / 6 + 1.0 / 12 + 1.0 / 7))
        {
            printf("%d\n", 2 * a - 4);
            break;
        }
        else
            a++;
    }
    system("Pause");
    return 0;
}