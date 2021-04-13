#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
string getmode();
typedef struct node
{
  int value;
  struct node *Next;
} Node;
void print(Node *head);
void search(Node *head, int n);
void add(Node *head);
Node *invert(Node *head);
int main()
{
  Node *head = (Node *)malloc(sizeof(Node));
  head->Next = NULL;
  while (1)
  {
    string input = getmode();
    if (input == "1")
    {
      add(head);
    }
    else if (input == "2")
    {
      print(head);
    }
    else if (input == "3")
    {
      head = invert(head);
    }
    else if (input == "4")
    {
      int n;
      cout << endl
           << "please put in the number you want to search" << endl;
      cin >> n;
      search(head, n);
    }
    else if (input == "5")
    {
      break;
    }
    else
    {
      cout << "please put in a correct number" << endl;
    }
  }
  system("pause");
  return 0;
}
void add(Node *head)
{
  int num;
  Node *p = head;
  while (p->Next != NULL)
  {
    p = p->Next;
  }
  cout << "please put in the value" << endl;
  cin >> num;
  p->Next = (Node *)malloc(sizeof(Node));
  p->value = num;
  p = p->Next;
  p->Next = NULL;
}

string getmode()
{
  cout << endl
       << endl
       << "What do you want?(please put in the number in front of the options)" << endl
       << "1.add a node to the end" << endl
       << "2.Print all nodes" << endl
       << "3.Arrange all nodes in inverted order" << endl
       << "4.Search nodes with a certain value" << endl
       << "5.Exit" << endl;
  string input;
  cin >> input;
  return input;
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
Node *invert(Node *head)
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
}