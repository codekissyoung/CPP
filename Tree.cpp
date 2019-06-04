#include "Tree.h"
#include <cstdio>
#include <cstdlib>

BiThrTree pre; // 全局变量，始终指向刚刚访问过的节点

void CreateBiThrTree( BiThrTree *T ){
    TElemType ch;
    scanf( "%c", &ch );
    if( ch == '#' ){
        *T = nullptr;
    }else{
        *T = (BiThrTree)malloc( sizeof(BiThrTree) );
        (*T) -> data = ch;
        CreateBiThrTree( &(*T) -> lchild );
        CreateBiThrTree( &(*T) -> rchild );
    }
}

void InThreading( BiThrTree p ){
    if( p )
    {
        InThreading( p -> lchild );

        if( p -> lchild == nullptr ){
            p -> LTag   = thread_tag;
            p -> lchild = pre;
        }

        if( pre -> rchild == nullptr ){
            pre -> RTag   = thread_tag;
            pre -> rchild = p;
        }

        pre = p;

        InThreading( p -> rchild );
    }
}
