#include "Screen.h"

Screen &Screen::move( pos r, pos c )
{
    pos row = r * width;
    cursor  = row + c;
    return *this;
}

char Screen::get( pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

Screen &Screen::set( char c )
{
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set( pos r, pos col, char ch )
{
    contents[ r * width + col ] = ch;
    return *this;
}

Screen::pos Screen::size() const {
    return height * width;
}