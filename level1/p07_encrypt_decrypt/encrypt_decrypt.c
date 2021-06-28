#include<stdio.h>
#include<string.h>

char text[128];
char cryp[128];
void encrypt();
void decrypt();

int main()
{
	scanf("%s",text);
	encrypt();
	printf("加密后：%s\n",cryp);
	decrypt();
	printf("解密后：%s\n",text);
	return 0;
 } 
 
 void encrypt()
 {
 	int len=strlen(text);
 	for(int i=0;i<len;i++){
 		cryp[i]=text[i]+i+len;
	 }
 }
 
 void decrypt()
 {
 	int len=strlen(cryp);
 	for(int i=0;i<len;i++){
 		text[i]=cryp[i]-i-len;
	 }
 }
 
