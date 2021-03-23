#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
char t[5]={'0','A','B','C'};
void work(int num,int a,int b,int c)
{
	if(num==1)
	{
		printf("%c----->%c\n",t[a],t[b]);
		return ;
	}
	work(num-1,a,c,b);
	printf("%c----->%c\n",t[a],t[b]);
	work(num-1,c,b,a);
}
int main()
{
	cin>>n;
	work(n,1,3,2);
	return 0;
} 
