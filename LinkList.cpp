#include "LinkList.h"

#include <cstdio>
#include <sys/types.h>

// 从 LinkList 里获取第 i 个元素的值，存入 e
bool get_elem( LinkList L, uint32_t i, ElemType *e )
{
    LinkList p = L -> next; // 第一个结点
    uint32_t j = 1;

    while( p != nullptr && j <= i )
    {
        if( j == i )
        {
            *e = p -> data;
            return true;
        }else{
            p = p -> next;
            ++j;
        }
    }

    return false;
}

// 在 L 的第 i 个元素后面，插入新元素 e
bool insert_elem_after( LinkList L, uint32_t i, const ElemType e )
{
    LinkList p = L; // 头结点
    uint32_t j = 0;

    while( p != nullptr && j <= i )
    {
        if( j == i ){
            auto new_elem = new Node{ e, nullptr };
            new_elem -> next = p -> next;       // 新节点先指向后一个元素
            p -> next = new_elem;               // 当前元素再指向新节点
            return true;
        }else{
            p = p -> next;
            ++j;
        }
    }

    return false;
}

// 在 L 的第 i 个元素之前，插入新元素 e
bool insert_elem_before( LinkList L, uint32_t i, const ElemType e )
{
    // 等价于在 第 ( i - 1 ) 个元素后 插入 新元素 e
    return insert_elem_after( L, i - 1, e );
}

// 删除链表的 第 i 个元素，并且将其值保存在 e 中
bool delete_elem( LinkList L, uint32_t i, ElemType *e ){
    // 等价于 删除 第(i - 1)个元素的后一个元素
    i = i - 1;

    LinkList p = L; // 头结点
    uint32_t j = 0;

    while( p != nullptr && j <= i )
    {
        if( j == i ){
            LinkList del_elm = p -> next; // 要删除的节点
            p -> next = p->next->next;    // 当前节点指向，后面节点 的 后面节点
            *e = del_elm -> data;         // 保存删除节点的 数据到 e
            delete del_elm;
            return true;
        }else{
            p = p -> next;
            ++j;
        }
    }

    return false;
}

// 清除一个链表，操作结果将 L 重置为空表
bool clear_list( LinkList L ){

    LinkList first_elm = L -> next; // 第一个元素
    LinkList del_elem  = nullptr;

    while ( first_elm != nullptr )
    {
        del_elem = first_elm;           // 即将删除 第一个元素
        first_elm = first_elm -> next;  // 下一个元素 成为 第一个元素
        delete del_elem;               // 删除第一个元素
    }

    L -> next = nullptr;
    return true;
}
