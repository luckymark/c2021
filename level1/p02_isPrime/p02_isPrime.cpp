#include <cmath>
#include <cstdio>
#define ll long long 
using namespace std;
const int maxn=100000,N1=maxn+5;

int pr[N1],cnt;
bool vis[N1];
void get_prime()
{
    for(int i=2;i<=maxn;i++)
    {
        if(!vis[i]) pr[++cnt]=i;
        for(int j=1;j<=cnt&&i*pr[j]<=maxn;j++)
        {
            vis[i*pr[j]]=1;
            if(i%pr[j]==0) break;
        }
    }
}
int check(ll x)
{
    ll m=sqrt(x);
    for(int j=1;pr[j]<=m&&j<=cnt;j++)
        if(x%pr[j]==0) return 0;
    return 1;
}

ll n;

int main()
{
    scanf("%lld",&n);
    if(n<=1){ puts("bad input"); return 0; }
    get_prime();
    int flag=check(n);
    if(!flag) puts("NO"); else puts("YES");
    return 0;
}

