#include "link.h"
int main()
{
    int n;
    while (1)
    {
        HomeScreen();
        importdata();
        scanf_s("%d", &n);
        fflush stdin;
        system("cls");
        switch (n)
        {
        case 1:ShowList();break;
        case 2:Input();break;
        case 3:Output();break;
        case 4:exit(0);break;
        }
        printf("�ٴ����г����밴1���˳������밴0");
        scanf_s("%d", &n);
        switch (n)
        {
        case 1:system("cls");break;
        case 2:exit(0);
        }
    }
    return 0;
}

