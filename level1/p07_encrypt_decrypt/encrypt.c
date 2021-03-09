/*尝试凯撒加密与解密*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//加密
void encode(char str[], int n) {
    int i;
    char c;
    for (i = 0; i < strlen(str); ++i) {
        c = str[i];
        if (str[i] >= 'A' && str[i] <= 'Z') {
            if (c + n % 26 <= 'Z') {
                str[i] = (char)(c + n % 26);
            }
            else {
                str[i] = (char)(c + n % 26 - 26);
            }
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            if (c + n % 26 <= 'z') {
                str[i] = (char)c + n % 26;
            }
            else {
                str[i] = (char)c + n % 26 - 26;
            }
        }
        else {
            str[i] = c;//不是字母，不加密
        }
    }
    printf("\nAfter encode: \n");
    puts(str);
}

//解密
void decode(char str[], int n) {
    int i;
    char c;
    for (i = 0; i <= strlen(str); ++i) {
        c = str[i];
        if (str[i] <= 'z' && str[i] >= 'a') {
            if (c - n % 26 > 'a') {
                str[i] = (char)(c - n % 26);
            }
            else {
                str[i] = (char)(c - n % 26 + 26);
            }
        }
        else if (str[i] <= 'Z' && str[i] >= 'A') {
            if (c - n % 26 > 'A') {
                str[i] = (char)(c - n % 26);
            }
            else {
                str[i] = (char)(c - n % 26 + 26);
            }
        }
        else {
            str[i] = c;
        }
    }
    printf("\nAfter decode: \n");
    puts(str);
}


int main() {
    char str[50];
    int k, q = 1;
    int n,c;
    while (q) {
        system("cls");
        printf("Please enter your word:\n");
        scanf_s("%s", str,50);
        printf("Please set the encode function: \n");
        scanf_s("%d", &n);
        printf("-----------------\n");
        printf("1: Encryption\n");
        printf("2: Decryption\n");
        printf("-----------------\n");
        printf("\nPlease choose: ");
        scanf_s("%d", &k);
        if (k == 1) {
            encode(str, n);
        }
        else if (k == 2) {
            decode(str, n);
        }

        printf("Do you want to quit (1/0): \n");
        scanf_s("%d", &c);
        if (c == 1) {
            q = 0;
        }
    }
    return 0;

}

