#include<bits/stdc++.h>
using namespace std;
bool visit[101];
int prime[101],cnt;
void PrmCalc()
{
	for(int i=2;i<=100;i++)
	{
		if(!visit[i])
		prime[++cnt]=i;
		for(int j=1;j<=cnt&&prime[j]*i<=100;j++)
		{
			visit[prime[j]*i]=1;
			if(!(i%prime[j]))
			break;
		}
	}
	return;
}
void Solve(int n)
{
	for(int i=1;i<=cnt;i++)
	for(int j=i;j<=cnt;j++)
	for(int k=j;k<=cnt;k++)
	if(n==prime[i]+prime[j]+prime[k])
	{
		cout<<n<<"="<<prime[i]<<"+"<<prime[j]<<"+"<<prime[k]<<endl;
		return;
	}
	return;
}
int main()
{
	system("title Goldbach");
	PrmCalc();
	for(int i=6;i<=100;i++)
	Solve(i);
	return 0;
}
