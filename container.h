#include "vector.h"

class Container
{
    public:

        virtual ~Container() {};

        virtual double& operator[]( int ) = 0;

        virtual int size() const = 0;

};

