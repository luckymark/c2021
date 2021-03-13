/*
README:
  对储存仓库信息的文件格式做出规定：第一行记录货品数，随后每一行读取货物名称和数字
  货物名字禁止包含空格
    先选择是新建一个仓库文件或读取一个仓库文件  
      再进入主菜单：
      1.查看仓库内容
      2.入库
      3.出库
      4.将某项物品从仓库中移除
      5.退出
    操作过程中会自动保存文件

*/
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <Tchar.h>
using namespace std;

class items
{
  int Count;
  string Name;

public:
  items(string s, int n)
  {
    Name = s;
    Count = n;
  }
  string showName()
  {
    return Name;
  }
  int showCounts()
  {
    return Count;
  }
  void changeCount(int n)
  {
    if (n + Count < 0)
    {
      cout << "Not enough!" << endl
           << "Only " << Count << " left" << endl;
    }
    else
    {
      Count = Count + n;
    }
  }
};
class itemDatas
{
  vector<items *> datas;

public:
  void clear()
  {
    datas.clear();
  }
  void additem(string Name, int n)
  {
    vector<items *>::iterator i;
    bool OK = true;
    for (i = datas.begin(); i < datas.end(); i++)
    {

      string s1 = (*i)->showName();
      if (strcmp(s1.c_str(), Name.c_str()) == 0)
      {
        OK = false;
        (*i)->changeCount(n);
      }
    }
    if (OK)
    {
      if (n > 0)
      {
        items *item = new items(Name, n);
        datas.push_back(item);
      }
      else
      {
        cout << "Wrong!" << endl;
        return;
      }
    }
  }
  void deleteitem(string Name)
  {
    vector<items *>::iterator i;
    string s1 = Name;
    bool OK = true;
    for (i = datas.begin(); i < datas.end(); i++)
    {
      string s2 = (*i)->showName();
      if (strcmp(s1.c_str(), s2.c_str()) == 0)
      {
        OK = false;
        datas.erase(i);
      }
    }
    if (OK)
    {
      cout << "Not found" << endl;
    }
  }
  void print()
  {
    vector<items *>::iterator i;
    for (i = datas.begin(); i < datas.end(); i++)
    {
      cout << (*i)->showName() << "    " << (*i)->showCounts() << endl;
    }
  }
  void save(FILE *fp)
  {
    fprintf(fp, "%d\n", datas.size());
    vector<items *>::iterator i;
    for (i = datas.begin(); i < datas.end(); i++)
    {
      string s = (*i)->showName();
      fprintf(fp, "%s %d\n", s.c_str(), (*i)->showCounts());
    }
  }

  void load(FILE *fp)
  {
    datas.clear();
    int n, Count;
    string Name;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
      char s[100];
      fscanf(fp, "%s %d", s, &Count);
      Name = s;
      items *item = new items(Name, Count);
      datas.push_back(item);
    }
    /*    long file_len;
      fseek(fp, 0, SEEK_END); // 将文件指针移动到文件结尾，成功返回0，不成功返回-1
      file_len = ftell(fp);   // 求出当前文件指针距离文件开始的字节数
      fseek(fp, 0, SEEK_SET); // 再定位指针到文件头
      char *str_buf = (char *)malloc(file_len + 1);
      string Name;
      int Count;
      char s[100];
      while (fgets(str_buf, file_len, fp))
      {
        fscanf(fp, "%s %d", s, &Count);
        Name = s;
        items *item = new items(Name, Count);
        datas.push_back(item);
      }*/
  }
};
string LoadOrNot();
string getfile();
string getmode();
int main()
{
  FILE *fp;
  string input, path;
  itemDatas data;
  while (1)
  {

    while (1)
    {
      string s = LoadOrNot();
      if (s == "L")
      {
        path = getfile();
        fp = fopen(path.c_str(), "r");
        data.load(fp);
        fclose(fp);
        break;
      }
      else if (s == "N")
      {
        path = getfile();
        fp = fopen(path.c_str(), "w");
        data.clear();
        fclose(fp);
        break;
      }
      else
      {
        cout << "Wrong!" << endl;
      }
    }

    if (fp != NULL)
    {
      //int *List = getList(fp);
      while (1)
      {
        input = getmode();
        if (input == "1")
        {
          data.print();
        }
        else if (input == "2")
        {
          cout << "请输入要添加的物品" << endl;
          string Name;
          cin >> Name;
          cout << "请输入要入库的数量" << endl;
          int import;
          cin >> import;
          data.additem(Name, import);
          FILE *fp = fopen(path.c_str(), "w");
          data.save(fp);
          fclose(fp);
        }
        else if (input == "3")
        {
          cout << "请输入要出库的物品" << endl;
          string Name;
          cin >> Name;
          cout << "请输入要出库的数量" << endl;
          int ex;
          cin >> ex;
          data.additem(Name, -ex);
          FILE *fp = fopen(path.c_str(), "w");
          data.save(fp);
          fclose(fp);
        }
        else if (input == "4")
        {
          cout << "What item do you want to remove from the list?" << endl;
          string Name;
          cin >> Name;
          data.deleteitem(Name);
          FILE *fp = fopen(path.c_str(), "w");
          data.save(fp);
          fclose(fp);
        }
        else if (input == "5")
        {
          cout << "Thanks for your using!!" << endl;
          data.save(fp);
          system("pause");
          return 0;
        }

        else
        {
          cout << "The input might be wrong,please put in a correct number." << endl;
        }
      }
    }
    else
    {
      cout << "The input is wrong!! " << endl;
    }
  }

  system("pause");
  return 0;
}
string getmode()
{
  cout << "What do you want?(please put in the number in front of the options)" << endl
       << "1.Review the List of goods" << endl
       << "2.Import" << endl
       << "3.Export" << endl
       << "4.Remove items" << endl
       << "5.Exit" << endl;
  string input;
  cin >> input;
  return input;
}

void print(int List)
{
}

string getfile()
{
  cout << "please put in the path of List" << endl;
  string path;
  cin >> path;
  return path;
}
string LoadOrNot()
{
  cout << "Load(L) a list or New(N) one?" << endl
       << "Please put in L or N" << endl;
  string s;
  cin >> s;
  return s;
}