#include<bits/stdc++.h>
using namespace std;
int n,p[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97},r[3];
void dfs(int x,int s)
{
	if(s>3) return;
	else if(x==n && s==3 && r[0]<=r[1] && r[1]<=r[2])
	{
		cout<<r[0]<<"+"<<r[1]<<"+"<<r[2]<<"="<<n<<endl;
	}
	else
	{
		for(int i=0;i<25;i++)
		{
			if((x+p[i])<=n)
			{
				r[s]=p[i];
				dfs(x+p[i],s+1);
			} 
		}
	}
}
int main()
{
	cin>>n;
	if(n<=5 || n>100) cout<<"error"<<endl;
	else dfs(0,0);
	return 0;
}
