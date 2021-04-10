#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(unsigned long long n) {
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    cout << isPrime(49999);
    return 0;
}