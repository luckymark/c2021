#include<iostream>
#include<windows.h>
using namespace std;
inline void putspace(const int &t){
    for (int i = 0;i < t;++i)putchar(' ');
}
const int length = 100;
const int cmdlength = 120;
char letter[length];
inline bool isWhite(const char &c){
    return c == ' ' || c == '\n' || c == '\r' || c == EOF;
}
inline void getLetter(){
    char c = ' ';
    while (isWhite(c = getchar()));
    int cnt = 0;
    letter[cnt++] = c;
    while (!isWhite(c = getchar()) && cnt < length - 1)letter[cnt++] = c;
    letter[cnt] = '\0';
}
inline void putLetter(){
    for (int i = 0;letter[i] != '\0';++i)
        putchar(letter[i]);
}
int now = 0;
bool dr = true;
int main(){
    printf("input a letter or word\n");
    getLetter();
    while (true){
        //system("cls");
        putchar('\r');
        putspace(now);
        putLetter();
        putchar(' ');
        if (dr)++now;
        else --now;
        if (now >= cmdlength || now <= 0)dr = !dr;
        Sleep(30);
    }
    return 0;
}