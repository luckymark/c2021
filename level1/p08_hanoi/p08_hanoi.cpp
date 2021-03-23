#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
int main()
{
	cin>>n;
	if(n<64)cout<<((unsigned long long)(1)<<n)-1;
	else cout<<((((unsigned long long)(1)<<63)-1)<<1)+1;
	return 0;
} 
