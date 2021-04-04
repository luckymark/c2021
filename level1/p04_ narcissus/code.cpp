#include<bits/stdc++.h>
using namespace std;
int st[10],dig[4];
void verify(int i,int j,int k)
{
	int ans=st[i]+st[j]+st[k];
	if(ans<100||ans>=1000)
	return;
	dig[1]=ans/100;
	dig[2]=(ans/10)%10;
	dig[3]=ans%10;
	sort(dig+1,dig+4);
	if(dig[1]==i&&dig[2]==j&&dig[3]==k)
	cout<<ans<<" ";
	return;
}
int main()
{
	system("title Narcissus");
	for(int i=1;i<=9;i++)
	st[i]=i*i*i;
	for(int i=0;i<=9;i++)
	for(int j=i;j<=9;j++)
	for(int k=j;k<=9;k++)
	verify(i,j,k);
	return 0;
}
