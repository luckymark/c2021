#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a[4]={6,12,7,2};
  int n=0;
  int tt=a[0]*a[1]*a[2]*a[3];
  for(int i=0;i<4;i++)
  {
    n+=tt/a[i];
  }
  int t=tt-n;
  double ans=(9*tt/t)-4;
  cout<<ans<<endl;
  return 0;
}
