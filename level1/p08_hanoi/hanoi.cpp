//Solve this problem by the way of BV1rs411Y76X
#include<cstdio>
#include<iostream>
#include<conio.h>
#include<cstring>
using namespace std;
bool letgo(){
    char c;
    while (true){
        c = getch();
        if (c == 'y' || c == 'Y')return true;
        if (c == 'n' || c == 'N')return false;
    }
}
struct stack{
    int v[64], t;
    stack(){
        t = 0;
        memset(v, 0, sizeof v);
    }
    inline void add(const int &x){
        v[t++] = x;
    }
    inline int top(){
        if (t > 0)return v[t - 1];
        else return 64;
    }
    inline int pop(){
        return v[--t];
    }
};
int disk;
unsigned long long steps;
int mov[] = { 1,2,0 };
char tower[] = { 'A','B','C' };
struct calc{
    bool v[64];
    int x[64], t;
    stack ABC[3];
    calc(int n):t(n){
        memset(v, 0, sizeof v);
        memset(x, 0, sizeof x);
        for (int i = 0;i < n;++i)ABC[0].add(i);
    }
    inline int move(){
        for (int i = 0;i < t;++i)
            if (!v[i]){
                v[i] = 1;
                return i;
            }
            else v[i] = 0;
        return -1;
    }
    inline void next(unsigned long long st){
        int now = this->move();
        int to = mov[x[now]];
        if (now > ABC[to].top())to = mov[to];
        printf("step %llu:move disk %d from %c to %c\n", st, now + 1, tower[x[now]], tower[to]);
        ABC[x[now]].pop();
        x[now] = to;
        ABC[to].add(now);
    }
};
int main(){
    while (true){
        printf("please input the number of disks : ");
        scanf("%d", &disk);
        steps = disk == 64 ? -1 : (1ULL << disk) - 1;
        if (disk <= 6)break;
        printf("There will be %llu steps\n", steps);
        printf("Are you sure to continue?(y/n)");
        if (letgo())break;
        system("cls");
    }
    calc hanoi(disk);
    if (disk & 1)swap(tower[1], tower[2]);
    for (unsigned long long i = 0;i < steps;++i)
        hanoi.next(i + 1);
    return 0;
}