#include "Prim.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void create_path( MAZE *maze,int block_id) {
    if(maze->map[block_id]){// 如果现在已经是路了 1
        return;
    }
    if (!block_id) {
        block_id = randomselect(maze->block_count); //随机选择一个格子 :第一次调用
    }
    maze->map[block_id] = 1; // 所处的位置是路
    int direction = randomselect(5);// 1,2,3,4
    int toward_block = find_block_by_dirction(maze, block_id, direction);
    if(!toward_block){ // 如果朝着的方向非法
        return;
    }
    if (maze->map[toward_block]) { // 如果是路 1
        // 如果在同一条路上 加入集合
        merge_node_by_id(maze->dismap, block_id,toward_block);
    } else {
        // 如果没路
        create_path(maze,toward_block);
    }
}

/**
 * 从指定的方块出发寻找某一个方向上的指定方块
 * @param maze
 * @param base_block
 * @param direction
 * @return 方块id
 */
int find_block_by_dirction(MAZE *maze, int base_block, int direction) {
    int target_block;
    switch (direction) {
        case up://往上
            target_block = base_block - maze->cons;
            if (target_block < 0) return 0; // 超出边界
            return target_block;

        case down:
            target_block = base_block + maze->cons;
            if (target_block > maze->block_count) return 0; // 超出边界
            return target_block;

        case left:
            // 如果现在的已经是最左侧的格子
            if (base_block % maze->cons == 1) {
                return 0; // 超出边界
            }
            return base_block - 1;

        case right:
            // 如果现在已经是最右侧的格子
            if (base_block % maze->cons == 0) {
                return 0;
            }
            return base_block + 1;
    }
}

/**
 * 初始化迷宫结构体
 * @param maze
 * @param rows
 * @param cons
 * @param start
 * @param end
 */
void init_maze(MAZE *maze, int rows, int cons, int start, int end) { // 初始化结构体
    maze->cons = cons;
    maze->start = start;
    maze->rows = rows;
    maze->end = end;
    maze->block_count = rows * cons;
    maze->map = (int *) calloc(maze->block_count + 1, sizeof(int)); // 创建地图数组 初始化为0
    maze->dismap = (disjointset *)malloc(sizeof(disjointset)*(maze->block_count+1));
    init_disjointset(maze->dismap, maze->block_count+1); // 初始化并查集
}

/**
 * 生成地图
 * @param maze
 * @return
 */
void CreateMap(MAZE *maze) {
    srand((unsigned) time(NULL)); //更改随机数种子
    // 不断打破墙壁直到有一条路从起点到终点为止
    do {
        create_path(maze,0);
    } while (!test_if_a_b_in_same_set_by_id(maze->dismap,maze->start,maze->end)); //直到起点和终点在同一条路上 1
}

int randomselect(int range) {
    // 注意！不需要选择0号和最后一个方块！
    return rand() % (range - 1) + 1;
}

void printmap(MAZE *maze){
    //先输出最上层的一堵墙
    for (int first_line = 0; first_line < (maze->cons)*2; ++first_line) {
        printf("#");
    }
    printf("\n");

    //开始输出迷宫部分
    for (int row = 1; row < maze->rows+1; ++row) { // 行序号
        printf("#");
        int *next_line_walls = (int * )calloc(maze->cons*2+1,sizeof(int));// 这是记录下一行的墙长啥样的1墙0路
        for (int con = 1; con < maze->cons+1; ++con) { // 列序号
            // 输出路
            int now_block = con + maze->cons*(row-1);
            if (maze->map[now_block]){ // 如果是路
                printf(" ");
            } else{ // 如果不是路
                printf("#");
            }
            // 输出墙
            int toward_block;


            for (int direction = 2; direction < 5; ++direction) { // 依次down, left, right 2 3 4
                if (direction == 3){ //TODO:左其实也不要
                    continue;
                }
                switch(direction){
                    case down:
                         toward_block = find_block_by_dirction(maze,now_block,direction);
                        if(!toward_block){ // 如果朝向非法
                            continue;
                        }
                        if (test_if_a_b_in_same_set_by_id(maze->dismap,toward_block,now_block)){//如果在同一条路上
                            // 数组默认值就是0了，所以不干事

                    } else{ // 如果不是路，那就是墙
                            next_line_walls[con*2] = 1;
                        }
                        break;
                    default: // 左右方向
                        toward_block = find_block_by_dirction(maze,now_block,direction);
                        if(!toward_block){ // 如果朝向非法
                            continue;
                        }
                        if (test_if_a_b_in_same_set_by_id(maze->dismap,toward_block,now_block)){//如果在同一条路上
                            // 数组默认值就是0了，所以不干事

                        } else{ // 如果不是路，那就是墙
                            printf("#");
                        }
                }
            }
        }
        printf("\n");
        //在每一行结束之前，输出下一行的墙
        for(int con = 0;con <= maze->cons*2;++con){
            if (next_line_walls[con]){ // 如果是路
                printf(" ");
            } else{ // 如果不是路
                printf("#");
            }
        }
        printf("\n");
    }

    //最后输出最下层的一堵墙
    for (int last_line = 0; last_line < maze->cons + 2; ++last_line) {
        printf("#");
    }
    printf("\n");
}