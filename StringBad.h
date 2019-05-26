#ifndef CPP_STRINGBAD_H
#define CPP_STRINGBAD_H

#include <iostream>

class StringBad
{
    private:
        char *str;                  // 指向string实际存储的char数组
        int len = 0;                // char数组长度
        static int num_strings;     // StringBad 类构造的对象的个数

    public:
        StringBad();                         // 默认构造函数
        ~StringBad();                        // 析构函数
        StringBad( const char *s );          // 构造函数,不使用 explicit,因为这个隐式转换很常见和方便
        StringBad( const StringBad &st );    // 复制构造函数
        int length() const { return len; }

        StringBad &operator=( const StringBad &st );
        StringBad &operator=( const char * );
        char &operator[]( int i );
        const char &operator[]( int i ) const;

        friend bool operator<( const StringBad &st, const StringBad &st2 );
        friend bool operator>( const StringBad &st, const StringBad &st2 );
        friend bool operator==( const StringBad &st, const StringBad &st2 );
        friend std::ostream &operator<<(std::ostream &os, const StringBad &st );
        friend std::istream &operator>>(std::istream &is, StringBad &st);

        static int HowMany(){ return num_strings; }
};

std::ostream &operator<<( std::ostream &os, const StringBad &st );
std::istream &operator>>( std::istream &is, StringBad &st );

bool operator<( const StringBad &st, const StringBad &st2 );
bool operator>( const StringBad &st, const StringBad &st2 );
bool operator==( const StringBad &st, const StringBad &st2 );

#endif //CPP_STRING_H
