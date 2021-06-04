#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Time(int item,int len)
{
    int key=1;
    item+=1;
    while (item+key<=len)
    {
        item+=key;
        key++;
    }
    return key-1;
}

char *Encrypt(char *p)
{
    int len=(int)strlen(p);
    char flag;
    char *key=(char*)malloc(len);
    strcpy(key, p);
    for (int i=0; i<=len; i++)
    {
        int item=i,j=1;
        while (item+j<len)
        {
            flag=key[item];
            key[item]=key[item+j];
            key[item+j]=flag;
            item+=j;
            j++;
        }
    }
    return key;
}

char *Decrypt(char *q)
{
    int len=(int)strlen(q);
    char flag;
    char *key=(char*)malloc(len);
    strcpy(key, q);
    for (int i=2; i<=len; i++)
    {
        int item=len-i,end=item;
        int time=Time(item, len);
        for (int j=1; j<=time; j++) end+=j;
        while (time>0)
        {
            flag=key[end];
            key[end]=key[end-time];
            key[end-time]=flag;
            end-=time;
            time--;
        }
    }
    return key;
}

char *strInput()
{
    int len=100,cnt=0,c;
    char *p=NULL;
    p=(char*)malloc(len);
    while ((c=getchar())!='\n')
    {
        p[cnt++]=c;
        if(cnt>=len-1)
        {
            len+=100;
            p=(char*)realloc(p, len);
        }
    }
    return p;
}

int main(int argc, const char * argv[])
{
    printf("请输入要加密的字符串：");
    char *p=strInput();
    char *cryptogram=Encrypt(p);
    printf("加密后的字符串为：%s\n",cryptogram);
    printf("请输入要解密的字符串：");
    char *q=strInput();
    char *decipher=Decrypt(q);
    printf("解密后的字符串为：%s\n",decipher);
}
