
#include<stdio.h>
#include<math.h>

int main(){
  float age=2.0;
  while (fabs((1.0/6)*age+(1.0/12)*age+(1.0/7)*age+5+(1.0/2)*age+4-age)>=0.01){
    age++;
  }

  printf("When his son died Diophantus is %.0f years old\n",age-4 );

  return 0;
}


