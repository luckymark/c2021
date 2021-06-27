#include <stdio.h>
#include <windows.h>
typedef struct linklist
{
    int Element;
    linklist *next;
} linklist; //创建链表
linklist *linkstart()
{
    linklist *Headnode = (linklist *)malloc(sizeof(linklist));
    if (Headnode == NULL)
        printf("stack over flow");
    Headnode->Element = 0;
    Headnode->next = NULL;
    return Headnode;
}
void linkcreate(linklist *Head, int num, int *element)
{
    linklist *Currentnode = Head;
    int i;
    for (i = 0; i < num; i++)
    {
        Currentnode->Element = element[i];
        Currentnode->next = (linklist *)malloc(sizeof(linklist));
        if (i != num - 1)
            Currentnode = Currentnode->next;
    }
    Currentnode->next = NULL;
}
void listprintf(linklist *Head, int num)
{
    linklist *Currentnode = Head;
    int i;
    for (i = 0; i < num; i++)
    {
        printf("Element %d is %d\n", i, Currentnode->Element);
        Currentnode = Currentnode->next;
    }
}
linklist *Changedir(linklist *Current)
{
    linklist *lastnode;
    if (Current->next != NULL)
    {
        lastnode = Changedir(Current->next);
    }
    else
    {
        lastnode = Current;
        return lastnode;
    }
    Current->next->next = Current;
    return lastnode;
}
linklist *listopposite(linklist *Head, int num)
{
    linklist *lastnode;
    lastnode = Changedir(Head);
    Head->next = NULL;
    return lastnode;
}
int checklist(linklist *Head, int num, int want)
{

    linklist *Currentnode = Head;
    int checkornot;
    for (int i = 0; i < num; i++)
    {
        if (Currentnode->Element == want)
        {
            printf("the position of the number %d you want is element %d\n do you want check next '%d' yes--1 no--0\n", want, i + 1, want);
            scanf("%d", &checkornot);
            if (checkornot == 1)
                continue;
            else
                return i + 1;
        }
        Currentnode = Currentnode->next;
    }
    printf("can't find this num\n");
    return 0;
}
int main()
{
    int num;
    printf("Make a new list,please input the numbers of elements of the list\n");
    scanf("%d", &num);
    linklist *Head;                                 //头指针
    int *element = (int *)calloc(num, sizeof(int)); //创建要输入的数组
    printf("please input the ordered list one by one\n");
    for (int i = 0; i < num; i++)
        scanf("%d", element + i);
    Head = linkstart();             //创建头指针
    linkcreate(Head, num, element); //存入链表

    int yesornot = 1;
    while (yesornot == 1)
    {
        printf("Now choose what you want to do.\n1.print the list\n2.Make the list opposite\n3.Find the element you want\n");
        int choose = 0;
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            listprintf(Head, num);
            break;
        case 2:
            Head = listopposite(Head, num);
            break;
        case 3:
        {

            int want;
            printf("please input the number you want\n");
            scanf("%d", &want);
            checklist(Head, num, want);
            break;
        }
        default:
            break;
        }
        printf("Do you want to continue yes--1 No-- 0\n");
        scanf("%d", &yesornot);
    }
    system("Pause");
    return 0;
}