#include "ReadKeyboard.h"

int GetDirection(){
    while(1){
        Sleep(20);
        if(_kbhit()){
            switch(_getch()){
                case 72:return 0;
                case 'w':return 0;
                case 75:return 1;
                case 'a':return 1;
                case 77:return 2;
                case 'd':return 2;
                case 80:return 3;
                case 's':return 3;
                case 13:return 4;
                case ' ':return 4;
                case 'g':return 5;
                case 'h':return 6;
                case 'b':return 7;
                case 27:exit(0);
            }
        }
    }
}

int GetChoice1(){
    while(1){
        Sleep(20);
        if(_kbhit()){
            switch(_getch()){
                case '1':return 1;
                case '2':return 2;
                case '3':return 3;
                case 27 :exit(0);
            }
        }
    }
}

int GetChoice2(){
    while(1){
        Sleep(20);
        if(_kbhit()){
            switch(_getch()){
                case 'b':return 0;
                case 'w':return 1;
                case 27 :exit(0);
            }
        }
    }
}

int KeyToValue(){
    while(1){
        Sleep(20);
        if(_kbhit()){
            return _getch();
        }
    }
}