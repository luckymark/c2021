#ifndef _HUM_VS_AI_H
#define _HUM_VS_AI_H

#include "initmap.h"
#include "assist.h"

int hum_VS_AI();
int hasNeighbors(int x, int y);
int negaMax_alphabeta(int depth, chess_t chess, int alpha, int beta, int player);
void chess_AI_Negmax_Alphabeta(chess_t* chess);
int evaluatePoint(int chessColor, chess_t chess);
int count_score(int n[], int chessColor);
int score_table(char number, char empty);
int evaluate_board();
chess_queue generate_point(int player);
chess_t AI_turn();

#endif
