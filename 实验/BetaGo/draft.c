/*
int PD[21][15] = { {0},{0} };//principle diagonal
int BD[21][15] = { {0},{0} };//back diagonal
void flat()
{
    for (int i = 0;i < 11;i++)
        for (int j = 0;j < L-i;j++)
        {
            PD[i][j] = board[i + j][j];
            PD[10 + i][j] = board[j][i + j];
        }
    for (int i = 0;i < 11;i++)
        for (int j = 0;j < L - i;j++)
        {
            BD[i][j] = board[i + j][L - j];
            BD[10 + i][j] = board[j][L - i - j];
        }
}

void testflat()
{
    for(int i=0;i<21;i++)
        for(int j=0;j<21;j++)
            printf("%d\t", PD[i][j]);
    for (int i = 0;i < 21;i++)
        for (int j = 0;j < 21;j++)
            printf("%d\t", BD[i][j]);
}
*/ //c����ƽ�滯���ܲ�������
/*
 for(int j=0;j<15;j++)
     for (int i = 0;i < 21;i++)
     {
         if (PD[i][j] == 1)
         {
             k = 0;
             int t = i;
             while (PD[t][j] == 1)
                 t++;k++;
             if (PD[i-1][j] == 2 || PD[t+1][j] == 2)//�жϲ��Ǳ߽�
                 k--;
             if (PD[i-1][j] == 2 && PD[t+1][j] == 2)
                 k = -1;//�����������һ
             if (k >= 0)
                 human_score = human_score + pow(10, k);

         }

     }
#define ONE 10//live one
#define TWO 100
#define THREE 1000
#define FOUR 100000
#define FIVE 10000000
#define BLOCKED_ONE 1
#define BLOCKED_TWO 10
#define BLOCKED_THREE 100
#define BLOCKED_FOUR 10000
#define TWO_THREE
#define BLOCK_FOUR
#define FOUR_THREE
 */

 /*
                 k = 1;
                 int t = j;//��t��ʱ�洢j,����֮����ǰ��������Ȼ��j++,�����ظ����
                 j++;
                 while (board[i][j] == T)
                 {
                     j++;
                     k++;
                 }
                 if (board[i][j] == F || board[i][t - 1] == F || board[i][j] == wall || board[i][t - 1] == wall)
                     k--;
                 if ((board[i][j] == F && board[i][t - 1] == F) || (board[i][j] == wall && board[i][t - 1] == wall))
                     k = -1;//�����������һ
                 if (k >= 0)
                     score = score + pow(10, k);
                 j = t;
             }
         }

     for (int i = 1;i < L + 1;i++)//������
         for (int j = 1;j < L + 1;j++)
         {
             if (board[i][j] == T)
             {
                 k = 1;
                 int t = i;
                 i++;
                 while (board[i][j] == T)//i=16,���ﾭ��һ��i++��i�Ѿ�������ĺ���һ����
                 {
                     i++;
                     k++;
                 }
                 if (board[t - 1][j] == F || board[i][j] == F || board[t - 1][j] == wall || board[i][j] == wall)
                     k--;
                 if ((board[t - 1][j] == F && board[i][j] == F )|| (board[t - 1][j] == wall && board[i + 1][j] == wall))
                     k = -1;//�����������һ
                 if (k >= 0)
                     score = score + pow(10, k);
                 i = t;
             }
         }

     for (int i = 1;i < L + 1;i += 1)//������Խ���
         for (int j = 1;j < L + 1;j += 1)
         {
             if (board[i][j] == T)
             {
                 k = 1;
                 int t1 = i, t2 = j;
                 i++;
                 j++;
                 while (board[i][j] == T)
                 {
                     i++;
                     j++;
                     k++;
                 }
                 if (board[t1 - 1][t2 - 1] == F || board[i][j] == F || board[t1 - 1][t2 - 1] == wall || board[i][j] == wall)
                     //�жϲ��Ǳ߽�
                     k--;
                 if ((board[t1 - 1][t2 - 1] == F && board[i][j] == F )|| (board[t1 - 1][t2 - 1] == wall && board[i][j] == wall))
                     k = -1;//�����������һ
                 if (k >= 0)
                     score = score + pow(10, k);
                 i = t1;
                 j = t2;
             }
         }

     for (int i = 1;i < L + 1;i += 1)//��鷴�Խ���
         for (int j = 1;j < L + 1;j += 1)
         {
             if (board[i][j] == T)
             {
                 k = 1;
                 int t1 = i, t2 = j;
                 i += 1;
                 j -= 1;
                 while (board[i][j] == T)
                 {
                     i += 1;
                     j -= 1;
                     k++;
                 }
                 if (board[t1 - 1][t2 + 1] == F || board[i][j] == F || board[i][j] == wall || board[i][j] == wall)
                     k--;//�����߽�Ҳ�൱��������
                 if ((board[t1 - 1][t2 + 1] == F && board[i][j] == F )|| (board[i][j] == wall && board[i][j] == wall))
                     k = -1;//�����������һ
                 if (k >= 0)
                     score = score + pow(10, k);
                 i = t1;
                 j = t2;
             }
         }

         int DFS(int me, int others, int depth)//dfs�����Ĳ������
{
    int my_score = -100;
    int t = -1000;
    int temp;
    int cnt;
    int empty_p[100][2] = { {0},{0} };
    int a[4] = { 0 };
    int i = 0;
    int best_position = 0;
    if (depth==0)//����Ԥ�������������ݹ飬���ط���
    {
        t = evaluate(red, white) - evaluate(white, red);
        if (t > my_score)
        {
            my_score = t;
            best_position = a[0];
        }
        return best_position;
    }
    else
    {
        cnt = generator(empty_p);
        for (int k = 0;k < cnt;k++)
        {
            int tree_x = empty_p[k][0];
            int tree_y = empty_p[k][1];
            board[tree_x][tree_y] = me;
            a[i] = k;
            i++;
            temp = me;//�����з��ͼ���
            me = others;
            others = temp;
            DFS(me, others, depth--);
            board[tree_x][tree_y] = me;//���ص���һ����������

        }

    }
}

 */
