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

bool less_than( char arr[], int a, int b )
{
    int n = strlen( arr );
    for( int i = 0; i < n; i++ )
        return arr[ (a + i) % n ] < arr[ ( b + i ) % n ];
}

int main( int argc, char *argv[] )
{
    try
    {
        // 环形数组
        char arr[] = { 's', 'b', 'c', 'q', 'p', 'k' };

        int min = 0;
        int n = sizeof(arr);

        for( int i = 1; i < n; i++ )
        {
            if( less_than( arr, i, min ) )
                min = i;
        }
        for( int i = 0; i < n; i++ )
            putchar( arr[ (min + i) % n ] );

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

