#include<windows.h>
#include<conio.h>
#include<cstdio>
#include<queue>
#include<ctime>
using namespace std;
const char wall = 'X';
const int mx[] = { 1,-1,0,0 };
const int my[] = { 0,0,1,-1 };
typedef  pair<pair<int, int>, pair<int, int>> mwall;
priority_queue<mwall>q;
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
struct maze{
    bool m[201][201];
    bool met[201][201];
    int height, width;
    int px, py;
    int mstep;
    maze(int x, int y):height(x), width(y){
        memset(m, 1, sizeof m);
        memset(met, 0, sizeof met);
        for (int i = 1;i < height;i += 2)
            for (int j = 1;j < width;j += 2)
                m[i][j] = 0;
        px = 1;py = 0;
        m[1][0] = 0;
        m[height - 1][width] = 0;
        mstep = 0;
        initmaze();
    }
    mwall makeWall(int x, int y, int d){
        return make_pair(make_pair(rand(), d), make_pair(x, y));
    }
    bool trymet(int &x, int &y, int d){
        if (!met[x + mx[d] * 2][y + my[d] * 2]){
            m[x += mx[d]][y += my[d]] = 0;
            return met[x += mx[d]][y += my[d]] = 1;
        }
        return 0;
    }
    void initmaze(){
        met[1][0] = met[1][1] = 0;
        q.push(makeWall(1, 1, 0));
        q.push(makeWall(1, 1, 2));
        while (!q.empty()){
            mwall w = q.top();
            int x = w.second.first, y = w.second.second, d = w.first.second;
            q.pop();
            if (trymet(x, y, d))
                for (int i = 0;i <= 3;++i)
                    if (m[x + mx[i]][y + my[i]] && x + mx[i] && y + my[i] && x + mx[i] * 2 < height && y + my[i] * 2 < width && !met[x + mx[i] * 2][y + my[i] * 2])
                        q.push(makeWall(x, y, i));
        }
        for (int i = 0;i <= height;++i){
            for (int j = 0;j <= width;++j)
                if (px == i && py == j)putchar('O');
                else putchar(m[i][j] ? wall : ' ');
            putchar('\n');
        }
        printf("Score:%d          press ESC to exit\n", mstep);
    }
    void writeScreen(int x, int y, char c){
        unsigned long a;
        if (!FillConsoleOutputCharacter(hout, c, 1, { (short)y,(short)x }, &a))a = GetLastError();
    }
    bool trymove(int x){
        if (!m[px + mx[x]][py + my[x]]){
            writeScreen(px, py, ' ');
            px += mx[x];
            py += my[x];
            writeScreen(px, py, 'O');
            ++mstep;
            SetConsoleCursorPosition(hout, { 6,(short)(height + 1) });
            printf("%d", mstep);
            SetConsoleCursorPosition(hout, { (short)(width + 1),(short)(height + 1) });
            if (px == height - 1 && py == width)win();
            return true;
        }
        return false;
    }
    bool move(char c){
        switch (c){
            case 80:return trymove(0);
            case 72:return trymove(1);
            case 77:return trymove(2);
            case 75:return trymove(3);
            case 27:exit(0);
        }
        return false;
    }
    void win(){
        system("cls");
        printf("you win with score %d\n", mstep);
        printf("press any key to exit\n");
        getchar();
        exit(0);
    }
};
int main(){
    srand(time(NULL));
    printf("press any key to start\n");
    getch();
    system("cls");
    maze *map = new maze(10 << 1, 10 << 1);
    while (true)
        if (kbhit())
            if (map->move(getch()))
                Sleep(10);
    return 0;
}