#include<iostream>
using namespace std;
int main(){
    for (int i = 1;i <= 9;++i)
        for (int j = 0;j <= 9;++j)
            for (int k = 0;k <= 9;++k){
                int num = i * 100 + j * 10 + k;
                if (i * i * i + j * j * j + k * k * k == num)
                    printf("%d = %d^3 + %d^3 +%d^3\n", num, i, j, k);
            }
    return 0;
}