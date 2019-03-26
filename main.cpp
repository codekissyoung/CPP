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
        Vector vec { 23.33, 34.52, 34.23, 21.34 };

        for( int i = 0; i < vec.size(); ++i )
            cout << vec[i] << endl;

        Vector vec2;
        vec2 = vec;

        cout << "vec2 : " << endl;
        for( int i = 0; i < vec2.size(); ++i )
            cout << vec2[i] << endl;

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

