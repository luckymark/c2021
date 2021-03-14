#include <iostream>
#include <string>
using namespace std;
string a;
char b[1000005];
void encrypt(string s) {
    for (int i = 0; i < s.length(); i++){
        b[i] = s[i] + 3;
        cout << b[i];
    }
    cout << endl;
}
void decrept(){
    for (int i = 0; i < a.length(); i++){
        char tmp = b[i] - 3;
        cout << tmp;
    }
    cout << endl;
}
int main() {
    cin >> a;
    encrypt(a);
    decrept();
    system("pause");
    return 0;
}

