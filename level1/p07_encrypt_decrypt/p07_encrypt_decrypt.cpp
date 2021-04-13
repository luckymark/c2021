#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#define dd double
#define ll long long 
using namespace std;
const int maxn=100,N1=maxn+5,base=63;

// base64:
char encx(int x)
{
    x=x&base;
    if(0<=x&&x<=25) return x+'A';
    if(26<=x&&x<=51) return x-26+'a';
    if(52<=x&&x<=61) return x-52+'0';
    if(x==62) return '+'; else return '/';
}
int decx(char x)
{
    if('A'<=x&&x<='Z') return x-'A';
    if('a'<=x&&x<='z') return x-'a'+26;
    if('0'<=x&&x<='9') return x-'0'+52;
    if(x=='+') return 62; else return 63;
}
int encrypt(char *s,char *enc,int len)
{
    int n=0,tmp,i;
    for(i=0;i<len;i+=3)
    {
        tmp=(*(int*)(s+i))&0xffffff; 
        enc[n++]=encx(tmp); tmp>>=6;
        enc[n++]=encx(tmp); tmp>>=6;
        enc[n++]=encx(tmp); tmp>>=6;
        enc[n++]=encx(tmp);
    }
    if(len%3==1) enc[n-1]='=', enc[n-2]='=';
    else if(len%3==2) enc[n-1]='='; 
    return n;
}
void decrypt(char *enc,char *s)
{
    int tmp,y,len=strlen(enc);
    if(enc[len-1]=='=') enc[len-1]='A'; if(enc[len-2]=='=') enc[len-2]='A';
    for(int i=0,j;i<len;i+=4)
    {
        j=i/4; tmp=0;
        y=decx(enc[i+3]); tmp|=y; tmp<<=6;
        y=decx(enc[i+2]); tmp|=y; tmp<<=6;
        y=decx(enc[i+1]); tmp|=y; tmp<<=6;
        y=decx(enc[i]); tmp|=y;
        *(int*)(s+j*3)=tmp;
    }
}

char origin[N1],ency[N1],decy[N1];

int main()
{
    freopen("a.in","r",stdin);
    scanf("%s",origin); int len=strlen(origin);
    int lene=encrypt(origin,ency,len);
    for(int i=0;i<lene;i++) printf("%c",ency[i]); puts("");
    decrypt(ency,decy);
    for(int i=0;i<lene;i++) printf("%c",decy[i]); puts("");
    return 0;
}

