//�ڰ׿�
#define empty 2
#define black 1
#define white 0
#define wall -1
#define deepth 2
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
} steps; //��һ�������Ĳ����Ӻ��������ĵ÷�
/*typedef struct each
{
    int x;
    int y;
    int scores;
}each;//������ÿһ���״̬*/
typedef struct back
{
    int deep;
    int end;
} back;
//function
int **creatboard(void);
void printf_board(int **board);                                            //��ӡ����
void tree(int **board, int choose, steps *head, int deep, int *a, int *b); //���´���n����
void Roleplay(int **board, int choose, steps *head);                       //�û�����
void Robotplay(int **board, int choose, steps *head);                      //����������
int steps_scores(int **board, int x, int y);                               //��ֵ����
void copyboard(int **from, int **to);                                      //����һ����ʱ�����̱�������״̬
int win(int **board, int x, int y);
int judge_win(int **board, int x, int y, int dx, int dy, int obj, int deep);
void judge_ends(int **board, int x, int y, int dx, int dy, int obj, int deep, back *a);
int board_scores(int **board, int choose);
steps *find_steps(steps *head);
void test_board(int **board);
//else
