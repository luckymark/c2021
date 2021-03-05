#include<stdio.h> 

int main(){
	int PrimesTable[500];
 	int i,j,k,count=0;
 	int isPrime;
 	int Goldbach;
 	PrimesTable[0]=2;
 	
 	for(i=3;i<=100;i++){
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
	for(i=4;i<=100;i+=2){
		Goldbach=0;
		for(j=0;j<=count;j++){
			for(k=0;k<=count;k++){
				if(PrimesTable[j]+PrimesTable[k]==i){
					Goldbach=1;
					
				}
			}
		}
		
	}
	
	if(Goldbach==1){
		printf("Goldbach is true within 100");
	}else{
		printf("Wrong");
	}
	 
}
