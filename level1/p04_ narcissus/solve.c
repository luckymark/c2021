#include <stdio.h>
// #include <iostream>
int pows( int n, int m )
{
    int i;
    int j = n;
    for ( i = 0; i < m - 1; i++ ) {
        n = n * j;
    }
    return n;
}
// using namespace std;
int main()
{
    int      digits      = 3;  //在这里修改位数
    long int lowerlimit  = 1;
    long int higherlimit = 1;  //定义上下限
    int      i;
    for ( i = 0; i < digits - 1; i++ ) {
        lowerlimit *= 10;
    }
    // lowerlimit *= ( long int )pow( 10.0, digits );
    higherlimit = lowerlimit * 10;

    long int j = lowerlimit;
    for ( ; j <= higherlimit; j++ ) {
        //分离
        long int sum = 0;
        long int m   = j;
        do {
            sum += ( long int )pows( m % 10, digits );
            m = m / 10;
            if ( sum > j ) {
                break;
            }
        } while ( m );
        if ( sum == j ) {  //如果符合条件
            printf( "%ld ", j );
        }
    }
}