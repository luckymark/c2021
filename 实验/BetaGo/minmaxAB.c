/*
int minMax_AB(int depth, int me, int Alpha, int Beta, int tmp_board[][L+2])
//分数传递,t为1表示红棋，为2表示白棋,调用时Alpha，Beta赋为NGIF,PTIF
{
    int i, j;
    int c[L+2][L+2];
    int minmax;
    int rival;
    Tree tree;
    tree.Alpha = Alpha;
    tree.Beta = Beta;
    tree.X = 0;
    tree.Y = 0;
    if (me == 1)
        rival = 2;
    else
        rival = 1;
    if (depth == 0|| judge_winner(tree.X, tree.Y, me) == me)
        return evaluate(me, tmp_board)-evaluate(rival,tmp_board);
    if (depth % 2)//判断是min层还是max层,奇数是min层
    {
        for (i = 1;i < L + 1;i++)
            for (j = 1;j < L + 1;j++)
            {
                if (!tmp_board[i][j]&& neighbor(i, j) && tree.Alpha < tree.Beta)
                {
                    memcpy(c, tmp_board, sizeof(int) * L * L);//更新棋盘
                    c[i][j] = me;
                    if (judge_winner(i, j, white) == white && depth == rank-1)
                        //优先情况：对方已经有活四就必须堵
                    {
                        AI_x = j;
                        AI_y = i;
                        return 0;
                    }
                    minmax = minMax_AB(depth - 1, rival, tree.Alpha, tree.Beta, c);
                    c[i][j] = 0;
                    if (minmax < tree.Beta)
                    {
                        tree.Beta = minmax;
                        tree.X = j;
                        tree.Y = i;
                        if (tree.Alpha >= tree.Beta)
                            return tree.Alpha;//α剪枝，抛弃后续节点
                    }
                }
            }
        return tree.Beta;
    }
    else
    {
        for (i = 1;i < L + 1;i++)
            for (j = 1;j < L + 1;j++)
            {
                if (!tmp_board[i][j] && neighbor(i, j) && tree.Alpha < tree.Beta)
                {
                    memcpy(c, tmp_board, sizeof(int) * L * L);
                    //用一个新的数组表示棋盘，以免破坏原棋盘
                    c[i][j] = me;
                    if (judge_winner(i, j, red) == red&&depth==rank)
                        //优先情况：自己已经有活四就必须接着下
                    {
                        AI_x = j;
                        AI_y = i;
                        return 0;
                    }
                    minmax = minMax_AB(depth - 1, rival, tree.Alpha, tree.Beta,c);
                    c[i][j] = 0;
                    if (minmax > tree.Alpha)
                    {
                        tree.Alpha = minmax;
                        tree.X = j;
                        tree.Y = i;
                        if (tree.Alpha >= tree.Beta)
                            return tree.Beta;//α剪枝，抛弃后续节点
                    }
                }
            }
        AI_x = tree.X;
        AI_y = tree.Y;
        return tree.Alpha;
    }

}


*/
