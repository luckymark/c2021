#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a[1000];
  int k=0;
  for(int i=100;i<=999;i++)
  {
    int a1,a2,a3;
    a1=i%10;
    a2=(i/10)%10;
    a3=i/100;
    a1=a1*a1*a1;
    a2=a2*a2*a2;
    a3=a3*a3*a3;
    if(i==a1+a2+a3){
      k++;
      a[k]=i;
    }
  }
  for(int i=1;i<=k;i++)
  {
    printf("%d ",a[i]);
  }
  return 0;
}
