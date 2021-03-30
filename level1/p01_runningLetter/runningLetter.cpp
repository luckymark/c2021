/*
### ��Ŀ�����ܵ���ĸ

### ����Ҫ��

1. ��console�����һ����ĸ���򵥴ʣ�
1. ʹ����ĸ�򵥴ʣ���һ���ٶȴ��������˶�
1. ��������Ļ�߽�ʱ�����˶�


*/
#include<stdio.h>
#include<windows.h>

int GetCMDWeight(HANDLE,CONSOLE_SCREEN_BUFFER_INFO);
void ShowLetter(HANDLE,int,int);
void RunLetter(HANDLE,int,char*);

int main(){
    //��ʼ��
    HANDLE HCOut=GetStdHandle(STD_OUTPUT_HANDLE);//https://docs.microsoft.com/en-us/windows/console/scrolling-a-screen-buffer-s-window
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    int CMDLen = GetCMDWeight(HCOut,CSBI);

    //�ֶ��趨���ֵ
    char Word[16]={0};
    scanf("%s", Word);
    system("cls");

    //��ʼrunning
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