#include "common.h"
#include "func.h"
#include "stock.h"
#include "student.h"
#include "vector.h"
#include "date.h"
#include "stack.h"
#include "my_string.h"

#include <iostream>

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;

int main( int argc, char *argv[] )
{
    string str = " welcome to http://www.baidu.com/abc/gde ，we are big family. refer to http://codekissyoung.com eg. ";

    auto vec_str = find_urls( str );

    cout << vec_str;

    return EXIT_SUCCESS;
}
