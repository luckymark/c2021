#include <bits/stdc++.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <vector>
#include <bitset>
using namespace std;
#define mod (1 + total_num / 2) * total_num / 4
const int Size = 21;
int _map[105][105];
const int len = 512;         // the length of gene
                             //00 up 01 down 10 left 11 right
const int total_num = 10000; // the number of node

void print_map()
{
    system("cls");
    for (int i = 0; i <= Size + 1; ++i)
    {
        for (int j = 0; j <= Size + 1; ++j)
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

struct Node //every node denotes a path
{
    bool get_destination;
    int step;            //the steps the node run
    bool gene[512];      // denotes the gene
    inline void create() //create gene
    {
        for (int i = 0; i < len; i++)
            gene[i] = rand() % 2;
        mark();
    }
    inline const bool operator<(Node p) // go futher, in higher priority
    {
        if (get_destination)
            return true;
        if (p.get_destination)
            return false;
        if (step > p.step)
            return true;
        return false;
    }
    void modify_gene() //delete all the return
    {
        for (int i = 2; i < len; i += 2)
        {
            if ((gene[i] == gene[i - 2]) && (gene[i + 1] != gene[i - 1]))
                gene[i + 1] = gene[i - 1];
        }
    }
    void mark() // get the distance of steps
    {
        modify_gene();
        get_destination = false;
        step = 0;
        int posx = 1, posy = 1;
        for (int i = 0; i < len; i += 2)
        {
            if (gene[i])
            {
                if (gene[i + 1]) //right
                {
                    if (!_map[posx][posy + 1])
                    {
                        posy++;
                        step++;
                    }
                    else
                        return;
                }
                else //left
                {
                    if (!_map[posx][posy - 1])
                    {
                        posy--;
                        step++;
                    }
                    else
                        return;
                }
            }
            else
            {
                if (gene[i + 1]) //down
                {
                    if (!_map[posx + 1][posy])
                    {
                        posx++;
                        step++;
                    }
                    else
                        return;
                }
                else //up
                {
                    if (!_map[posx - 1][posy])
                    {
                        posx--;
                        step++;
                    }
                    else
                        return;
                }
            }
            if (posy == Size && posx == Size)
            {
                get_destination = true;
                return;
            }
        }
    }
    inline void variation() // make one of the gene be modified
    {
        if (step == 0)
            return; //This is a great bug!!!
        int var = rand() % (step * 2);
        gene[var] = gene[var] | 1;
    }
    void show_path() //print the path
    {
        int posx = 1, posy = 1;
        _map[posx][posy] = -1;
        print_map();
        for (int i = 0; i < len; i += 2)
        {
            _map[posx][posy] = 0;
            if (gene[i])
            {
                if (gene[i + 1]) //right
                {
                    if (!_map[posx][posy + 1])
                        posy++;
                    else
                        return;
                }
                else //left
                {
                    if (!_map[posx][posy - 1])
                        posy--;
                    else
                        return;
                }
            }
            else
            {
                if (gene[i + 1]) //down
                {
                    if (!_map[posx + 1][posy])
                        posx++;
                    else
                        return;
                }
                else //up
                {
                    if (!_map[posx - 1][posy])
                        posx--;
                    else
                        return;
                }
            }
            _map[posx][posy] = -1;
            print_map();
            Sleep(500);
            if (posy == Size && posx == Size)
                return;
            Sleep(30);
        }
    }
};
vector<Node> n;

inline void inherit(Node j, Node k) //parents give birth to two kids
{
    int x_point = int(long(rand()) % (2 * long(max(j.step, k.step)))); // the position of gene to overlape
    Node son1, son2;
    for (int i = 0; i <= x_point; i++)
    {
        son1.gene[i] = j.gene[i];
        son2.gene[i] = k.gene[i];
    }
    for (int i = x_point + 1; i < len; i++)
    {
        son2.gene[i] = j.gene[i];
        son1.gene[i] = k.gene[i];
    }
    son1.mark();
    son2.mark();
    n.push_back(son1);
    n.push_back(son2);
}

int Russian_roulette() // decide the parents with probability
{
    int chosen = int(long(rand()) * long(rand()) % long(mod));
    //distribute the probability with the rank as 1+2+3+4 etc
    int _down = 1, _up = total_num / 2;
    int mid = (_up + _down) / 2;
    while (mid > _down)
    {
        if ((1 + mid) * mid / 2 < chosen)
        {
            _down = mid;
            mid = (mid + _up) / 2;
            continue;
        }
        else if ((1 + mid) * mid / 2 > chosen)
        {
            _up = mid;
            mid = (mid + _down) / 2;
            continue;
        }
        else
            return total_num / 2 - mid;
    }
    return total_num / 2 - mid;
}

int times = 0;
bool generate() // give birth to the next genertion
{               //0-1/2 excllent one, 1/2-1 die,1/4 chance of variation
    sort(n.begin(), n.end());
    ++times;
    cout << "this is " << times << " generations, distance = " << n[1].step << endl;
    if (n[0].get_destination)
    {
        n[0].show_path();
        cout << "get to the destination with " << times << " generations!";
        Sleep(100);
        return true;
    }
    for (int i = total_num; i >= total_num / 2 + 1; i--)
        n.pop_back();
    for (int i = 1; i <= total_num / 2; i++)
    {
        int parent1 = Russian_roulette();
        int parent2 = Russian_roulette();
        inherit(n[parent1], n[parent2]);
    }
    for (int i = 1; i <= total_num / 4; i++)
    {
        int k = rand() % n.size() + 1;
        n[k].variation(); //variate;
    }
    return false;
}

void read_map()
{
    char c;
    for (int i = 0; i <= Size + 1; i++)
    {
        for (int j = 0; j <= Size + 1; j++)
        {
            c = getchar();
            if (c == ' ')
                _map[i][j] = 0;
            if (c == '0')
                _map[i][j] = 1;
            c = getchar();
        }
        c = getchar();
    }
}

void init()
{
    Node x;
    x.step = -1;
    n.push_back(x); // this Node is to judge whether to get to the destination
    n[0].get_destination = false;
    for (int i = 1; i <= total_num; i++) //delete half of the Node and create such many Node
    {
        Node x;
        x.create();
        n.push_back(x);
    }
}

int main()
{
    freopen("map.txt", "r", stdin);
    read_map();
    print_map();
    srand(time(NULL));
    init();
    while (!generate())
        ;
    return 0;
}