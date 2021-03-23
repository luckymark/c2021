#include <stdio.h>
#include <stdlib.h>


void main() {
    int n = 0;
    const int RIGHT_BORDER = 105, LEFT_BORDER = 0;
    char value = 1;
    while (1) {
        if (value) {
            for (int i = 0; i < n; i++) {
                printf(" ");
            }
            printf("Running Word");
            n++;
            system("cls");
            if (n == RIGHT_BORDER) {
                value = 0;
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                printf(" ");
            }
            printf("Running Word");
            n--;
            system("cls");
            if (n == LEFT_BORDER) {
                value = 1;
            }
        }
    }
}

