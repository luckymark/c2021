#include <bits/stdc++.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;
const int size[4] = {0, 21, 31, 41};
int _map[105][105], step;
bool carry;
int level;
//-2:* -1:x 0:  1:0 2:$ 3:#
void read_map()
{
    char c;
    for (int i = 0; i <= size[level] + 1; i++)
    {
        for (int j = 0; j <= size[level] + 1; j++)
        {
            c = getchar();
            if (c == ' ')
                _map[i][j] = 0;
            if (c == '0')
                _map[i][j] = 1;
            if (c == '$')
                _map[i][j] = 2;
            if (c == '#')
                _map[i][j] = 3;
            c = getchar();
        }
        c = getchar();
    }
}

void print_map()
{
    system("cls");
    for (int x = 0; x <= size[level] + 1; ++x)
    {
        for (int y = 0; y <= size[level] + 1; ++y)
        {
            if (_map[x][y] == -1 && carry)
                putchar('+');
            if (_map[x][y] == -1 && !carry)
                putchar('x');
            if (_map[x][y] == 0)
                putchar(' ');
            if (_map[x][y] == 1)
                putchar('0');
            if (_map[x][y] == 2)
                putchar('$');
            if (_map[x][y] == 3)
                putchar('#');
            putchar(' ');
        }
        printf("\n");
    }
}

void start_game()
{
    read_map();
    if (level == 1)
    {
        cout << "easy level !";
        Sleep(1500);
    }
    if (level == 2)
    {
        cout << "medium level !";
        Sleep(1500);
    }
    if (level == 3)
    {
        cout << "hard level !";
        Sleep(1500);
    }
    int tot = 4, posx = 1, posy = 1;
    _map[posx][posy] = -1;
    carry = false;
    print_map();
    while (tot)
    {
        char c = getch();
        if (c == 'a')
        {
            if (!_map[posx][posy - 1])
            {
                if (_map[posx][posy] == -1)
                    _map[posx][posy] = 0;
                posy -= 1;
                _map[posx][posy] = -1;
            }
            if (_map[posx][posy - 1] == 2)
            { //$
                if (_map[posx][posy] == -1)
                    _map[posx][posy] = 0;
                posy -= 1;
                if (!carry)
                {
                    _map[posx][posy] = -1;
                    carry = true;
                }
            }
            if (_map[posx][posy - 1] == 3)
            { //#
                if (_map[posx][posy] == -1)
                    _map[posx][posy] = 0;
                posy -= 1;
                if (carry)
                {
                    _map[posx][posy] = -1;
                    carry = false;
                    tot--;
                }
            }
        }
        if (c == 'd')
        {
            if (!_map[posx][posy + 1])
            {
                if (_map[posx][posy] == -1)
                    _map[posx][posy] = 0;
                posy += 1;
                _map[posx][posy] = -1;
            }
            if (_map[posx][posy + 1] == 2)
            { //$
                if (_map[posx][posy] == -1)
                    _map[posx][posy] = 0;
                posy += 1;
                if (!carry)
                {
                    _map[posx][posy] = -1;
                    carry = true;
                }
            }
            if (_map[posx][posy + 1] == 3)
            { //#
                if (_map[posx][posy] == -1)
                    _map[posx][posy] = 0;
                posy += 1;
                if (carry)
                {
                    _map[posx][posy] = -1;
                    carry = false;
                    tot--;
                }
            }
        }
        if (c == 'w')
        {
            if (!_map[posx - 1][posy])
            {
                if (_map[posx][posy] == -1)
                    _map[posx][posy] = 0;
                posx -= 1;
                _map[posx][posy] = -1;
            }
            if (_map[posx - 1][posy] == 2)
            { //$
                if (_map[posx][posy] == -1)
                    _map[posx][posy] = 0;
                posx -= 1;
                if (!carry)
                {
                    _map[posx][posy] = -1;
                    carry = true;
                }
            }
            if (_map[posx - 1][posy] == 3)
            { //#
                if (_map[posx][posy] == -1)
                    _map[posx][posy] = 0;
                posx -= 1;
                if (carry)
                {
                    _map[posx][posy] = -1;
                    carry = false;
                    tot--;
                }
            }
        }
        if (c == 's')
        {
            if (!_map[posx + 1][posy])
            {
                if (_map[posx][posy] == -1)
                    _map[posx][posy] = 0;
                posx += 1;
                _map[posx][posy] = -1;
            }
            if (_map[posx + 1][posy] == 2)
            { //$
                if (_map[posx][posy] == -1)
                    _map[posx][posy] = 0;
                posx += 1;
                if (!carry)
                {
                    _map[posx][posy] = -1;
                    carry = true;
                }
            }
            if (_map[posx + 1][posy] == 3)
            { //#
                if (_map[posx][posy] == -1)
                    _map[posx][posy] = 0;
                posx += 1;
                if (carry)
                {
                    _map[posx][posy] = -1;
                    carry = false;
                    tot--;
                }
            }
            ++step;
        }
        print_map();
    }
}
int main()
{
    freopen("p10 map.txt", "r", stdin);
    step = 0;
    cout << endl
         << endl
         << endl
         << "the game need you to push every '$' to a '#' with as few steps as possible! " << endl
         << "press any key to continue~";
    char c = getch();
    level = 1;
    print_map();
    for (; level <= 3; ++level)
    {
        start_game();
        cout << "you've taken " << step << " steps! " << endl
             << "press any key to continue" << endl;
        c = getch();
    }
    cout << "You have finished the game!";
    return 0;
}