// all the value are randomly created within the range of (0,12)
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
const int n = 10;
struct Node
{
    int val, code;
    Node *nex;
};
Node *root, *t;
inline void create_Node(int num)
{
    Node *p;
    p = new Node;
    p->val = rand() % 13;
    p->nex = NULL;
    p->code = num;
    t->nex = p;
    t = p;
}
void Inverse(Node *p)
{
    if (p->nex == NULL)
    {
        root = p;
        return;
    }
    Inverse(p->nex);
    p->nex->nex = p;
}
int main()
{
    srand(time(NULL));
    t = root = new Node;
    root->val = rand() % 13;
    root->code = 0;
    for (int i = 1; i < n; ++i)
        create_Node(i);
    t = root;
    cout << "the initial linklist:" << endl;
    while (t != NULL)
    {
        cout << t->code << ':' << t->val << ' ';
        t = t->nex;
    }
    cout << endl
         << endl;
    t = root;
    Inverse(t);
    t->nex = NULL;
    t = root;
    cout << "the inversed linklist:" << endl;
    while (t != NULL)
    {
        cout << t->code << ':' << t->val << ' ';
        t = t->nex;
    }
    cout << endl;
    bool found = false;
    cout << "the code of Node with the value of 5 is:";
    t = root;
    while (t != NULL)
    {
        if (t->val == 5)
        {
            found = true;
            cout << t->code << ' ';
        }
        t = t->nex;
    }
    if (!found)
        cout << 1;
    cout << endl
         << endl;
    return 0;
}