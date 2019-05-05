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
#include "Sales_data.h"
#include "Str.h"
#include "Screen.h"
#include "Window_mgr.h"

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

    Screen myScreen = Screen( 5, 5, 'X');

    myScreen.move( 4, 0 ).set('#').display( cout );
    cout << endl;

    myScreen.display( cout );
    cout << endl;

    cout << "done!" << endl;
    return EXIT_SUCCESS;
}
