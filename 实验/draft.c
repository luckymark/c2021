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
*/ //c语言平面化可能并不方便
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
             if (PD[i-1][j] == 2 || PD[t+1][j] == 2)//判断不是边界
                 k--;
             if (PD[i-1][j] == 2 && PD[t+1][j] == 2)
                 k = -1;//区分死棋和死一
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
