#include "My_stack.h"

My_stack::My_stack()
{
    top = 0;
}

My_stack::~My_stack()
{
    
}

bool My_stack::isempty() const
{
    return top == 0;
}

bool My_stack::isfull() const
{
    return top == MAX;
}

bool My_stack::push( const Item &item )
{
    if( top < MAX )
    {
        items[top++] = item;
        return true;
    }
    else
    {
        return false;
    }
}

bool My_stack::pop( Item &item )
{
    if( top > 0 )
    {
        item = items[--top];
        return true;
    }
    else
    {
        return false;
    }
}