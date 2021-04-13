#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
int MAX_LEVEL;
typedef struct node
{
public:
  int value;
  node *Next, *up, *down;
} Node;
node *create(int *data, int max, int size);
void initNode(Node *node);
void connect(Node *pre, Node *aft);
void print(Node *head);
void search(Node *head, int n);
void invert(Node *head, int n);
int main()
{
  cout << "Please put in the level." << endl;
  cin >> MAX_LEVEL;
  int size;
  cout << "Please put in the numbers of datas" << endl;
  cin >> size;
  cout << "Please put in the datas" << endl;
  int *data = (int *)malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++)
  {
    cin >> data[i];
  }
  node *head = create(data, MAX_LEVEL, size);
  /*  for (int i = 0; i < size; i++)
        {
          for (int j = i; j < size; j++)
          {
            if (data[i] > data[j])
            {
              int temp = data[i];
              data[i] = data[j];
              data[j] = temp;
            }
          }
        }
        for (int i = 0; i < size; i++)
        {
          cout << data[i] << endl;
        }
      */

  print(head);
  system("pause");
}
void invert(Node *head, int value)
{
  Node *NewNode = (Node *)malloc(sizeof(Node));
  initNode(NewNode);
  Node *p = head;
  Node *temp = head;
  while (p != nullptr)
  {
    temp = p;
    while ((p->Next) != nullptr)
    {
      if (p->value < value)
      {
        temp = p;
        p = (p->Next);
      }
    }
    //    NewNode = (temp->Next);
    //    (NewNode->Next) = p;
    //    NewNode->value = value;
    p = temp->down;
  }
  if (temp->Next == nullptr)
  {
    connect(temp, NewNode);
  }
  else
  {
    connect(NewNode, temp->Next);
    connect(temp, NewNode);
  }
}

void print(Node *head)
{
  Node *p = head;
  while (p->Next != NULL)
  {
    cout << p->value << " ";
    p = p->Next;
  }
  cout << endl;
}
/*Node *invert(Node *head)
{
  Node *p = head->Next, *pbefore = head;
  while (p->Next != NULL)
  {
    Node *ptemp = p;
    p = p->Next;
    ptemp->Next = pbefore;
    pbefore = ptemp;
  }
  p->Next = pbefore;
  head->Next = (Node *)malloc(sizeof(Node));
  head->Next->Next = NULL;
  return p->Next;
}
void search(Node *head, int goal)
{
  int n = 0;
  bool ok = true;
  Node *p = head;
  while (p->Next != NULL)
  {
    n = n + 1;
    if (p->value == goal)
    {
      ok = false;
      cout << n << " ";
    }
    p = p->Next;
  }
  if (ok)
  {
    cout << -1;
  }
  cout << endl;
}*/
void connect(Node *pre, Node *aft)
{
  Node *ppre = pre;
  Node *paft = aft;
  while (ppre != nullptr && paft != nullptr)
  {
    ppre->Next = paft;
    ppre = ppre->up;
    paft = paft->up;
  }
}
node *create(int *data, int max, int size)
{
  Node *head = (Node *)malloc(sizeof(Node));
  head->value = INT_MIN;
  head->up = nullptr;
  head->Next = nullptr;
  Node *pNode = head;
  for (int i = 0; i < max; i++)
  {
    Node *temp = (Node *)malloc(sizeof(Node));
    pNode->down = temp;
    pNode->Next = nullptr;
    temp->value = INT_MIN;
    temp->up = pNode;
    pNode = temp;
  }
  pNode->Next = nullptr;
  pNode->down = nullptr;

  //初始化头部
  for (int i = 0; i < size; i++)
  {
    invert(head, data[i]);
  }
  return head;
}
void initNode(Node *node)
{
  bool w = rand() % 2 == 1;
  int i = 0;
  node->Next = nullptr;
  Node *pNode = node;
  while (w && i < MAX_LEVEL)
  {
    Node *temp = (Node *)malloc(sizeof(Node));
    pNode->up = temp;
    temp->down = pNode;
    temp->Next = nullptr;
    pNode = temp;
    i++;
    srand(time(NULL));
    w = rand() % 2 == 1;
  }
  pNode->up = nullptr;
}