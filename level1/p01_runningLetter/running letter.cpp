#include<stdio.h>
#include<windows.h>
int main()
{
    int m = 10;
    while (1)
    {
        for (int n = 0; n < m; n++)
        {
            for (int i = 0; i <= n; ++i)
            {
                printf("\n");
            }
            for (int i = 0; i <= n; ++i)
            {
                printf(" ");
            }
            printf("H");
            Sleep(100);
            system("cls");
        }
        for (int n = m; n > 0; n--)
        {
            
            for (int i = 0; i <= n; ++i)
            {
                printf("\n");
            }for (int i = 0;i<=n; ++i)
            {
                printf(" ");
            }
            printf("H");
            Sleep(100);
            system("cls");
        }
    }
    return 0;
}