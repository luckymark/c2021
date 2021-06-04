#include <stdio.h>

void age()
{
    float n;
    for (float i=1; ; i++)
    {
        n=i-i/6-i/12-i/7-5-4;
        if (n*2==i)
        {
            printf("    儿子死时丢番图为%.0f岁。\n",i);
            break;
        }
    }
}

int main(int argc, const char * argv[])
{
    printf("Q:\n");
    printf("    取自《希腊诗选》（Greek Anthology）：\n");
    printf("    丢番图的童年经过了他一生的六分之一，\n");
    printf("    青年经过了十二分之一，\n");
    printf("    又有七分之一的时间是单身汉。\n");
    printf("    结婚五年后得了个儿子，\n");
    printf("    儿子比父亲先死四年，\n");
    printf("    年纪是他的一半。\n");
    printf("    问儿子死时丢番图多大？\n\n");
    printf("A:\n");
    age();
}
