#include<iostream>
#include<cstdio>
#include<math.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include<windows.h>
using namespace std;

int main(){
	int a[1000]={0};
	long op,ed;
	op=clock();
	a[1]=1;
	for(int i=2;i<=997;i++){
		if(a[i]==0){
			for(int j=i*i;j<=1000;j+=i){
				a[j]=1;
			}
			cout<<i<<endl; 
		} 
	}
	ed=clock();
	cout<<"time="<<ed-op;
}
