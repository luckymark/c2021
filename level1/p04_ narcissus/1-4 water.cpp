#include<iostream>
#include<cstdio>
#include<math.h>
#include<stdlib.h>
#include<string.h> 
using namespace std;

int main(){
	int a,b,c;
	for(int i=100;i<=999;i++){
		a=i/100;
		b=(i/10)%10;
		c=i%10;
		if(pow(a,3)+pow(b,3)+pow(c,3)==i){
			cout<<i<<endl;
		}
	}
}
