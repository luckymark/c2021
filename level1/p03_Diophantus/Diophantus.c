#include <stdio.h>
//¶ª·¬Í¼ÎÊÌâ 
int main(){
	float x;
	for(x=1;x<200;x++){
		if((x/6+x/12+x/7+5+x/2+4)==x){
			printf("%.0f",x);
			break;
		}
	}
	return 0;
} 
