#include <cmath>
#include <ctime>
#include <cstdio>
#define dd double
#define ll long long 
using namespace std;
const int maxn=1000,N1=maxn+5;

clock_t st,ed;
int pr[N1],cnt;
bool vis[N1];
void get_prime()
{
    for(int i=2;i<=maxn;i++)
    {
        if(!vis[i]) pr[++cnt]=i, printf("%d ",i);
        for(int j=1;j<=cnt&&i*pr[j]<=maxn;j++)
        {
            vis[i*pr[j]]=1;
            if(i%pr[j]==0) break;
        }
    }
    puts("");
}

int main()
{
    st=clock();
    get_prime();
    ed=clock();
    printf("%.7lfs\n",(double)(ed-st)/CLOCKS_PER_SEC);
    //Time complexity:O(n)
    return 0;
}

