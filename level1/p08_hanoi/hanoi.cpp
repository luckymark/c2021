#include <stdio.h>
#define N 4
int main()
{
    int hanoi(int, char, char, char);
    int  counter;
    counter = hanoi(N, 'A', 'B', 'C');
    return 0;
}
int hanoi(int n, char x, char y, char z) //通过y,把x的n个盘子放到z.
{
    int move(char, int, char);
    //出口
    if (n == 1)
        move(x, 1, z);
    //自相似过程
    else
    {
        hanoi(n - 1, x, z, y); //对于每个n都是把前n-1个放在一个柱子上
        move(x, n, z);  //然后再把第n个放在另外的柱子上
        hanoi(n - 1, y, x, z); //再把前n-1个放到第n个上面
    }
    return 0;
}
int move(char getone, int n, char putone)
{
    static int k = 1;
    printf("%2d:%3d # %c---%c\n", k, n, getone, putone);
    if (k++ % 3 == 0)
        printf("\n");
    return 0;
}
