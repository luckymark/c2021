#include<stdio.h> 

int main(){
	int x,i,j,k;
	for(x=100;x<1000;x++){
		i=x/100;
		j=(x-i*100)/10;
		k=(x-i*100-j*10);
		if(x==i*i*i+j*j*j+k*k*k){
			printf("%d\n",x);
		}
	}
}
