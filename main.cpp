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

int main(int argc, char *argv[] )
{
    try
    {
        Screen myScreen( 5, 5, 'x' );
        myScreen.move( 4, 0 ).set('#').display(cout);
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

