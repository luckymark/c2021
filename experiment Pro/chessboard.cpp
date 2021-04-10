#include "head.cpp"
//空闲为0 先手执白1 后手执黑2
struct ChessBoard //某种局面
{
    int board[size][size];                     //仅需保存一盘棋局即可
    bool end_game(int x, int y, int condition) //判断游戏是否结束
    {
        for (int i = 0; i <= 7; i += 2)
            if (judge(x, y, condition, i) + judge(x, y, condition, i + 1) - 1 >= 5)
                return true;
        return false;
    }
    void print_board() //打印棋盘
    {
        system("cls");
        printf("\n");
        printf("\n");
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == -1)
                    printf("%c", '|');
                if (board[i][j] == 0)
                    printf("_");
                if (board[i][j] == 1)
                    printf("%c", 'x');
                if (board[i][j] == 2)
                    printf("%c", 'o');
                printf(" ");
            }
            printf("\n");
        }
    }
    int judge(int x, int y, int condition, int direction)
    { //判断第一个阻挡点,八个方向 0上 1下 2左 3右 4右上 5左下 6左上 7右下
        int con = 0;
        if (direction == 0) //上
        {
            while (board[x - con][y] == condition)
            {
                ++con;
                if (x - con == -1)
                    break;
            }
            return con;
        }
        if (direction == 1) //下
        {
            while (board[x + con][y] == condition)
            {
                ++con;
                if (x + con == size)
                    break;
            }
            return con;
        }
        if (direction == 2) //左
        {
            while (board[x][y - con] == condition)
            {
                ++con;
                if (y - con == -1)
                    break;
            }
            return con;
        }
        if (direction == 3) //右
        {
            while (board[x][y + con] == condition)
            {
                ++con;
                if (y + con == size)
                    break;
            }
            return con;
        }
        if (direction == 4) //右上
        {
            while (board[x - con][y + con] == condition)
            {
                ++con;
                if (x - con == -1 || y + con == size)
                    break;
            }
            return con;
        }
        if (direction == 5) //左下
        {
            while (board[x + con][y - con] == condition)
            {
                ++con;
                if (x + con == size || y - con == -1)
                    break;
            }
            return con;
        }
        if (direction == 6) //左上
        {
            while (board[x - con][y - con] == condition)
            {
                ++con;
                if (x - con == -1 || y - con == -1)
                    break;
            }
            return con;
        }
        if (direction == 7) //右下
        {
            while (board[x + con][y + con] == condition)
            {
                ++con;
                if (x + con == size || y + con == size)
                    break;
            }
            return con;
        }
        return 0;
    }
} B;
