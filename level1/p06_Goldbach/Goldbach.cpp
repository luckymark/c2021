#include<bits/stdc++.h>
using namespace std;
int prime( int p )
{
    for(int i=2;i<=p;i++)
    {
        if(p%i==0)
        {
            if(p==i) return 1;
            else return 0;
        }
    }
}
void Goldbach( int n )
{
    for(int i=2;i<=n;i++)
    {
        if(prime(i)==1&&prime(n-i)==1)
        {
            printf("%d=%d+%d",n,i,n-i);
            break;
        }
    }
}
int main()
{
    int m, n, i, c;
    m=1;
    n=100;
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    c = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        c++;
        if ( c%5 ) printf(", ");
        else printf("\n");
    }

    return 0;
}
