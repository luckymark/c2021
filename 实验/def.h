//һЩ�궨��
#define useful 3         //�����������λ��
#define empty 2          //û�����ӵ�λ��
#define black 1          //����
#define white 0          //����
#define wall -1          //Χǽ
#define deepth 6         //�������
#define Maxnn 1000000000 //�����
#define Minn -1000000000 //����С

//��¼�������ӵ������ͷ���
typedef struct steps
{
    int scores;
    int x;
    int y;
    int num;
    steps *nextstep;
    int win;
} steps;

//������ÿһ���״̬
typedef struct each
{
    int x;
    int y;
    int scores;
} each;

//����������������������
typedef struct seek
{
    int robot;
    int role;
    int sum;
    int end;
} seek;

//����ʽ����������ȺͶ˵�״̬
typedef struct continuation
{
    int deep;
    int end;
} back;

//����
//����������
int **creatboard(void);
void printf_board(int **board);
//����������
void Roleplay(int **board, int choose);
void Robotplay(int **board, int choose, int x, int y);
//���������ĺ���
void tree(int **board, int choose, steps *head, int deep, int *a, int *b, int x, int y);
void tree_search(steps *current, int count, int deep);
//��������������
steps *head_creat(void);
void mark(int **board, int x, int y);
steps *find_steps(steps *head);
//�жϸ�����
int win(int **board, int x, int y);
int board_scores(int **board, int choose);
void line_search(int **board, int i, int j, seek *s, int user);
int scores(int chesses, int ends);
//����ʽ����(δ����)
int steps_scores(int **board, int x, int y);
void search(int **board, int x, int y, int dx, int dy, int obj, back *a);
int cmp1(const void *a, const void *b);
int cmp2(const void *a, const void *b);