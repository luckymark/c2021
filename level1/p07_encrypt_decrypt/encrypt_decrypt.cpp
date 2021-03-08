//This program models after Base64
#include<iostream>
#include<cstdio>
#include<ctime>
#include<conio.h>
using namespace std;
inline bool x(const char &c){
    return c != '\n' && c != '\r' && c != EOF;
}
inline char get(const bool &b){
    if (b)return 0;
    char c = getchar();
    return x(c) ? c : 0;;
}
inline char encrypt(const char &x){
    if (x == 31)return '+';
    if (x >= 26)return (rand() % 2) ? '0' + x - 26 : '9' - x + 26;
    return (rand() % 2) ? 'a' + x : 'Z' - x;
}
inline bool geten(unsigned long long &x, bool &b){
    x = b = 0;
    for (int i = 0;i < 5;++i){
        x = x << 7 | get(b);
        b |= (x & 0x7f) ? 0 : 1;
        if ((!i) && b)return false;
    }
    return true;
}
inline char decrypt(const char &x){
    if ('A' <= x && x <= 'Z')return 'Z' - x;
    if ('a' <= x && x <= 'z')return x - 'a';
    if ('0' <= x && x <= '4')return x - '0' + 26;
    if ('5' <= x && x <= '9')return '9' - x + 26;
    if (x == '+')return 31;
    return 0;
}
inline bool getde(unsigned long long &x){
    x = 0;
    for (int i = 0;i < 7;++i){
        x = x << 5 | decrypt(get(false));
        if (!x)return false;
    }
    return true;
}
bool ende;//(true=encrypt,false=decrypt)
unsigned long long t;
bool flag;
char buff[7];
int main(){
    srand(time(NULL));
    printf("please select the mode\n");
    printf("1.encrypt\n2.decrypt\n");
    while (true){
        if (kbhit()){
            char c = getch();
            if (c == '1')ende = true;
            else if (c == '2')ende = false;
            else continue;
            break;
        }
    }
    printf("please input the string(ASCII) in one line(mode:%s)\n", ende ? "encrypt" : "decrypt");
    if (ende){
        while (true){
            if (!geten(t, flag))break;
            for (int i = 0;i < 7;++i){
                buff[i] = encrypt(t & 0b11111);
                t >>= 5;
            }
            for (int i = 6;i >= 0;--i)putchar(buff[i]);
            if (flag)break;
        }
    }
    else{
        while (true){
            if (!getde(t))break;
            for (int i = 0;i < 5;++i){
                buff[i] = t & 0b1111111;
                t >>= 7;
            }
            for (int i = 4;i >= 0;--i)
                if (buff[i])putchar(buff[i]);
                else break;
        }
    }
    return 0;
}