#include <stdio.h>

int main(){
	int n;
	int a,b,c;
	for(n=100;n<1000;n++){
		c = n%10;//个位数
		b = n/10%10;//十位数
		a = n/100;//百位数
		if((a*a*a+b*b*b+c*c*c)==n){
			printf("%d\n",n);
		}
	}
}
