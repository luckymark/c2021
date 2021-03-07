#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
inline void putspace(const int &t){
    for (int i = 0;i < t;++i)putchar(' ');
}
int length = 100, cmdlength;
char letter[1000];
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
bool dr = true;//moving direction(true-right,false-left)
int main(){
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bInfo;
    GetConsoleScreenBufferInfo(hOutput, &bInfo);
    length = cmdlength = bInfo.dwSize.X - 1;//bInfo.dwSize.X(the width of cmd)
    printf("input a letter or word:");
    getLetter();
    printf("press any key to stop\n");
    while (true){
        putchar('\r');//use '\r' to get back to the start of line
        putspace(now);
        putLetter();
        if (!dr)putchar(' ');//put a space to cover the character
        if (dr)++now;
        else --now;
        if (now >= cmdlength - (int)strlen(letter) - 1 || now <= 0)dr = !dr;//change direction
        if (kbhit() && getch())break;//break if press a key
        Sleep(30);//30ms may be smooth enough
    }
    return 0;
}