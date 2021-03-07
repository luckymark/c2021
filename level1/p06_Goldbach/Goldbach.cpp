#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 100 + 5;
bool is[MAXN];
int pm[MAXN];
int main(){
    //哥德巴赫猜想 <=> 任一大于2的偶数都可写成两个质数之和
    memset(is, 1, sizeof is);
    is[0] = is[1] = 0;
    for (register int i = 2;i <= 100;++i){
        if (is[i])pm[++pm[0]] = i;
        for (register int j = 1;j <= pm[0] && i * pm[j] <= 100;++j){
            is[i * pm[j]] = 0;
            if (i % pm[j] == 0)break;
        }
    }
    for (int i = 4;i <= 100;i += 2){
        for (int j = 1;j < pm[0] && pm[j] < i;++j)
            if (is[i - pm[j]]){
                printf("%d = %d + %d\n", i, pm[j], i - pm[j]);
                break;
            }
    }
    return 0;
}