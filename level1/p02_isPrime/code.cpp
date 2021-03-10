#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cout<<"Enter the number to be judged:";
	cin>>a;
	if(a<=1)
	{
		cout<<a<<" is not a prime.";
		return 0;
	}
	for(int i=2;i<=sqrt(a);i++)
	if(!(a%i))
	{
		cout<<a<<" is not a prime.";
		return 0;
	}
	cout<<a<<" is a prime.";
	return 0;
}
