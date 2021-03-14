#include <iostream>
using namespace std;
const int max_lifetime = 800; // the life span of the legendary "PengZu"
int main() {
    for(int i=0;i<max_lifetime;i++){ // i is the lifetime of Diophantus
        if(i % 6 != 0 || i % 12 != 0 || i%7 != 0)  continue;
        int childhood = i / 6;
        int youth = i / 12;
        int bachelor = i / 7;
        int marriage = 5;
        int father = childhood + youth + bachelor + marriage;
        int son = 0;
        for(int j = 1;j <= i-father;j++){
            if(son == i/2 && father + son + 4 == i) {
                cout << i << endl;
                break;
            } else son++;
        }
    }
    system("pause");
    return 0;
}
