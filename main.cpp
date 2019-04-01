#include <iomanip>
#include <ios>
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <array>
#include <algorithm>
#include <stdexcept>

#include <cmath>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cctype>
#include <fstream>
#include <cerrno>

#include "common.h"
#include "func.h"
#include "stock.h"
#include "median.h"
#include "vector.h"
#include "container.h"
#include "date.h"

using namespace std;

int main(int argc, char *argv[] )
{
    try
    {
        Sales_data book1( cin );

        print( cout, book1 );

        int int_arr[] = { 1, 2, 3, 4, 5, 6 };

        vector<int> ivec( begin( int_arr ), end( int_arr ) );

        for( auto x : ivec )
            cout << x << endl;


        return EXIT_SUCCESS;
    }
    catch( runtime_error& e )
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

