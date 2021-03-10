#include <stdio.h>

int main()
{
	int m=0,i=0,k;
	do
	{
		i++;
		if(i%12==0&&i%7==0&&(i/6+i/12+i/7+5+i/2+4)==i)//直接用循环解方程除法取整后会得到错误结果，先要保证年龄是6,12,7的公倍数
		{
			m=i;
		}
	}
	while(m!=i);
	printf("儿子死时丢番图的年龄是%d",m-4);
} 
