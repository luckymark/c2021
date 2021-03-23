#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("please input a num:");
    scanf("%d",&n);
    int *p;
    p=(int*)malloc(n*sizeof(int));
    if(p==NULL){
        printf("WRONG");
        return 0;
    }
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        p[i]=t;
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",p[i]);
    }
    free(p);
    return 0;
}