#include <iostream>
using namespace std;
const int lifetime = 84; // His lifetime could be divided by 12 and 7,so by common sense,his lifetime is 84.
const int childhood = 14;
const int youth = 7;
const int bachelor = 12;
const int marriage = 5;
int main() {
    int father = childhood + youth + bachelor + marriage;
    int son = 0;
    int time = lifetime - 4 - father;
    if (time == lifetime / 2) cout << 80 << endl;
    return 0;
}
