#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<cstring>
using namespace std;

int num=0;

struct box{
	int m;
	string name;
}box;

struct box list[100];

void print_list();
void into_list(string nam,int number);
void out_list(string nam,int number);

int main(){
	int n,shu;
	string str;
    cout<<"��ʾ�����������1"<<endl; 
    cout<<"�������2"<<endl;
	cout<<"��������3"<<endl; 
	cout<<"�˳�����4"<<endl;
	while(scanf("%d",&n)){
		switch (n){
			case 1:
				print_list();
			    break;
			case 2:
				cout<<"��������Ʒ���ƺ�����,�ûس����"<<endl;
				cin>>str;
				cin>>shu;
				into_list(str,shu);
				break;
			case 3:
				cout<<"��������Ʒ���ƺ�����,�ûس����"<<endl;
				cin>>str;
				cin>>shu;
				out_list(str,shu);
				break;
			case 4:
			    return 0; 
		}
	}
	return 0; 
}

void print_list(){
    for(int i=0;i<num;i++){
    	cout<<list[i].name<<" "<<list[i].m;
	}
}

void into_list(string nam,int number){
	bool same;
	int here;
	same=0;
	for(int i=0;i<num;i++){
		if(list[i].name==nam){
			same=1;
			here=i;
		}
	}
	if(!same){
		list[num].name=nam;
		list[num].m=number;
		num++;
	} 
	else{
		list[here].m+=number;
	}
}

void out_list(string nam,int number){
	bool exist;
	int here;
	exist=0;
	for(int i=0;i<num;i++){
		if(list[i].name==nam){
			exist=1;
			here=i;
		}
	}
	if(exist){
		list[here].m-=number;
	}
	else{
		cout<<"���ڸ���ħ"; 
	}
}
