#include "vector.h"

#include <iostream>
#include <initializer_list>

using namespace std;

Vector::Vector(int s)
{
    if( s < 0 )
        throw length_error{"length < 0"};
    elem = new double[s];
    sz = s;
}

void Vector::copy(const Vector &arg)
{
    for(int i = 0; i < arg.size(); ++i )
        elem[i] = arg.elem[i];
}

Vector::Vector( const Vector& arg ) : elem{ new double[arg.size()] }, sz{ arg.sz }
{
    copy(arg);
}

Vector::Vector( initializer_list<double> lst ) : elem{ new double[lst.size()] }, sz{ lst.size() }
{
    ::copy( lst.begin(), lst.end(), elem );
}

Vector &Vector::operator=( const Vector& vec )
{
    auto *p = new double[vec.size()];
    for( int i = 0; i < vec.size(); ++i )
        p[i] = vec[i];
    delete[] elem;
    elem = p;
    sz = vec.size();
    return *this;
}

double &Vector::operator[](int i) const
{
    if( i < 0 || i >= size() )
        throw out_of_range { "Vector::operator[]" };
    return elem[i];
}

int Vector::size() const
{
    return sz;
}

void Vector::read()
{
    for( int i = 0; i != size(); i++ )
        cin >> elem[i];
}

void Vector::push_back( double i )
{
    elem[size() - 1] = i;
    sz ++;
}

double Vector::sum()
{
    double sum = 0;
    for( int i = 0; i != size(); i++ )
        sum += elem[i];
    return sum;
}
