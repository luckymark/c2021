#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;
int main() {
    HANDLE hOut;
    CONSOLE_SCREEN_BUFFER_INFO a;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hOut, &a);
    int length_of_console = a.dwSize.X;
    int flag = 0; // symbolize whether 'a' has reached the two sides
    while(1){
        for(int i=0;i<length_of_console;i++){
            for (int j=0;j<i;j++)cout << " ";
            cout << "A";
            Sleep(30);
            if (i == length_of_console - 1) flag = 1; // so that 'a' could turn left
            if (i == 0)  flag = 0;
            if (flag) i -= 2;
            system("cls");
        }
    }
    system("pause");
    return 0;
}

