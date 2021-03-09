#include<bits/stdc++.h>
#include<cstring>
#include<windows.h>
using namespace std;
int main()
{
	string s="x";
    while(true){
        for(int i=1;i<=30;i++){
            cout<<s;
            Sleep(100);
            system("cls");
            string k=" ";
            s=k.append(s);
        }
        for(int i=1;i<=30;i++){
            s.erase(s.begin());
            cout<<s;
            Sleep(100);
            system("cls");
        }
    }
	return 0;
}