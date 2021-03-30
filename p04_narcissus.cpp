#include<bits/stdc++.h>
using namespace std;
int cub(int x)
{
	return x*x*x;
}
bool nar(int x)
{
	int sum=0;
	int sum0=x;
	while(x>0)
	{
		sum+=cub(x%10);
		x/=10;
	}
	return sum==sum0;
}
int main()
{
	for(int i=100;i<=999;i++)
	{
		if(nar(i)) cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
