#include<iostream>
#include<cstdio>
#include<math.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include<windows.h>
using namespace std;

int Prime[50]={0};
int t=0;
int a[100]={0};

void FindPrime(){
	a[1]=1;
	for(int i=2;i<=97;i++){
		if(a[i]==0){
			for(int j=i*i;j<=100;j+=i){
				a[j]=1;
			}
			Prime[t]=i;
			t++; 
		} 
    }
}

int main(){
	bool gede,bahe;
	int now;
	FindPrime();
	bahe=1; 
    for(int i=6;i<=100;i+=2){
    	now=1;
    	gede=1; 
    	while(Prime[now]<=i/2){
    		if(a[i-Prime[now]]==0){
    			gede=0;
    			break;
			}
			now++;
		}
		if(gede){
			bahe=0;
			break;
		} 
    }
    if(bahe){
    	cout<<"Yes";
	}
	else{
		cout<<"No!What happened??";
	}
	return 0;
}



