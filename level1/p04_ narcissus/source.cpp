#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
bool judge(int n){
  if(pow(n/100,3)+pow(n/10%10,3)+pow(n%10,3)==n)return true;
  return false;
}
int main() {
  for(int i=100;i<=999;i++)if(judge(i))cout<<i<<endl;
  system("pause");
	return 0;
}