#include<stdio.h>
#define ll long long

inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') 
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int main(){
	ll n=read();
	if(n<=0){
		printf("The input is wrong.");
	}
	else if(n==1||(n%2==0&&n!=2)){
		//1和大于2的偶数不是素数 
		printf("%lld isn't prime.",n);
	}
	else{
		for(ll i=3;i*i<n;i+=2){
			if(n%i==0){
				printf("%lld isn't prime.",n);
				return 0;
			}
		}
		printf("%lld is prime.",n);
	}
	return 0;
}
