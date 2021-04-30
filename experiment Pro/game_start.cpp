#include "head.cpp"
void game_start() //玩家对战电脑模式，玩家先手
{
    memset(B.board, 0, sizeof(B.board));
    printf("player first? y or n\n");
    char c;
    cin >> c;
    if (c == 'n')
        B.board[size / 2][size / 2] = 2; //电脑先手
    B.print_board();
    int round = 0;
    while (true)
    {
        round += 2;
        if (round >= size * size - 4) //和棋
        {
            printf("Peaciful end!");
            return;
        }
        int x = 0, y = 0, pre = B.board[0][0]; //记录之前这个位置的放置类型
        B.board[x][y] = -1;
        while (true) //玩家操作
        {
            char c = getch();
            if (c == 'j' && !pre) //落子
            {
                B.board[x][y] = 1;
                previousx = x;
                previousy = y;
                B.print_board();
                if (B.end_game(x, y, 1)) //玩家获胜
                {
                    printf("The player wins!");
                    return;
                }
                break;
            }
            if (c == 'a') //左
            {
                if (y - 1 > -1)
                {
                    B.board[x][y] = pre;
                    pre = B.board[x][y - 1];
                    --y;
                    B.board[x][y] = -1;
                }
            }
            if (c == 's') //下
            {
                if (x + 1 < size)
                {
                    B.board[x][y] = pre;
                    pre = B.board[x + 1][y];
                    ++x;
                    B.board[x][y] = -1;
                }
            }
            if (c == 'w') //上
            {
                if (x - 1 > -1)
                {
                    B.board[x][y] = pre;
                    pre = B.board[x - 1][y];
                    --x;
                    B.board[x][y] = -1;
                }
            }
            if (c == 'd') //右
            {
                if (y + 1 < size)
                {
                    B.board[x][y] = pre;
                    pre = B.board[x][y + 1];
                    ++y;
                    B.board[x][y] = -1;
                }
            }
            B.print_board();
        }
        int score = -INT_MAX, new_score; //电脑操作
        x = 0;
        y = 0;
        for (int i = max(0, previousx - 5); i < min(size, previousx + 5); i++)
            for (int j = max(0, previousy - 5); j < min(size, previousy + 5); j++)
            {
                if (B.board[i][j])
                    continue;
                new_score = take_step_value(i, j, 2, &node[1], 1); //用最强的电脑棋手与之对战
                if ((new_score > score) || ((new_score == score) && (rand() | 1)))
                {
                    x = i;
                    y = j;
                    score = new_score;
                }
            }
        B.board[x][y] = 2; //落子
        B.print_board();
        if (B.end_game(x, y, 2)) //电脑获胜
        {
            printf("The computer wins!");
            return;
        }
    }
}