#ifndef CPP_STR_H
#define CPP_STR_H

#include "vec.h"

class Str {
    public:
        typedef Vec<char>::size_type size_type;

        Str(){}

        Str(size_type n, char c) : data(n,c) {

        }

        Str( const char *cp )
        {
            std::copy( cp, cp + std::strlen(cp), std::back_inserter(data) );
        }

        template <typename In>
        Str(In b, In e)
        {
            std::copy( b, e, std::back_inserter(data) );
        }

        char &operator[](size_type i){ return data[i]; }
        const char &operator[](size_type i) const { return data[i]; }

        friend std::istream & operator>>( std::istream &, Str & );
        friend std::ostream & operator<<( std::ostream &, const Str & );

        size_type size() const { return data.size(); }

    private:
        Vec<char> data;
};
#endif
