#include <iostream>

using namespace std;

double Diophantus() {
    double aDad, aSon = 35, temp;

    do {
        ++aSon;
        aDad = 2 * aSon;
        temp = aDad * 33 / 84 + 5 + 4 + aSon;
    } while (temp != aDad);

    return aDad - 4;
}

int main() {
    cout << Diophantus();
    return 0;
}