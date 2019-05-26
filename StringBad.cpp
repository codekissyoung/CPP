#include "StringBad.h"

#include <iostream>
#include <cstring>

using namespace std;

int StringBad::num_strings = 0; // 必须在此处初始化，而不是在声明处

StringBad::StringBad() : len{0}
{
    str = new char[1];
    str[0] = '\0';
    ++num_strings;
}

StringBad::~StringBad()
{
    cout << --num_strings << " StringBad object left" << endl;
    delete[] str;
}

StringBad::StringBad( const char *s )
{
    len = strlen( s );
    str = new char[len + 1];
    strcpy( str, s );
    ++num_strings;
}

StringBad::StringBad( const StringBad &st ){
    ++num_strings;
    len = st.len;
    str = new char[len + 1];
    strcpy( str, st.str );
}

// assign StringBad to StringBad
StringBad &StringBad::operator=( const StringBad &st ){
    if( this == &st )
        return *this;
    delete[] str;

    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}

// assign C-Style-string to StringBad
StringBad &StringBad::operator=(const char *s ) {
    delete[] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy( str, s );
    return *this;
}

// read-write char access for StringBad
char &StringBad::operator[](int i) {
    return str[i];
}

// 在重载时，C++区分const与non-const特征标，所以这里提供一个仅供 const StringBad 对象使用的版本
const char &StringBad::operator[](int i) const {
    return str[i];
}

bool operator<( const StringBad &st1, const StringBad &st2 ) {
    return strcmp(st1.str, st2.str ) < 0 ;
}

bool operator>( const StringBad &st1, const StringBad &st2 ){
    return st2 < st1;
}

bool operator==( const StringBad &st1, const StringBad &st2 ){
    return 0 == strcmp( st1.str, st2.str );
}

istream &operator>>( istream &is, StringBad &st ){
    char temp[80];
    is.get( temp, 80 );
    if( is )
        st = temp;
    while( is && is.get() != '\n' )
        continue;
    return is;
}

ostream &operator<<( ostream &os, const StringBad &st )
{
    os << st.str;
    return os;
}

