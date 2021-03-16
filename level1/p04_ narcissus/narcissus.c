#include <stdio.h>
int is_narcissus(int x){
    int a = x / 100;
    int c = x % 10;
    int b = (x - a * 100 - c) / 10;
    if (x == a * a * a + b * b * b + c * c * c)
    return 1;
    else return 0;
}
int main(){
    int i;
    for (i = 100; i <= 999; ++ i) {
        if (is_narcissus(i)) printf("%d\n",i);
    }
    system("pause");
    return 0;
}