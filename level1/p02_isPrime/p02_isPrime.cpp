#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
bool f=1;
int main()
{
	cin>>n;
	for(unsigned long long i=2;i*i<=n;++i)
	if(n%i==0)f=0;
	if(f)cout<<"YES";
	else cout<<"NO";
	return 0;
}
