//任一大于2的整数都可写成三个质数之和。
#include <math.h>
#include <stdio.h>  //TODO：优化效率 给出多解
int main()
{
    int primes[] = { 0, 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
    for ( int i = 0; i <= 100; i++ ) {
        for ( int j = 0; j < 26; j++ ) {
            for ( int m = 0; m < 26; m++ ) {
                for ( int n = 0; n < 26; n++ ) {
                    if ( primes[m] + primes[n] + primes[j] == i ) {
                        printf( "%d能用三个质数之和来表示，三个质数是:%d,%d,%d\n", i, primes[j], primes[m], primes[n] );
                        goto loop;
                    }
                }
            }
        }
    loop:
        printf( "" );
    }
}