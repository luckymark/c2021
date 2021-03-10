# include<stdio.h>
# include<math.h>
int choose(int x){
	int ret=1;
	if(x==1||(x%2==0&&x!=2)){
		ret=0;
	}
	for(int i=3;i<=sqrt(x);i+=2){
		if(x%i==0){
			ret=0;
			break;
		}
	}
	return ret;
} 

int main(){
	int x;
	for(x=2;x<=1000;x++){
		if(choose(x)==1){
			printf("%d\n",x);
		}
	}
	return 0;
}
