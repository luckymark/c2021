#include <cstdio>
#include <ctime>
#include <iostream>
using namespace std;
template <typename T>
struct node {
    node *nex;
    T value;
    node(node *x, T v) : nex(x), value(v) {}
    node(T v) : value(v) { nex = NULL; }
};
template <typename T>
struct list {
    node<T> *s, *t;
    list() { s = t = NULL; }
    list(node<T> *x) : s(x), t(x) {}
    node<T> *begin() { return s; }
    void reverse(node<T> *x, node<T> *pre) {
        if (x->nex)
            reverse(x->nex, x);
        x->nex = pre;
    }
    void reverse() {
        reverse(s, NULL);
        swap(s, t);
    }
    node<T> *insert(node<T> *x, T v) {
        if (!x) {
            x = new node<T>(v);
            return x;
        }
        node<T> *y = new node<T>(x->nex, v);
        x->nex = y;
        if (x == t)
            t = y;
        return y;
    }
    node<T> *insert(T v) {
        if (!t) {
            s = t = new node<T>(v);
            return t;
        }
        node<T> *y = new node<T>(v);
        t->nex = y;
        return t = y;
    }
    node<T> *find(T v) {
        for (node<T> *i = this->begin(); i; i = i->nex)
            if (i->value == v)
                return i;
        return NULL;
    }
    node<T> *find(node<T> *x, T v) {
        for (node<T> *i = x; i; i = i->nex)
            if (i->value == v)
                return i;
        return NULL;
    }
    int indexof(node<T> *x) {
        int cnt = 0;
        for (node<T> *i = this->begin(); i; i = i->nex)
            if (i == x)
                return cnt;
            else
                ++cnt;
        return -1;
    }
};
int main() {
    srand(time(NULL));
    list<int> *l = new list<int>;
    for (int i = 0; i < 100; ++i)
        l->insert(i);
    l->reverse();
    node<int> *five = l->find(5);
    printf("%d\n", l->indexof(five));
    while (five) {
        five = l->find(five->nex, 5);
        printf("%d\n", l->indexof(five));
    }
    return 0;
}