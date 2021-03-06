#include<iostream>
using namespace std;
inline bool isp(const int &x){
    if (x == 2 || x == 3)return 1;
    if (x == 1 || (x % 6 != 1 && x % 6 != 5))return 0;
    for (register int i = 5;i * i <= x;i += 6)
        if ((x % i) == 0 || (x % (i + 2)) == 0)return 0;
    return 1;
}
long long digit;
int main(){
    printf("please input a digit(<2^64)");
    scanf("%lld", &digit);
    printf("%lld is", digit);
    printf(isp(digit) ? " a prime" : " not a prime");
    return 0;
}