#include "My_Queue.h"

#include <iostream>
using namespace std;

bool My_Queue::enqueue(const Item &item) {
    if( isfull() )
        return false;

    Node *add = new Node{ item, nullptr };

    if( front == nullptr )
        front = add;        // 第一个元素
    else
        rear -> next = add; // 设置目前队尾元素的 next

    rear = add; // 设置新的队尾元素

    ++items;

    return true;
}

bool My_Queue::dequeue( Item &item ) {
    if( isempty() )
        return false;

    item = front->item;

    Node *front_for_del = front;
    front = front->next;
    delete front_for_del;

    --items;

    if( isempty() )
        rear = nullptr;

    cout << item << " out" << endl;
    return true;
}

My_Queue::~My_Queue() {
    while ( !isempty() )
    {
        Item item;
        dequeue( item );
    }
    cout << "~My_Queue called" << endl;
}