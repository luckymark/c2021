#include <stdio.h>
#include <math.h>
#include <time.h>

//常规做法 
int is_prime1(){
	int i,n,m,t = 0;
	for(n = 2;n < 1000;n ++){
		m = 1;
		for(i = 2;i <= sqrt(n);i ++){
			if(n % i == 0){
				m = 0;
				break;
			}
		}
		if(m == 1){
			printf("%d\t",n);
			t ++;
		}
		if(t == 15){
			printf("\n");
			t = 0;
		}
	}
	return 0;
}

//埃氏筛 
int is_prime2(){
	char a[1000] = {1};
	int i,x,m = 0;
	for(i = 2;i < 1000;i ++){
		if(a[i] == 0){
			for(x = i*i;x < 1000;x = x + i)a[x] = 1;
			printf("%d\t",i);
			m ++;
			if(m == 15){
				printf("\n");
				m = 0;
			}
		}
	}
}

int main(){
	int n,m = 0;
	clock_t start_t,end_t;
	double total_t;
	
	//常规做法 
	start_t = clock();
	is_prime1();
	end_t=clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("\n程序运行的总时间为: %fs\n",total_t);
	
	//埃氏筛 
	start_t = clock();
	is_prime2();
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("\n程序运行的总时间为: %fs",total_t);
	return 0;
}
