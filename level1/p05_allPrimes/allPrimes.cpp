#include <ctime>
#include <iostream>

using namespace std;

void allPrimes() {
    clock_t startTime = clock();

    int list[170];
    int i, n, cnt = 0;

    for (n = 2; n < 1001; ++n) {
        for (i = 0; i < cnt; ++i)
            if (n % list[i] == 0) goto end;

        list[cnt++] = n;
        cout << n << ' ';

    end:
        continue;
    }

    clock_t endTime = clock();

    cout << "\n计算时间: " << endTime - startTime << endl;
}

int main() {
    allPrimes();
    return 0;
}