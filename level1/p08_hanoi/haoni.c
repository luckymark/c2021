#include <stdio.h>
int m = 0;
void move(int disk, char A, char C) {
    m++;
    printf("�� %d ���ƶ��� �� %d ��Բ�̴� %c �ƶ��� %c\n", m, disk, A, C);
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
    printf("������Բ�̵ĸ���\n");
    scanf("%d", &disks);
    hanoi(disks, A, B, C);
    return 0;
}

