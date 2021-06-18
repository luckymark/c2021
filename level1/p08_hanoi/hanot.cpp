#include<iostream>
#include<cstdio>
#include<math.h>
#include<stdlib.h>
#include<string.h> 
using namespace std;

void hano(int gs,int st,int fi,int be){
	if(gs==1){
		cout<<gs<<":"<<st<<" - "<<fi<<endl;
	}
	else{
		hano(gs-1,st,be,fi);
		cout<<gs<<":"<<st<<" - "<<fi<<endl;
		hano(gs-1,be,fi,st);
	}
}

int main(){
	int n;
	cin>>n;
    hano(n,1,3,2);
	return 0;
}
