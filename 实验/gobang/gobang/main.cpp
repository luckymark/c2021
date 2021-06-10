#include "gobang.h"
#include "types.h"
#include <time.h>
#include <iostream>

using namespace std;

char map[MAP_SIZE][MAP_SIZE] = {0};

char AIChessColor[] = "0";
char PlayerChessColor[] = "@";

int AI_Play(bool ifFirst);

int P_Play();

void print_map();

int check(int x, int y, char color);

int scoref(int occupy, int empty);

int count_score(char n[], char color);

int is(int x, int y);

void ability(List *list);

int min_alphabeta(int depth, CHESS chess, int alpha, int beta);

int max_alphabeta(int depth, CHESS chess, int alpha, int beta);

void AI(CHESS *chess, int depth);


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
                cout << "You Lose!!!" << endl;
                print_map();
                break;
            }
            print_map();
            again_1:
            ret = P_Play();
            if (ret == -2) {
                fflush(stdin);
                goto again_1;
            } else if (ret == 1) {
                cout << "You Win!!!" << endl;
                print_map();
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
                cout << "You Win!!!";
                print_map();
                break;
            } else if (ret != 0) {
                goto again_2;
            }
            print_map();
            ret = AI_Play(0);
            if (ret == 1) {
                cout << "You Lose!!!" << endl;
                print_map();
                break;
            }
        }
        print_map();
        i++;
    }
    return 0;
}

int AI_Play(bool ifFirst) {
    CHESS chess;
    chess.x = 0;
    chess.y = 0;
    time_t start, end;
    if (ifFirst) {
        start = clock();
        chess.x = 7;
        chess.y = 7;
        end = clock();
    } else {
        cout << "Waiting..." << endl;
        start = clock();
        AI(&chess, DEEP);
        end = clock();
    }
    printf("AI Chess:(%d, %d), use time:%f second\n", chess.x + 1, chess.y + 1, ((double) end - start) / 1000);
    map[chess.x][chess.y] = AIChessColor[0];
    if (check(chess.x, chess.y, AIChessColor[0])) {
        return 1;
    }
    return 0;
}

int P_Play() {
    int x = 0, y = 0;
    int ret = 0;
    cout << "Set your chess:";
    ret = scanf("%d, %d", &x, &y);
    x--;
    y--;
    if (ret != 2) {
        cout << "scanf ERROR" << endl;
        return -2;
    }
    if (x < 0 || x > 14 || y < 0 || y > 14) {
        cout << "num ERROR" << endl;
        return -1;
    }
    if (map[x][y] != SPACE) {
        cout << "There has been a chess" << endl;
        return -1;
    }
    map[x][y] = PlayerChessColor[0];
    if (check(x, y, PlayerChessColor[0])) {
        return 1;
    }
    return 0;
}

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

int check(int x, int y, char color) {
    int count = 0;
    for (int i = (x - 4 > 0 ? x - 4 : 0); (i <= x + 4) && (i <= MAP_SIZE); i++) {
        if (color == map[i][y]) {
            count++;
            if (count >= 5) return 1;
        } else count = 0;
    }
    count = 0;
    for (int i = (y - 4 > 0 ? y - 4 : 0); (i <= y + 4) && (i <= MAP_SIZE); i++) {
        if (color == map[x][i]) {
            count++;
            if (count >= 5) return 1;
        } else count = 0;
    }
    count = 0;
    int bx = x, by = y;
    int cx, cy;
    if (x < 4 || y < 4) {
        if (x < y) {
            bx = 0;
            by = y - x;
        } else {
            by = 0;
            bx = x - y;
        }
    }
    for (int i = bx, j = by; (i <= x + 4) && (i < MAP_SIZE) && (j <= y + 4) && (j < MAP_SIZE); i++, j++) {
        if (color == map[i][j]) {
            count++;
            if (count >= 5) return 1;
        } else count = 0;
    }
    count = 0;
    bx = x;
    by = y;
    if (x - 4 < 0 || y + 4 > 14) {
        if (4 - x > y - 10) {
            bx = 0;
            by = y + x;
        } else {
            by = 14;
            bx = x + y - 14;
        }
    }
    for (int i = bx, j = by; (i <= x + 4) && (i < MAP_SIZE) && (j >= y - 4) && (j >= 0); i++, j--) {
        if (color == map[i][j]) {
            count++;
            if (count >= 5) return 1;
        } else count = 0;
    }
    return 0;
}

int scoref(int occupy, int empty) {
    if (occupy >= 5)return WIN5;
    if (occupy == 4) {
        if (empty == 2)return ALIVE4;
        if (empty == 1)return DIE4;
    }
    if (occupy == 3) {
        if (empty == 2)return ALIVE3;
        if (empty == 1)return DIE3;
    }
    if (occupy == 2) {
        if (empty == 2)return ALIVE2;
        if (empty == 1)return DIE2;
    }
    if (occupy == 1) {
        if (empty == 2)return ALIVE1;
        if (empty == 1)return DIE1;
    }
    return 0;
}

int count_score(char n[], char color) {
    int i = 1;
    int empty = 0;
    int occupy = 0;
    int score_n = 0;
    if (n[0] == SPACE) {
        empty++;
    } else if (n[0] == color) {
        occupy++;
    }

    while (i < MAP_SIZE) {
        if (n[i] == color)occupy++;
        else if (n[i] == SPACE) {
            if (occupy == 0)empty = 1;
            else {
                score_n += scoref(occupy, empty + 1);
                empty = 1;
                occupy = 0;
            }
        } else {
            score_n += scoref(occupy, empty);
            empty = 0;
            occupy = 0;
        }
        i++;
    }
    score_n += scoref(occupy, empty);
    return score_n;
}

