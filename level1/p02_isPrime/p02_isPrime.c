#include <stdio.h>
#include <math.h>

int main ()
{
	int x;
	int i;
	int ret=1;
	scanf("%d",&x);
	if(x==1||(x%2==0&&x!=2)){
		ret=0;
	}
	for (i=3;i<=sqrt(x);i+=2){
		if(x%i==0){
			ret=0;
			break;
		}
	}
	if (ret ==0){
		printf("no");
	}else {
		printf("yes");
	}	
	return 0;
}
