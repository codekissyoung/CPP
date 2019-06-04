#ifndef MAIN_TREE_H
#define MAIN_TREE_H

#include <stdint.h>

/*
 * 线索二叉树
 */
typedef enum { child_tag, thread_tag } PointerTag;
typedef char TElemType;

typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode *lchild;
    struct BiThrNode *rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiThrNode, *BiThrTree;

void CreateBiThrTree( BiThrTree *T );

void InThreading( BiThrTree p );

#endif //MAIN_TREE_H
