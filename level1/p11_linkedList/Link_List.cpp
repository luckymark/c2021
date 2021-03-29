#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
	int date;
	struct Node* next;
};

Node* Node_create()
{
	int n = 0;
	Node* head, * p1, * p2;
	p1 = p2 = new Node;
    cin >> p1->date;
    head = NULL;
    while(p1->date!=0)
    {
        if(n==0)
        {
            head = p1;
            n++;
        }
        else
        {
            p2->next = p1;
            p2 = p1;
            p1 = new Node;
            cin >> p1->date;
            n++;
        }
        p2->next = NULL;
    }
    return head;
}

void insert(Node* head, int p, int x)
{
    Node *tmp = head;
    for(int i = 0;i<p;i++)
    {
        if(tmp==NULL)
            return;
        if(i<p-1)
            tmp = tmp->next;
    }
    Node *tmp2 = new Node;
    tmp2->date = x;
    tmp2->next = tmp->next;
    tmp->next = tmp2;
}

Node* upside_down(Node*head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node *tmp, *p;
    tmp = p = NULL;
    tmp = head->next;
    while(tmp->next!=NULL)
    {
        p = tmp->next;
        tmp->next = p->next;
        p->next = head->next;
        head->next = p;
    }
    return head;
}

int main()
{
    Node *head = Node_create();
    Node *upside_down_head = upside_down(head);
    Node *p = upside_down_head->next;
    int i = 1;
    while(p!=NULL)
    {
        if(p->date==5)
        {
            printf("Á´±íÐòºÅÎª£º");
            printf("%d\n", i);
        }
        i++;
        p = p->next;
    }
    return 0;
}