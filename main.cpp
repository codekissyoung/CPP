#include "common.h"
#include "func.h"
#include "stock.h"
#include "median.h"
#include "vector.h"
#include "container.h"
#include "date.h"
#include "stack.h"

#include <iostream>
#include <array>

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

int main( int argc, char *argv[] )
{
    try
    {
        cout << PI << endl;
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
