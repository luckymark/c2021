#include<stdio.h>

int main()
{
	double age1,age2;
	int age;
	for(int i=1;;i++){
		age1=i;
		age2=age1-age1/6-age1/12-age1/7-5-4;
		if(age1==age2*2){
			age=age1-4;
			printf("%d",age);
			break;
		}
	}
	return 0;
}
