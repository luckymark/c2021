#include<stdio.h>
int A[65] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
            20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,
            40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,
            60,61,62,63,64}, B[65] = { 0 }, C[65] = { 0 };
void AddXToY(int x[], int y[])
{
    int m = 0, n = 0;
    while (x[m] == 0 && m < 64)
        m++;
    while (y[n] == 0 && n < 64)
        n++;
    if (y[n] != x[n] && (y[n] > x[m] || y[n + 1] > x[m] || y[n] == 0))
    {
        if (y[n] != 0)y[n - 1] = x[m];
        else  y[n] = x[m];
        x[m] = 0;
    }
}
int main()
{   
    printf("A\tB\tC\n");
    for (int n=1;n<=64;n++) 
    {
        printf("%d\t%d\t%d\n",A[n],B[n],C[n]);
    }
    char x, y;
    int k;
    int* x1=0, * y1=0;
    int* p, * q;
    while (!(A[64] == 0 && (B[1] == 1 || C[1] == 1)))
    {

        printf("请输入A/B/C A/B/C\n");
        scanf("%d", &k);
        scanf("%c %c", &x, &y);
        switch (x)
        {
        case 'a' | 'A': p = A;  break;
        case 'b' | 'B':p = B; break;
        case'c' | 'C':p = C; break;
        default:printf("error\n"); continue;
        }
        switch (y)
        {
        case 'a' | 'A':q = A;  break;
        case 'b' | 'B':q = B;break;
        case'c' | 'C':q = C; break;
        default:printf("error\n");continue;
        }
        AddXToY(p, q);
        for (int n = 1;n <= 64;n++)
        {
            printf("%d\t%d\t%d\n", A[n], B[n], C[n]);
        }
    }
}
