#include<iostream>
#include<math.h>
#include<stdio.h>
#include<Windows.h>
#include <time.h> 
using namespace std;
int saves[10000];
int hanoi(int n){
  if(saves[n]==0){
    saves[n]=2*hanoi(n-1)+1;;
    return 2*hanoi(n-1)+1;
  }
  else return saves[n];
}
int main() {
  saves[1]=1;
  int n;
  cin>>n;
  cout<<hanoi(n)<<endl;
  system("pause");
	return 0;
}