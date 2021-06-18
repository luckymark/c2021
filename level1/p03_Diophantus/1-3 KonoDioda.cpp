#include<iostream>
#include<cstdio>
#include<math.h>
#include<stdlib.h>
#include<string.h> 
using namespace std;

int main(){
	int fth,sn;
	for(int i=28;i<=300;i+=28){
		fth=i;
		sn=fth-fth*11/28-9;
		if(fth==sn*2){
			cout<<i;
		}
	}
}
