#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int a[1000];
int main()
{
  time_t begin,end;
  double ret;
  begin=clock();
  a[1]=2;
  a[2]=3;
  int k=2;
  bool judge=1;
  for(int i=4;i<=1000;i++)
  {
    for(int j=1;j<=k;j++){
      if(i%a[j]==0){
        judge=0;
      }
    }
    if(judge==0) judge=1;
    else{
      k++;
      a[k]=i;
    }
  }
  for(int i=1;i<=k;i++)
  {
    printf("%d ",a[i]);
  }
  end=clock();
  ret=double(end-begin);
  cout<<"runtime:   "<<ret<<"ms"<<endl;
  return 0;
}
