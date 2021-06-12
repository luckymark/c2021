#include <iostream>

using namespace std;

void narcissus() {
    int x, y, z, n = 100;
    while (n < 1000) {
        z = n % 10;
        y = n / 10 % 10;
        x = n / 100;
        if (x * x * x + y * y * y + z * z * z == n) cout << n << ' ';
        ++n;
    }
    cout << endl;
}

int main() {
    narcissus();
    return 0;
}