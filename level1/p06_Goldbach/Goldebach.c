#include<stdio.h>
#include<math.h>

int isPrime(int n){
	int i=1;
	if(n>2&&n%2==0){
		i=0;
	}else{
		for(int i=3;i<=sqrt(n);i+=2){
			if(n%i==0){
				i=0;
				break;
			}
		}
	}
	return i;
}

int Goldbach(int n){
	int ret=0;
	for(int i=2;i<n;i++){
		if(isPrime(i)&&isPrime(n-i)){
			ret=1;
			break;
		}
	}
	return ret;
}

int main(){
	int ret=1;
	for(int n=4;n<=100;n+=2){
		if(Goldbach(n)==0){
			ret=0;
			break;
		}
	}
	if(ret){
		printf("true");
	}else{
		printf("wrong");
	}
	return 0;
} 
