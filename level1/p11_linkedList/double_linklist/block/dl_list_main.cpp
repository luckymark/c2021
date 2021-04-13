#include "dl_list_link.h"
using namespace std;

int main(){
    Linklist *node=(Linklist*)malloc(sizeof(Linklist));
    node->pre=NULL;
    node->next=NULL;
    node->order=0;
    printf("Please input the size of the list:\n");
    int size;
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
        int val;
        scanf("%d",&val);
        link_init(val,i,node);
    }
    puts("input 1 to insert");
    puts("input 2 to delete");
    puts("input 3 to find");
    puts("input 4 to show all the elements");
    puts("input 5 to exit");
    while(true){
        int choice;
        scanf("%d",&choice);
        switch(choice){
        case 1:{
            int ord,valin;
            scanf("%d%d",&ord,&valin);
            link_insert(ord,valin,node);
            break;
        }
        case 2:{
            int valde;
            scanf("%d",&valde);
            link_delete(valde,node);
            break;
        }
        case 3:{
            int valfd;
            scanf("%d",&valfd);
            link_find(valfd,node);
            break;
        }
        case 4:{
            link_show(node);
            break;
        }
        case 5:{
            exit(0);
            break;
        }
        default:{
            puts("Invalid input");
        }
    }
    }
    return 0;
}