#include "common.h"
#include "func.h"
#include "stock.h"
#include "median.h"
#include "vector.h"
#include "container.h"
#include "date.h"
#include "stack.h"

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>

int main( int argc, char *argv[] )
{
    using namespace std;

    try
    {
        cout << PI << endl;
        uint64_t count;
        cout << "count:";
        cin >> count;

        uint64_t begin = pow(10, count -1);
        uint64_t end   = pow(10, count);

        for(uint64_t num = begin; num < end; ++num )
        {
            uint64_t sum = 0;
            for(uint64_t pos = 0; pos < count; pos++ )
            {
                uint64_t divisor = pow(10, pos);
                sum += pow( num / divisor % 10, count);
            }
            if( num == sum )
                cout << num << endl;
        }

        return 0;
    }
    catch( domain_error &e )
    {
        cout << e.what();
        cout << endl << "no homework grades" << endl;
    }
    catch( runtime_error &e )
    {
        cerr << "runtime error:" << e.what() << endl;
        return 1;
    }
    catch( ... )
    {
        cout << "unknown exception !" << endl;
        return 2;
    }
}

