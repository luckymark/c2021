#include <iostream>

using namespace std;

void hanoi(int n, char A, char B, char C) {  //将A塔上n块圆盘通过B塔搬运至C塔上
    // A塔为被搬运塔，B塔为中间塔，C塔为目标塔
    if (n > 0) {
        hanoi(n - 1, A, C, B);  //把n - 1块圆盘从A塔搬运至B塔
        cout << "将顶层圆盘从塔" << A << "移至塔" << C << endl;
        hanoi(n - 1, B, A, C);  //把剩下n - 1块圆盘从B塔搬运至C塔
    }
}

int main() {
    hanoi(64, 'A', 'B', 'C');
    return 0;
}