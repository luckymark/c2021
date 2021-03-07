#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
const int MAXN = 1000 + 5;
bool is[MAXN];
int pm[MAXN], n, m, t;
int main(){
    memset(is, 1, sizeof is);
    is[0] = is[1] = 0;
    for (register int i = 2;i <= 1000;++i){
        if (is[i]){
            pm[++pm[0]] = i;
            printf("%d ", i);
        }
        for (register int j = 1;j <= pm[0] && i * pm[j] <= 1000;++j){
            is[i * pm[j]] = 0;
            if (i % pm[j] == 0)break;
        }
    }
    printf("\nUsed Time:%lfs", 1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}