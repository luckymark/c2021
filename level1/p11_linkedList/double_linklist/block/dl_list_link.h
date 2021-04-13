#include<bits/stdc++.h>
typedef struct Linklist{
    int value;
    int order;
    Linklist *pre,*next;
}Linklist;

void link_init(int val,int i, Linklist *node);
void link_insert(int ord,int valin, Linklist *node);
void link_delete(int valde, Linklist *node);
void link_find(int valfd, Linklist *node);
void link_show(Linklist *node);