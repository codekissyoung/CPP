#ifndef __CONTAINER__
#define __CONTAINER__

#include "vector.h"
class Container
{
    public:

        virtual ~Container() {};

        virtual double& operator[]( int );

        virtual int size() const;

};
#endif
