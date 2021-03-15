#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
#define maxn 100001

struct Goods
{
    char name[100];
    int num, price;
    inline void print()
    {
        if (num == 0)
            return;
        printf("%s", name);
        printf("\n  number:%d\n  price:%d\n", num, price);
    }
    inline void in()
    {
        int x;
        printf("how many do you want to put in:");
        scanf("%d", &x);
        num += x;
    }
    inline void out()
    {
        int x;
        printf("how many do you want to take out:");
        scanf("%d", &x);
        if (num - x >= 0)
            num -= x;
        else
            printf("error! there is not so many staff\n");
    }
    inline void create(char *s)
    {
        for (int i = 0; i < strlen(s); ++i)
            name[i] = s[i];
        printf("it's a new type, please input the number:");
        scanf("%d", &num);
        printf("please input the price:");
        scanf("%d", &price);
        printf("successfully reserved!\n");
    }
    inline bool read()
    {
        num = price = 0;
        if (scanf("%s", &name) == EOF)
            return false;
        char c = getchar();
        while (c < '0' || c > '9')
            c = getchar();
        while (c >= '0' && c <= '9')
        {
            num = (num << 1) + (num << 3) + c - '0';
            c = getchar();
        }
        while (c < '0' || c > '9')
            c = getchar();
        while (c >= '0' && c <= '9')
        {
            price = (price << 1) + (price << 3) + c - '0';
            c = getchar();
        }
        return true;
    }
};
Goods g[maxn];

int tot = 0;

void read_list()
{
    freopen("in.txt", "r", stdin);
    tot = 0;
    while (g[++tot].read())
        ;
    tot--;
    fclose(stdin);
    freopen("CON", "r", stdin);
}

void print_list()
{
    freopen("in.txt", "w", stdout);
    for (int i = 1; i <= tot; ++i)
        g[i].print();
    fclose(stdout);
    freopen("CON", "w", stdout);
    printf("\n");
    for (int i = 1; i <= tot; ++i)
        g[i].print();
}

int find_item(char *c)
{
    for (int i = 1; i <= tot; ++i)
    {
        if (strlen(c) != strlen(g[i].name))
            continue;
        bool comp = true;
        for (int j = 0; j < strlen(g[i].name); j++)
            if (c[j] != g[i].name[j])
                comp = false;
        if (comp)
            return i;
    }
    return 0;
}

int main()
{
    read_list();
    while (1)
    {
        printf("\n");
        cout << "The operation list:" << endl
             << "1:list" << endl
             << "2:in" << endl
             << "3:out" << endl
             << "4:quit" << endl;
        int a;
        scanf("%d", &a);
        if (a == 1)
        {
            read_list();
            print_list();
        }
        if (a == 2)
        {
            printf("please type the name:");
            char s[100];
            scanf("%s", &s);
            int i = find_item(s);
            if (i)
                g[i].in();
            else
                g[++tot].create(s);
            print_list();
        }
        if (a == 3)
        {
            printf("please type the name:");
            char s[100];
            scanf("%s", &s);
            int i = find_item(s);
            if (i)
                g[i].out();
            else
                printf("error! there's no such staff!\n");
            print_list();
        }
        if (a == 4)
        {
            print_list();
            printf("all the data has been reserved!\n");
            Sleep(1500);
            break;
        }
    }
    return 0;
}