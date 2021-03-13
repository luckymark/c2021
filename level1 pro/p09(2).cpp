// the version of self-created algorithm with union find set

#include <bits/stdc++.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;
const int size = 41;
int _map[105][105], belong[105][105];

inline int _hash(int x, int y)
{
    return (x - 1) * size + y;
}
inline int _dehashx(int num)
{
    if (num % size)
        return num / size + 1;
    else
        return num / size;
}
inline int _dehashy(int num)
{
    if (num % size == 0)
        return size;
    else
        return num - num / size * size;
}

int father(int x, int y)
{
    if (belong[x][y] == _hash(x, y))
        return belong[x][y];
    return belong[x][y] = father(_dehashx(belong[x][y]), _dehashy(belong[x][y]));
}

void print_map()
{
    system("cls");
    for (int i = 0; i <= size + 1; ++i)
    {
        for (int j = 0; j <= size + 1; ++j)
        {
            if (_map[i][j] == -1)
                putchar('x');
            else if (_map[i][j])
                putchar('0');
            else
                putchar(' ');
            putchar(' ');
        }
        printf("\n");
    }
}

int dead_loop = 0;
inline bool valid(int x, int y)
{
    if (_map[x][y] == 0)
        return false;
    if (dead_loop > 1000)
    {
        dead_loop = 0;
        return true;
    }
    if ((x <= 2 && y <= 2) || (x >= size - 1 && y >= size - 1))
        return true;
    int tot = 0;
    if (_map[x - 1][y])
        tot++;
    if (_map[x + 1][y])
        tot++;
    if (_map[x][y - 1])
        tot++;
    if (_map[x][y + 1])
        tot++;
    if (tot <= 1)
    {
        dead_loop++;
        return false;
    }
    return true;
}

void create_map()
{
    while (father(1, 1) != father(size, size))
    {
        int x = rand() % size + 1, y = rand() % size + 1;
        if (!valid(x, y))
            continue;
        _map[x][y] = 0;
        if (x - 1 && !_map[x - 1][y])
        {
            int k = father(x - 1, y);
            belong[_dehashx(k)][_dehashy(k)] = belong[x][y];
        }
        if (x + 1 <= 50 && !_map[x + 1][y])
        {
            int k = father(x + 1, y);
            belong[_dehashx(k)][_dehashy(k)] = belong[x][y];
        }
        if (y - 1 && !_map[x][y - 1])
        {
            int k = father(x, y - 1);
            belong[_dehashx(k)][_dehashy(k)] = belong[x][y];
        }
        if (y + 1 <= 50 && !_map[x][y + 1])
        {
            int k = father(x, y + 1);
            belong[_dehashx(k)][_dehashy(k)] = belong[x][y];
        }
    }
}

void game_start()
{
    int posx = 1, posy = 1;
    _map[posx][posy] = -1;
    print_map();
    while (!(posx == size && posy == size))
    {
        char c = getch();
        if (c == 'a')
            if (!_map[posx][posy - 1])
            {
                _map[posx][posy] = 0;
                posy -= 1;
                _map[posx][posy] = -1;
            }
        if (c == 'd')
            if (!_map[posx][posy + 1])
            {
                _map[posx][posy] = 0;
                posy += 1;
                _map[posx][posy] = -1;
            }
        if (c == 'w')
            if (!_map[posx - 1][posy])
            {
                _map[posx][posy] = 0;
                posx -= 1;
                _map[posx][posy] = -1;
            }
        if (c == 's')
            if (!_map[posx + 1][posy])
            {
                _map[posx][posy] = 0;
                posx += 1;
                _map[posx][posy] = -1;
            }
        print_map();
    }
    cout << "You have reached the destination!";
    return;
}

int main()
{
    freopen("out.txt", "w", stdout);
    srand(time(NULL));
    memset(_map, 1, sizeof(_map));
    for (int x = 1; x <= size; ++x)
        for (int y = 1; y <= size; ++y)
            belong[x][y] = _hash(x, y);
    create_map();
    print_map();
    printf("\n\n\n\n");
    game_start();
    return 0;
}
