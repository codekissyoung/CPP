#include <initializer_list>

#ifndef __VECTOR__
#define __VECTOR__
using namespace std;
class Vector
{
    private:
        double* elem;
        unsigned long sz;

    public:
        // 构建一个Vector
        Vector( int s );

        Vector( initializer_list<double> lst );

        // 析构函数
        ~Vector() 
        {
            delete[] elem;
        }
        
        // 通过下标访问元素
        double& operator[]( int i );

        int size();
        
        void read();

        void push_back( double );

        double sum();
};
#endif
