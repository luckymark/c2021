//�ڰ׿�
#define empty 2
#define black 1
#define white 0
#define wall -1
#define deepth 4
#define Maxnn 1000000000
#define Minn -1000000000
//���ڴ���ÿһ�������������
typedef struct steps
{
    int scores;
    int x;
    int y;
    int num;
    steps *nextstep;
    int win;
} steps; //��һ�������Ĳ����Ӻ��������ĵ÷�
typedef struct each
{
    int x;
    int y;
    int scores;
} each; //������ÿһ���״̬*/
typedef struct continuation
{
    int deep;
    int end;
} back;
//function
int **creatboard(void);
void printf_board(int **board);                                                          //��ӡ����
void tree(int **board, int choose, steps *head, int deep, int *a, int *b, int x, int y); //���´���n����
void Roleplay(int **board, int choose);                                                  //�û�����
void Robotplay(int **board, int choose, int x, int y);                                   //����������
int steps_scores(int **board, int x, int y);                                             //��ֵ����
void copyboard(int **from, int **to);                                                    //����һ����ʱ�����̱�������״̬
int win(int **board, int x, int y);

void search(int **board, int x, int y, int dx, int dy, int obj, back *a);
int board_scores(int **board, int choose);
steps *find_steps(steps *head);
void test_board(int **board);
//else
int canplay(int **board, int x, int y);
void tree_search(steps *current, int count, int deep);
steps *head_creat(void);
int cmp1(const void *a, const void *b);
int cmp1(const void *a, const void *b);
int scores(int chesses, int ends);