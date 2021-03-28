#include<stdio.h>
#include "linkedList.h"
int main()
{
    List list;
    int number;
    int isfound;
    Node* head = NULL;
    list.head = NULL;
    do
    {
        scanf_s("%d", &number);
        add(&list,number);
    } while (number != -1);
    reverse(&list);
    isfound = search(&list, 5);
    isfound = searchAgain(&list, isfound, 5);
    //deleteNode(&list, 5);
    //isfound=search(&list, 5)+1;//方法二
    freeList(&list);

    return 0;

}

void add(List* plist, int number)
{
    if (number != -1)
    {
        //add a new node
        Node* p = (Node*)malloc(sizeof(Node));
        p->value = number;
        p->next = NULL;
        //find the last
        plist-> tail = plist->head;
        if (plist->tail)
        {
            while (plist->tail->next)
                plist->tail = plist->tail->next;//last和last->next都是指向Node的指针，last指向下一个
        //attach     
            plist->tail->next=p;
        }
        else
            plist->head = p;
    }
}


int search(List* plist, int aim)
{
    int i=0;
    Node* p;
    for (Node* p = plist->head;p ;p = p->next)
    {
        if (p->value == aim)
        {
            printf("The sequence of aimed node is %d(from 0)\n", i);
            return i;
            break;
        }
        i++;
    }
        return-1;
}

void deleteNode(List* plist,int number)
{
    Node* p;
    Node* q;
    for (p = plist->head,q=NULL;p;p = p->next,q=p)
    {
        if (q)
            plist->head = p->next;
        else 
        {
            if (number == p->value)
            {
                q = p->next;
                free(p);
            }
        }
    }
}

void reverse(List* plist)
{
    Node* p;
    Node* q;
    Node* r;
    plist->tail = plist->head;
    p = plist->head;
    q = NULL;
    do
    {
        r = p->next;
        p->next = q;
        q = p;
        p = r;
    } while (p->next);
    p->next = q;
    plist->head = p;
    for (p = plist->head; p; p = p->next)
        printf("%d\t", p->value);
}

void reverse(List* plist)
{   
    Node* p;
    plist->tail->next = plist->head;
    p = plist->head;
    plist->head = plist->head->next;
    p = NULL;
}



int searchAgain(List* plist,int isfound,int aim)
{
    Node* p;
    p = plist->head;
    int i;
    for (i = 0; i <= isfound; i++)
        p = p->next;
    for (i;p;i++,p=p->next)
    {
        if (p->value == aim)
        {
            printf("The sequence of the next aimed node is %d(from 0)\n", i);
            return i;
            break;
        }
    }
}
void freeList(List* plist)
{
    Node* p;
    Node* q;
    for (p = plist->head;p;p = q)
    {
        q = p->next;
        free(p);
    }
}