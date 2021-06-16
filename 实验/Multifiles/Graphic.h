#ifndef GRAPHIC_H
#define GRAPHIC_H
#include "Global.h"
#include "Risk.h"
#include "Algorithm.h"
#include "ReadKeyBoard.h"

void Print();
void PrintPlayer(const string &s,const double &x);
bool Computer(const bool &Color);
bool Player(int Color);
void PlayerVSPlayer();
void PlayerVSComputer();
void ComputerVSComputer();
void Game();
void Menu();
#endif