#include<stdio.h>
void hanoi(int n, char A, char B, char C);//解决汉诺塔问题的函数
void move(int i, char A, char B);//表示移动

int main()
{
    int n, t;
    char a='a', c='c', b='b';
    printf("please input the number of diskes that you want to move\n");
    scanf_s("%d", &n);
    hanoi(n, a, b, c);
    return 0;
}

void hanoi(int n, char A, char B, char C)
//A是起始柱，B是中间临时放置的柱子，C是目标柱
{
    int t = n;
    if (t > 0)
    //递归终止的条件，注意递归不用循环来写，层层进入的过程是计算机来完成的
    {
        //解决n个盘子的问题分三步
        hanoi(t - 1, A, C, B);//把n-1个盘子从起始柱移动到中间柱
        move(t, A, C);//最大的盘子（第n个）从起始柱移动到目标柱
        hanoi(t - 1, B, A, C);//把n-1个盘子从中间柱移动到目标柱
        t--;
    }  
}
void move(int i, char A, char B)
{
    printf("move disk %d from %c to %c\n", i, A, B);
}