#include "vec.h"

template <typename T>
Vec<T> &Vec<T>::operator=( const Vec &rhs )
{
    if( &rhs == this )
        return *this;

    uncreate();

    create( rhs.begin(), rhs.end() );

    return *this;
}