int evaluate() {
    int AIscore = 0;
    int Pscore = 0;
    char n[MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            n[j] = map[i][j];
        }
        AIscore += count_score(n, AIChessColor[0]);
        Pscore += count_score(n, PlayerChessColor[0]);
        memset(n, SPACE, MAP_SIZE * sizeof(n[0]));
    }
    for (int j = 0; j < MAP_SIZE; j++) {
        for (int i = 0; i < MAP_SIZE; i++) {
            n[i] = map[i][j];
        }
        AIscore += count_score(n, AIChessColor[0]);
        Pscore += count_score(n, PlayerChessColor[0]);
        memset(n, SPACE, MAP_SIZE * sizeof(n[0]));
    }
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int x = i, y = 0; (x < MAP_SIZE) && (y < MAP_SIZE); x++, y++) {
            n[y] = map[x][y];
        }
        AIscore += count_score(n, AIChessColor[0]);
        Pscore += count_score(n, PlayerChessColor[0]);
        memset(n, SPACE, MAP_SIZE * sizeof(n[0]));
    }
    for (int j = 1; j < MAP_SIZE; j++) {
        for (int y = j, x = 0; (x < MAP_SIZE) && (y < MAP_SIZE); x++, y++) {
            n[x] = map[x][y];
        }
        AIscore += count_score(n, AIChessColor[0]);
        Pscore += count_score(n, PlayerChessColor[0]);
        memset(n, SPACE, MAP_SIZE * sizeof(n[0]));
    }
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int y = i, x = 0; (y >= 0) && (x < MAP_SIZE); y--, x++) {
            n[x] = map[x][y];
        }
        AIscore += count_score(n, AIChessColor[0]);
        Pscore += count_score(n, PlayerChessColor[0]);
        memset(n, SPACE, MAP_SIZE * sizeof(n[0]));
    }
    for (int j = 1; j < MAP_SIZE; j++) {
        for (int y = j, x = MAP_SIZE - 1; (y < MAP_SIZE) && (x >= 0); y++, x--) {
            n[y - j] = map[x][y];
        }
        AIscore += count_score(n, AIChessColor[0]);
        Pscore += count_score(n, PlayerChessColor[0]);
        memset(n, SPACE, MAP_SIZE * sizeof(n[0]));
    }
    return AIscore - 1.5*Pscore;
}

int is(int x, int y) {
    for (int i = (x - 1 > 0 ? x - 1 : 0); i <= x + 1 && i < MAP_SIZE; i++) {
        for (int j = (y - 1 > 0 ? y - 1 : 0); j <= y + 1 && j < MAP_SIZE; j++) {
            if (i != 0 || j != 0) {
                if (map[i][j] != SPACE)return 1;
            }
        }
    }
    return 0;
}

void ability(List *list) {
    int k = 0;
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if ((map[i][j] == SPACE) && (is(i, j))) {
                list->chess[k].x = i;
                list->chess[k].y = j;
                list->num = k + 1;
                k++;
            }
        }
    }
}

int min_alphabeta(int depth, CHESS chess, int alpha, int beta) {
    int tmp = evaluate();
    int i, x, y;
    int t;
    int best = WIN5;
    List list;
    if ((depth <= 0) || (check(chess.x, chess.y, AIChessColor[0]))) {
        return tmp;
    }
    ability(&list);
    for (i = 0; i < list.num; i++) {
        x = list.chess->x;
        y = list.chess->y;
        map[x][y] = PlayerChessColor[0];
        t = max_alphabeta(depth - 1, list.chess[1], best < alpha ? best : alpha, beta);
        map[x][y] = SPACE;
        if (t < best)best = t;
        if (t < beta)break;
    }
    return best;
}

int max_alphabeta(int depth, CHESS chess, int alpha, int beta) {
    int tmp = evaluate();
    int i, x, y;
    int t;
    int best = -WIN5;
    List list;
    if ((depth <= 0) || (check(chess.x, chess.y, PlayerChessColor[0]))) {
        return tmp;
    }
    ability(&list);
    for (int i = 0; i < list.num; i++) {
        x = list.chess->x;
        y = list.chess->y;
        map[x][y] = AIChessColor[0];
        t = min_alphabeta(depth - 1, list.chess[i], alpha, best > beta ? best : beta);
        map[x][y] = SPACE;
        if (t > best) {
            best = t;
        }
        if (t > alpha) {
            break;
        }
    }
    return best;
}

void AI(CHESS *chess, int depth) {
    int i = 0, j = 0;
    int x = 0, y = 0;
    int tmp = 0;
    int best = -WIN5;
    List option_list;
    List sure_list;
    ability(&option_list);
    for (i = 0; i < option_list.num; i++) {
        x = option_list.chess[i].x;
        y = option_list.chess[i].y;
        map[x][y] = AIChessColor[0];
        tmp = min_alphabeta(depth - 1, option_list.chess[i], WIN5, best);
        if (tmp == best) {
            sure_list.chess[j].x = option_list.chess[i].x;
            sure_list.chess[j].y = option_list.chess[i].y;
            sure_list.num = j + 1;
            j++;
        }
        if (tmp > best) {
            best = tmp;
            j = 0;
            sure_list.num = 1;
            sure_list.chess[j].x = option_list.chess[i].x;
            sure_list.chess[j].y = option_list.chess[i].y;
        }
        map[x][y] = SPACE;
    }
    j = (int) (rand() % sure_list.num);
    chess->x = sure_list.chess[j].x;
    chess->y = sure_list.chess[j].y;
}