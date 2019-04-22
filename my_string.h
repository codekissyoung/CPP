#ifndef CPP_MY_STRING_H
#define CPP_MY_STRING_H

#include <iostream>

class StringBad
{
    private:
        char *str;
        int len;
        static int num_strings;

    public:
        explicit StringBad( const char *s ); // 构造函数
        StringBad();                         // 默认构造函数
        StringBad( const StringBad &st );    // 复制构造函数
        ~StringBad();                        // 析构函数

        StringBad &operator=( const StringBad &st );
        StringBad &operator=( const char * );
        char &operator[]( int i );
        const char &operator[]( int i ) const;

        friend bool operator<( const StringBad &st, const StringBad &st2 );
        friend bool operator>( const StringBad &st, const StringBad &st2 );
        friend std::ostream &operator<<(std::ostream &os, const StringBad &st );
        friend std::istream &operator>>(std::istream &is, StringBad &st);

        static int HowMany(){ return num_strings; }
};

std::ostream &operator<<( std::ostream &os, const StringBad &st );
std::istream &operator>>( std::istream &is, StringBad &st );
bool operator<( const StringBad &st, const StringBad &st2 );
bool operator>( const StringBad &st, const StringBad &st2 );

#endif //CPP_STRING_H
