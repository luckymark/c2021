#include<stdio.h>
#include<math.h>

int main(){
  int x,isPrime=0,i;
  scanf("%d",&x );
  if (x%2==0){
    isPrime=1;
  }else{
    for(i=3;i<=sqrt(x);i+=2){
      if(x%i==0){
        isPrime=1;
        break; 
      }
    }
  }

  if(isPrime==1){
    printf("It's not a Prime\n" );
  }else{
    printf("It's a Prime\n");
  }
  return 0;
}
