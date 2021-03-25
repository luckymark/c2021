/* �� main �����д���һ����������
1. ����������������ʵ���ڵ�� value��
1. �����������нڵ㷴��
1. �ڸ������в��ҵ�һ��ֵΪ 5 �Ľڵ㣬����ҵ��򷵻ظýڵ����ţ����򷵻أ�1��
1. ������һ��ֵΪ 5 �Ľڵ㣬����ֵͬ�ϣ�*/

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
    printf("������Ҫ�����������С��\n");
    scanf("%d",&n);
    link* p = initLink(n+1);
    link* temp = p->next;
    for(int i = 1;i <= n;i ++){
        printf("�������%d�Žڵ��Ԫ��ֵ\n",i);
        scanf("%d",&temp->elem);
        temp = temp->next;
    }

    //����
    p = reverse(p,n);
    temp = p->next;
    printf("��������ɹ���\n");
    for(int i = 1;i<=n;i++){
        printf("%d ",temp->elem);
        temp = temp->next;
    }
    printf("\n");

    //���� 5
    for(int num=1;num<=2;num++){
        int position = find(p,n,5,num);
        if(position!=-1)
            printf("��%d��ֵΪ5�Ľڵ����(�����)�ǣ�%d\n",num,position);
        else
            printf("û���ҵ�ֵΪ5�Ľڵ�\n");
    }
    return 0;
}

//init linklist
link* initLink(int n){
    link* p = (link*)malloc(sizeof(link)); //����һ��ͷ�ڵ�
    link* temp = p; //����һ���м�������ڱ�������
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
    link* temp = p; //������ʱ�ڵ㣬���ڱ���
    link* c = (link*)malloc(sizeof(link));
    for(int i = 1;i < add;i ++){
        if(temp==NULL){
            printf("�����λ����Ч\n");
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
    int x = 0; //��¼�ҵ��Ĵ���
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
