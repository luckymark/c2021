#include <cmath>
#include <cstdio>
#define dd double
#define ll long long 
using namespace std;
const int maxn=100000,N1=maxn+5;

int a[2];
void check(int x)
{
    int tx=x,tot=0;
    for(int i=0;i<=2;i++)
    {
        a[i]=tx%10, tx/=10;
        tot+=a[i]*a[i]*a[i];
    }
    if(tot==x) printf("%d\n",x);
}

int main()
{
    for(int i=100;i<=999;i++)
    {
        check(i);
    }
    return 0;
}

