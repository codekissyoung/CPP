#ifndef MAIN_TREE_H
#define MAIN_TREE_H

#include <stdint.h>

#define MAX_TREE_SIZE 100

typedef char TELemType;

// Child Tree Node
typedef struct CTNode{
    int child;           // 孩子节点的下标
    struct CTNode *next; // 下一个孩子节点
}CTNode, *ChildPtr;

// Normal Node
typedef struct TNode{
    TELemType data;
    int parent;          // 父节点下标
    ChildPtr firstchild; // 第一个孩子节点
} TNode;

typedef struct Tree{
    TNode nodes[MAX_TREE_SIZE];
    int root; // 根的位置
    int num;  // 节点数
} Ptree;


/*
 * 二叉树
 * */
typedef char BElemType;

typedef struct BNode{
    BElemType data;
    struct BNode *lchild;
    struct BNode *rchild;
}BNode, *pBNode;

#endif //MAIN_TREE_H
