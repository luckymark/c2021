#include <conio.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

class Goods {  //货物类
   public:
    Goods(string theMod = NULL, int theNum = 0) { mod = theMod, num = theNum; }
    string mod;
    int num;
};

map<string, Goods> data;  //存放货物数据
bool alter = false;       //是否更改文件

void Infile() {  // 以读模式打开文件
    ifstream infile;
    infile.open("goods.dat");

    string line, name, mod;
    int num;

    while (infile.good()) {
        getline(infile, line);
        istringstream iss(line);
        iss >> name >> mod >> num;
        data.insert(make_pair(name, Goods(mod, num)));
    }
    infile.close();
}

void Outfile() {  //数据写入文件中
    ofstream outfile;
    outfile.open("goods.dat");
    map<string, Goods>::const_iterator it = data.begin();
    while (it != data.end()) {
        outfile << it->first + ' ' << it->second.mod + ' ' << it->second.num << endl;
        ++it;
    }
    outfile.close();
}

void ShowStock() {  //显示存货列表
    cout << "存货列表" << endl;
    map<string, Goods>::const_iterator it = data.begin();
    while (it != data.end()) {
        cout << "Name: " << it->first << setw(21) << "\tMod: " << it->second.mod << setw(21)
             << "\tNumber: " << it->second.num << endl;
        ++it;
    }
}

void Inbound() {  //入库
    ShowStock();

    alter = true;

    string line, name, mod;
    int num, i, j;
    map<string, Goods>::iterator it;

    cout << "\n→入库←" << endl;
    cout << "请依次输入货物的 “名称” “型号” “数量” 并按回车结束" << endl;
    cout << "注：用空格分隔，输入为空即结束输入" << endl;
    while (getline(cin, line)) {
        num = 0, i = 0, j = 0;
        if (line.empty()) break;

        while (line[i] == ' ') ++i;
        while (line[i] != ' ') ++i, ++j;
        name.assign(line, i - j, j);
        j = 0;

        while (line[i] == ' ') ++i;
        while (line[i] != ' ') ++i, ++j;
        mod.assign(line, i - j, j);

        while (line[i] == ' ') ++i;
        while (line[i] != ' ' && line[i] != '\0') {
            num *= 10;
            num += line[i] - '0';
            ++i;
        }

        if (num < 0) {  //入库数量为负值
            cerr << "入库数量不能为负值，请重新输入" << endl;
            continue;
        }
        if (mod.empty() || name.empty()) {
            cerr << "输入有误，请重新输入" << endl;
            continue;
        }
        if (mod.size() > 12 || name.size() > 12) {
            cerr << "名称或型号长度最大为12，请重新输入" << endl;
            continue;
        }

        it = data.find(name);
        if (it == data.end()) {  //无该货物
            data.insert(make_pair(name, Goods(mod, num)));
            cout << name << "成功入库" << num << "件，目前存货为" << num << "件" << endl;
        } else {  //已有货物
            it->second.num += num;
            cout << name << "成功入库" << num << "件，目前存货为" << it->second.num << "件" << endl;
        }
    }
    cout << "入库结束！ 以下为目前存货表" << endl;
    ShowStock();
}

void Outbound() {  //出库
    ShowStock();

    alter = true;

    string line, name;
    int num, i, j;
    map<string, Goods>::iterator it;

    cout << "\n←出库→" << endl;
    cout << "请依次输入货物名称以及出库数量" << endl;
    cout << "注：用空格分隔，输入为空即结束输入" << endl;

    while (getline(cin, line)) {
        num = 0, i = 0, j = 0;
        if (line.empty()) break;

        while (line[i] == ' ') ++i;
        while (line[i] != ' ') ++i, ++j;
        name.assign(line, i - j, j);

        while (line[i] == ' ') ++i;
        while (line[i] != ' ' && line[i] != '\0') {
            num *= 10;
            num += line[i] - '0';
            ++i;
        }
        if (num < 0) {  //出库数量为负值
            cerr << "出库数量不能为负值，请重新输入" << endl;
            continue;
        }
        if (name.empty()) {
            cerr << "输入有误，请重新输入" << endl;
            continue;
        }

        it = data.find(name);
        if (it == data.end()) {  //没有找到货物
            cout << "不存在该货物" << endl;
        } else {                         //找到货物
            if (it->second.num < num) {  //出库数量大于存货
                cout << "出库数量大于存货数量，需要全部出库吗？(1--是 0--否)" << endl;
                while (cin >> j) {
                    if (j == 1) {
                        data.erase(it);
                        cout << name << "已全部出库" << endl;
                        break;
                    } else if (j == 0) {
                        cout << name << "出库失败" << endl;
                        break;
                    }
                }
                cin.ignore();
            } else if (it->second.num == num) {  //出库数量等于存货
                data.erase(it);
                cout << name << "已全部出库" << endl;
            } else {  //出货数量小于存货
                it->second.num -= num;
                cout << name << "出库" << num << "件，剩余" << it->second.num << "件" << endl;
            }
        }
    }
    cout << "出库结束！ 以下为目前存货表" << endl;
    ShowStock();
}

void ShowMenu() {  //功能菜单
    cout << "***************"
         << "\n请选择功能"
         << "\n1. 显示存货列表"
         << "\n2. 入库"
         << "\n3. 出库"
         << "\n0. 退出程序"
         << "\n***************" << endl;
}

void Choose() {  //功能选择
    char in = getch();
    system("cls");
    switch (in) {
        case '1': {  //显示存货列表
            ShowStock();
            system("pause");
            break;
        }
        case '2': {  //入库
            Inbound();
            system("pause");
            break;
        }
        case '3': {  //出库
            Outbound();
            system("pause");
            break;
        }
        case '0': {  //退出程序
            system("cls");
            if (alter) {  //存货改变，重新写入数据
                Outfile();
            }
            system("pause");
            exit(0);
        }
        default: {
            break;
        }
    }
}

void warehouse() {
    while (true) {
        ShowMenu();
        Choose();
        system("cls");
    }
}

int main() {
    Infile();

    warehouse();

    return -1;  //非正常结束
}