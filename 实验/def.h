//黑白空
#define empty 0
#define black 1
#define white 2
//用于储存每一步可能情况的树
typedef struct steps
{
    int scores;
    int x;
    int y;
    steps* nextstep;
} steps;
//function
int** creatboard(void);
void printf_board(int** board);   //打印棋盘
void create_tree(int **board,int choose, steps* head,int deep); //往下创建n层树
void Roleplay(int** board,int choose, steps* head);//用户下棋
void Robotplay(int** board,int choose, steps* head);//机器人下棋
int getscores(int** board, int choose);//估值函数
void copyboard(int** from, int** to);//生成一个暂时的棋盘保存棋盘状态
void win(int** board);
//else

