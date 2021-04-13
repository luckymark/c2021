#include<stdio.h>
int g[101];
int s[101];
int m[101];

int main(){
	g[1]=1;
	int t=0;
	s[t]=2;
	for(int i=3;i<=100;i++){
		if(g[i]==0){
			t++;
			s[t]=i;
			for(int j=2;j*i<=100;j++)
			g[i*j]=1;
		}
	}
	for(int i=0;i<=t;i++){
		for(int j=i;j<=t;j++){
			int l=s[i]+s[j];
			if(l>100)
			break;
			for(int k=i;k<=t;k++){
				l+=s[k];
				if(l>100)
				break;
				else
				m[l]=1;
			}
		}
	}
	for(int i=6;i<=100;i++){
		if(m[i]==0){
			printf("Goldbach's guess of a number under one hundred is wrong.");
			return 0;
		}
	}
	printf("Goldbach's guess of a number under one hundred is correct .");
	return 0;
}
