#include <stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    if (n <= 1) {
        printf("error");
        return 0;
    }
    for (i = 2; i <= n / i; ++ i) {
        if (n % i == 0) {
            printf("Not prime.");
            return 0;
        }
    }
    printf("Is prime.");
    return 0;
}