#include "common.h"
#include "func.h"
#include "stock.h"
#include "median.h"
#include "vector.h"
#include "date.h"
#include "stack.h"
#include "my_string.h"

#include <iostream>

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

int main( int argc, char *argv[] )
{
    try{
        cout << "Hello CLion!" << endl;
        return EXIT_SUCCESS;
    }
    catch( domain_error &e ){
        cout << e.what() << endl;
        return 1;
    }
    catch( runtime_error &e ) {
        cerr << "runtime error:" << e.what() << endl;
        return 2;
    }
    catch( ... ){
        cout << "unknown exception !" << endl;
        return -1;
    }
}
