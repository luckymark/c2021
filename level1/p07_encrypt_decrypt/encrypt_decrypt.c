#include <stdio.h>
#include <stdlib.h>
char book[] = "18381048095";
typedef struct string {
    char * str;
    int length;
    int capacity;
} string;
void get_str(string * str);
void init_str(string * str);
void update(string * str);
void encrypt(string * str);
void decrypt(string * str);
void showStr(string * str);
int main(int argc, char const *argv[])
{
    printf("Please enter the letters:\n");
    string * str = (string *)malloc(sizeof(string));
    get_str(str);
    char ch;
    printf("Enter 'e' to encrypt it, 'd' to decrypt it and 'q' to quit.\n");
    while (ch = getchar()) {
        if (ch == 'q') break;
        else if (ch == 'e') encrypt(str);
        else if (ch == 'd') decrypt(str);
        else if (ch == '\n') continue;
        else {
            printf("Invalid input!\n");
            continue;
        }
        showStr(str);
    }
    return 0;
}
void showStr(string * str) {
    int i;
    for (i = 0; i < str->length; ++ i){
        putchar(str->str[i]);
    }
    putchar('\n');
}
void encrypt(string * str) {
    int i;
    for (i = 0; i < str -> length; ++ i) str -> str[i] += book[i % 11] - '0';
}
void decrypt(string * str) {
    int i;
    for (i = 0; i < str -> length; ++ i) str -> str[i] -= book[i % 11] - '0';
}
void get_str(string * str) {
    init_str(str);
    char ch;
    while (ch = getchar()) {
        if (ch == '\n') break;
        update(str);
        str->str[str->length++] = ch;
    }
}
void init_str(string * str) {
    str -> length = 0;
    str -> capacity = 10;
    str -> str = (char*)malloc(sizeof(char) * str -> capacity);
}
void update(string * str) {
    if (str -> length > str -> capacity - 3) {
        str -> capacity += str -> capacity / 2;

        char * p = (char*)malloc(sizeof(char) * str -> capacity);
        int i;
        for (i = 0; i < str -> length; ++ i)
            p[i] = str -> str[i];
        str -> str = p;
    }
}