#include <stdio.h>
#include <windows.h>
#include <string.h>
typedef struct Good
{
    char name[20];
    char mode[20];
    int numbers;
} good;

void goodprintf(good *current);
void get(char putin[20], good *current);
int checkname(char putin[], good *current, int goods);
int goodout(good *current, char wantout[], int goods);
void deleteit(good *current, int i, int goods);
int main()
{
    int choose = 4;
    int goods = 0;
    good *head = NULL;
    while (1)
    {
        printf("please choose what you want\n1--show the list\n2--put in\n3--put out\n4--exit\n");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
        {
            if (goods == 0)
                printf("there is nothing in the warehouse\n");
            else
                for (int i = 1; i <= goods; i++)
                    goodprintf(head + i - 1);
            break;
        }
        case 2:
        {
            int cont = 1;
            int a = 0;
            while (cont)
            {
                char putin[20];
                printf("The name the good you want to put in\n");
                scanf("%s", putin);

                if (goods == 0)
                {
                    goods++;
                    head = (good *)realloc(head, goods * sizeof(good));
                    if (head == NULL)
                        exit(1);
                    get(putin, head + goods - 1);
                }
                else
                {
                    if (a = checkname(putin, head, goods))
                    {
                        int add;
                        puts("how many");
                        scanf("%d", &add);
                        (head + a - 1)->numbers = (head + a - 1)->numbers + add;
                    }
                    else
                    {
                        goods++;
                        head = (good *)realloc(head, goods * sizeof(good));
                        if (head == NULL)
                            exit(1);
                        get(putin, head + goods - 1);
                    }
                }

                printf("continue? yes-1 no-0\n");
                scanf("%d", &cont);
            }
            break;
        }
        case 3:
        {
            char wantout[20];
            printf("please tell me which good you want to put it out\n");
            for (int i = 1; i <= goods; i++)
                goodprintf(head + i - 1);
            scanf("%s", wantout);
            if (!goodout(head, wantout, goods))
                goods--;
            break;
        }
        case 4:
            free(head);
            return 0;
        default:
            break;
        }
    }
}
void goodprintf(good *current)
{
    printf("Name:%s  ", current->name);
    printf("Mode:%s  ", current->mode);
    printf("Numbers:%d\n", current->numbers);
}
void get(char putin[20], good *current)
{
    strcpy(current->name, putin);
    printf("please input the mode of good\n");
    scanf("%s", current->mode);
    printf("please input the numbers\n");
    scanf("%d", &current->numbers);
}
int checkname(char putin[], good *current, int goods)
{
    for (int i = 1; i <= goods; i++)
    {
        if (strcmp(putin, (current + i - 1)->name))
            return 0;
        else
            return i;
    }
}
int goodout(good *current, char wantout[], int goods)
{
    for (int i = 1; i <= goods; i++)
    {
        if (!strcmp((current + i - 1)->name, wantout))
        {
            int outnum, check = 1;
            while (check)
            {
                printf("tell me how many do you want to let out,the current number is %d\n", (current + i - 1)->numbers);
                scanf("%d", &outnum);
                if (outnum > (current + i - 1)->numbers)
                {
                    puts("too much,again");
                }
                else if (outnum < (current + i - 1)->numbers)
                {
                    (current + i - 1)->numbers = (current + i - 1)->numbers - outnum;
                    return 1;
                }
                else
                {
                    deleteit(current, i, goods);
                    goods--;
                    current = (good *)realloc(current, goods * sizeof(good));
                    return 0;
                }
            }
        }
        else if (i == goods)
        {
            puts("no such good");
            return 1;
        }
    }
}
void deleteit(good *current, int i, int goods)
{
    for (int j = 1; j <= goods - i; j--)
    {
        current[i + j - 2] = current[i + j - 1];
    }
}