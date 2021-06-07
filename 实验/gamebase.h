#ifndef frostylight_gobang_gamebase
#define frostylight_gobang_gamebase

// the size of board + 1
const int boardsize = 15 + 1;

// the color of chess
enum chess{ empty, black, white };

// sente plays firstly
const chess sente = chess::black, gote = chess::white;

// get the opposite color
chess opposite(const chess &color){
    if (color == chess::black)return chess::white;
    if (color == chess::white)return chess::black;
    return chess::empty;
}

// the position in the board or the direction
struct pos{
    int x, y;
    pos(const int &xx, const int &yy):x(xx), y(yy){}

    // the opposite direction
    inline pos operator -()const{ return pos(-x, -y); }

    // check if this pos is vaild
    inline bool isVaild(const int &bSize = boardsize)const{ return 1 <= x && x < bSize && 1 <= y && y < bSize; }

    // move toward the giving direction
    inline bool move(const pos &p){
        x += p.x;y += p.y;
        return this->isVaild();
    }
};

// four different direction
pos direction[4] = { {1,0},{0,1},{1,1},{1,-1} };

const int AIConsiderAreaSize = 3;

const int dfsdepth = 4;

#endif