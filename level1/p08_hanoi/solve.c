// #include <stdio.h>
// int move( int m );
// int count( char from, char to );
// int main()
// {
//     /*
//      * A     B     C
//      *
//      * 1号
//      * 2号
//      *--------------------
//      *
//      * A柱上认为只有2个圆盘，最底下的和剩下的（整体）
//      * n = 2 时：
//      * (1号) A -> B 传递前执行
//      * 2号 A -> C 递归结束时执行
//      * (1号) B -> C 回归时执行
//      * 递归结束条件：A真的只剩下两个圆盘
//      * 函数本身：移动2个圆盘
//      */
//     int n;
//     printf( "A柱上的圆盘个数：" );
//     scanf( "%d", &n );
//     move( n );
// }

// int move( int m )
// {                    // m：A柱上圆盘数
//     if ( 1 == m ) {  // m柱上只剩1个盘子的时候
//         count( 'A', 'C' );
//     } else {
//         count( 'A', 'B' );
//         move( m - 1 );
//         count( 'B', 'C' );
//     }
// }

// int count( char from, char to )
// {  // 把盘从from柱移动到to
//     printf( "%c --> %c \n", from, to );
// }


#include <stdio.h>
void hanoi( int n, char A, char B, char C )  // n个圈圈在柱子A上，借助柱子B，移动到柱子C上
{
    if ( n == 1 )  //如果A柱子上只有一个圈圈，直接移动到C上
        printf( "%c --> %c\n", A, C );
    else {
        hanoi( n - 1, A, C, B );        //将A柱子上的n-1个圈圈，借助柱子C，移动到柱子B上
        printf( "%c --> %c\n", A, C );  //将A柱子上的最后一个圈圈移动到柱子C上
        hanoi( n - 1, B, A, C );        //将B柱子上的n-1个圈圈，借助柱子A，移动到柱子C上
    }
}

int main()
{
    hanoi( 8, 'A', 'B', 'C' );
    return 0;
}
