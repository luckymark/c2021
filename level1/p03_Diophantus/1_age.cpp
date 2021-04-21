#include<stdio.h>
using namespace std;
int main(){
	for(double i=1.0; ;i++){
		if(i/6+i/12+i/7+5+i/2+4==i){
			printf("%d\n",int(i-4));
			break;
		}
	}
	return 0;
}