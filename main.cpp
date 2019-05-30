#include "common.h"
#include "func.h"
#include "Stock.h"
#include "Student_info.h"
#include "My_vector.h"
#include "My_stack.h"
#include "My_Queue.h"
#include "My_array.h"
#include "My_pair.h"
#include "StringBad.h"
#include "vec.h"
#include "Sales_item.h"
#include "Str.h"
#include "Screen.h"
#include "Window_mgr.h"
#include "Brass_model.h"

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <initializer_list>
#include <stack>
#include <queue>
#include <memory>
#include <valarray>

#include <cmath>
#include <time.h>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <climits>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

typedef uint64_t ElemType;

typedef struct Node{
    ElemType data;
    struct Node *next;
} Node;

typedef Node* LinkList;

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
bool insert_elem_after( LinkList L, uint32_t i, const ElemType e ){

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
bool insert_elem_before( LinkList L, uint32_t i, const ElemType e ){
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

int main( int argc, char *argv[] )
{
    LinkList students = new Node{ 0, nullptr };

    insert_elem_after( students, 0, 1099 );
    insert_elem_before( students, 1, 2934 );
    insert_elem_after( students, 1, 94856 );
    insert_elem_after( students, 1, 1938954 );
    insert_elem_after( students, 1, 4223455 );

    ElemType del_elm;
    delete_elem( students, 1, &del_elm );
    cout << "delete " << del_elm << endl;

    ElemType a;
    int i = 1;
    while ( get_elem( students, i, &a ) ){
        cout << "a : " << a << endl;
        ++i;
    }

    clear_list( students );

    i = 1;
    while ( get_elem( students, i, &a ) ){
        cout << "a : " << a << endl;
        ++i;
    }

    return EXIT_SUCCESS;
}
