#include<stdio.h>
#include<math.h>

int p(int);

int main(){
    int num = 0;
    scanf("%d", &num);
    if(num<2){
        printf("error");
    }else{
        for (int i = 2; i < num + 1; i++){
            p(i) ? printf("%d,", i) : 0;
        }
    }
    return 0;
}

int p(int n){
    int flag = 0;
    for (int i = 2; i <= sqrt((double)n); i++){
        if(n%i==0){
            flag = 1;
            break;
        }
    }
    return !flag;
}