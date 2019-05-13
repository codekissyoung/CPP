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

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;

int main( int argc, char *argv[] ) {
    cout << "runing ..." << endl;

    deque<int> deq = {2, 3, 4, 5, 6, 7, 9};

    stack<int> stk(deq);

    stack<string, vector<string>> str_stk;

    stack<int> intStack;

    for (size_t ix = 0; ix != 10; ++ix)
        intStack.push(ix);

    while (!intStack.empty())
    {
        int value = intStack.top();
        cout << value << endl;
        intStack.pop();
    }


    cout << "done!" << endl;

    return EXIT_SUCCESS;
}
