#include<iostream>
#include<cstdio>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int n;
	bool pr=1;
	cin>>n;
	for(int i=2;i<=sqrt(double(n));i++){
		if(n%i==0){
			pr=0;
		}
	}
	if ((pr)&&(n!=1)){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}
