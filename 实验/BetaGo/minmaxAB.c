/*
int minMax_AB(int depth, int me, int Alpha, int Beta, int tmp_board[][L+2])
//��������,tΪ1��ʾ���壬Ϊ2��ʾ����,����ʱAlpha��Beta��ΪNGIF,PTIF
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
    if (depth % 2)//�ж���min�㻹��max��,������min��
    {
        for (i = 1;i < L + 1;i++)
            for (j = 1;j < L + 1;j++)
            {
                if (!tmp_board[i][j]&& neighbor(i, j) && tree.Alpha < tree.Beta)
                {
                    memcpy(c, tmp_board, sizeof(int) * L * L);//��������
                    c[i][j] = me;
                    if (judge_winner(i, j, white) == white && depth == rank-1)
                        //����������Է��Ѿ��л��ľͱ����
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
                            return tree.Alpha;//����֦�����������ڵ�
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
                    //��һ���µ������ʾ���̣������ƻ�ԭ����
                    c[i][j] = me;
                    if (judge_winner(i, j, red) == red&&depth==rank)
                        //����������Լ��Ѿ��л��ľͱ��������
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
                            return tree.Beta;//����֦�����������ڵ�
                    }
                }
            }
        AI_x = tree.X;
        AI_y = tree.Y;
        return tree.Alpha;
    }

}


*/
