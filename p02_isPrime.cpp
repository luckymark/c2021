#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	int m=(int)sqrt(n)+1;
	for(int i=2;i<m;i++)
	{
		if(n%i==0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl; 
	return 0;
} 
