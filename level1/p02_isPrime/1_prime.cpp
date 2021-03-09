#include<stdio.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	bool flag = true;
	if(n==1){
		printf("1 is not prime\n");
		return 0;
	}
	for(int i=2;i*i<=n;i++){
		if(!(n%i)){
			flag = false;
			break;
		}
	}
	if(flag)
		printf("%d is prime\n",n);
	else
		printf("%d is not prime\n",n);
	return 0;
}