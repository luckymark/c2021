#include "gobang.h"
#include <iostream>
#include "map_print.h"
#include "function.h"

using namespace std;




int main() {
    cout << "    Welcome to Gobang!!!" << endl;
    cout << "                     by Hepper123" << endl;
    cout << "FORMAT:\"x,y\"" << endl;
    again:
    cout << "Whether to play chess first?(Y/N)" << endl;
    fflush(stdin);
    int t = getchar();
    if (t == 89 || t == 121);
    else if (t == 78 || t == 110) {
        AIChessColor[0] = BLACK;
        PlayerChessColor[0] = WHITE;
    } else {
        cout << "Input ERROR" << endl;
        goto again;
    }
    for (int j = 0; j < MAP_SIZE; j++) {
        for (int k = 0; k < MAP_SIZE; k++) {
            map[j][k] = SPACE;
        }
    }
    int i = 0;
    int ret = 0;


    while (i < (MAP_SIZE) * (MAP_SIZE) / 2) {
        if (AIChessColor[0] == BLACK) {
            if (i == 0) {
                ret = AI_Play(1);
            } else {
                ret = AI_Play(0);
            }
            if (ret == 1) {
                print_map();
                cout << "You Lose!!!" << endl;
                break;
            }
            print_map();
            again_1:
            ret = P_Play();
            if (ret == -2) {
                fflush(stdin);
                goto again_1;
            } else if (ret == 1) {
                print_map();
                cout << "You Win!!!" << endl;
                break;
            } else if (ret != 0) {
                goto again_1;
            }
        } else {
            again_2:
            ret = P_Play();
            if (ret == -2) {
                fflush(stdin);
                goto again_2;
            } else if (ret == 1) {
                print_map();
                cout << "You Win!!!";
                break;
            } else if (ret != 0) {
                goto again_2;
            }
            print_map();
            ret = AI_Play(0);
            if (ret == 1) {
                print_map();
                cout << "You Lose!!!" << endl;
                break;
            }
        }
        print_map();
        i++;
    }
    return 0;
}
