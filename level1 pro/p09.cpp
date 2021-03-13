// the version of Random Prime algorithm

#include <bits/stdc++.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;
const int size = 31;
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

void create_map()
{
    int visited = 0;
    queue<int> que;
    int posx, posy;
    que.push(1);
    visited++;
    while (!que.empty())
    {
        //print_map();
        int p = que.front();
        posx = _dehashx(p);
        posy = _dehashy(p);
        int tot = 0;
        while (true)
        {
            if (tot >= 4)
            {
                que.pop();
                break;
            }
            int k = rand() % 4 + 1;
            if (k == 1)
            {
                if (posx == 1)
                {
                    ++tot;
                    continue;
                }
                if (father(posx - 2, posy) != father(posx, posy))
                {
                    visited++;
                    que.push(_hash(posx - 2, posy));
                    _map[posx - 1][posy] = 0;
                    belong[posx - 2][posy] = 1;
                    break;
                }
                else
                {
                    ++tot;
                    continue;
                }
            }
            if (k == 2)
            {
                if (posx == size)
                {
                    ++tot;
                    continue;
                }
                if (father(posx + 2, posy) != father(posx, posy))
                {
                    visited++;
                    que.push(_hash(posx + 2, posy));
                    _map[posx + 1][posy] = 0;
                    belong[posx + 2][posy] = 1;
                    break;
                }
                else
                {
                    ++tot;
                    continue;
                }
            }
            if (k == 3)
            {
                if (posy == 1)
                {
                    ++tot;
                    continue;
                }
                if (father(posx, posy - 2) != father(posx, posy))
                {
                    visited++;
                    que.push(_hash(posx, posy - 2));
                    _map[posx][posy - 1] = 0;
                    belong[posx][posy - 2] = 1;
                    break;
                }
                else
                {
                    ++tot;
                    continue;
                }
            }
            if (k == 4)
            {
                if (posy == size)
                {
                    ++tot;
                    continue;
                }
                if (father(posx, posy + 2) != father(posx, posy))
                {
                    visited++;
                    que.push(_hash(posx, posy + 2));
                    _map[posx][posy + 1] = 0;
                    belong[posx][posy + 2] = 1;
                    break;
                }
                else
                {
                    ++tot;
                    continue;
                }
            }
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
    srand(time(NULL));
    memset(_map, 1, sizeof(_map));
    for (int x = 0; x <= size + 1; ++x)
        for (int y = 0; y <= size + 1; ++y)
        {
            if (x % 2 && y % 2)
                _map[x][y] = 0;
            else
                _map[x][y] = 1;
            belong[x][y] = _hash(x, y);
        }
    _map[size + 1][size + 1] = 1;
    create_map();
    print_map();
    printf("\n\n\n\n");
    game_start();
    return 0;
}