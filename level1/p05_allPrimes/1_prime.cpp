#include<stdio.h>
#include<algorithm>
#include<time.h>
const int N = 1001;
int prime[N];//记录存在的质数
bool num[N];//对应1-1000内的数，质数为0
using namespace std;
int main(){
    int t=1;//质数计数
    clock_t start,finish;
    start = clock();
    for(int i=2;i<N;i++){
        if(!num[i]){
            printf("%d ",i);
            prime[t]=i;
            t++;
        }
        for(int j=1;prime[j]*i<N&&j<t;j++){
            num[prime[j]*i]=1;
        }   
    }
    //printf("%d\n",t-1);
    puts("");
    finish = clock();
    printf("Time:%lfs\n",(double)(finish-start));
    return 0;
}