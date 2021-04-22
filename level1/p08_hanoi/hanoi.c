#include<stdio.h>
 
 void hanoi(int x,char i,char j, char k); 
 
 int main(void){
 	int x;
 	scanf("%d",&x);
 	if(x<1){
 		printf("Wrong");
	 }else{
	 	hanoi(x,'A','B','C');
	 }
 	
 	return 0;
 }
 
 void hanoi(int x,char i,char j, char k){
 	 
	 if(x==1){
 		printf("%c¡ú%c\n",i,k);
	 }else{
	 	hanoi(x-1,i,k,j);
	 	printf("%c¡ú%c\n",i,k);
	 	hanoi(x-1,j,i,k);
	 }
 }
