/* 在 main 函数中创建一个单向链表；
1. 遍历该链表，依次现实各节点的 value；
1. 将该链表所有节点反序；
1. 在该链表中查找第一个值为 5 的节点，如果找到则返回该节点的序号，否则返回－1；
1. 查找下一个值为 5 的节点，返回值同上；*/

#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList{
    int elem;
    struct linkedList *next;
}link;

link* initLink(int n);
link* reverse(link* p,int n);
link* insertLink(link* p,int elem,int add);
int find(link* p,int n,int ele,int num);

int main(){
    int n;
    printf("请输入要创建的链表大小：\n");
    scanf("%d",&n);
    link* p = initLink(n+1);
    link* temp = p->next;
    for(int i = 1;i <= n;i ++){
        printf("请输入第%d号节点的元素值\n",i);
        scanf("%d",&temp->elem);
        temp = temp->next;
    }

    //逆序
    p = reverse(p,n);
    temp = p->next;
    printf("逆序输出成功：\n");
    for(int i = 1;i<=n;i++){
        printf("%d ",temp->elem);
        temp = temp->next;
    }
    printf("\n");

    //查找 5
    for(int num=1;num<=2;num++){
        int position = find(p,n,5,num);
        if(position!=-1)
            printf("第%d个值为5的节点序号(逆序后)是：%d\n",num,position);
        else
            printf("没有找到值为5的节点\n");
    }
    return 0;
}

//init linklist
link* initLink(int n){
    link* p = (link*)malloc(sizeof(link)); //创建一个头节点
    link* temp = p; //创建一个中间变量用于遍历链表
    for(int i = 1 ; i < n; i ++){
        link* a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

//add new element
link* insertLink(link* p,int elem,int add){
    link* temp = p; //创建临时节点，用于遍历
    link* c = (link*)malloc(sizeof(link));
    for(int i = 1;i < add;i ++){
        if(temp==NULL){
            printf("插入的位置无效\n");
            return p;
        }
        temp = temp->next;
    }
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;
    return p;
}

//reverse the linklist
link* reverse(link*p,int n){
    link* temp = p->next;
    link* newp = (link*)malloc(sizeof(link));
    newp->next = NULL;
    for(int i =1;i<=n;i++){
        insertLink(newp,temp->elem,1);
        temp = temp->next;
    }
    return newp;
}

//find the element
int find(link* p,int n,int ele,int num){
    link* temp = p->next;
    int x = 0; //记录找到的次数
    for(int i=1;i<=n;i++){
        if(temp->elem==ele){
            x++;
            if(x==num)
                return i;
        }
        temp = temp->next;
    }
    return -1;
}
