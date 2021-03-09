#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// #define LENGTH 10
#define MAX 100

void HideCursor()  //隐藏光标
{
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &cursor_info );
}

int spaces( int num, int length )
{
    int required;
    int a, b;
    a = num / length;    // 倍数
    b = num % length;    // 余数
    if ( a % 2 == 0 ) {  //如果a是偶数 即此时应该增加空格
        required = b;
    } else {
        required = length - b;
    }
    return required;
}

int TextAttribute()  //获取屏幕宽度
{
    HANDLE                     hOut;
    CONSOLE_SCREEN_BUFFER_INFO scr;

    hOut = GetStdHandle( STD_OUTPUT_HANDLE ); /* 获取标准输出句柄 */
    GetConsoleScreenBufferInfo( hOut, &scr );
    int width = scr.dwMaximumWindowSize.X;
    return width;
}

int main()
{
    int  x = TextAttribute();
    char a[MAX];
    scanf( "%s", &a );
    system( "cls" );  // 清屏
    int i, j, k = 0;
    while ( 1 ) {
        i++;
        j = spaces( i, x );
        for ( ; j--; j == 0 ) {
            printf( " " );  // 支撑
        }
        printf( "%s", a );

        system( "cls" );  // 每循环一次清屏
    }
}
