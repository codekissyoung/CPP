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

int j = 0;
constexpr int i = 42;

int main( int argc, char *argv[] )
{
    using namespace std;
    cout << "runing ..." << endl;

//    const int *p        = nullptr;
    constexpr int *q    = nullptr;
    constexpr int *np   = nullptr;

    constexpr const int *p  = &i;
    constexpr int *p1       = &j;

    cout << "done!" << endl;
    return EXIT_SUCCESS;
}
