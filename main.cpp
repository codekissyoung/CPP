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

#include "common.h"
#include "func.h"
#include "stock.h"
#include "median.h"
#include "vector.h"
#include "container.h"

using namespace std;

int main( int argc, char *argv[] )
{
    try
    {
        vector<double> temps;

        double temp;

        while( cin >> temp )
            temps.push_back(temp);

        sort(temps.begin(),temps.end()); 

        for( auto x : temps )
            cout << x << "\t";

        cout << endl;

        cout << "中值:" << temps[temps.size()/2] << endl;

        cout << square(12) << endl;

        Vector test_v2 { 1.23, 4.21, 3.45, 7.8 };

        cout << "sum:" << test_v2.sum() << endl;

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
