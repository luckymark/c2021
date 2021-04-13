#include<stdio.h>

int mul(int x){
	return x*x*x;
}
int main(){
	for(int i=1;i<=9;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<=9;k++){
				int t=mul(i)+mul(j)+mul(k);
				//printf("111");
				if(t==i*100+j*10+k){
					printf("%d\n",t);
				}
			}
		}
	}
	return 0;
}
