#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
//constants
enum{ N = 1000 , SLEEP_TIME = 50};
char space[N];
int i;
//func
int GetWidth();
int abs(int x);
//entertainment
void DrawLine(int width);
void ChangeColor(int cnt);

int main(int argc, char const *argv[])
{
    printf("Please enter several letters within a line:\n");
    //Init
    char str[N]; scanf("%s",str);
    int len = strlen(str);
    int width = GetWidth();
    int pos;
    //Play
    int cnt = 0;
    while (1) {
        /*calculate pos*/
        pos = width - abs(width - ( cnt++ % (2 * width) ) );
        /*prevent crossing the border*/
        if (pos + len > width) continue;

                    ChangeColor(cnt);
        system("cls");
                    DrawLine(width);
        /*Output*/
        for (i = 0; i < width; ++ i) 
            space[i] = i < pos || i >= pos + len ? ' ' : str[i - pos];
        space[i] = '\0';
        printf("%s",space);

                    DrawLine(width);
        /*Sleep a while, let the user watch.*/
        Sleep(SLEEP_TIME);
    }
    return 0;
}
int GetWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO scr;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hOut, &scr);
    return scr.dwMaximumWindowSize.X;
}
int abs(int x)
{
    return x >= 0 ? x : -x;
}
void DrawLine(int width)
{
    for (i = 0; i < width; ++ i) space[i] = '*'; space[i] = '\0';
    printf("%s\n",space);
}
void ChangeColor(int cnt) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),cnt % 16);
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(cnt % 16) * 16 + 16 - (cnt % 16));
}