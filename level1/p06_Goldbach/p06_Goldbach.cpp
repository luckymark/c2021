#include <cmath>
#include <ctime>
#include <cstdio>
#define dd double
#define ll long long 
using namespace std;
const int maxn=100,N1=maxn+5;

clock_t st,ed;
int pr[N1],cnt;
bool vis[N1];
void get_prime()
{
    for(int i=2;i<=maxn;i++)
    {
        if(!vis[i]) pr[++cnt]=i; //printf("%d ",i);
        for(int j=1;j<=cnt&&i*pr[j]<=maxn;j++)
        {
            vis[i*pr[j]]=1;
            if(i%pr[j]==0) break;
        }
    }
    // puts("");
}
void check(int x)
{
    for(int i=2;i+2<=x;i++) if(!vis[i]&&!vis[x-i])
        { printf("%d:%d %d\n",x,i,x-i); return; }
    printf("%d:failed\n",x);
}

int main()
{
    // Goldbach conjecture:
    // every even number greater than 2 is able to be represented as the sum of two primes
    get_prime();
    for(int i=4;i<=maxn;i+=2) check(i);
    // Time complexity : O(n^2)
    return 0;
}

