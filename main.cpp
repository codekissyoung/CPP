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

using namespace std;

int main( int argc, char *argv[] )
{
    try
    {
        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        permutation( arr, 0, sizeof(arr)/ sizeof(int) - 1 );

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

