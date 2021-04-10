#ifndef P09_MAZE_PRIM_H
#define P09_MAZE_PRIM_H
#include "../DisjointSet/DisjointSet.h"
typedef struct {
    int *map;
    int rows;
    int cons;
    int start;
    int end;
    int block_count;
    disjointset *dismap;
} MAZE;
enum directions {
    up = 1, down, left, right
};
int find_block_by_dirction(MAZE *maze, int base_block, int diretion);
void init_maze(MAZE *maze, int rows, int cons, int start, int end);
void CreateMap(MAZE *maze);
void create_path( MAZE *maze,int block_id);
int randomselect(int range);
void printmap(MAZE *maze);
#endif //P09_MAZE_PRIM_H
