//
// Created by 10917 on 2021/6/10.
//

#ifndef GOBANG_MAP_PRINT_H
#define GOBANG_MAP_PRINT_H

#endif //GOBANG_MAP_PRINT_H

#include <iostream>
using namespace std;

char map[MAP_SIZE][MAP_SIZE] = {0};

char AIChessColor[] = "0";
char PlayerChessColor[] = "@";

void print_map();

void print_map() {
    cout << endl;
    cout << "   1 2 3 4 5 6 7 8 9101112131415" << endl;
    cout << "   -----------------------------" << endl;
    for (int i = 0; i < MAP_SIZE; i++) {
        if (i < 9) {
            cout << i + 1 << " |";
        } else {
            cout << i + 1 << "|";
        }
        for (int j = 0; j < MAP_SIZE; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}