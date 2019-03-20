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

Vector::Vector( initializer_list<double> lst )
    : elem{ new double[lst.size()] }, sz{ lst.size() }
{
    copy( lst.begin(), lst.end(), elem );
}

double& Vector::operator[](int i)
{
    if( i < 0 || i >= size() )
        throw out_of_range { "Vector::operator[]" };
    return elem[i];
}

int Vector::size()
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
