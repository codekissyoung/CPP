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

/* 使用到的 c 标准库 */
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cctype>

/* 项目头文件 */
#include "common.h"
#include "stock.h"
#include "median.h"
#include "vector.h"
#include "container.h"

using namespace std;

// -------------------------------------- main ------------------------------------------- //

int main( int argc, char *argv[] )
{
    static_assert( sizeof(int) >= 4, "sizeof int 小于4字节\n");

    Vector test_v1 { 1, 2, 3, 4 ,5 };
    Vector test_v2 { 1.23, 4.21, 3.45, 7.8 };

    cout << "sum:" << test_v2.sum() << endl;
    cout << "sum:" << test_v1.sum() << endl;
    
    cout << sizeof(wchar_t) << endl;

    auto ac = alignof(3.0);

    cout << ac << endl;

    return EXIT_SUCCESS;
}

