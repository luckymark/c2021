#include <cmath>
#include <cstdio>
#define dd double
#define ll long long 
using namespace std;
const int maxn=100000,N1=maxn+5;


int main()
{
    //(1/6+1/12+1/7)x+5+1/2x+4=x
    dd x=(5.0+4.0)/(1.0-1.0/2-1.0/6-1.0/7-1.0/12);
    printf("%.0lf\n",x); 
    return 0;
}

