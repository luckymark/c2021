#include<stdio.h>
int main(){
	double y=1.0;
	while(true){
		if(y/6+y/12+y/7+5==y/2-4)
		break;
		y=y+1;
	}
	printf("%d",(int)y-4);
	return 0;
}
