#include <math.h>
#include <stdio.h>
// #include <iostream>

// using namespace std;
int main()
{
    long int digits = 3;  //位数
    // cin >> digits;

    long int lowerlimit, higherlimit = 1;  //定义上下限
    lowerlimit *= ( long int )pow( 10.0, digits );
    higherlimit = lowerlimit * 10;

    long int i = lowerlimit;
    for ( ; i <= higherlimit; i++ ) {
        //分离
        long int sum, m = 0;
        do {
            sum += ( long int )pow( i % 10, digits );
            m = sum / 10;
        } while ( m );
        if ( sum == i ) {  //如果符合条件
            printf( "%ld ", i );
        }
    }
}