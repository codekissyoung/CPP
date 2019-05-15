#include "Str.h"

#include <iostream>

using namespace std;

ostream &operator<<( ostream &os, const Str &s )
{
    for(Str::size_type i = 0; i != s.size(); ++i)
    {
        os << s[i];
    }
    return os;
}

istream &operator>>( istream &is, Str &s )
{
    return is;
}