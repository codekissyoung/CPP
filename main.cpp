#include "common.h"
#include "func.h"
#include "stock.h"
#include "student.h"
#include "vector.h"
#include "date.h"
#include "stack.h"
#include "my_string.h"
#include "vec.h"
#include "Sales_item.h"
#include "Str.h"

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <initializer_list>

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;

int main( int argc, char *argv[] )
{
    cout << "runing ..." << endl;

    Sales_data total;

    if( read( cin, total ) )
    {
        Sales_data trans;
        while( read(cin, trans) )
        {
            if( total.isbn() == trans.isbn() )
            {
                total.combine(trans);
            }
            else
            {
                print(cout, total);
                cout << endl;
                total = trans;
            }
        }
        print(cout, total);
        cout << endl;
    }
    else
    {
        cerr << "No data?" << endl;
    }


    cout << "done!" << endl;
    return EXIT_SUCCESS;
}
