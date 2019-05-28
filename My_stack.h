#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

template <typename Item>
class My_stack
{
private:
    enum { SIZE = 10 };  // 默认栈的大小
    int top;            // 栈顶
    int size;           // 栈大小
    Item *items;        // 内部数据结构,使用堆内数组实现

public:
    My_stack() : top{0}, size{SIZE}, items{ new Item[SIZE] } { };
    explicit My_stack( int ss ) : size{ ss }, top{0}, items{ new Item[ss]} { }
    My_stack( const My_stack &st );

    ~My_stack() { std::cout << "~My_stack called" << std::endl; }

    bool isempty() const{ return top == 0; }

    bool isfull() const{ return top == size; }

    bool push( const Item &item );

    bool pop( Item &item );

    My_stack<Item> &operator=( const My_stack &st );
};

template<typename Item>
My_stack<Item> &My_stack<Item>::operator=(const My_stack &st) {
    if( this == &st )
        return *this;

    top = st.top;
    size = st.size;

    delete[] items;
    items = new Item[size];
    for( int i = 0; i < size; ++i )
        items[i] = st.items[i];

    return *this;
}

template <typename Item>
bool My_stack<Item>::push( const Item &item )
{
    if( isfull() )
    {
        return false;
    }else{
        items[top++] = item;
        return true;
    }
}

template <typename Item>
bool My_stack<Item>::pop( Item &item )
{
    if ( isempty() ){
        return false;
    } else {
        item = items[--top];
        return true;
    }
}

template<typename Item>
My_stack<Item>::My_stack(const My_stack &st) {
    size = st.size;
    top = st.top;
    items = new Item[size];
    for( int i = 0; i < size; ++i )
    {
        items[i] = st.items[i];
    }
}

#endif