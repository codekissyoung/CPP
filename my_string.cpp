#include "my_string.h"

#include <iostream>
#include <cstring>

using namespace std;

int StringBad::num_strings = 0;

StringBad::StringBad( const char *s )
{
    len = strlen( s );
    str = new char[len + 1];
    strcpy( str, s );
    ++num_strings;

    cout << num_strings << " : " << str << " object created" << endl;
}

StringBad::StringBad( const StringBad &st ){
    ++num_strings;
    len = st.len;
    str = new char[len + 1];
    strcpy( str, st.str );
    cout << num_strings << " object copyed" << endl;
}

StringBad &StringBad::operator=( const StringBad &st ){
    cout << "= operator run" << endl;
    if( this == &st )
        return *this;
    delete[] str;

    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    strcpy( str, "C++" );
    ++num_strings;
    cout << num_strings << " : " << str << " object created" << endl;
}

StringBad::~StringBad()
{
    cout << str << " object deleted ";

    --num_strings;

    cout << num_strings << " left" << endl;

    delete[] str;
}

ostream &operator<<( ostream &os, const StringBad &st )
{
    os << st.str;
    return os;
}

void callme1(StringBad &rsb)
{
    cout << "String passed by referencen : ";
    cout << rsb << endl;
}

void callme2( StringBad sb )
{
    cout << "String passed by value : ";
    cout << sb << endl;
}