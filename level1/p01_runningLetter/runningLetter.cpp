/*
### 题目：奔跑的字母

### 功能要求：

1. 在console上输出一个字母（或单词）
1. 使该字母或单词，按一定速度从左至右运动
1. 当遇到屏幕边界时反向运动


*/
#include<stdio.h>
#include<windows.h>

int GetCMDWeight(HANDLE,CONSOLE_SCREEN_BUFFER_INFO);
void ShowLetter(HANDLE,int,int);
void RunLetter(HANDLE,int,char*);

int main(){
    //初始化
    HANDLE HCOut=GetStdHandle(STD_OUTPUT_HANDLE);//https://docs.microsoft.com/en-us/windows/console/scrolling-a-screen-buffer-s-window
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    int CMDLen = GetCMDWeight(HCOut,CSBI);

    //手动设定相关值
    char Word[16]={0};
    scanf("%s", Word);
    system("cls");

    //开始running
    while(TRUE)
        RunLetter(HCOut, CMDLen, Word);

    system("pause");
    return 0;
}

int GetCMDWeight(HANDLE HCOut,CONSOLE_SCREEN_BUFFER_INFO CSBI){
    GetConsoleScreenBufferInfo(HCOut,&CSBI);//https://docs.microsoft.com/en-us/windows/console/getconsolescreenbufferinfo
    int X = (int)CSBI.dwSize.X;//https://docs.microsoft.com/en-us/windows/console/coord-str
    return X;
}

void ShowLetter(HANDLE HCOut,int posx,char* Word){
    COORD pos = {(SHORT)posx, 1};
    SetConsoleCursorPosition(HCOut, pos);
    printf("%s",Word);
    Sleep(40);
    system("cls");
}

void RunLetter(HANDLE HCOut,int len,char* Word){
    int i = 0, WordLen = strlen(Word);
    for (; i < len-WordLen;i++)
        ShowLetter(HCOut,i,Word);
    for (; i > 0;i--)
        ShowLetter(HCOut,i,Word);
}