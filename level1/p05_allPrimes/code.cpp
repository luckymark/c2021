#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
bool visit[1001];
int prime[1001],cnt;
clock_t t1,t2;
int main() 
{
	system("title AllPrimes");
	LARGE_INTEGER cpuFreq;
	LARGE_INTEGER startTime;
	LARGE_INTEGER endTime;
	QueryPerformanceFrequency(&cpuFreq);
	QueryPerformanceCounter(&startTime);
	for(int i=2;i<=1000;i++)
	{
		if(!visit[i])
		prime[++cnt]=i;
		for(int j=1;j<=cnt&&prime[j]*i<=1000;j++)
		{
			visit[prime[j]*i]=1;
			if(!(i%prime[j]))
			break;
		}
	}
	QueryPerformanceCounter(&endTime);
	for(int i=1;i<=cnt;i++)
	cout<<prime[i]<<" ";
	cout<<endl<<"It takes "<<(((endTime.QuadPart - startTime.QuadPart) * 1000.0f) / cpuFreq.QuadPart)<<"ms to calculate.";
	return 0;
}
