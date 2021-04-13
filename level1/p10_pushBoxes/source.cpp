#include <iostream>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <Tchar.h>
#include <string.h>
#include <vector>
#define WALL 0
#define ROUTE 1
#define LOSTER 2
#define BOX 3
#define UP 75
#define DOWN 77
#define LEFT 72
#define RIGHT 80
using namespace std;
int Rank, L, endx;
class items
{
public:
  int x, y; //坐标
  virtual bool judge(int **Maze, int x, int y, int input) = 0;
  virtual int getcaption() = 0;
};
class people : public items
{
public:
  virtual int getcaption() { return LOSTER; }
  virtual bool judge(int **Maze, int xx, int yy, int input)
  {
    if (Maze[y][x] == WALL)
      return false;
    else
      return true;
  }
};
class box : public items
{
public:
  virtual int getcaption() { return BOX; }
  virtual bool judge(int **Maze, int xx, int yy, int input)
  {
    if (Maze[y][x] == WALL)
      return false;
    if (x == xx && y == yy)
    {
    }
  }
};
vector<box *> boxdatas;
FILE *getfile(string s);
void win(int **Maze);
void playBoxes(int **Maze);
void getBoxesmode();
int **initializeMaze();
void saveMaze(int **Maze, FILE *fp);
int **getMaze(FILE *fp);
void playMaze(int **Maze);
void print(int **Maze);
void getMazemode();
string getmode();
void CreateMaze(int **Maze, int x, int y);
void move(int input, items &item, int **Maze);
int main()
{
  // people loster;//初始化迷路之人

  string mode;
  SetConsoleTitle(_T("Maze"));
  while (true)
  {
    mode = getmode();
    if (mode == "1")
    {
      getMazemode();
    }
    if (mode == "2")
    {
      getBoxesmode();
    }
    else if (mode == "3")
    {
      break;
    }
    else
    {
      cout << "please put in correct number";
    }
  }

  return 0;
}
string getmode()
{
  cout << "what do you want?choose the number" << endl;
  cout << "1.Loster in Maze" << endl;
  cout << "2.pushBoxes" << endl;
  cout << "3.exit" << endl;
  string mode;
  cin >> mode;
  return mode;
}
void saveMaze(int **Maze, FILE *fp)
{
  fprintf_s(fp, "%d\n", endx);
  fprintf_s(fp, "%d\n", L);
  for (int i = 0; i < L; i++)
    for (int j = 0; j < L; j++)
      fprintf_s(fp, "%d\n", Maze[i][j]);
}
int **getMaze(FILE *fp)
{
  fscanf(fp, "%d", &endx);
  fscanf(fp, "%d", &L);
  srand((unsigned)time(NULL));
  int **Maze = (int **)malloc(L * sizeof(int *));
  for (int i = 0; i < L; i++)
  {
    Maze[i] = (int *)calloc(L, sizeof(int));
  }
  for (int i = 0; i < L; i++)
    for (int j = 0; j < L; j++)
      fscanf(fp, "%d", &Maze[i][j]);
  return Maze;
}
int **initializeMaze()
{
  cout << "choose level (level 0 is the most difficult)" << endl;
  cin >> Rank;
  cout << "please put in the size of the square Maze" << endl;
  cin >> L;
  L = L + 2;
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
  return Maze;
}
void getMazemode()
{
  while (true)
  {
    cout << "do you want to randomly generate a Maze or load a Maze from computer?" << endl;
    cout << "1.randomly generation" << endl;
    cout << "2.load a Maze" << endl;
    cout << "3.exit" << endl;
    string mode;
    cin >> mode;
    if (mode == "1")
    {
      playMaze(initializeMaze());
    }
    else if (mode == "2")
    {
      cout << "please put in the path of the Maze" << endl;
      string path;
      cin >> path;
      FILE *fp = fopen(path.c_str(), "r");
      playMaze(getMaze(fp));
    }
    else if (mode == "3")
      break;
    else
      cout << "pardon?" << endl;
  }
}
void playMaze(int **Maze)
{
  people loster;
  loster.x = 1;
  loster.y = 2;
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
        Maze[loster.y][loster.x] = ROUTE;
        Maze[2][1] = LOSTER;
        win(Maze);
        break;
      }
    }
}
FILE *getfile(string s)
{
  cout << "please put in the save path" << endl;
  string path;
  cin >> path;
  return fopen(path.c_str(), s.c_str());
}
void win(int **Maze)
{
  system("cls");
  cout << "Congraduation!" << endl
       << "YOU WIN!" << endl
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
      else
      {
        printf("●");
      }
    }
    printf("\n");
  }
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
bool judge(items &item, int **Maze)
{
}

void move(int input, items &item, int **Maze)
{
  int tempx = item.x;
  int tempy = item.y;
  switch (input)
  {

  case LEFT:
    item.y--;
    break;
  case UP:
    item.x--;
    break;
  case DOWN:
    item.x++;
    break;
  case RIGHT:
    item.y++;
    break;
  default:
    break;
  }
  bool box_ok = true;
  vector<box *>::iterator i;

  if (item.judge(Maze, item.x, item.y, input))
  {

    for (i = boxdatas.begin(); i < boxdatas.end(); i++)
    {
      if (!((*i)->judge(Maze, item.x, item.y, input)))
        box_ok = false;
    }
    if (box_ok)
    {
      Maze[item.y][item.x] = item.getcaption();
      Maze[tempy][tempx] = ROUTE;
    }
  }
  else
  {
    item.y = tempy;
    item.x = tempx;
    Maze[item.y][item.x] = item.getcaption();
  }
}
void playBoxes(int **Maze)
{
  people loster;
  loster.x = 1;
  loster.y = 2;
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
        Maze[loster.y][loster.x] = ROUTE;
        Maze[2][1] = LOSTER;
        win(Maze);
        break;
      }
    }
}
void getBoxesmode()
{
  while (true)
  {
    cout << "do you want to randomly generate a Maze or load a Maze from computer?" << endl;
    cout << "1.randomly generation" << endl;
    cout << "2.load a Maze" << endl;
    cout << "3.exit" << endl;
    string mode;
    cin >> mode;
    if (mode == "1")
    {
      playBoxes(initializeMaze());
    }
    else if (mode == "2")
    {
      cout << "please put in the path of the Maze" << endl;
      string path;
      cin >> path;
      FILE *fp = fopen(path.c_str(), "r");
      playBoxes(getMaze(fp));
    }
    else if (mode == "3")
      break;
    else
      cout << "pardon?" << endl;
  }
}