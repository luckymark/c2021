#include <stdio.h>
#include <time.h>
enum {N = 1001};
int primes[N], cnt;
int sieved[N];    	

void get_primes(int n);
int main(int argc, char const *argv[])
{
    clock_t timer = clock();
    get_primes(1000);
    int i;
    for (i = 0; i < cnt; ++ i) {
        printf("%d\t",primes[i]);
    }
    printf("\nTime:%dms\n",clock() - timer);
    system("pause");
    return 0;
}
void get_primes(int n)
{
    int i,j;
    for (i = 2; i <= n; i ++ )
    {
        if (!sieved[i]) primes[cnt ++ ] = i;
        for (j = 0; primes[j] <= n / i; j ++ )
        {
            sieved[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;	
        }
    }
}