#include <stdio.h>
void hanoi(int n,char origin,char medium,char dest) {
    if (n == 1) {
        printf("%c -> %c\n", origin, dest);
        return;
    }
    hanoi(n-1,origin,dest,medium);
    printf("%c -> %c\n", origin, dest);
    hanoi(n-1,medium,origin,dest);
}
int main() {
    int n = 3;
    hanoi(n,'A','B','C');
    return 0;
}