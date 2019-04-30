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

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <fstream>

int main( int argc, char *argv[] )
{
    using namespace std;
    cout << "runing ..." << endl;

    Sales_item book;

    cout << "ISBN\t\t\t\tsold\tprice\trevenue" << endl;
    while( cin >> book ){
        cout << book << endl;
    }

    cout << "done!" << endl;
    return EXIT_SUCCESS;
}
