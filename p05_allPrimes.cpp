#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int main()
{
	int isprime[1000];
	for(int i=0;i<=1000;i++)
	{
		isprime[i]=1;
	}
	for(int i=2;i<=1000;i++)
	{
		if(isprime[i]==1)
		{
			cout<<i<<" ";
			for(int j=2;i*j<=1000;j++)
			{
				isprime[i*j]=0;
			}
		}
	}
	cout<<endl;
	printf("Time used = %.4fs\n", (double)clock() / CLOCKS_PER_SEC);//单位秒
	return 0;
}
