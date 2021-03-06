#include <stdio.h>
#include <math.h>

int is_prime(int n){
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}	
	}
	return 1;
} 

int main(){
	int n;
	printf("Please enter a number: ");
	scanf("%d",&n);
	if(is_prime(n)&&n>1){
		printf("It is a prime number.");
	}else{
		printf("It isn't a prime number.'");
	}
}
