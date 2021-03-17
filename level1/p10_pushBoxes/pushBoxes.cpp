#include <conio.h>
#include <cstdio>
#include <fstream>
#include <windows.h>
using namespace std;
char kb;
const int moveh[] = {1, -1, 0, 0};
const int movew[] = {0, 0, 1, -1};
enum MapC { ROAD, WALL, BOX, DES, PLAYER, BOXINDES };
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
WINBOOL setColor(WORD color = 0x07) { return SetConsoleTextAttribute(hout, color); }
WINBOOL setCursor(short h, short w) { return SetConsoleCursorPosition(hout, {w, h}); }
void drawChar(short h, short w, int kind);
void drawColor(short h, short w, int color);
void tip();
struct Map {
    int height, width, playerX, playerY, TBD;
    int **map, **playMap;
    bool isAvailable() { return height && width; }
    void getData(fstream &MD);
    void playInit(int &score, int historyScore);
    void trymove(int &score, int direction);
    bool play(int &score, int historyScore);
};
struct GameData {
    fstream MapReader, ScoreRecord;
    int LevelNumber, CurrentLevel, *Scores;
    Map *Maps;
    void showInfo();
    void start();
    GameData();
    ~GameData();
} Game;
int main() {
    Game.start();
    return 0;
}
void drawColor(short h, short w, int color) {
    unsigned long t;
    FillConsoleOutputAttribute(hout, color, 1, {w, h}, &t);
}
void drawChar(short h, short w, int kind) {
    unsigned long t = 0;
    char c;
    switch (kind) {
        case ROAD:;
            c = ' ';
            drawColor(h, w, 0x07);
            break;
        case WALL:;
            c = ' ';
            drawColor(h, w, 0xf0);
            break;
        case BOXINDES:;
        case BOX:;
            c = ' ';
            drawColor(h, w, 0xe0);
            break;
        case DES:;
            c = 'X';
            drawColor(h, w, 0x0e);
            break;
        default:;
        case PLAYER:;
            c = 'O';
            drawColor(h, w, 0x0f);
            break;
    }
    FillConsoleOutputCharacter(hout, c, 1, {w, h}, &t);
}
void prinTip() {
    printf("push all the boxes(");
    setColor(0xe0);
    putchar(' ');
    setColor(0x07);
    printf(")to the destination(");
    setColor(0x0e);
    putchar('X');
    setColor(0x07);
    putchar(')');
    putchar('\n');
}
void Map::getData(fstream &MD) {
    if (MD >> height >> width)
        ;
    else {
        height = width = 0;
        return;
    }
    map = new int *[height];
    for (int i = 0; i < height; ++i) {
        map[i] = new int[width];
        for (int j = 0; j < width; ++j)
            MD >> map[i][j];
    }
}
void Map::playInit(int &score, int historyScore) {
    system("cls");
    TBD = 0;
    playMap = new int *[height];
    for (int i = 0; i < height; ++i) {
        playMap[i] = new int[width];
        for (int j = 0; j < width; ++j) {
            switch (playMap[i][j] = map[i][j]) {
                case ROAD: putchar(' '); break;
                case WALL:;
                    setColor(0xf0);
                    putchar(' ');
                    break;
                case BOX:;
                    ++TBD;
                    setColor(0xe0);
                    putchar(' ');
                    break;
                case DES:;
                    setColor(0x0e);
                    putchar('X');
                    break;
                case PLAYER:;
                    playerX = i;
                    playerY = j;
                    setColor(0x0f);
                    putchar('O');
                    break;
            }
            setColor();
        }
        printf("%d", i);
        putchar('\n');
    }
    printf("press Esc to return to menu\n");
    printf("Scores:%d     The best score:%d\n", score, historyScore);
    prinTip();
}
void Map::trymove(int &score, int direction) {
    int toX = playerX + moveh[direction], toY = playerY + movew[direction];
    if (toX < 0 || toX >= height || toY < 0 || toY >= width)
        return;
    switch (playMap[toX][toY]) {
        case DES:;
        case ROAD:;
            ++score;
            drawChar(playerX, playerY, playMap[playerX][playerY] -= PLAYER);
            playerX = toX;
            playerY = toY;
            drawChar(playerX, playerY, playMap[playerX][playerY] += PLAYER);
            break;
        case BOX:;
        case BOXINDES:;
            int ttX = toX + moveh[direction], ttY = toY + movew[direction];
            if (ttX < 0 || ttX >= height || ttY < 0 || ttY >= width)
                return;
            if (playMap[ttX][ttY] != ROAD && playMap[ttX][ttY] != DES)
                return;
            ++score;
            if (playMap[toX][toY] == BOXINDES)
                ++TBD;
            if (playMap[ttX][ttY] == DES)
                --TBD;
            drawChar(ttX, ttY, playMap[ttX][ttY] += BOX);
            drawChar(toX, toY, playMap[toX][toY] -= BOX);
            drawChar(playerX, playerY, playMap[playerX][playerY] -= PLAYER);
            playerX = toX;
            playerY = toY;
            drawChar(playerX, playerY, playMap[playerX][playerY] += PLAYER);
            break;
    }
}
bool Map::play(int &score, int historyScore) {
    playInit(score, historyScore);
    while (true) {
        if (_kbhit()) {
            kb = _getch();
            if (kb <= 0) {
                switch (_getch()) {
                    case 80: trymove(score, 0); break;
                    case 72: trymove(score, 1); break;
                    case 77: trymove(score, 2); break;
                    case 75: trymove(score, 3); break;
                }
                if (!TBD)
                    return true;
            }
            else if (kb == 27)
                break;
        }
    }
    for (int i = 0; i < height; ++i)
        delete[] playMap[i];
    delete[] playMap;
    return false;
}
void GameData::showInfo() {
    system("cls");
    printf("press left/right to select the Level\n");
    printf("    Level.%02d   Score:%5d\n", CurrentLevel + 1, Scores[CurrentLevel]);
    printf("press Enter to start,Esc to exit");
}
void GameData::start() {
    printf("press any key to start the game\n");
    _getch();
    showInfo();
    while (true) {
        if (_kbhit()) {
            kb = _getch();
            if (!kb) {
                kb = _getch();
                if (kb == 75)
                    CurrentLevel = (CurrentLevel - 1 + LevelNumber) % LevelNumber;
                else if (kb == 77)
                    CurrentLevel = (CurrentLevel + 1 + LevelNumber) % LevelNumber;
                else
                    continue;
                setCursor(1, 0);
                printf("    Level.%02d   Score:%5d\n", CurrentLevel + 1, Scores[CurrentLevel]);
                setCursor(3, 0);
            }
            else if (kb == 13) {
                int Tscore = 0;
                if (Maps[CurrentLevel].play(Tscore, Scores[CurrentLevel])) {
                    system("cls");
                    printf("you win with score:%d\n", Tscore);
                    printf("press any key return to the menu");
                    if (Tscore < Scores[CurrentLevel] || !Scores[CurrentLevel])
                        Scores[CurrentLevel] = Tscore;
                    _getch();
                }
                showInfo();
            }
            else if (kb == 27)
                exit(0);
        }
    }
}
GameData::GameData() {
    MapReader.open("Maps.data", ios::in);
    if (!MapReader.is_open()) {
        printf("Error:Mapdata not found");
        system("pause");
        exit(1);
    }
    if (MapReader >> LevelNumber)
        CurrentLevel = 0;
    else {
        printf("Error:Mapdata is broken");
        system("pause");
        exit(1);
    }
    //读入地图数据
    Maps = new Map[LevelNumber];
    for (int i = 0; i < LevelNumber; ++i) {
        Maps[i].getData(MapReader);
        if (!Maps[i].isAvailable()) {
            LevelNumber = i + 1;
            break;
        }
    }
    //读入得分记录
    Scores = new int[LevelNumber];
    ScoreRecord.open("Scores.data", ios::in);
    if (!ScoreRecord)
        memset(Scores, 0, LevelNumber << 2);
    else {
        for (int i = 0; i < LevelNumber; ++i)
            if (ScoreRecord >> Scores[i]) {
            }
            else {
                Scores[i] = 0;
            }
        ScoreRecord.close();
    }
}
GameData::~GameData() {
    MapReader.close();
    ScoreRecord.open("Scores.data", ios::out);
    for (int i = 0; i < LevelNumber; ++i)
        ScoreRecord << Scores[i] << " ";
    ScoreRecord.close();
}