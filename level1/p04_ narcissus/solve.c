// 功能要求：
// 打印出所有3位水仙花数
// 水仙花数：n位数的每个数位的n次方之和等于该n位数本身

// 例如：153=1^3+5^3+3^3
// 153 --> 1,5,3
#include <stdio.h>
int main()
{
    int ge, shi, bai;
    for ( ge = 0; ge < 10; ge++ ) {
        for ( shi = 0; shi < 10; shi++ ) {
            for ( bai = 0; bai < 10; bai++ ) {
                int result = ge * ge * ge + shi * shi * shi + bai * bai * bai;
                if ( result < 1000 && result >= 100 ) {
                    printf( "%d\n", result );
                }
            }
        }
    }
}
/*
1 1 1
1 1 9
1 2 1
1 2 9



*/