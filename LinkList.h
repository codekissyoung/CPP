#ifndef MAIN_LINKLIST_H
#define MAIN_LINKLIST_H

#include <cstdint>

typedef uint64_t ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
} Node;

typedef Node* LinkList;

bool get_elem( LinkList L, uint32_t i, ElemType *e );
bool insert_elem_after( LinkList L, uint32_t i, ElemType e );
bool insert_elem_before( LinkList L, uint32_t i, ElemType e );
bool delete_elem( LinkList L, uint32_t i, ElemType *e );
bool clear_list( LinkList L );

#endif //MAIN_LINKLIST_H
