#include "nibolan.h"
int main()
{
    Q Q1;
    S S1;
    char m1;
    int m2 = 0, m3 = 0, m4 = 0, m = 0;
    initQueue(&Q1);
    initStack(&S1);
    input(&Q1);
    do
    {
        m1 = Qpop(&Q1);//m1要同时储存符号和数字
        if (m1 == 0) break;
        else
        {
            if (m1 >= '0' && m1 <= '9')
            {
                m = (int)(m1 - '0');
                Sappend(&S1, m);
            }
            else
            {
                //不仅要跳出while循环，还要让不再执行下面的else，所以前面加上='\0'
                m2 = Spop(&S1);
                m3 = Spop(&S1);
                m4 = calculate(m1, m2, m3);
                Sappend(&S1, m4);
            }
        }

    }     while (m);
    printf("%d", m4);
}

void input(Q* myqueue)
{
    char str[100] = { '\0' };
    gets(str);
    for (int i = 0;str[i] != '\0';i++)
        Qappend(myqueue, str[i]);
}

int calculate(char p1, int p2, int p3)
{
    int p = 0;

    switch (p1)
    {
    case '+':   p = p3 + p2; break;
    case '-':   p = p3 - p2; break;
    case '*':   p = p3 * p2; break;
    case '/':   p = p3 / p2; break;
    case '%':   p = p3 % p2; break;
    case '^':   p = pow(p3, p2);break;
    }
    return p;
}

void initQueue(Q* myqueue)
{
    myqueue->front = myqueue->rear = 0;
}

void Qappend(Q* myqueue, char y)
{
    if (myqueue->rear == N)
        printf("失败");
    else
    {
        myqueue->dataQ[myqueue->rear] = y;
        myqueue->rear += 1;
    }
}

char Qpop(Q* myqueue)
{
    if (myqueue->front == myqueue->rear)
        return 0;
    else
    {
        myqueue->front += 1;
        return (myqueue->dataQ[myqueue->front - 1]);
    }
}

void initStack(S* mystack)
{
    mystack->top = -1;
}
void Sappend(S* mystack, int z)
{
    if (mystack->top == N - 1)
        printf("Error");
    mystack->top++;
    mystack->dataS[mystack->top] = z;
}
int Spop(S* mystack)
{
    int q;
    if (mystack->top == -1)
        printf("Error");
    //利用传出参数传出栈顶元素
    q = mystack->dataS[mystack->top];
    mystack->top--;
    return q;
}