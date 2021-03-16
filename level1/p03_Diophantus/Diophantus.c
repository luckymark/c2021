#include <stdio.h>
int main(){
    double t;
    for (t = 5; ; ++ t) {
        if (t / 6 + t / 12 + t / 7 + 5 + t / 2 + 4 == t) {
            printf("%g\n",t - 4);
            break;
        }
    }
    system("pause");
    return 0;
}