#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define dd double
#define ll long long 
#define ull unsigned long long 
using namespace std;
const int maxn=100,N1=maxn+5,base=63;

int n;
int tot=0;
void mov(int dep,int st,int via,int ed)
{
    if(dep>1) mov(dep-1,st,ed,via);
    printf("step %d: %d %d -> %d\n",++tot,dep,st,ed);
    if(dep>1) mov(dep-1,via,st,ed);
}

int main()
{
    freopen("a.out","w",stdout);
    scanf("%d",&n);
    int A=1,B=2,C=3; 
    mov(n,A,B,C);
    return 0;
}


// ull f[N1];

// 题解：
// 1. 考虑递推（或归纳）， 设A柱子为起始柱，B柱子为辅助柱，C柱子为目标柱
//     假设我们已经求解出A柱子上有i个圆盘时的答案，现在需要求解有i+1个圆盘时的答案；
//     第i+1个圆盘在移动前必须保证如下条件：A中最上面的圆盘是i+1，B应该放置1~i的所有圆盘，C是空柱子
//     然后再把B当做起始柱，A当做辅助柱，把放置在B上的1~i的所有圆盘依次挪到C
//     可得递推式：f[i]=f[i-1]*2+1, f[1]=1
//     n=64可以用递推轻松求解(注意要使用unsigned long long)
