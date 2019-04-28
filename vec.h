#ifndef CPP_VEC_H
#define CPP_VEC_H

#include <cstddef>
#include <memory>

template <typename T>
class Vec {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef size_t size_type;
        typedef T value_type;

        Vec(){ create(); }

        explicit Vec( size_type n, const T &val = T() ) { create( n, val ); }

        Vec( const Vec& v ) { create( v.begin(), v.end() ); }

        Vec &operator=( const Vec& );

        ~Vec(){ uncreate(); }

        size_type size() const { return limit - data; }

        // 根据 Vec 是否常量，分别调用不同的方法
        T &operator[]( size_type i ){ return data[i]; }
        const T &operator[]( size_type i ) const { return data[i]; }

        iterator begin() { return data; }
        const_iterator begin() const { return data; }

        iterator end() { return avail; }
        const_iterator end() const { return avail; }

        void push_back( const T &val )
        {
            if( avail == limit )
                grow(); // 重新申请内存
            unchecked_append( val );    // 将新增元素加入到元素末端
        }

        void clear();

    private:
        iterator data;   // 指针指向 Vec 的第一个元素
        iterator avail;  // 指针指向 最后一个元素后面的一个位置
        iterator limit;  // 指针指向 目前已申请内存的后面一个位置

        std::allocator<T> alloc;

        void create();

        void create(size_type, const T &);

        void create(const_iterator, const_iterator);

        void uncreate();

        void grow();

        void unchecked_append( const T & );
};

#endif
