#include <iostream>
#include<cstdio>
using namespace std;
bool isPrime(int x){ // simple version
    if (x == 1) return false;
    for(int i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return true;
}
int main() {
    int n;
    cin >> n;
    bool ans = isPrime(n);
    if (ans) printf("%d is a prime.\n",n);
    else printf("%d is not a prime.\n",n);
    system("pause");
    return 0;
}
