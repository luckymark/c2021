//
// Created by mux on 2021-04-07.
//

#include "Board.h"
#include "../randomc/randomc.h"
#include <ctime>

#define RANDOM_MAX 1000

Board::Board(int current, char *name) {
    this->m_name = name;
//    this->m_map = map; 暂时不支持下残局
    this->m_current_player = current;
    // 初始化棋局
    for (int row = 1; row < 16; ++row) {
        for (int con = 1; con < 16; ++con) {
            this->m_map[row][con].key = -1;
        }
    }

    // 初始化Zobrist表
    int seed = (int) time(nullptr); // 随机数生成种子
    CRandomMersenne RanGen(seed);
    for (int row = 1; row < 16; ++row) {
        for (int con = 1; con < 16; ++con) {
            this->m_map[row][con].Black_Zobrist = RanGen.IRandom(0, RANDOM_MAX);
            this->m_map[row][con].White_Zobrist = RanGen.IRandom(0, RANDOM_MAX);
        }
    }
    // 初始化Zobrist值
    this->Current_Zobrist = RanGen.IRandom(0, RANDOM_MAX);
}



int Board::put_piece(int row, int con, int player) {
    return 0;
}

