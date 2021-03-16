#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node * next;
    int val;
} * node;
node head,point5;
int num;
char ch;
int cnt = 0,endflag = 0;
void reverse(node n);
void show();
void add(int x);
void init();
int main() {
    init();
    printf("Please enter:\n\tq to quit,\n\tc to create\n\tn to get next order of 5\n\tr to reverse\n");
    while (ch = getchar()) {
        putchar('\n');
        if (ch == 'q') break;//退出
        else if (ch == 'n') printf("%d",next5());//下一个5
        else if (ch == 'c') {//创建
            printf("Please enter several numbers:\n");
            init();
            do {
                scanf("%d",&num);
                add(num);
            }
            while (getchar() != '\n');
            printf("We create:\n");
            show();
        }
        else if (ch == 'r') {
            reverse(head->next);
            show();
        }
    }
    // show();
}
void init() {
    point5 = NULL;
    endflag = 0;
    cnt = 0;
    head = (node)malloc(sizeof(*head));
    head->next = NULL;
    head->val = 0;
}
void add(int x) {
    node p = head;
    while (p->next != NULL) p = p->next;
    node n_p = (node)malloc(sizeof(*n_p));
    n_p->next = NULL;
    n_p->val = x;
    p->next = n_p;
}
void show() {
    putchar('\n');
    node p = head->next;
    while (p != NULL) {
        printf("%d\t",p->val);
        p = p->next;
    }
    putchar('\n');
}
void reverse(node n) {
    if (!n) return;
    //如果递归到n是最后一个节点
    if (!n->next) {
        head -> next = n;
        return;
    } 
    node next = n -> next;
    if (n == head -> next) n -> next = NULL; //构造尾节点
    reverse(next);
    next -> next = n;
}
int next5() {
    if (endflag) return -1;
    if (!point5) point5 = head;
    point5 = point5 -> next;
    cnt += 1;
    while (point5 && point5 -> val != 5) cnt ++, point5 = point5 -> next;
    if (!point5) {
        endflag = 1;
        return -1;
    }
    else return cnt;
}