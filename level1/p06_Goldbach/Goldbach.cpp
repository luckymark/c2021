#include <iostream>

using namespace std;

bool Goldbach() {
    int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    bool meet = false;

    for (int n = 4; n <= 100; n += 2) {
        meet = false;
        for (int i = 0; i < 15; ++i)
            for (int j = i; j < 25; ++j) {
                if (prime[i] + prime[j] == n) {
                    meet = true;
                    goto judge;
                } else if (prime[i] + prime[j] > n)
                    break;
            }

    judge:
        if (meet == true)
            continue;
        else
            return false;
    }

    return true;
}

int main() {
    cout << Goldbach();
    return 0;
}