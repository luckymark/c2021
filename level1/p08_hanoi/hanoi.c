#include <stdio.h>
#include <windows.h>
typedef struct Set
{
    int m;
    char x, y, z;
} SET; //用于操作柱子编号以及递归层数
SET *Change(SET *Q)
{
    char n;
    n = Q->x;
    Q->x = Q->y;
    Q->y = Q->z;
    Q->z = n;
    return Q;
}
SET *Hanoi(int m, SET *P)
{
    if (m == 2)
    {
        return P;
    }
    else
    {

        Hanoi(m - 1, P);
        printf("%c to %c , %c to %c , %c to %c , ", P->x, P->z, P->x, P->y, P->z, P->y);
        printf("\n%c to %c\n", P->x, P->z);
        Change(P);
        Hanoi(m - 1, P);
        printf("%c to %c , %c to %c , %c to %c , ", P->x, P->z, P->x, P->y, P->z, P->y);
        if (m != P->m)
        {
            if (m != 2)
            {
                if (m % 2 == 0)
                    printf("\n%c to %c\n", P->x, P->z);
                else
                    printf("\n%c to %c\n", P->z, P->x);
            }
        }
        Change(P);
    }
}
int main()
{
    SET hanoi;
    hanoi.x = 'a';
    hanoi.y = 'b';
    hanoi.z = 'c';
    scanf("%d", &hanoi.m);
    if (hanoi.m == 2)
        printf("%c to %c , %c to %c , %c to %c , ", hanoi.x, hanoi.z, hanoi.x, hanoi.y, hanoi.z, hanoi.y); //两层时
    else
        Hanoi(hanoi.m, &hanoi); //两层以上时

    system("Pause");
    return 0;
}