//
// Created by mux on 2021-04-07.
//
#ifndef FIVEINAROW_GAME_H
#define FIVEINAROW_GAME_H
#include "../Board/Board.h"
#include <vector>
/**
 * 寻找可能的可以落子的点，去除明显不需要思考的点 即在这一层可能的落子位置
 * 其实是决策树的每一层
 * @param board
 * @return
 */
vector<Point>* find_possible_solutions(Board *board);

/**
 * 估计AI胜利概率（全局）
 * @param board
 * @return 0~1的float
 */
float estimate_winning_possibility_to_system(Board *board);

/**
 * 计算一个落子操作的得分（针对一个点）
 * @param board
 * @param point
 * @return
 */
int score_of_a_point(Board *board,Point point);

/**
 * 寻找此时AI赢面最大的地儿
 * @param board
 * @return
 */
Point find_best_point(Board *board);


#endif //FIVEINAROW_GAME_H
