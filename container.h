#ifndef __CONTAINER__
#define __CONTAINER__

#include "vector.h"

class Container
{
    public:

        virtual ~Container() {};

        virtual double& operator[]( int ) = 0;

        virtual int size() const = 0;

};
/*
class Vector_container : virtual public Container
{
    Vector v;

    public :

        Vector_container();

        Vector_container( int s );

        Vector_container( initializer_list<double> lst );

        ~Vector_container();

        double& operator[]( int s);

        int size();

};
*/
#endif
