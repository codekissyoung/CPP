#include "common.h"
#include "func.h"
#include "stock.h"
#include "student.h"
#include "vector.h"
#include "date.h"
#include "stack.h"
#include "my_string.h"

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

    string str = "you are a nice people";

    list<string> list_str;

    split( str, back_inserter(list_str) );

    vector<string> vec_str;

    split( str, back_inserter(vec_str) );

    cout << vec_str;

    cout << list_str;

    return EXIT_SUCCESS;
}
