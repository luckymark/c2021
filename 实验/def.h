//黑白空
#define empty 2
#define black 1
#define white 0
#define wall -1
#define deepth 2
#define Maxnn 1000000000
#define Minn -1000000000
//用于储存每一步可能情况的树
typedef struct steps
{
    int scores;
    int x;
    int y;
    int num;
    steps *nextstep;
} steps; //这一步下了哪步棋子和这个方向的得分
/*typedef struct each
{
    int x;
    int y;
    int scores;
}each;//棋盘上每一格的状态*/
typedef struct back
{
    int deep;
    int end;
} back;
//function
int **creatboard(void);
void printf_board(int **board);                                            //打印棋盘
void tree(int **board, int choose, steps *head, int deep, int *a, int *b); //往下创建n层树
void Roleplay(int **board, int choose, steps *head);                       //用户下棋
void Robotplay(int **board, int choose, steps *head);                      //机器人下棋
int steps_scores(int **board, int x, int y);                               //估值函数
void copyboard(int **from, int **to);                                      //生成一个暂时的棋盘保存棋盘状态
int win(int **board, int x, int y);
int judge_win(int **board, int x, int y, int dx, int dy, int obj, int deep);
void judge_ends(int **board, int x, int y, int dx, int dy, int obj, int deep, back *a);
int board_scores(int **board, int choose);
steps *find_steps(steps *head);
void test_board(int **board);
//else
