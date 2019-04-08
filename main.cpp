#include "common.h"
#include "func.h"
#include "stock.h"
#include "median.h"
#include "vector.h"
#include "container.h"
#include "date.h"

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

using namespace std;

int main( int argc, char *argv[] )
{
    try
    {

        array<double, Seasons> expenses;
        fill( &expenses );
        show( expenses );

        int *pt = new int {100};
        int *pt_arr = new int[10];

        int arr[10] = { 10, 23, 45, 56, 67, 76};

        cout << "sizeof pt_arr" << sizeof(pt_arr) << endl;
        cout << "sizeof arr" << sizeof(arr) << endl;
        cout << "*pt: " << *pt << endl;

        delete pt;

        vector<string> test_str {"hello", "codekissyong", "very funny"};
        vector<int> test_int { 12, 34, 55, 67, 76, 32, 23 };

        print(test_int);
        print(test_str);

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

