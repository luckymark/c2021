#include <stdio.h>

int main(){
	int n;
	int a,b,c;
	for(n=100;n<1000;n++){
		c = n%10;//��λ��
		b = n/10%10;//ʮλ��
		a = n/100;//��λ��
		if((a*a*a+b*b*b+c*c*c)==n){
			printf("%d\n",n);
		}
	}
}
