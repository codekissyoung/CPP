#ifndef __VECTOR__
#define __VECTOR__

#include <initializer_list>

class My_vector
{
    private:
        double* elem{};
        unsigned long sz{};
        void copy( const My_vector& );

    public:

        My_vector() = default;

        explicit My_vector( int s );

        My_vector( std::initializer_list<double> lst );

        My_vector( const My_vector& arg );

        My_vector& operator=( const My_vector& );

        ~My_vector(){ delete[] elem; }

        double& operator[]( int i ) const;

        int size() const;
        
        void read();

        void push_back( double );

        double sum();
};
#endif
