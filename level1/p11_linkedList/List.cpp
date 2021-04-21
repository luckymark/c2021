#include<bits/stdc++.h>
using namespace std;

typedef struct link{
    int id;
    int value;
    link *next;
}link;

link *creat(int n);
void insert_end(link *head);
void print(link *head);
void insert(link *head,int n);
void Deletememory(link *head);
void Deletepoint(link *head,int n);
link *recreat(link *head);
void search(link *head);

int main(){
    link *head = NULL;
    puts("节点数：");
    int n;
    scanf("%d",&n);
    head = creat(n);
    print(head);
    puts("反序：");
    recreat(head);
    print(head);
    puts("查找5：");
    search(head);
    return 0;
}

link *creat(int n){
    link *head,*node,*end;
    head = (link *)malloc(sizeof(link));
    if(head==NULL){
        puts("error");
        exit(0);
    }
    end = head;
    for(int i=0;i<n;i++){
        node = (link *)malloc(sizeof(link));
        if(node==NULL){
            puts("error");
            exit(0);
        }
        scanf("%d %d",&node->id,&node->value);
        end->next=node;
        end=node;
    }
    end->next = NULL;
    return head;
}

void insert_end(link *head){
    link *p=head;
    while(p->next!=NULL){
        p = p->next;
    }
    link *end;
    end = (link *)malloc(sizeof(link));
    if(end==NULL){
        puts("error");
        exit(0);
    }
    scanf("%d %d",&end->id,&end->value);
    p->next=end;
    end->next=NULL;
}

void insert(link *head,int n){
    link *p=head;
    int i=1;
    p = p->next;
    while(i<n){
        p=p->next;
        if(p==NULL){
            puts("error");
            exit(0);
        }
        i++;
    }
    link *node;
    node = (link *)malloc(sizeof(node));
    if(node==NULL){
        puts("error");
        exit(0);
    }
    scanf("%d %d",&node->id,&node->value);
    link *nxt=p->next;
    p->next=node;
    node->next=nxt;
}

void print(link *head){
    link *p=head;
    p = p->next;
    int i=1;
    while(p!=NULL){
        printf("%d\t%d\t%d\t\n",i,p->id,p->value);
        i++;
        p = p->next;
    }
}

void Deletememory(link *head){
    link *p=head,*pr=NULL;
    while(p!=NULL){
        pr=p;
        p = p->next;
        free(pr);
    }
    puts("free succeed");
}

void Deletepoint(link *head,int n){
    int i=1;
    link *p= head->next;
    while(i<n-1){
        p=p->next;
        if(p->next==NULL){
            puts("error");
            exit(0);
        }
        i++;
    }
    link *node=p->next;
    p->next=node->next;
    free(node);
}

link *recreat(link *head){
    link *pl=NULL,*pr=NULL,*pt=NULL;
    if(head==NULL||head->next==NULL)
        return head;
    else{
        pl = head->next;
        pr=pl->next;
        head->next=NULL;
        pl->next=NULL;
        while(pr!=NULL){
            pt=pr->next;
            pr->next=pl;
            pl=pr;
            pr=pt;
        }
        free(pt);
        free(pr);
        head->next=pl;
        return head;
    }
}

void search(link *head){
    link *p=head->next;
    int i=1;
    while(p!=NULL){
        if(p->value==5){
            printf("%d %d %d\n",i,p->id,p->value);
            i++;
        }
        p=p->next;
    }
}