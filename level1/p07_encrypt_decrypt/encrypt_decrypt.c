#include <stdio.h>
#include <stdlib.h>
typedef struct string {
    char * str;
    int length;
    int capacity;
} string;
void get_str(string * str);
void init_str(string * str);
void update(string * str);
int main(int argc, char const *argv[])
{
    string str;
    get_str(&str);
    int i;
    for (i = 0; i < str.length; ++ i){
        putchar(str.str[i]);
    } 
    return 0;
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