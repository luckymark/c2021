
//README：
// 可选择随机生成地图（深搜生成的迷宫，随机放置的箱子，故基本无解┭┮﹏┭┮）或者从本地读取一个地图文件.txt，已上传一个经典地图
//  地图文件规则：第一行为地图大小（正方形边长），随后每一行按照顺序保存元素
//  倘若遇到了喜欢的随机生成地图，可选择将其保存
//-----------------------------------------------------------------
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <Tchar.h>
#define WALL 0
#define ROUTE 1
#define LOSTER 2
#define BOX 3
#define GOAL 4
using namespace std;
FILE *getfile(string s);
void win(int **Maze);
int **initializeMaze();
int **getMaze(FILE *fp);
string getMazemode();
FILE *getfile(string s);
void playMaze(int **Maze);
int goalx[100], goaly[100];
void saveMaze(int **Maze, FILE *fp);
int Rank, L, n, steps = 0, startx, starty;
class items
{
public:
  int x, y; //坐标
};
class people : public items
{
};
int judge(items &item, int **Maze, int tempx, int tempy);
void print(int **Maze);
void CreateMaze(int **Maze, int x, int y);
void move(int input, items &item, int **Maze);
int main()
{
  string mode;
  SetConsoleTitle(_T("Push_boxes"));
  while (1)
  {
    mode = getMazemode();
    if (mode == "1")
    {
      playMaze(initializeMaze());
    }
    else if (mode == "2")
    {
      FILE *fp = getfile("r");
      playMaze(getMaze(fp));
      fclose(fp);
    }
    else if (mode == "3")
      break;
    else
    {
      cout << "pardon?" << endl;
    }
  }
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
int judge(items &item, int **Maze, int tempx, int tempy)
{ //撞墙
  if (Maze[item.y][item.x] == WALL)
  {
    return 0;
  }
  else if (Maze[item.y][item.x] == BOX)
  {
    if (Maze[2 * item.y - tempy][2 * item.x - tempx] == WALL || Maze[2 * item.y - tempy][2 * item.x - tempx] == BOX)
    { //推箱子撞墙
      return 0;
    }
    else
    {
      //成功推箱子
      steps = steps + 1;
      return 2;
    }
  }
  steps = steps + 1;
  //普通行走
  return 1;
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
  switch (judge(item, Maze, tempx, tempy))
  {
  case 0: //无法行走
    item.y = tempy;
    item.x = tempx;
    break;
  case 1: //普通行走
    Maze[tempy][tempx] = ROUTE;
    for (int i = 0; i < n; i++)
    {
      if (Maze[goalx[i]][goaly[i]] != BOX)
        Maze[goalx[i]][goaly[i]] = GOAL;
    }
    Maze[item.y][item.x] = LOSTER;
    break;
  case 2: //推箱子
    Maze[tempy][tempx] = ROUTE;
    for (int i = 0; i < n; i++)
    {
      if (Maze[goalx[i]][goaly[i]] != BOX)
        Maze[goalx[i]][goaly[i]] = GOAL;
    }
    Maze[2 * item.y - tempy][2 * item.x - tempx] = BOX;
    Maze[item.y][item.x] = LOSTER;
    break;
  default:
    break;
  }
  /*
  {
    Maze[tempy][tempx] = ROUTE;
    for (int i = 0; i < n; i++)
    {
      Maze[goalx[i]][goaly[i]] = GOAL;
    }
    Maze[item.y][item.x] = LOSTER;
  }
  else
  {

    Maze[item.y][item.x] = LOSTER;
  }*/
}
string getMazemode()
{
  cout << "do you want to randomly generate a Box_Maze or load a Box_Maze from computer?" << endl;
  cout << "1.randomly generation" << endl;
  cout << "2.load a Box_Maze" << endl;
  cout << "3.exit" << endl;
  string mode;
  cin >> mode;
  return mode;
}
FILE *getfile(string s)
{
  cout << "please put in the save path" << endl;
  string path;
  cin >> path;
  return fopen(path.c_str(), s.c_str());
}
int **initializeMaze()
{
  cout << "choose level of the Maze (level 0 is the most difficult)" << endl;
  cin >> Rank;
  cout << "please put in the size of the square Maze" << endl;
  cin >> L;
  cout << "please put in the numbers of the boxes" << endl;
  cin >> n;

  L = L + 2;
  //分配内存
  srand((unsigned)time(NULL));
  int **Maze = (int **)malloc(L * sizeof(int *));
  for (int i = 0; i < L; i++)
  {
    Maze[i] = (int *)calloc(L, sizeof(int));
  }
  //初始化边缘
  for (int i = 0; i < L; i++)
  {
    Maze[i][0] = ROUTE;
    Maze[0][i] = ROUTE;
    Maze[i][L - 1] = ROUTE;
    Maze[L - 1][i] = ROUTE;
  }
  Maze[2][1] = ROUTE;
  //创建迷宫
  CreateMaze(Maze, 2, 1);
  Maze[2][1] = LOSTER;
  //打个洞当出口

  //增加箱子和箱子目标点（不理想）
  system("cls");
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
        goalx[i] = xx;
        goaly[i] = yy;

        break;
      }
    }
  }
  startx = 1;
  starty = 2;
  return Maze;
}
void playMaze(int **Maze)
{
  srand((unsigned)time(NULL));
  int **Maze_c = (int **)malloc(L * sizeof(int *));
  for (int i = 0; i < L; i++)
  {
    Maze_c[i] = (int *)calloc(L, sizeof(int));
  }
  for (int i = 0; i < L; i++)
    for (int j = 0; j < L; j++)
    {
      Maze_c[i][j] = Maze[i][j];
    }
  people loster;
  loster.x = startx;
  loster.y = starty;
  system("cls");
  print(Maze);
  //键盘控制
  while (1)
  {
    Sleep(20);

    if (_kbhit())
    {
      Sleep(200);
      system("cls");
      int input = 0;
      if (input = getch())
      {
        move(getch(), loster, Maze);
      }
      print(Maze);
      bool ex = true;
      for (int i = 0; i < n; i++)
      {
        if (Maze[goalx[i]][goaly[i]] != BOX)
        {
          ex = false;
        }
      }
      if (ex)
      {
        win(Maze_c);
        break;
      }
    }
  }
  system("pause");
}
int **getMaze(FILE *fp)
{
  n = 0;
  fscanf(fp, "%d", &L);
  srand((unsigned)time(NULL));
  int **Maze = (int **)malloc(L * sizeof(int *));
  for (int i = 0; i < L; i++)
  {
    Maze[i] = (int *)calloc(L, sizeof(int));
  }
  for (int i = 0; i < L; i++)
    for (int j = 0; j < L; j++)
    {
      fscanf(fp, "%d", &Maze[i][j]);
      if (Maze[i][j] == GOAL)
      {

        goalx[n] = i;
        goaly[n] = j;
        n++;
      }
      if (Maze[i][j] == LOSTER)
      {
        startx = j;
        starty = i;
      }
    }
  return Maze;
}
void win(int **Maze)
{
  system("cls");
  cout << "Congraduation!" << endl
       << "YOU WIN!" << endl
       << "Your step is  " << steps << endl
       << "if you like this Maze,you can choose to save it on your computer(put in S) or exit(put in any others)";
  string input;
  cin >> input;
  if (input == "S")
  {
    FILE *fp = getfile("w");
    saveMaze(Maze, fp);
    fclose(fp);
  }
}
void saveMaze(int **Maze, FILE *fp)
{
  steps = 0;
  fprintf_s(fp, "%d\n", L);
  for (int i = 0; i < L; i++)
    for (int j = 0; j < L; j++)
      if (j == startx && i == starty)
      {
        fprintf_s(fp, "%d\n", LOSTER);
      }
      else
      {
        if (Maze[i][j] != LOSTER)
        {
          fprintf_s(fp, "%d\n", Maze[i][j]);
        }
        else
        {
          fprintf_s(fp, "%d\n", ROUTE);
        }
      }
}