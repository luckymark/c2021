#include<bits/stdc++.h>
using namespace std;
struct node{
  int d;
  struct node *next;
};

void append(int x,struct node * head,struct node * tail)
{
  struct node * p;
  struct node * appendd;
  appendd = (struct node *)malloc(sizeof(struct node));
  p = head->next;
  if(p == NULL)
  {
    printf("error\n");
    return;
  }
  while(p->next != NULL)
  {
    p = p->next;
  }
  p->next = appendd;
  appendd->d = x;
  appendd->next = NULL;
  tail->next = appendd;
}
void build(int n,struct node * head,struct node* tail)
{
  for(int i=1;i<=n;i++){
    if(i == 1){
      int x;
      scanf("%d",&x);
      struct node * appendd;
      appendd = (struct node *)malloc(sizeof(struct node));
      appendd->d = x;
      head->next = appendd;
      tail->next = appendd;
      appendd->next = NULL;
    }
    else{
      int x;
      scanf("%d",&x);
      append(x,head,tail);
    }
  }
}
void find(struct node* da)
{
  struct node* pp = da;
  int i=1;
  while(pp->next!=NULL)
  {
    if(pp->next->d == 5)
    {
      printf("%d\n",i);
    }
    pp= pp->next;
    i++;
  }
  printf("-1\n");
}
void back(struct node* head,struct node * tail)
{
  struct node * p;
  p = head;
  tail = head;
  while(p->next != NULL)
  {
    struct node * p2;
    p2 = p->next;
    p->next = head;
    head = p;
    p = p2;
    if(p->next == NULL)
    {
      p->next = head;
      head = p;
      break;
    }
  }
}
int main()
{
  struct node * head,* tail;
  head = (struct node*)malloc(sizeof(struct node));
  head->next = NULL;
  tail = (struct node*)malloc(sizeof(struct node));
  tail->next = NULL;
  int n;
  scanf("%d",&n);
  build(n,head,tail);
  while(true)
  {
    printf("input 'a' to append a number to the tail of the linklist\n");
    printf("input 'b' to turn the linklist front to back\n");
    printf("input 'f' to find '5' in the linklist\n");
    printf("input 'o' exist\n");
    char a = getchar();
    if(a=='a'){
      int x;
      scanf("%d",&x);
      append(x,head,tail);
    }
    if(a=='b') back(head,tail);
    if(a=='f')
    {
      find(head);
      system("pause");
    }
    if(a=='o'){
      system("cls");
      break;
    }
    system("cls");
  }
  return 0;
}
