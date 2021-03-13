#include <iostream>
using namespace std;
void move(char getone, char putone)
{
    cout << getone << "-->" << putone << endl;
}
void hanot(int n, char A, char B, char C)
{
    if (n == 1)
        move(A, C);
    else
    {
        hanot(n - 1, A, C, B);
        move(A, C);
        hanot(n - 1, B, A, C);
    }
}
int main()
{
    int m;
    cin >> m;
    hanot(m, 'A', 'B', 'C');
    return 0;
}