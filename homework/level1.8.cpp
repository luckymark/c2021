#include <stdio.h>

void move(int n, char a, char b, char c);

int main()
{
	int n;
	printf("please input the number of your disks:");
	scanf("%d", &n);
	move(n, 'A', 'B', 'C');


}
void move(int m, char a, char b, char c)//move函数的作用是把m块盘子移到目标柱 
{
	if(1==m)
	    printf("move disk %d from %c to %c\n", m, a, c); //递归截止条件
	else
	{
		move(m-1,a,c,b);//将 m-1个盘子先放到中间柱（对于第m块）上，（对于m-1块）此时起始柱是a，目标柱是b 
	    printf("move disk %d from %c to %c\n", m, a, c);//将A座上地剩下的一个盘移动到C盘上
		move(m-1,b,a,c);//将m-1个盘从中间柱移动到目标柱上 
	}
	


