#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// 获取标准输出（即控制台）的句柄
HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

// 光标移到特定位置
void gotoxy(int x, int y)
{
    COORD C;
    C.X = x;
    C.Y = y;
    // 利用控制台句柄设置光标移到特定位置
    SetConsoleCursorPosition(hStdout, C);
}

void runningLetter() {
    // 起始位置从0，0开始
    int sx = 0, sy = 0;
    // 获得当前的控制台的buffer 信息（包括高度和宽度）
    CONSOLE_SCREEN_BUFFER_INFO info;
    // flag 为true 时，表示字母从左到右移动，false则表示从右到左
    int flag = 1; // left -> right,
    while (1) {
        // 不断刷新控制台buffer 信息
        GetConsoleScreenBufferInfo(hStdout, &info);
        // 在输出之前先清空控制台
        system("cls");
        // 把光标移动至sx，sy
        gotoxy(sx, sy);
        // 打印字母
        printf("x");
        // 等待1 ms（可以自己设置
        Sleep(1);
        // 如果到边缘了，就切换flag
        if (sx == info.dwSize.X || (!flag && sx == 0)) flag = !flag;
        // 根据flag 获得下一次sx 的位置
        flag ? ++sx : --sx;
    }
}

int main() {
    runningLetter();
    return 0;
}
