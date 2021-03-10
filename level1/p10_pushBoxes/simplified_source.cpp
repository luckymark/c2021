#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <Tchar.h>
#define WALL 0
#define ROUTE 1
#define LOSTER 2
#define BOX 3
#define GOAL 4
using namespace std;
int Rank, L, n, steps = 0;
class items
{
public:
  int x, y; //坐标
};
class people : public items
{
};
bool judge(items &item, int **Maze, int tempx, int tempy);
void print(int **Maze);
void CreateMaze(int **Maze, int x, int y);
void move(int input, items &item, int **Maze);
int main()
{

  people loster; //初始化迷路之人
  loster.x = 1;
  loster.y = 2;
  SetConsoleTitle(_T("Push_boxes"));
  cout << "choose level of the Maze (level 0 is the most difficult)" << endl;
  cin >> Rank;
  cout << "please put in the size of the square Maze" << endl;
  cin >> L;
  cout << "please put in the numbers of the boxes" << endl;
  cin >> n;

  L = L + 2;
  int endx;
  //初始化边缘
  srand((unsigned)time(NULL));
  int **Maze = (int **)malloc(L * sizeof(int *));
  for (int i = 0; i < L; i++)
  {
    Maze[i] = (int *)calloc(L, sizeof(int));
  }
  for (int i = 0; i < L; i++)
  {
    Maze[i][0] = ROUTE;
    Maze[0][i] = ROUTE;
    Maze[i][L - 1] = ROUTE;
    Maze[L - 1][i] = ROUTE;
  }
  Maze[2][1] = ROUTE;
  //创建迷宫并打印
  CreateMaze(Maze, 2, 1);
  Maze[2][1] = LOSTER;
  for (int i = L - 3; i >= 0; i--)
  {
    if (Maze[i][L - 3] == ROUTE)
    {
      Maze[i][L - 2] = ROUTE;
      endx = i;
      break;
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << "LOADING" << endl
         << "少女祈祷中" << endl;

    while (1)
    {
      srand((unsigned)time(NULL));
      int xx = rand() % (L - 2) + 1;
      srand((unsigned)time(NULL));
      int yy = rand() % (L - 2) + 1;

      if (Maze[xx][yy] == ROUTE)
      {
        Maze[xx][yy] = BOX;
        break;
      }
    }
    while (1)
    {
      srand((unsigned)time(NULL));
      int xx = rand() % (L - 2) + 1;
      srand((unsigned)time(NULL));
      int yy = rand() % (L - 2) + 1;

      if (Maze[xx][yy] == ROUTE)
      {
        Maze[xx][yy] = GOAL;
        break;
      }
    }
  }
  print(Maze);
  //键盘控制
  while (1)
    if (_kbhit())
    {
      Sleep(200);
      system("cls");
      move(_getch(), loster, Maze);
      print(Maze);
      if (loster.y == endx && loster.x == L - 2)
      {
        system("cls");
        cout << "Congraduation!" << endl
             << "YOU WIN!" << endl;
        break;
      }
    }
  system("pause");
  return 0;
}
void print(int **Maze)
{
  for (int i = 0; i < L; i++)
  {
    for (int j = 0; j < L; j++)
    {
      if (Maze[i][j] == ROUTE)
      {
        printf("  ");
      }
      else if (Maze[i][j] == WALL)
      {
        printf("■");
      }
      else if (Maze[i][j] == LOSTER)
      {
        printf("●");
      }
      else if (Maze[i][j] == BOX)
      {
        printf("□");
      }
      else
      {
        printf("×");
      }
    }
    cout << endl;
  }
  cout << endl
       << endl
       << "Steps:" << steps;
}
void CreateMaze(int **Maze, int x, int y)
{
  Maze[x][y] = ROUTE;

  //确保四个方向随机
  int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for (int i = 0; i < 4; i++)
  {
    int r = rand() % 4;
    int temp = direction[0][0];
    direction[0][0] = direction[r][0];
    direction[r][0] = temp;

    temp = direction[0][1];
    direction[0][1] = direction[r][1];
    direction[r][1] = temp;
  }

  //向四个方向开挖
  for (int i = 0; i < 4; i++)
  {
    int dx = x;
    int dy = y;

    //控制挖的距离，由Rank来调整大小
    int range = 1 + (Rank == 0 ? 0 : rand() % Rank);
    while (range > 0)
    {
      dx += direction[i][0];
      dy += direction[i][1];

      //排除掉回头路
      if (Maze[dx][dy] == ROUTE)
      {
        break;
      }

      //判断是否挖穿路径
      int count = 0;
      for (int j = dx - 1; j < dx + 2; j++)
      {
        for (int k = dy - 1; k < dy + 2; k++)
        {
          //abs(j - dx) + abs(k - dy) == 1 确保只判断九宫格的四个特定位置
          if (abs(j - dx) + abs(k - dy) == 1 && Maze[j][k] == ROUTE)
          {
            count++;
          }
        }
      }

      if (count > 1)
      {
        break;
      }

      //确保不会挖穿时，前进
      --range;
      Maze[dx][dy] = ROUTE;
    }

    //没有挖穿危险，以此为节点递归
    if (range <= 0)
    {
      CreateMaze(Maze, dx, dy);
    }
  }
}
bool judge(items &item, int **Maze, int tempx, int tempy)
{
  if (Maze[item.y][item.x] == WALL)
  {
    return false;
  }
  else if (Maze[item.y][item.x] == BOX)
  {
    if (Maze[2 * item.y - tempy][2 * item.x - tempx] == WALL)
    {
      return false;
    }
    else
    {
      Maze[2 * item.y - tempy][2 * item.x - tempx] = BOX;
      return true;
    }
  }
}
void move(int input, items &item, int **Maze)
{
  int tempx = item.x;
  int tempy = item.y;
  switch (input)
  {

  case 72:
    item.y--;
    break;
  case 75:
    item.x--;
    break;
  case 77:
    item.x++;
    break;
  case 80:
    item.y++;
    break;
  default:
    break;
  }
  if (judge(item, Maze, tempx, tempy))
  {
    steps++;
    Maze[item.y][item.x] = LOSTER;
    Maze[tempy][tempx] = ROUTE;
  }
  else
  {
    item.y = tempy;
    item.x = tempx;
    Maze[item.y][item.x] = LOSTER;
  }
}