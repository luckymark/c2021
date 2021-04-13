#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int s[1001];

int main(){
	clock_t begin,end;
	double cost;
	begin=clock();
	for(int i=3;i<=1000;i++){
		if(s[i]!=0)
		continue;
		for(int j=2;i*j<=1000;j++){
			s[i*j]=1;
		}
	}
	for(int i=2;i<=1000;i++){
		if(s[i]==0)
		printf("%-5d",i);
	}
	end=clock();
	cost=(double)(end-begin)/CLOCKS_PER_SEC;
	printf("\nconstant CLOCKS_PER_SEC is: %ld, time cost is: %lf secs", CLOCKS_PER_SEC, cost);
	return 0;
}
