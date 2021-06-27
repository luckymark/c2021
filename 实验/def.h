//一些宏定义
#define useful 3         //落棋有意义的位置
#define empty 2          //没有棋子的位置
#define black 1          //黑棋
#define white 0          //白棋
#define wall -1          //围墙
#define deepth 6         //搜索深度
#define Maxnn 1000000000 //无穷大
#define Minn -1000000000 //无穷小

//记录可能落子点的坐标和分数
typedef struct steps
{
    int scores;
    int x;
    int y;
    int num;
    steps *nextstep;
    int win;
} steps;

//棋盘上每一格的状态
typedef struct each
{
    int x;
    int y;
    int scores;
} each;

//用于棋盘搜索的数据整合
typedef struct seek
{
    int robot;
    int role;
    int sum;
    int end;
} seek;

//启发式搜索返回深度和端点状态
typedef struct continuation
{
    int deep;
    int end;
} back;

//函数
//处理棋盘类
int **creatboard(void);
void printf_board(int **board);
//基础功能类
void Roleplay(int **board, int choose);
void Robotplay(int **board, int choose, int x, int y);
//博弈树核心函数
void tree(int **board, int choose, steps *head, int deep, int *a, int *b, int x, int y);
void tree_search(steps *current, int count, int deep);
//构建树辅助函数
steps *head_creat(void);
void mark(int **board, int x, int y);
steps *find_steps(steps *head);
//判断赋分类
int win(int **board, int x, int y);
int board_scores(int **board, int choose);
void line_search(int **board, int i, int j, seek *s, int user);
int scores(int chesses, int ends);
//启发式搜索(未启用)
int steps_scores(int **board, int x, int y);
void search(int **board, int x, int y, int dx, int dy, int obj, back *a);
int cmp1(const void *a, const void *b);
int cmp2(const void *a, const void *b);