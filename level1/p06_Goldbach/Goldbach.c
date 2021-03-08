#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(int n){
	int i;
	for(i=2;i<=sqrt(n);i++){
		if(n%i==0)return false;
	}
	return true;
}

int main(){
	int n,m,x=0;
	for(n = 4;n <= 100;n += 2){
		for(m = 2;m <= n;m ++){
			if(is_prime(m) && is_prime(n - m)){
				printf("%3d = %2d + %2d\n",n,m,n - m);
				x++;
				break;
			}
		}
		if(x==49)printf("The Goldbach is true");
	}
	return 0;
}
