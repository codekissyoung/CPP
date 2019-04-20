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
        StringBad(const char *s);
        StringBad( const StringBad &st );
        StringBad();
        ~StringBad();

        // = 赋值操作符
        StringBad &operator=( const StringBad &st );

        friend std::ostream &operator<<(std::ostream &os, const StringBad &st );
};

std::ostream &operator<<( std::ostream &os, const StringBad &st );

void callme1( StringBad &rsb );
void callme2( StringBad );

#endif //CPP_STRING_H
