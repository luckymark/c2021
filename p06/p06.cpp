#include <iostream>
#include <stdio.h>
using namespace std;
int isPrime(int x){
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0) return 0;
    }
    return 1;
}
int main() {
    int prime[30];
    int cnt = 0;
    for (int n = 2; n < 100; n++){
        if(isPrime(n)) prime[++cnt] = n;
    }
    for(int x = 4 ; x <= 100; x += 2){
        for(int i = 1; i <= cnt; i++){
            if (isPrime(x - prime[i])){ // could use binary search in prime[] to optimize
                printf("%d = %d + %d\n",x,prime[i],x-prime[i]);
                break;
            }
        }
    }
    system("pause");
    return 0;
}