#include <cstdio>
#include <cstring>
#include <windows.h>
#include <algorithm>
using namespace std;


char str[]="sto NamelessOIer orz";

int main()
{
    int now=0,len=20,type=1;
    while(1)
    {
        system("cls");
        for(int i=1;i<=now;i++) printf(" ");
        for(int i=0;i<len;i++) printf("%c",str[i]);
        if(now==80) type=-1;
        now+=type;
        if(!now) type=1;
        Sleep(10);
    }
    return 0;
}
