#include <stdio.h>

// 任意输入一个正整数n
// 判断n是否为素数


int method1( unsigned int m )
{
    // 从 2 ~ m-1 一个个试，如果有任一次除法取余不为0，那么不是素数
    for ( int i = m - 1; i > 1; i-- ) {
        if ( m % i != 0 ) {  // 取余不为0
            printf( "%u不是素数", m );
            return 0;  // 不是素数
        }
    }
    printf( "%u是素数", m );
    return 1;  //是素数
}

int method2( unsigned int m )
{
    // 从 2 ~ (m-1)/2 一个个试 (去掉2,2是重复的潜在因数)
    for ( int i = ( m - 1 ) / 2; i > 1; i-- ) {
        if ( m % i != 0 ) {  // 取余不为0
            printf( "%u不是素数", m );
            return 0;  // 不是素数
        }
    }
    printf( "%u是素数", m );
    return 1;  //是素数
}

int method3( unsigned int m )
{
    // 去掉 2 ~ m 中是倍数的部分，留下素数来测试
    // ?
}

int method4( unsigned int m )
{
#include <math.h>
    // N=根号N*根号N
    // N的因数除了根号N，其他都是成对存在的，且必定一个大于根号N一个小于根号N
    // 假设N不是质数，有个因数大于根号N（不是N本身）
    // 则N必定有一个与之对应的小于根号N的因数
    // 也就是说，如果2到根号N都没有N的因数，那么对应的根号N到N-1都没有N的因数，N就是个质数
    for ( int i = ( int )sqrt( m ); i > 1; i-- ) {  //从2到算术平方根遍历。
        if ( m % i != 0 ) {                         // 取余不为0
            printf( "%u不是素数", m );
            return 0;  // 不是素数
        }
    }
    printf( "%u是素数", m );
    return 1;  //是素数
}

int main()
{
    unsigned int n;
    scanf( "%u", &n );
    // method1( n );
    // method2( n );
    method4( n );
}
