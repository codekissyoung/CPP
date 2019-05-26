#ifndef CPP_MY_QUEUE_H
#define CPP_MY_QUEUE_H

#include <iostream>

typedef unsigned int Item;

class My_Queue {
public:
    enum { Q_SIZE = 10 };
    explicit My_Queue( int qs = Q_SIZE ):qsize{qs},items{0},front{nullptr},rear{nullptr} { }

    ~My_Queue();
    bool isempty() const { return items == 0; }
    bool isfull() const { return items == qsize; }
    int count() const { return items; }
    bool enqueue( const Item &item );
    bool dequeue( Item &item );

private:
    // 声明在类中的 结构类型，作用域为整个类
    struct Node{
        Item item;
        struct Node *next;
    };

    const int qsize;    // 整个队列能容纳的元素个数
    int items;          // 当前元素个数
    Node *front;        // 队列的第一个元素
    Node *rear;         // 队列的最后一个元素
};

#endif //CPP_MY_QUEUE_H
