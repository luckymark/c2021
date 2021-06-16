#include "hum_VS_AI.h"

/*************************************************
Function: hum_VS_AI

Description: �˻���ս������������Ҫ������Ӧ��ҵ�����¼���ͬʱ��ÿһ���������󣬵���AI_turn������AI���塣

Input: null

Return: ������Ϸʤ����
********************************************/
int hum_VS_AI() {
    int x, y, i, j, is_find = 0; //is_find���ڼ���Ƿ��ҵ��������ʱ��Ӧ�����ϵ�λ��
    int is_first = 1;
    MOUSEMSG mouse;
    chess_t chess;
    RECT r = { 480,250,580,300 }; 
    LOGFONT f;
    gettextstyle(&f);						// ��ȡ��ǰ��������
    f.lfHeight = 20;						// ��������߶�Ϊ 20
    settextstyle(&f);						// ����������ʽ
    setfillcolor(RGB(228, 121, 21));  //���ð�ť��ɫ
    RECT R = { 480, 150, 580, 200 };
    fillrectangle(480, 150, 580, 200);
    drawtext(_T("�������"), &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    while (true) {
        drawtext(_T("��Ļغ�"), &r, DT_CENTER); // ��Ӧ������д�ӡ����
        mouse = GetMouseMsg(); //��ȡһ�������Ϣ
        if (mouse.uMsg == WM_LBUTTONDOWN) { //�ж��������Ƿ���
            for (i = 0; i < 15 && is_find != 1; i++) {
                for (j = 0; j < 15 && is_find != 1; j++) {
                    if (abs(mouse.x - (112 + i * 25)) < 12 && abs(mouse.y - (112 + j * 25)) < 12) {//Ѱ�Ҿ������������ĵ�
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
                    drawtext(_T("AI����"), &R, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
                    chess.x = 7, chess.y = 7;
                    gBoard[chess.x][chess.y] = AIChessColor;
                    i = 112 + 25 * 7;
                    j = 112 + 25 * 7;
                    setfillcolor(RGB(255, 255, 255));
                    solidcircle(i, j, 10); //���ư�ɫ���ӣ�����AI��
                    setfillcolor(RGB(255, 0, 0));
                    solidcircle(i, j, 2); //��������ʾ���
                    is_first = 0;
                }
            }
            if (is_find == 1) {
                i--; //��������forѭ����ʱ��++�ˣ������Ҫ-1����������
                j--;
                if(gBoard[j][i]==SPACE) { //�����϶�Ӧλ��û������
                    if (!is_first) { //������ǵ�
                        setfillcolor(RGB(255, 255, 255));
                        solidcircle(25 * chess.y + 112, 25 * chess.x + 112, 10);
                    }
                    setfillcolor(RGB(0, 0, 0));
                    solidcircle(x, y, 10); //���ƺ�ɫ���ӣ�������ң�
                    gBoard[j][i] = humChessColor;
                    HRGN del = CreateRectRgn(480, 250, 580, 300); //ɾ���������������
                    setcliprgn(del);
                    DeleteObject(del);
                    clearcliprgn();
                    setcliprgn(NULL);
                    if (is_win(j, i, humChessColor)) { //�ж�����Ƿ��Ѿ���ʤ
                        return humChessColor;
                    }
                    chess = AI_turn();//AI����
                    if (is_win(chess.x, chess.y, AIChessColor)) { //�ж�AI�Ƿ��Ѿ���ʤ
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

Description: �ֵ�AI���壬����chess_AI_Negmax_Alphabeta������ȡAI����ľ�������
             ���ڻ�����ʾ��Ϣ�Լ����ӡ�ʾ���

Input: null

Return: ����ÿһ��AI���������λ����Ϣ
********************************************/
chess_t AI_turn() {
    RECT r = { 480,250,580,300 }; //��ӡ����
    drawtext(_T("�ֵ�AI����"), &r, DT_CENTER); // ��Ӧ������д�ӡ����
    chess_t chess;
    chess_AI_Negmax_Alphabeta(&chess); //��ȡAI���������λ��
    int i = 112 + 25 * chess.y, j = 112 + 25 * chess.x;
    setfillcolor(RGB(255, 255, 255)); 
    solidcircle(i, j, 10); //���ư�ɫ���ӣ�����AI��
    setfillcolor(RGB(255, 0, 0));
    solidcircle(i, j, 2); //��������ʾ���
    gBoard[chess.x][chess.y] = AIChessColor; // ���̼�¼������Ϣ
    HRGN del = CreateRectRgn(480, 250, 580, 300); //ɾ��������������
    setcliprgn(del);
    DeleteObject(del);
    clearcliprgn();
    setcliprgn(NULL);
    return chess;
}

/*************************************************
Function: chess_AI_Negmax_Alphabeta

Description: �ֵ�AI���壬��ÿһ�����������λ�ã�������ɸѡ���о��߳�������ߵ�λ�� 

Input: ��Ȼ�Ǻ��������룬����Ҫ���ڼ�¼���߳�����������꣬���ø��ӽ��ڷ���ֵ��

Return: NULL
********************************************/
void chess_AI_Negmax_Alphabeta(chess_t* chess) {
    int i, k = 0;
    int x, y, tmp, depth = 4; //������Ը������������
    int best = -WIN5; //�ҵ�����߷�,��ʼֵ��һ����Сֵ
    chess_queue  option_queue; //��ѡ�Ŀ��Ӷ���
    chess_queue sure_queue;  //����ʵ�����λ��
    option_queue = generate_point(AIChessColor); //Ѱ�ҿ������ӵĵط�

    for (i = 1; i <= option_queue.len; i++) { //һ��һ����������һ��
        x = option_queue.chess[i].x;
        y = option_queue.chess[i].y;
        gBoard[x][y] = AIChessColor; //������һ����
        tmp = negaMax_alphabeta(depth, option_queue.chess[i], -WIN5, WIN5, humChessColor); //��ô�λ�õķ���
        if (tmp == best) { //�ҵ�һ���͵�ǰ��߷�һ���ķ�������������
            sure_queue.chess[k].x = option_queue.chess[i].x;
            sure_queue.chess[k].y = option_queue.chess[i].y;
            sure_queue.len = k + 1;
            k++;
        }
        else if (tmp > best) { //�ҵ�һ���ȵ�ǰ��߷ָ��ߵķ�����ˢ�����ֵ
            best = tmp;
            k = 0;
            sure_queue.len = 1;
            sure_queue.chess[k].x = option_queue.chess[i].x;
            sure_queue.chess[k].y = option_queue.chess[i].y;
            k++;
        }
        gBoard[x][y] = SPACE; //����ѡ��
    }
    if (best == -WIN5) { //�п�������λ�ö�Ҫ����ͷ�Ҫ�ͣ�����AI����ʱ��sure_queue����û�м�¼����ʱ���ѡ��һ��������
        k = (int)(rand() % option_queue.len);
        chess->x = option_queue.chess[k].x;
        chess->y = option_queue.chess[k].y;
    }
    else {
        k = (int)(rand() % sure_queue.len); //����ж����߷��������ѡ��һ��
        chess->x = sure_queue.chess[k].x;
        chess->y = sure_queue.chess[k].y;
    }
}

/*************************************************
Function: negaMax_alphabeta

Description: ���ĺ�����������ֵ��������������ȵ�˼��������������µ�ǰλ�õ�Ԥ�����������alpha_beta��֦

Input: int depth : ������� 
       chess_t chess : ��һ���������ӵ�����
       int alpha : ���ڼ�֦
       int beta : ���ڼ�֦
       int player:���ֶ�Ӧ���

Return: ���������õ���Ԥ������
********************************************/
int negaMax_alphabeta(int depth, chess_t chess, int alpha, int beta, int player) {
    int res = evaluate_board(); //��ǰ���̷�����AI-player��
    int x, y, tempScore;
    if ((depth <= 0) || (is_win(chess.x, chess.y, player % 2 + 1))) //����Ѿ��ﵽĿ����ȣ�����һ���Է��Ѿ�ʤ��
        return res;
    chess_queue queue;
    queue = generate_point(player); //��¼��ǰ�������ӵ�λ��

    for (int i = 1; i <= queue.len; i++) { //�������DFS�Ĺ���
        x = queue.chess[i].x;
        y = queue.chess[i].y;
        gBoard[x][y] = player; //����ѡ��
        tempScore = -negaMax_alphabeta(depth - 1, queue.chess[i], -beta, -alpha, player % 2 + 1);
        gBoard[x][y] = SPACE; //����ѡ��
        if (tempScore > alpha)
            alpha = tempScore;
        if (alpha >= beta)
            break;
    }
    return alpha;
}

/*************************************************
Function: evaluate_board

Description: �������ϵ�λ�÷ֽ�Ϊ���С��С�б����ɵ�һά����.
             ����count_score��������һά���飬�ֱ������Һ�AI�ķ�����

Input: null

Return: ��ǰ���AI�ܷ�������ֵܷĲ�ֵ
********************************************/
int evaluate_board() {
    int AIScore = 0, humScore = 0;
    int i, j, x, y, n[M_SIZE];
    memset(n, 0, sizeof(n));
    //�������к��ŵķ���֮��
    for (i = 0; i < M_SIZE; i++) {
        for (j = 0; j < M_SIZE; j++)
            n[j] = gBoard[i][j];
        AIScore += count_score(n, AIChessColor);
        humScore += count_score(n, humChessColor);
        memset(n, 0, sizeof(n));
    }
    //�����������ŵķ���֮��
    for (j = 0; j < M_SIZE; j++) {
        for (i = 0; i < M_SIZE; i++)
            n[i] = gBoard[i][j];
        AIScore += count_score(n, AIChessColor);
        humScore += count_score(n, humChessColor);
        memset(n, 0, sizeof(n));
    }
    //���������°���б��(\)�ķ���֮��
    for (i = 0; i < M_SIZE; i++) {
        for (x = i, y = 0; x < M_SIZE && y < M_SIZE; x++, y++)
            n[y] = gBoard[x][y];
        AIScore += count_score(n, AIChessColor);
        humScore += count_score(n, humChessColor);
        memset(n, 0, sizeof(n));
    }
    //���������ϰ���б�ߵķ���֮��
    for (j = 1; j < M_SIZE; j++) {
        for (x = 0, y = j; y < M_SIZE && x < M_SIZE; x++, y++)
            n[x] = gBoard[x][y];
        AIScore += count_score(n, AIChessColor);
        humScore += count_score(n, humChessColor);
        memset(n, 0, sizeof(n));
    }
    //���������ϰ뷴б��(/)�ķ���֮��
    for (i = 0; i < M_SIZE; i++) {
        for (y = i, x = 0; y >= 0 && x < M_SIZE; y--, x++)
            n[x] = gBoard[x][y];
        AIScore += count_score(n, AIChessColor);
        humScore += count_score(n, humChessColor);
        memset(n, 0, sizeof(n));
    }
    //���������°뷴б�ߵķ���֮��
    for (j = 1; j < M_SIZE; j++) {
        for (y = j, x = M_SIZE - 1; y < M_SIZE && x >= 0; y++, x--)
            n[y - j] = gBoard[x][y];
        AIScore += count_score(n, AIChessColor);
        humScore += count_score(n, humChessColor);
        memset(n, 0, sizeof(n));
    }
    return AIScore - humScore; //����  AI-�� �ķ���
}

/*******************************************
Function: generate_point

Description: Ѱ�ҵ�ǰ��ֿ��������Ҷ�����������λ�á�
             Ҫ����λ��Ϊ����һ��֮�����ھ�(Ҫ�����ھ���Ϊ��ʹ����ĵط����ӽ���ʵ)
             Ps��Ϊ�˱���alpha-beta��֦��ʹ��������ʽ�����㷨����Ϊɱ����ֱ�ӷ��أ�������д��µ����� ��

Input: int player : ��ǰ�غϵ�����

Return: ���ص�ǰ��ֿ������ӵ�λ�ýṹ�壨�ṹ���а���һ�����飬��¼����λ����Ϣ��
********************************************/
chess_queue generate_point(int player) {
    int i, j = 0;
    int length;
    chess_queue rivalFive; //�Է���5
    chess_queue ComFour; //������4
    chess_queue rivalFour; //�Է�����
    chess_queue ComDoubleThree; //����˫����
    chess_queue rivalDoubleThree; //�Է�˫����
    chess_queue ComThree; //��������
    chess_queue rivalThree; //�Է�����
    chess_queue ComTwo; //�������
    chess_queue rivalTwo; //�Է����
    chess_queue others; //����
    chess_queue queue;  //���ں�������

    for (i = 0; i < M_SIZE; i++) {
        for (j = 0; j < M_SIZE; j++) {
            chess_t p;
            p.x = i, p.y = j;
            if ((gBoard[i][j] == SPACE) && hasNeighbors(i, j)) {//���ھӵĿ���,��Ϊ�����ӵĶ���
                int ComScore = evaluatePoint(player, p); //��������
                int rivalScore = evaluatePoint(player % 2 + 1, p); //�Է�����

                if (ComScore >= WIN5) { //������5
                    queue.len++;
                    queue.chess[queue.len] = p;
                    return queue; //��ɱ�壬ֱ�ӷ���
                }
                else if (rivalScore >= WIN5) { //�Է���5
                    rivalFive.len++;
                    rivalFive.chess[rivalFive.len] = p; //�Է��ı�ɱ�壬�����赲
                }
                else if (ComScore >= ALIVE4) { //��������
                    ComFour.len++;
                    ComFour.chess[ComFour.len] = p;
                }
                else if (rivalScore >= ALIVE4) { //�Է�����
                    rivalFour.len++;
                    rivalFour.chess[rivalFour.len] = p;
                }
                else if (ComScore >= 2 * ALIVE3) { //����˫����
                    ComDoubleThree.len++;
                    ComDoubleThree.chess[ComDoubleThree.len] = p;
                }
                else if (rivalScore >= 2 * ALIVE3) { //�Է�����
                    rivalDoubleThree.len++;
                    rivalDoubleThree.chess[rivalDoubleThree.len] = p;
                }
                else if (ComScore >= ALIVE3) { //��������
                    ComThree.len++;
                    ComThree.chess[ComThree.len] = p;
                }
                else if (rivalScore >= ALIVE3) { //�Է�����
                    rivalThree.len++;
                    rivalThree.chess[rivalThree.len] = p;
                }
                else if (ComScore >= ALIVE2) { //�������
                    ComTwo.len++;
                    ComTwo.chess[ComTwo.len] = p;
                }
                else if (rivalScore >= ALIVE2) { //�Է����
                    rivalTwo.len++;
                    rivalTwo.chess[rivalTwo.len] = p;
                }
                else { //����
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
    //����Ϊɱ�壬ֱ�ӷ���
    //���·Ǳ�ɱ����˽���һ�����µ����򣬰�˳���Ž�queue
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

Description: �жϵ�ǰλ�� (x,y) s��֮���Ƿ�����(�����ǶԷ����ӻ��Ǽ������ӣ�

Input: x->int ������
       y->int ������

Return: TRUE->���� ��FALSE->����
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

Description: ����ĳһ���Ӧ�ķ�����ע���˺�����Ҫ��������ʽ�����㷨���жϸõ�����ͣ�����������ĵȣ�

Input: int chessColor //������ɫ
       chess_t chess //��������

Return: �����õ��ķ���
********************************************/
int evaluatePoint(int chessColor, chess_t chess) {
    int x = chess.x, y = chess.y;
    int i, j, number = 0, empty = 2, score = 0;
    gBoard[x][y] = chessColor;
    for (i = x, j = y + 1; j < M_SIZE; j++) { //�����ۼӣ������ұ����Ӹ���
        if (gBoard[i][j] == chessColor)
            number++;
        else {
            if (gBoard[i][j] != SPACE) //�Է�����
                empty--;
            break;
        }
    }
    for (i = x, j = y; j >= 0; j--) { //�����ۼӣ�����������Ӹ���
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
    for (i = x, j = y; i >= 0; i--) { //���ϼ���
        if (gBoard[i][j] == chessColor)
            number++;
        else {
            if (gBoard[i][j] != SPACE)
                empty--;
            break;
        }
    }
    for (i = x + 1, j = y; i < M_SIZE; i++) { //���¼���
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
    for (i = x - 1, j = y + 1; i >= 0 && j < M_SIZE; i--, j++) { //�����ϼ���
        if (gBoard[i][j] == chessColor)
            number++;
        else {
            if (gBoard[i][j] != SPACE)
                empty--;
            break;
        }
    }
    for (i = x, j = y; i < M_SIZE && j >= 0; i++, j--) { //�����¼���
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
    for (i = x, j = y; i >= 0 && j >= 0; i--, j--) {//�����ϼ���
        if (gBoard[i][j] == chessColor)
            number++;
        else {
            if (gBoard[i][j] != SPACE)
                empty--;
            break;
        }
    }
    for (i = x + 1, j = y + 1; i < M_SIZE && j < M_SIZE; i++, j++) {//�����¼���
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

Description: ������һ�С��С�б�ߵ�����������λ����ÿ�ҵ�һ�����Ӿ͸��ݵ���score_table������������������������ܺͣ�������С��С�б�ߵķ�����

Input: int n[] : ����ÿһ�С��С�б�ߵ�һά����
       int chessColor : ���غ����ֵ�������ɫ

Return: ��һ�飨һά���飩�ķ����ܺ�
********************************************/
int count_score(int n[], int chessColor) {
    int i = 1; //n[0]��������Ϊ��ʼ�㵥������
    int empty = 0; //�յ�λ��
    int number = 0; //���ӵĸ���
    int scoretmp = 0; //��������ܺ�

    if (n[0] == SPACE) //λ��Ϊ��
        empty++;
    else if (n[0] == chessColor) //��������
        number++;

    while (i < M_SIZE) {
        if (n[i] == chessColor) //��������
            number++;
        else if (n[i] == SPACE) { //λ��Ϊ�գ����������������
            if (number == 0) //��һ��λ��ҲΪ��
                empty = 1;
            else { //��һ��λ��Ϊ��������
                scoretmp += score_table(number, empty + 1);
                empty = 1;
                number = 0;
            }
        }
        else {//�Է�����
            scoretmp += score_table(number, empty);
            empty = 0;
            number = 0;
        }
        i++;
    }
    scoretmp += score_table(number, empty);
    return scoretmp; //���ر�������ܺ�
}

/*************************************************
Function: score_table

Description: �������Ӹ��������˵Ŀ��Ӹ����������

Input: number->���ӵĸ���
       empty->���ӵĸ���

Return: ����
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