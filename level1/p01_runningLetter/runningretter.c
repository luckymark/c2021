#include <stdio.h>
#include <windows.h>
#define Namelen 20
int main()
{
    CONSOLE_SCREEN_BUFFER_INFO cw;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_INPUT_HANDLE), &cw);
    int x = 1, y, i;
    int m = cw.srWindow.Left - cw.srWindow.Right; //没能成功
    //int m = cw.dwMaximumWindowSize.X;
    char s[Namelen];
    scanf("%s", s);
    while (1)
    {
        y = m - abs(m - x);
        for (i = 1; i < y; i++)
            printf(" ");
        Sleep(60);
        printf("%s", s);
        system("cls");
        x = (x + 1) % (2 * m);
    }
    return 0;
}
/*CONSOLE_SCREEN_BUFFER_INFO cw;
GetConsoleScreenBufferInfo(GetStdHandle(STD_INPUT_HANDLE), &cw);*/