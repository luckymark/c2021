#include<stdio.h>
#include<string.h>

char * encrypt(char [],int key);
char * decrypt(char [],int key);

int main(){
	char ps1[128]= {'\0'};
	char ps2[128]= {'\0'};
	int i,x;
	int key;
	int result;
	gets(ps1);

	printf("0 for decrypt and 1 for encrypt.\n");
	scanf("%d",&result);
	printf("Key please.\n");
	scanf("%d",&key);
	
	if(result==0){
		decrypt(ps1,key);
	}else if(result==1){
		encrypt(ps1,key);
	}else{
		printf("error");
	}
	
	printf("%s",ps1);
}

char * encrypt(char ps[],int key){
	int x=strlen(ps);
	int i;
	
	for(i=0;i<x;i++){
		ps[i]+=i+key;
	}
	
	return ps;	
}

char * decrypt(char ps[],int key){
	int x=strlen(ps);
	int i;
	
	for(i=0;i<x;i++){
		ps[i]-=i+key;
	}
	
	return ps;	
}


