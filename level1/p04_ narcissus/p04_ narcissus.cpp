/*打印出所有3位水仙花数
水仙花数：n位数的每个数位的n次方之和等于该n位数本身

例如：153=1^3+5^3+3^3*/
#include<bits/stdc++.h>
using namespace std;
int a,b,c,cnt;
int main()
{
	for(int i=100;i<1000;++i)
	{
		a=i/100;
		b=i/10%10;
		c=i%10;
		if(i==a*a*a+b*b*b+c*c*c)printf("第%d个水仙花数:%d\n",++cnt,i);
	}
	return 0;
}
