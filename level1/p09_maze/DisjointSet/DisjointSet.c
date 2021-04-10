#include "DisjointSet.h"

/**
 * 初始化并查集：指定全部节点的父节点为自己，指定其下只有一层（自己）
 * @param p
 * @param length
 */
void init_disjointset(disjointset p[], int length) {
    // 这里的length是真实长度，有4个节点，length就是4
    for (int i = 0; i < length; ++i) {
        p[i].parent = i;
        p[i].rank = 1;
    }
}

/**
 * 找到一个节点的顶层父节点
 * @param p
 * @param id
 * @return 顶层id
 */
int find_top_parent_by_id(disjointset p[], int id) {
    int son = id;
    int parent;
    for (;;) {
        parent = find_parent_by_id(p, son);
        if (parent == son) { // 直到父节点等于自己
            return parent; // 返回顶层id
        } else {
            son = parent; // 不等于就继续往上寻找
        }
    }
}

/**
 * 找到一个节点的直接父节点
 * @param p
 * @param id
 * @return 直接父节点id
 */
int find_parent_by_id(disjointset p[], int id) {
    return p[id].parent;
}

/**
 * 合并两个节点
 * @param p
 * @param id_a
 * @param id_b
 */
void merge_node_by_id(disjointset p[], int id_a, int id_b) {
    int top_a = find_top_parent_by_id(p, id_a);
    int top_b = find_top_parent_by_id(p, id_b);
    if (top_a == top_b) return; // 不需要合并

    int rank_a = p[top_a].rank;
    int rank_b = p[top_b].rank;
    if (rank_a <= rank_b) { // a比b简单
        p[id_b].parent = top_a; // b的父节点是a
    } else { // b比a简单
        p[id_a].parent = top_b;
        p[id_b].rank += rank_a;
    }// 注意：此处省略了维护合并后子节点的秩，因为它的秩不会再被用到

    if (rank_a == rank_b) {// 如果两边的秩相同，那么层级数得+1！
        p[top_a].rank++;
    }
}

/**
 * 查询两个节点是不是在同一个集合中
 * @param p
 * @param id_a
 * @param id_b
 * @return 是1 否0
 */
int test_if_a_b_in_same_set_by_id(disjointset p[], int id_a, int id_b) {
    int top_a = find_top_parent_by_id(p, id_a);
    int top_b = find_top_parent_by_id(p, id_b);
    if (top_a == top_b) {
        return 1;
    } else {
        return 0;
    }
}
