#include<iostream>
using namespace std;

int main(){
    int age = 0;
    while(true){
        if(age/6.0+age/12.0+age/7.0+5+4+age*0.5==age)
            break;
        else
            age++;
    }
    cout << age;
    return 0;
}