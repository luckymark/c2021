#include<bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;

#define gc c=getchar()
#define r(x) read(x)
#define ll long long

template<typename T>
inline void read(T&x){
	x=0;T k=1;char gc;
	while(!isdigit(c)){if(c=='-')k=-1;gc;}
	while(isdigit(c)){x=x*10+c-'0';gc;}x*=k;
}

const int N=1e3+7;

inline void Save();

char type[N];

map<string,int>ID;
int Count[N];
string Type[N];

int tot;

inline void Init(){
	freopen("Data.txt","r",stdin);
	int count;
	while(scanf("%s%d",type,&count)!=EOF){
		ID[type]=++tot;
		Type[tot]=type;
		Count[tot]=count;
	}
	freopen("CON", "r", stdin);
	system("mode con cols=60 lines=20");
}

inline void Save(){
	freopen("Data.txt","w",stdout);
	for(int i=1;i<=tot;++i){
		if(Count[i]){
			for(int j=0;j<Type[i].length();++j){
				putchar(Type[i][j]);
			}
			printf("\n%d\n",Count[i]);
		}
	}
	freopen("CON", "w", stdout);
}

inline void Print(){
	system("cls");
	printf("There are %d goods in total\n",tot);
	for(int i=1;i<=tot;++i){
		if(Count[i]){
			for(int j=0;j<Type[i].length();++j){
				putchar(Type[i][j]);
			}
			printf(":%d\n",Count[i]);
		}
	}
}

inline void Inbound(){
	system("cls");
	puts("Please input the type and count of the goods:");
	int count;
	scanf("%s%d",type,&count);
	if(count<0){
		puts("The count is wrong.");
		return ;
	}
	if(ID[type]){
		Count[ID[type]]+=count;
	}
	else {
		ID[type]=++tot;
		Type[tot]=type;
		Count[tot]=count;
	}
	puts("Succeed");
}

inline void Outbound(){
	system("cls");
	puts("Please input the type and count of the goods:");
	int count;
	scanf("%s%d",type,&count);
	if(count<0){
		puts("The count is wrong.");
		return ;
	}
	if(ID[type]){
		if(Count[ID[type]]<count){
			puts("Failed!\nOutbounding more than have stored.");
		}
		else {
			Count[ID[type]]-=count;
			puts("Succeed");
		}
	}
	else {
		puts("Failed!\nGoods not find.");
	}
}

int GetChoice(){
    while(1){
    	Sleep(20);
        if(_kbhit()){
            switch(_getch()){
            	case '1':return 1;
            	case '2':return 2;
            	case '3':return 3;
            	case 27:Save(),exit(0);
            }
        }
    }
}

inline void Menu(){
	system("cls");
	puts("\033[33mWelcome to the Manage System");
	while(1){
		puts("Press [ 1 ] to show the list of goods");
		puts("Press [ 2 ] to inbound goods");
		puts("Press [ 3 ] to outbound goods");
		puts("Press [ ESC ] to exit");
		switch(GetChoice()){
			case 1:Print();break;
			case 2:Inbound();break;
			case 3:Outbound();break;
		}
		puts("\nPress [ Enter ] to continue");
		while(1){
	    	Sleep(20);
	        if(_kbhit())break;
	    }
		system("cls");
	}
}

int main(){
	Init();
	Menu();
	return 0;
}