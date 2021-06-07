#include "link.h"
#include <cstdio>
#include <ctime>
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