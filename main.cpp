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
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <initializer_list>
#include <stack>
#include <queue>
#include <memory>

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;

int main( int argc, char *argv[] ) {
    cout << "runing ..." << endl;

    shared_ptr<string> p1; // 一个空智能指针

    if( p1 && p1->empty() )
        *p1 = "hi";

    string test_str = "hello world";


    return EXIT_SUCCESS;
}
