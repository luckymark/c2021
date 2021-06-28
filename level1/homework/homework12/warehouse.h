#pragma once
#ifndef WAREHOUSE_WAREHOUSE_H
#define WAREHOUSE_WAREHOUSE_H

#include"warehouse.c"

void PrintWareHouse(FILE* fp, const char fileName[], char buff[], int sizeOfBuff);
void RepeatEnterHouse(FILE* fp, const char fileName[], const char numberForStop, char buff[], int sizeOfBuff);
void RepeatExitHouse(FILE* fp, const char fileName[], const char numberForStop, char buff[], int sizeOfBuff);


#endif