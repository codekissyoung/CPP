#ifndef __VECTOR__
#define __VECTOR__

#include <initializer_list>

class Vector
{
    private:
        double* elem{};
        unsigned long sz{};
        void copy( const Vector& );

    public:

        // 默认构造函数
        Vector() = default;

        // 使用 整数 的构造函数
        Vector( int s );

        // 使用 初始化列表 的构造函数
        Vector( std::initializer_list<double> lst );

        // 拷贝构造函数
        Vector( const Vector& arg );

        // 拷贝赋值操作
        Vector& operator=( const Vector& );

        ~Vector()
        {
            delete[] elem;
        }

        double& operator[]( int i ) const;

        int size() const;
        
        void read();

        void push_back( double );

        double sum();
};
#endif
