#include<bits/stdc++.h>
#include<ctime>
using namespace std;
inline void print(int x){
    char a[10];
    int tot=0;
    while(x){
        a[++tot]=x%10+'0';
        x/=10;
    }
    while(tot){
        putchar(a[tot]);
        --tot;
    }
}
int prime[1001];
int main(){
    int num=0;
    double sta=clock();
    memset(prime,true,sizeof(prime));
    bool is_prime=true;
    print(2);putchar(' ');
    prime[++num]=2;
    for(int i=3;i<=1000;i+=2){
        int k=sqrt(i);
        is_prime=true;
        for(int j=1;j<=num;j++){
            if(!(i%prime[j])){
                is_prime=false;
                break;
            }
        }
        if(is_prime){
            print(i);
            putchar(' ');
            prime[++num]=i;
        }
    }
    double end=clock();
    printf("\nrunning time: %.0lf ms",end-sta);
    return 0;
}