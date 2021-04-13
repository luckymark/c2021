#include "dl_list_link.h"

void link_init(int val,int i, Linklist *node){
    Linklist *p=(Linklist*)malloc(sizeof(Linklist));
    p->order=i;
    if(node->pre==NULL){
        node->next=p;
        node->pre=p;
        p->pre=node;
        p->next=node;
        p->value=val;
    }
    else{
        node->pre->next=p;
        p->pre=node->pre;
        p->next=node;
        node->pre=p;
        p->value=val;
    }
}

void link_insert(int ord,int valin, Linklist *node){
    //printf("!!!!!!!!\n");
    Linklist *p=node->next;
    if(p==NULL){
        printf("the list is empty\n");
        return;
    }
    while(p->order!=ord){
        //printf("1111111!!!!!!!!\n");
        p=p->next;
        if(p->next==node&&p->order!=ord){
            printf("exceed the size of the link\n");
            return;
        }
    }
    Linklist *p2=(Linklist*)malloc(sizeof(Linklist));
    p2->order=ord;
    p2->value=valin;
    p2->pre=p->pre;
    p2->pre->next=p2;
    p2->next=p;
    p->pre=p2;
    while(p!=node){
        //printf("22222!!!!!!!!    %d\n",p->value);
        p->order=p->order+1;
        p=p->next;
    }
}

void link_delete(int valde, Linklist *node){
    Linklist *p=node->next;
    if(p==NULL){
        printf("the list is empty\n");
    }
    while(p->value!=valde){
        p=p->next;
        if(p->next==node&&p->value!=valde){
            printf("%d is not a element of the list.\n",valde);
            return;
        }
    }
    p->pre->next=p->next;
    p->next->pre=p->pre;
    p=p->next;
    while(p!=node){
        p->order=p->order-1;
        p=p->next;
    }
}

void link_find(int valfd, Linklist *node){
    Linklist *p=node->next;
    if(p==NULL){
        printf("the list is empty\n");
    }
    while(p->value!=valfd){
        p=p->next;
        if(p->next==node&&p->value!=valfd){
            printf("%d is not a element of the list.\n",valfd);
            return;
        }
    }
    printf("the location of %d is %d",valfd,p->order);
}

void link_show(Linklist *node){
    Linklist *p=node->next;
    if(p==NULL){
        printf("the list is empty\n");
    }
    while(p!=node){
        printf("%-5d %-5d\n",p->order,p->value);
        p=p->next;
    }
}