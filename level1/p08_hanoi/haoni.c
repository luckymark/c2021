#include <stdio.h>
int m = 0;
void move(int disk, char A, char C) {
    m++;
    printf("第 %d 次移动： 将 %d 号圆盘从 %c 移动到 %c\n", m, disk, A, C);
}
void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        move(n, A, C);
    }
    else {
        hanoi(n - 1, A, C, B);
        move(n, A, C);
        hanoi(n - 1, B, A, C);
    }
}

int main() {
    char A = 'A';
    char B = 'B';
    char C = 'C';
    int disks;
    printf("请输入圆盘的个数\n");
    scanf("%d", &disks);
    hanoi(disks, A, B, C);
    return 0;
}

