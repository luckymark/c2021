#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,j,k;
	while(true){
		for(i=0;i<20;i++){
			if(i>10){
				k=20-i;
			}else{
				k=i;
			}
			for(j=0;j<k;j++){
				printf(" ");
			}
			printf("A");
			system("cls");
		} 
		
		
	}
}
