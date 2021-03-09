//在100范围内验证哥德巴赫猜想的正确性
#include<bits/stdc++.h>
using namespace std;
int pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
bool vis[100];
int main()
{
	for(int i=0;pr[i];++i)vis[pr[i]]=1;
	for(int i=4;i<=100;i+=2)
	{
		for(int j=0;pr[j];++j)
		if(vis[i-pr[j]]==1){printf("%d=%d+%d\n",i,pr[j],i-pr[j]);break;}
	}
	return 0;
}
