#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;

struct node_lists{
    string name;
    int num;
    bool operator == (const string &e){
        return (this->name == e);
    }
};
vector<node_lists>node_list;

void node_init(void);
void menu(void);
void get_choice(void);
void Print(void);
void Put_in(void);
void Catch_out(void);
void update(void);

int main(){
    node_init();
    menu();
    return 0;
}

void node_init(void){
    freopen("level1/p12_warehouse/node.in","r",stdin);
    int n;
    scanf("%d",&n);
    while(n--){
        node_lists x;
        cin>>x.name>>x.num;
        node_list.push_back(x);
    }
    fclose(stdin);
    freopen("CON","r",stdin);
}
void menu(void){
    system("cls");
    puts("\033[32mMenu:");
    puts("\033[33mPress 1 to show the warehouse");
    puts("Press 2 to put in");
    puts("Press 3 to catch out");
    puts("Press ESC to exit");
    get_choice();
}
void get_choice(){
    while(1){
        Sleep(20);
        if(kbhit()){
            switch(getch()){
                case '1':Print();break;
                case '2':Put_in();break;
                case '3':Catch_out();break;
                case 0X1B:update();exit(0);
            }
        }
    }
}
void Print(void){
    system("cls");
    puts("\033[32mid\tmodel\tamount\033[33m");
    for(int i=0;i<int(node_list.size());i++){
        cout<<i+1<<"\t"<<node_list[i].name<<"\t"<<node_list[i].num<<endl;
    }
    puts("Press enter to return to menu");
    while(getchar()!='\n');
    menu();
}
void Put_in(void){
    system("cls");
    puts("PUT IN");
    printf("Operand:");
    int n;
    scanf("%d",&n);
    puts("\033[32mmodel\tamount\033[33m");
    while(n--){
        node_lists x;
        cin>>x.name>>x.num;
        vector<node_lists>::iterator it;
        it=find(node_list.begin(),node_list.end(),x.name);
        if(it != node_list.end()){
            it->num+=x.num;
        }
        else{
            node_list.push_back(x);
        }
    }
    getchar();
    puts("Press enter to return to menu");
    while(getchar()!='\n');
    menu();
}
void Catch_out(void){
     system("cls");
    puts("CATCH OUT");
    printf("Operand:");
    int n;
    scanf("%d",&n);
    puts("\033[32mmodel\tamount\033[33m");
    while(n--){
        node_lists x;
        cin>>x.name>>x.num;
        vector<node_lists>::iterator it;
        it=find(node_list.begin(),node_list.end(),x.name);
        if(it != node_list.end()){
            if(it->num<=x.num)
                node_list.erase(it);
            else
                it->num-=x.num;
        }
        else{
            puts("Can't found this model");
        }
    }
    getchar();
    puts("Press enter to return to menu");
    while(getchar()!='\n');
    menu();
}
void update(void){
    freopen("level1/p12_warehouse/node.in","w",stdout);
    int n=node_list.size();
    printf("%d\n",n);
    for(int i=0;i<n;i++){
        cout<<node_list[i].name<<" "<<node_list[i].num<<endl;
    }
    fclose(stdout);
    freopen("CON","w",stdout);
}