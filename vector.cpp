#include "vector.h"

#include <iostream>
#include <initializer_list>

using namespace std;

My_vector::My_vector(int s)
{
    if( s < 0 )
        throw length_error{"length < 0"};
    elem = new double[s];
    sz = s;
}

void My_vector::copy(const My_vector &arg)
{
    for(int i = 0; i < arg.size(); ++i )
        elem[i] = arg.elem[i];
}

My_vector::My_vector( const My_vector& arg ) : elem{ new double[arg.size()] }, sz{ arg.sz }
{
    copy(arg);
}

My_vector::My_vector( initializer_list<double> lst ) : elem{ new double[lst.size()] }, sz{ lst.size() }
{
    ::copy( lst.begin(), lst.end(), elem );
}

My_vector &My_vector::operator=( const My_vector& vec )
{
    auto *p = new double[vec.size()];
    for( int i = 0; i < vec.size(); ++i )
        p[i] = vec[i];
    delete[] elem;
    elem = p;
    sz = vec.size();
    return *this;
}

double &My_vector::operator[](int i) const
{
    if( i < 0 || i >= size() )
        throw out_of_range { "My_vector::operator[]" };
    return elem[i];
}

int My_vector::size() const
{
    return sz;
}

void My_vector::read()
{
    for( int i = 0; i != size(); i++ )
        cin >> elem[i];
}

void My_vector::push_back( double i )
{
    elem[size() - 1] = i;
    sz ++;
}

double My_vector::sum()
{
    double sum = 0;
    for( int i = 0; i != size(); i++ )
        sum += elem[i];
    return sum;
}
