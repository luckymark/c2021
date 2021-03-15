#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
void work(int num,int a,int b,int c)
{
	if(num==1)
	{
		printf("将第%d根柱子上的一个盘子移动到第%d根柱子上\n",a,b);
		return ;
	}
	work(num-1,a,c,b);
	printf("将第%d根柱子上的一个盘子移动到第%d根柱子上\n",a,b);
	work(num-1,c,b,a);
}
int main()
{
	cin>>n;
	work(n,1,3,2);
	return 0;
} 
