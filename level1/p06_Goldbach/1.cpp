#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 101;
int prime[N];
bool num[N];
int main(){
    int t=0;
    for(int i=2;i<N;i++){
        if(!num[i]){
            prime[++t]=i;
        }
        if(i>5){
            int flag = 0;
            //奇数为1，偶数为0
            bool flag_1 = 0;
            // 1 为 哥德巴赫猜想成立
            flag = i%2 ? 1:0;
            for(int j=1;j<=t;j++){
                if(!num[i-prime[j]-flag-2]){
                    printf("%d = %d+%d+%d\n",i,flag+2,prime[j],i-prime[j]-flag-2);
                    flag_1=1;
                    break;
                }
            }
            if(!flag_1){
                printf("failed on %d\n",i);
                return 0;
            }
        }
        for(int j=1;i*prime[j]<N&&j<=t;j++){
            num[i*prime[j]]=1;
           // printf("num[%d]=%d\n",i*prime[j],num[i*prime[j]]);
        }
        
    }
    puts("test right\n");
    return 0;
}