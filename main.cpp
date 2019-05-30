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
bool get_elem( LinkList L, int i, ElemType *e )
{
    LinkList p = L -> next; // 第一个结点
    int j = 1;

    while( p != nullptr )
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

// 在L的第 i 个元素之前，插入新元素e
bool insert_elem( LinkList L, int i, ElemType *e ){
    // 等价于在 第 ( i - 1 ) 个元素后 插入 新元素 e
    i = i - 1;

    LinkList p = L; // 头结点
    int j = 0;

    while( p != nullptr )
    {
        if( j == i )
        {
            auto new_elem = new Node{ *e, nullptr };
            new_elem -> next = p -> next;
            p -> next = new_elem;
        }else{
            p = p -> next;
            ++j;
        }
    }

    return false;
}

int main( int argc, char *argv[] )
{
    LinkList students = new Node{ 0, nullptr };

    ElemType a = 1009;

    insert_elem( students, 1, &a );

    ElemType b = 9912;

    insert_elem( students, 1, &b );

    return EXIT_SUCCESS;
}
