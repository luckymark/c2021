#include <iostream>
using namespace std;
int digit[5]; // record every digit of the number
int main() {
    for(int i = 100;i < 1000;i++){
        int tmp = i;
        for(int j = 1;j <= 3;j++){
            digit[j] = tmp % 10;
            tmp /= 10;
        }
        int i0 = digit[1] * digit[1] * digit[1];
        int i1 = digit[2] * digit[2] * digit[2];
        int i2 = digit[3] * digit[3] * digit[3];
        if(i == i0 + i1 + i2) cout << i << endl;
    }
    return 0;
}
