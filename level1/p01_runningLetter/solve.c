#include <stdio.h>
#include <stdlib.h>
// #include <windows.h>
#define LENGTH 10  // 往返范围
#define MAX 100    // 字符串最大长度

int spaces( int num )
{
    int required;
    int a, b;
    a = num / LENGTH;    // 倍数
    b = num % LENGTH;    // 余数
    if ( a % 2 == 0 ) {  //如果a是偶数 即此时应该增加空格
        required = b;
    } else {
        required = LENGTH - b;
    }
    return required;
}

int main()
{

    char a[MAX];
    printf( "请输入字符串：" );
    scanf( "%s", &a );
    system( "cls" );  // 清屏
    int i, j, k = 0;
    while ( 1 ) {
        i++;
        j = spaces( i );
        for ( ; j--; j == 0 ) {  // ? why????
            printf( " " );       // 支撑
        }
        printf( "%s", a );

        // k = LENGTH - j - sizeof( a );
        // for ( ; k--; k == 0 ) {
        //     printf( " " );  // 支撑
        // }
        // printf( "||" );

        system( "cls" );  // 每循环一次清屏
    }
}
