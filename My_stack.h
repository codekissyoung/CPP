#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

class My_stack
{
public:
    typedef unsigned long Item;
    My_stack();
    ~My_stack() { std::cout << "~My_stack called" << std::endl; }

    bool isempty() const{
        return top == 0;
    }

    bool isfull() const{
        return top == MAX;
    }

    bool push( const Item &item );
    bool pop( Item &item );

private:
    enum {MAX = 10};
    Item items[MAX]; // 内部数据结构，使用数组实现栈
    int top; // 栈顶
};

#endif