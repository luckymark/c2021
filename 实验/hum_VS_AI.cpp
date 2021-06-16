#include "hum_VS_AI.h"

/*************************************************
Function: hum_VS_AI

Description: 人机对战辅助函数，主要用于响应玩家的鼠标事件，同时在每一次玩家下棋后，调用AI_turn函数让AI下棋。

Input: null

Return: 返回游戏胜利方
********************************************/
int hum_VS_AI() {
    int x, y, i, j, is_find = 0; //is_find用于检测是否找到了鼠标点击时对应棋盘上的位置
    int is_first = 1;
    MOUSEMSG mouse;
    chess_t chess;
    RECT r = { 480,250,580,300 }; 
    LOGFONT f;
    gettextstyle(&f);						// 获取当前字体设置
    f.lfHeight = 20;						// 设置字体高度为 20
    settextstyle(&f);						// 设置字体样式
    setfillcolor(RGB(228, 121, 21));  //设置按钮颜色
    RECT R = { 480, 150, 580, 200 };
    fillrectangle(480, 150, 580, 200);
    drawtext(_T("玩家先手"), &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    while (true) {
        drawtext(_T("你的回合"), &r, DT_CENTER); // 对应区域居中打印文字
        mouse = GetMouseMsg(); //获取一个鼠标消息
        if (mouse.uMsg == WM_LBUTTONDOWN) { //判断鼠标左键是否按下
            for (i = 0; i < 15 && is_find != 1; i++) {
                for (j = 0; j < 15 && is_find != 1; j++) {
                    if (abs(mouse.x - (112 + i * 25)) < 12 && abs(mouse.y - (112 + j * 25)) < 12) {//寻找距离鼠标点击最近的点
                        x = 112 + i * 25;
                        y = 112 + j * 25;
                        is_find = 1;
                    }
                }
            }
            if (is_find == 0 && is_first == 1) {
                if (abs(mouse.x - 530) < 50 && abs(mouse.y - 175) < 25) {
                    RECT R = { 480, 150, 580, 200 };
                    fillrectangle(480, 150, 580, 200);
                    drawtext(_T("AI先手"), &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    chess.x = 7, chess.y = 7;
                    gBoard[chess.x][chess.y] = AIChessColor;
                    i = 112 + 25 * 7;
                    j = 112 + 25 * 7;
                    setfillcolor(RGB(255, 255, 255));
                    solidcircle(i, j, 10); //绘制白色棋子（代表AI）
                    setfillcolor(RGB(255, 0, 0));
                    solidcircle(i, j, 2); //绘制下棋示意点
                    is_first = 0;
                }
            }
            if (is_find == 1) {
                i--; //由于跳出for循换的时候++了，因此需要-1抵消这个误差
                j--;
                if(gBoard[j][i]==SPACE) { //棋盘上对应位置没有棋子
                    if (!is_first) { //消除标记点
                        setfillcolor(RGB(255, 255, 255));
                        solidcircle(25 * chess.y + 112, 25 * chess.x + 112, 10);
                    }
                    setfillcolor(RGB(0, 0, 0));
                    solidcircle(x, y, 10); //绘制黑色棋子（代表玩家）
                    gBoard[j][i] = humChessColor;
                    HRGN del = CreateRectRgn(480, 250, 580, 300); //删除文字区域的文字
                    setcliprgn(del);
                    DeleteObject(del);
                    clearcliprgn();
                    setcliprgn(NULL);
                    if (is_win(j, i, humChessColor)) { //判断玩家是否已经获胜
                        return humChessColor;
                    }
                    chess = AI_turn();//AI下棋
                    if (is_win(chess.x, chess.y, AIChessColor)) { //判断AI是否已经获胜
                        return AIChessColor;
                    }
                    is_first = 0;
                }
                is_find = 0;
            }
        }
    }
}

/*************************************************
Function:AI_turn

Description: 轮到AI下棋，调用chess_AI_Negmax_Alphabeta函数获取AI下棋的决策坐标
             用于绘制提示信息以及棋子、示意点

Input: null

Return: 返回每一次AI决策下棋的位置信息
********************************************/
chess_t AI_turn() {
    RECT r = { 480,250,580,300 }; //打印区域
    drawtext(_T("轮到AI下棋"), &r, DT_CENTER); // 对应区域居中打印文字
    chess_t chess;
    chess_AI_Negmax_Alphabeta(&chess); //获取AI决策下棋的位置
    int i = 112 + 25 * chess.y, j = 112 + 25 * chess.x;
    setfillcolor(RGB(255, 255, 255)); 
    solidcircle(i, j, 10); //绘制白色棋子（代表AI）
    setfillcolor(RGB(255, 0, 0));
    solidcircle(i, j, 2); //绘制下棋示意点
    gBoard[chess.x][chess.y] = AIChessColor; // 棋盘记录下棋信息
    HRGN del = CreateRectRgn(480, 250, 580, 300); //删除文字区域文字
    setcliprgn(del);
    DeleteObject(del);
    clearcliprgn();
    setcliprgn(NULL);
    return chess;
}

/*************************************************
Function: chess_AI_Negmax_Alphabeta

Description: 轮到AI下棋，在每一个可以下棋的位置（经初步筛选）中决策出分数最高的位置 

Input: 虽然是函数的输入，但主要用于记录决策出来的最佳坐标，作用更接近于返回值。

Return: NULL
********************************************/
void chess_AI_Negmax_Alphabeta(chess_t* chess) {
    int i, k = 0;
    int x, y, tmp, depth = 4; //这里可以更改搜索的深度
    int best = -WIN5; //找到的最高分,初始值赋一个最小值
    chess_queue  option_queue; //待选的空子队列
    chess_queue sure_queue;  //最合适的下子位置
    option_queue = generate_point(AIChessColor); //寻找可以下子的地方

    for (i = 1; i <= option_queue.len; i++) { //一个一个子轮着试一遍
        x = option_queue.chess[i].x;
        y = option_queue.chess[i].y;
        gBoard[x][y] = AIChessColor; //尝试下一个子
        tmp = negaMax_alphabeta(depth, option_queue.chess[i], -WIN5, WIN5, humChessColor); //获得此位置的分数
        if (tmp == best) { //找到一个和当前最高分一样的分数，保存下来
            sure_queue.chess[k].x = option_queue.chess[i].x;
            sure_queue.chess[k].y = option_queue.chess[i].y;
            sure_queue.len = k + 1;
            k++;
        }
        else if (tmp > best) { //找到一个比当前最高分更高的分数，刷新最高值
            best = tmp;
            k = 0;
            sure_queue.len = 1;
            sure_queue.chess[k].x = option_queue.chess[i].x;
            sure_queue.chess[k].y = option_queue.chess[i].y;
            k++;
        }
        gBoard[x][y] = SPACE; //撤销选择
    }
    if (best == -WIN5) { //有可能任意位置都要比最低分要低，即当AI必输时，sure_queue可能没有记录，此时随机选择一个点下棋
        k = (int)(rand() % option_queue.len);
        chess->x = option_queue.chess[k].x;
        chess->y = option_queue.chess[k].y;
    }
    else {
        k = (int)(rand() % sure_queue.len); //如果有多个最高分数，随机选择一个
        chess->x = sure_queue.chess[k].x;
        chess->y = sure_queue.chess[k].y;
    }
}

/*************************************************
Function: negaMax_alphabeta

Description: 核心函数，负极大值搜索，用深度优先的思想搜索给定深度下当前位置的预估分数，结合alpha_beta剪枝

Input: int depth : 搜索深度 
       chess_t chess : 上一步尝试落子的棋子
       int alpha : 用于剪枝
       int beta : 用于剪枝
       int player:本轮对应玩家

Return: 返回搜索得到的预估分数
********************************************/
int negaMax_alphabeta(int depth, chess_t chess, int alpha, int beta, int player) {
    int res = evaluate_board(); //当前棋盘分数（AI-player）
    int x, y, tempScore;
    if ((depth <= 0) || (is_win(chess.x, chess.y, player % 2 + 1))) //如果已经达到目标深度，或上一步对方已经胜利
        return res;
    chess_queue queue;
    queue = generate_point(player); //记录当前可以下子的位置

    for (int i = 1; i <= queue.len; i++) { //这里就是DFS的过程
        x = queue.chess[i].x;
        y = queue.chess[i].y;
        gBoard[x][y] = player; //做出选择
        tempScore = -negaMax_alphabeta(depth - 1, queue.chess[i], -beta, -alpha, player % 2 + 1);
        gBoard[x][y] = SPACE; //撤销选择
        if (tempScore > alpha)
            alpha = tempScore;
        if (alpha >= beta)
            break;
    }
    return alpha;
}

/*************************************************
Function: evaluate_board

Description: 将棋盘上的位置分解为由行、列、斜线组成的一维数组.
             利用count_score函数遍历一维数组，分别结算玩家和AI的分数。

Input: null

Return: 当前棋局AI总分与玩家总分的差值
********************************************/
int evaluate_board() {
    int AIScore = 0, humScore = 0;
    int i, j, x, y, n[M_SIZE];
    memset(n, 0, sizeof(n));
    //计算所有横排的分数之和
    for (i = 0; i < M_SIZE; i++) {
        for (j = 0; j < M_SIZE; j++)
            n[j] = gBoard[i][j];
        AIScore += count_score(n, AIChessColor);
        humScore += count_score(n, humChessColor);
        memset(n, 0, sizeof(n));
    }
    //计算所有纵排的分数之和
    for (j = 0; j < M_SIZE; j++) {
        for (i = 0; i < M_SIZE; i++)
            n[i] = gBoard[i][j];
        AIScore += count_score(n, AIChessColor);
        humScore += count_score(n, humChessColor);
        memset(n, 0, sizeof(n));
    }
    //计算所有下半正斜线(\)的分数之和
    for (i = 0; i < M_SIZE; i++) {
        for (x = i, y = 0; x < M_SIZE && y < M_SIZE; x++, y++)
            n[y] = gBoard[x][y];
        AIScore += count_score(n, AIChessColor);
        humScore += count_score(n, humChessColor);
        memset(n, 0, sizeof(n));
    }
    //计算所有上半正斜线的分数之和
    for (j = 1; j < M_SIZE; j++) {
        for (x = 0, y = j; y < M_SIZE && x < M_SIZE; x++, y++)
            n[x] = gBoard[x][y];
        AIScore += count_score(n, AIChessColor);
        humScore += count_score(n, humChessColor);
        memset(n, 0, sizeof(n));
    }
    //计算所有上半反斜线(/)的分数之和
    for (i = 0; i < M_SIZE; i++) {
        for (y = i, x = 0; y >= 0 && x < M_SIZE; y--, x++)
            n[x] = gBoard[x][y];
        AIScore += count_score(n, AIChessColor);
        humScore += count_score(n, humChessColor);
        memset(n, 0, sizeof(n));
    }
    //计算所有下半反斜线的分数之和
    for (j = 1; j < M_SIZE; j++) {
        for (y = j, x = M_SIZE - 1; y < M_SIZE && x >= 0; y++, x--)
            n[y - j] = gBoard[x][y];
        AIScore += count_score(n, AIChessColor);
        humScore += count_score(n, humChessColor);
        memset(n, 0, sizeof(n));
    }
    return AIScore - humScore; //返回  AI-人 的分数
}

/*******************************************
Function: generate_point

Description: 寻找当前棋局可以下棋且对棋手有利的位置。
             要求是位置为空且一步之内有邻居(要求有邻居是为了使下棋的地方更接近现实)
             Ps：为了便于alpha-beta剪枝，使用了启发式搜索算法，若为杀棋则直接返回，否则进行大致的排序 。

Input: int player : 当前回合的棋手

Return: 返回当前棋局可以落子的位置结构体（结构体中包含一个数组，记录各点位置信息）
********************************************/
chess_queue generate_point(int player) {
    int i, j = 0;
    int length;
    chess_queue rivalFive; //对方成5
    chess_queue ComFour; //本方活4
    chess_queue rivalFour; //对方活四
    chess_queue ComDoubleThree; //本方双活三
    chess_queue rivalDoubleThree; //对方双活三
    chess_queue ComThree; //本方活三
    chess_queue rivalThree; //对方活三
    chess_queue ComTwo; //本方活二
    chess_queue rivalTwo; //对方活二
    chess_queue others; //其余
    chess_queue queue;  //用于函数返回

    for (i = 0; i < M_SIZE; i++) {
        for (j = 0; j < M_SIZE; j++) {
            chess_t p;
            p.x = i, p.y = j;
            if ((gBoard[i][j] == SPACE) && hasNeighbors(i, j)) {//有邻居的空子,做为可下子的队列
                int ComScore = evaluatePoint(player, p); //本方分数
                int rivalScore = evaluatePoint(player % 2 + 1, p); //对方分数

                if (ComScore >= WIN5) { //本方成5
                    queue.len++;
                    queue.chess[queue.len] = p;
                    return queue; //必杀棋，直接返回
                }
                else if (rivalScore >= WIN5) { //对方成5
                    rivalFive.len++;
                    rivalFive.chess[rivalFive.len] = p; //对方的必杀棋，必须阻挡
                }
                else if (ComScore >= ALIVE4) { //本方活四
                    ComFour.len++;
                    ComFour.chess[ComFour.len] = p;
                }
                else if (rivalScore >= ALIVE4) { //对方活四
                    rivalFour.len++;
                    rivalFour.chess[rivalFour.len] = p;
                }
                else if (ComScore >= 2 * ALIVE3) { //本方双活三
                    ComDoubleThree.len++;
                    ComDoubleThree.chess[ComDoubleThree.len] = p;
                }
                else if (rivalScore >= 2 * ALIVE3) { //对方活三
                    rivalDoubleThree.len++;
                    rivalDoubleThree.chess[rivalDoubleThree.len] = p;
                }
                else if (ComScore >= ALIVE3) { //本方活三
                    ComThree.len++;
                    ComThree.chess[ComThree.len] = p;
                }
                else if (rivalScore >= ALIVE3) { //对方活三
                    rivalThree.len++;
                    rivalThree.chess[rivalThree.len] = p;
                }
                else if (ComScore >= ALIVE2) { //本方活二
                    ComTwo.len++;
                    ComTwo.chess[ComTwo.len] = p;
                }
                else if (rivalScore >= ALIVE2) { //对方活二
                    rivalTwo.len++;
                    rivalTwo.chess[rivalTwo.len] = p;
                }
                else { //其余
                    others.len++;
                    others.chess[others.len] = p;
                }
            }
        }
    }
    if (rivalFive.len > 0) {
        queue = rivalFive;
        return queue;
    }else if (ComFour.len > 0 || rivalFour.len > 0) {
        queue = ComFour;
        length = queue.len;
        for (int x = 1; x <= rivalFour.len; x++) {
            queue.chess[length + x] = rivalFour.chess[x];
            queue.len++;
        }
        return queue;
    }else if (ComDoubleThree.len > 0 || rivalDoubleThree.len > 0) {
        queue = ComDoubleThree;
        length = queue.len;
        for (int x = 1; x <= rivalDoubleThree.len; x++) {
            queue.chess[length + x] = rivalDoubleThree.chess[x];
            queue.len++;
        }
        return queue;
    }
    //以上为杀棋，直接返回
    //以下非必杀，因此进行一个大致的排序，按顺序存放进queue
    queue = ComThree;
    length = queue.len;
    for (int x = 1; x <= rivalThree.len; x++) {
        queue.chess[length + x] = rivalThree.chess[x];
        queue.len++;
    }
    length = queue.len;
    for (int x = 1; x <= ComTwo.len; x++) {
        queue.chess[length + x] = ComTwo.chess[x];
        queue.len++;
    }
    length = queue.len;
    for (int x = 1; x <= rivalTwo.len; x++) {
        queue.chess[length + x] = rivalTwo.chess[x];
        queue.len++;
    }
    length = queue.len;
    for (int x = 1; x <= others.len; x++) {
        queue.chess[length + x] = others.chess[x];
        queue.len++;
    }
    return queue;
}

/*******************************************
Function: hasNeighbors

Description: 判断当前位置 (x,y) s步之内是否有子(不管是对方的子还是己方的子）

Input: x->int 横坐标
       y->int 纵坐标

Return: TRUE->有子 ；FALSE->无子
********************************************/
int hasNeighbors(int x, int y) {
    int s = 1;
    int i, j;
    for (i = (x - s > 0 ? x - s : 0); i <= x + s && i < M_SIZE; i++)
        for (j = (y - s > 0 ? y - s : 0); j <= y + s && j < M_SIZE; j++)
            if ((i != x || j != y) && gBoard[i][j] != SPACE)
                return TRUE;
    return FALSE;
}


/*******************************************
Function: evaluatePoint

Description: 评估某一点对应的分数。注：此函数主要用于启发式搜索算法，判断该点的类型（如活三、冲四等）

Input: int chessColor //棋子颜色
       chess_t chess //棋子坐标

Return: 评估得到的分数
********************************************/
int evaluatePoint(int chessColor, chess_t chess) {
    int x = chess.x, y = chess.y;
    int i, j, number = 0, empty = 2, score = 0;
    gBoard[x][y] = chessColor;
    for (i = x, j = y + 1; j < M_SIZE; j++) { //往右累加，计算右边棋子个数
        if (gBoard[i][j] == chessColor)
            number++;
        else {
            if (gBoard[i][j] != SPACE) //对方棋子
                empty--;
            break;
        }
    }
    for (i = x, j = y; j >= 0; j--) { //往左累加，计算左边棋子个数
        if (gBoard[i][j] == chessColor)
            number++;
        else {
            if (gBoard[i][j] != SPACE)
                empty--;
            break;
        }
    }
    score += score_table(number, empty);

    number = 0, empty = 2;
    for (i = x, j = y; i >= 0; i--) { //向上检索
        if (gBoard[i][j] == chessColor)
            number++;
        else {
            if (gBoard[i][j] != SPACE)
                empty--;
            break;
        }
    }
    for (i = x + 1, j = y; i < M_SIZE; i++) { //向下检索
        if (gBoard[i][j] == chessColor)
            number++;
        else {
            if (gBoard[i][j] != SPACE)
                empty--;
            break;
        }
    }
    score += score_table(number, empty);

    number = 0, empty = 2;
    for (i = x - 1, j = y + 1; i >= 0 && j < M_SIZE; i--, j++) { //向右上检索
        if (gBoard[i][j] == chessColor)
            number++;
        else {
            if (gBoard[i][j] != SPACE)
                empty--;
            break;
        }
    }
    for (i = x, j = y; i < M_SIZE && j >= 0; i++, j--) { //向左下检索
        if (gBoard[i][j] == chessColor)
            number++;
        else {
            if (gBoard[i][j] != SPACE)
                empty--;
            break;
        }
    }
    score += score_table(number, empty);

    number = 0, empty = 2;
    for (i = x, j = y; i >= 0 && j >= 0; i--, j--) {//向左上检索
        if (gBoard[i][j] == chessColor)
            number++;
        else {
            if (gBoard[i][j] != SPACE)
                empty--;
            break;
        }
    }
    for (i = x + 1, j = y + 1; i < M_SIZE && j < M_SIZE; i++, j++) {//向右下检索
        if (gBoard[i][j] == chessColor)
            number++;
        else {
            if (gBoard[i][j] != SPACE)
                empty--;
            break;
        }
    }
    score += score_table(number, empty);
    gBoard[x][y] = SPACE;
    return score;
}


/*************************************************
Function: count_score

Description: 计算这一行、列、斜线的连子数、空位数，每找到一串连子就根据调用score_table函数计算分数，最后求出分数总和，代表该行、列、斜线的分数。

Input: int n[] : 代表每一行、列、斜线的一维数组
       int chessColor : 本回合棋手的棋子颜色

Return: 这一组（一维数组）的分数总和
********************************************/
int count_score(int n[], int chessColor) {
    int i = 1; //n[0]在下面作为初始点单独计算
    int empty = 0; //空的位子
    int number = 0; //连子的个数
    int scoretmp = 0; //计算分数总和

    if (n[0] == SPACE) //位置为空
        empty++;
    else if (n[0] == chessColor) //本方棋子
        number++;

    while (i < M_SIZE) {
        if (n[i] == chessColor) //本方棋子
            number++;
        else if (n[i] == SPACE) { //位置为空，分两种情况来讨论
            if (number == 0) //上一个位置也为空
                empty = 1;
            else { //上一个位置为本方棋子
                scoretmp += score_table(number, empty + 1);
                empty = 1;
                number = 0;
            }
        }
        else {//对方棋子
            scoretmp += score_table(number, empty);
            empty = 0;
            number = 0;
        }
        i++;
    }
    scoretmp += score_table(number, empty);
    return scoretmp; //返回本组分数总和
}

/*************************************************
Function: score_table

Description: 根据连子个数和两端的空子个数计算分数

Input: number->连子的个数
       empty->空子的个数

Return: 分数
********************************************/
int score_table(char number, char empty) {
    if (number >= 5) {
        return WIN5;
    }
    else if (number == 4) {
        if (empty == 2)
            return ALIVE4;
        else if (empty == 1)
            return DIE4;
    }
    else if (number == 3) {
        if (empty == 2)
            return ALIVE3;
        else if (empty == 1)
            return DIE3;
    }
    else if (number == 2) {
        if (empty == 2)
            return ALIVE2;
        else if (empty == 1)
            return DIE2;
    }
    else if (number == 1 && empty == 2)
        return ALIVE1;
    else
        return 0;
}