#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;

typedef struct stores{
    char type[100];
    int number;
}stores;

stores goods[10005];
int kinds;

void InitStore();
void MenuStore();
void GetChoice();
void ShowStore();
void InStore();
void OutStore();
void Exit();

int main(){
    InitStore();
    MenuStore();
    return 0;
}

void InitStore(){
    char name[100];
    int num;
    freopen("store.txt","r",stdin);
    while(scanf("%s%d",name,&num)!=EOF){
        kinds++;
        strcpy(goods[kinds].type,name);
        goods[kinds].number=num;
    }
    freopen("CON","r",stdin);
    return;
}
void MenuStore(){
    system("cls");
    puts("This is the warehouse management system.");
    puts("Press \"1\" to show the stores in the warehouse.");
    puts("Press \"2\" to load the goods into the warehouse.");
    puts("Press \"3\" to take out the goods from the warehouse.");
    puts("Press \"4\" to exit the system.");
    GetChoice();
}

void GetChoice(){
    char ch=_getch();
    switch(ch){
        case '1':{
            ShowStore();
            break;
        }
        case '2':{
            InStore();
            break;
        }
        case '3':{
            OutStore();
            break;
        }
        case '4':{
            Exit();
            break;
        }
        default:{
            puts("Invalid input.");
            puts("Please choose again.");
            GetChoice();
            break;
        }
    }
}

void ShowStore(){
    system("cls");
    printf("Type     Number\n");
    for(int i=1;i<=kinds;i++){
        printf("%-10s%d\n",goods[i].type,goods[i].number);
    }
    puts("Press any buttom to back to menu");
    if(_getch())
    MenuStore();
}

void InStore(){
    system("cls");
    char name[100];
    int num;
    puts("Please input the name of the goods");
    scanf("%s",name);
    puts("Please input the number of the goods");
    scanf("%d",&num);
    int f=0;
    for(int i=1;i<=kinds;i++){
        for(int j=0;;j++){
            if(name[j]!=goods[i].type[j]){
                break;
            }
            else if(name[j]=='\0'&&goods[i].type[j]=='\0'){
                f=i;
            }
        }
        if(f){
            goods[i].number+=num;
            break;
        }
    }
    if(f==0){
        kinds++;
        goods[kinds].number=num;
        strcpy(goods[kinds].type,name);
    }
    puts("Load successfully!");
    puts("Press any buttom to back to menu");
    if(_getch())
    MenuStore();
}

void OutStore(){
    system("cls");
    char name[100];
    int num;
    puts("Please input the name of the goods");
    scanf("%s",name);
    puts("Please input the number of the goods");
    scanf("%d",&num);
    int f=0;
    for(int i=1;i<=kinds;i++){
        for(int j=0;;j++){
            if(name[j]!=goods[i].type[j]){
                break;
            }
            else if(name[j]=='\0'&&goods[i].type[j]=='\0'){
                f=i;
                break;
            }
        }
        if(f){
            goods[i].number-=num;
            break;
        }
    }
    if(f==0){
        puts("There is not this kind of goods!");
    }
    else if(goods[f].number==0){
        strcpy(goods[f].type,goods[kinds].type);
        goods[f].number=goods[kinds].number;
        kinds--;
        puts("Delete successfully!");
    }
    else if(goods[f].number>0){
        puts("Delete successfully!");
    }
    else{
        goods[f].number+=num;
        puts("There are not so many this kind of goods.");
        puts("This delete is invalid");
    }
    puts("Press any buttom to back to menu");
    if(_getch())
    MenuStore();
}

void Exit(){
    freopen("store.txt","w",stdout);
    for(int i=1;i<=kinds;i++){
        printf("%s %d\n",goods[i].type,goods[i].number);
    }
    exit(0);
}