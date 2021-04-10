#ifndef P09_MAZE_DISJOINTSET_H
#define P09_MAZE_DISJOINTSET_H

typedef struct {
    int key;
    int parent;
    int rank;
} disjointset;

void init_disjointset(disjointset p[], int length);

int find_top_parent_by_id(disjointset p[], int id);

int find_parent_by_id(disjointset p[], int id);

void merge_node_by_id(disjointset p[], int id_a, int id_b);

int test_if_a_b_in_same_set_by_id(disjointset p[], int id_a, int id_b);

#endif //P09_MAZE_DISJOINTSET_H
