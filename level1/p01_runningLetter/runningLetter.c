#include <stdio.h>
#include <stdlib.h>

void main() {
    int n = 0;
    char value = 1;//value为1时向右移动，否则向左移动 
    while (1) {
        if (value) {
            for (int i = 0; i < n; i++) {
                printf(" ");
            }
            printf("Running Word");
            n++;
            system("cls");//清屏 
            if (n == 105) {
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
            if (n == 0) {
                value = 1;
            }
        }
    }
}
