#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long n;
  cin>>n;
  bool k=1;
  for(int i=4;i<=sqrt(n);i++)
  {
    if(n%i==0){
      k=0;
      break;
    }
  }
  if(k==0) puts("This is not a prime.");
  else puts("This is a prime.");
  return 0;
}
