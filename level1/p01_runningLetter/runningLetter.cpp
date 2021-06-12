#include <windows.h>

#include <iostream>

using namespace std;

void runningLetter() {
    //输入字符或者字母
    string s;
    cin >> s;

    int x = 0, len = s.size();  // x为坐标

    //光标位置
    HANDLE hout;
    COORD pos;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = 0, pos.Y = 0;  //设置Y坐标(不变)

    //控制台窗口信息
    CONSOLE_SCREEN_BUFFER_INFO scr;

    //用于判断是否碰到右侧边界
    bool judge = false;

    DWORD result;

    while (true) {
        GetConsoleScreenBufferInfo(hout, &scr);  //每次刷新获取窗口大小
        if (x + len >= scr.dwSize.X)
            judge = true;
        else if (x <= 0)
            judge = false;

        pos.X = x;

        SetConsoleCursorPosition(hout, pos);  //设置光标位置
        cout << s;

        if (judge == false)
            ++x;
        else if (judge == true)
            --x;

        Sleep(50);  //设置刷新速度
        system("cls");
    }
    CloseHandle(hout);
}

int main() {
    runningLetter();
    return 0;
}