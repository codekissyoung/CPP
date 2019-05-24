#ifndef _STACK_H_
#define _STACK_H_

typedef unsigned long Item;

class My_stack
{
    private:
        
        enum {MAX = 10};

        // 内部数据结构，使用数组实现栈
        Item items[MAX];

        int top; // 栈顶

    public:
        
        My_stack();

        ~My_stack();

        // 栈空?
        bool isempty() const;

        // 栈满?
        bool isfull() const;

        // 入栈
        bool push( const Item &item );

        // 出栈
        bool pop( Item &item );
};

#endif