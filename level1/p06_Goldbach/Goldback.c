#include <stdio.h>
enum {N = 100};
int sieved[N + 1];
int primes[N + 1],cnt;
int i,j,k,l;
void init_primes();
int main(){
    init_primes();
    for (i = 6; i <= N; ++ i){
        for (j = 0; j < cnt; ++ j)
            for (k = 0; k < cnt; ++ k)
                for (l = 0; l < cnt; ++ l)
                    if (primes[j] + primes[k] + primes[l] == i) {
                        printf("%d == %d + %d + %d\n",i,primes[j],primes[k],primes[l]);
                        goto flag;
                    }
        printf("It is wrong within 100!");
        flag:
        ;
    }
    printf("It is verified that Goldbach conjecture is right within 100.\n");
    system("pause");
    return 0;
}
void init_primes(){
    for (i = 2; i <= N; ++ i) {
        if (!sieved[i]) {
            primes[cnt ++] = i;
            for (j = i + i; j <= N; j += i)
                sieved[j] = 1;
        }
    }
}