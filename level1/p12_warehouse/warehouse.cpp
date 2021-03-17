#include <conio.h>
#include <cstdio>
#include <fstream>
#include <map>
#include <windows.h>
using namespace std;
map<string, int> store;
fstream fileStore;
void init();
void update();
void showMenu();
void showStore();
void editStore();
void wait();
int countWidth(int n);
char *format(int stringWidth, int numberWidth);
bool isWhite(char c) { return c == ' ' || c == '\n' || c == '\r'; }
int main() {
    printf("Loading data...\n");
    init();
    wait();
    update();
    return 0;
}
void init() {
    fileStore.open("ware.data", ios::in);
    if (!fileStore.is_open()) return;
    string productType;
    int productNumber;
    while (fileStore >> productType >> productNumber)
        store[productType] += productNumber;
    fileStore.close();
}
void update() {
    fileStore.open("ware.data", ios::out);
    for (map<string, int>::iterator i = store.begin(); i != store.end(); ++i)
        if (i->second) fileStore << i->first << " " << i->second << "\n";
    fileStore.close();
}
void showMenu() {
    system("cls");
    printf("1.Show store data\n");
    printf("2.in/out\n");
    printf("3.exit the program\n");
}
void showStore() {
    system("cls");
    printf("Here is the list of products\n");
    int maxStringLen = 0, maxNumberLen = 0;
    for (map<string, int>::iterator i = store.begin(); i != store.end(); ++i) {
        if (!i->second) continue;
        maxStringLen = max((int)i->first.size(), maxStringLen);
        maxNumberLen = max(countWidth(i->second), maxNumberLen);
    }
    for (map<string, int>::iterator i = store.begin(); i != store.end(); ++i)
        if (i->second) printf(format(maxStringLen, maxNumberLen), i->first.c_str(), i->second);
}
void wait() {
    showMenu();
    for (char kb = _getch();; kb = _getch())
        switch (kb) {
            case '2':; editStore();
            case '1':;
                showStore();
                printf("press any key to return");
                _getch();
                showMenu();
                break;
            case '3':; return;
        }
}
char *format(int stringWidth, int numberWidth) {
    char *s = new char[50];
    sprintf(s, "%c-%ds : %c0%dd\n", '%', stringWidth, '%', numberWidth);
    return s;
}
int countWidth(int n) {
    int cnt = 1;
    while (n /= 10)
        ++cnt;
    return cnt;
}
void editStore() {
    showStore();
    printf("Input the product and number(negative means out)\n");
    char *s = new char[100];
    int num;
    scanf("%s %d", s, &num);
    store[s] += num;
}