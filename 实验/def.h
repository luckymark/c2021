//�ڰ׿�
#define empty 0
#define black 1
#define white 2
//���ڴ���ÿһ�������������
typedef struct steps
{
    int scores;
    int x;
    int y;
    steps* nextstep;
} steps;
//function
int** creatboard(void);
void printf_board(int** board);   //��ӡ����
void create_tree(int **board,int choose, steps* head,int deep); //���´���n����
void Roleplay(int** board,int choose, steps* head);//�û�����
void Robotplay(int** board,int choose, steps* head);//����������
int getscores(int** board, int choose);//��ֵ����
void copyboard(int** from, int** to);//����һ����ʱ�����̱�������״̬
void win(int** board);
//else

