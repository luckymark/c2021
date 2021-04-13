#include "maze.h"
using namespace std;

int main(){
    //generate the console
    int h=120,w=70;
	char chCmd[32];
	sprintf(chCmd,"mode con cols=%d lines=%d",h,w);
	system(chCmd);
    //generate the menu
    Menu();
    //choose the difficulty
    Differ();
    //creat the maze
    CreateMaze();
    //print the maze
    Start();
    return 0;
}