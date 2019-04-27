#ifndef CPP_VEC_H
#define CPP_VEC_H


#include <cstddef>

template <typename T>
class Vec {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;

        Vec()
        {
            create();
        }

        explicit Vec( size_type n, const T &val = T() )
        {
            create( n, val );
        }

        Vec( const Vec& v ) { create( v.begin(), v.end() ); }

        Vec &operator=( const Vec& )
        {

        }

        ~Vec(){ uncreate(); }

        size_type size() const { return limit - data; }

        // 根据 Vec 是否常量，分别调用不同的方法
        T &operator[]( size_type i ){ return data[i]; }
        const T &operator[]( size_type i ) const { return data[i]; }

        iterator begin() { return data; }
        const_iterator begin() const { return data; }

        iterator end() { return limit; }
        const_iterator end() const { return limit; }

    private:
        iterator data;   // 首元素
        iterator limit;  // 尾后元素

};

#endif
