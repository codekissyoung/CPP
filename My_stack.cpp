#include "My_stack.h"

My_stack::My_stack() : top{ 0 } { }

bool My_stack::push( const Item &item )
{
    if( isfull() )
    {
        return false;
    }else{
        items[top++] = item;
        return true;
    }
}

bool My_stack::pop( Item &item )
{
    if ( isempty() ){
        return false;
    } else {
        item = items[--top];
        return true;
    }
}