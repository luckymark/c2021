#include<stdio.h>
#include<time.h>
#include<Windows.h>
 
int main(){
	int PrimesTable[500];
 	int i,j,count=0;
 	int isPrime;
 	long time1,time2;
 	int k=0;
 	PrimesTable[0]=2;
 	
	time1=GetTickCount();

 	for(i=3;i<=1000;i++){
 		isPrime=1;
 		for(j=0;j<count;j++){
 			if(i%(PrimesTable[j])==0){
 				isPrime=0;
 				break;
			 }
			 
		 }
		 if(isPrime==1){
		 	count++;
		 	PrimesTable[count]=i;
		 }
	 }
	 
	 time2=GetTickCount();
	 printf("Time is %d\n",(int)(time2-time1));
	 
	 i=0;
	 for(i=0;i<=count;i++){
	 	printf("%d ",PrimesTable[i]);
	 	k++;
	 	if(k%5==0){
	 		printf("\n");
		 }
	 }
}
