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

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;

int main( int argc, char *argv[] )
{
    cout << "runing ..." << endl;

    list<string> authors = {"caokaiyan","zhangjian","fengbo"};

    vector<const char*> articles = { "a", "an", "the" };

    list<string> list2( articles.begin(), articles.end() );

    deque<string> authList( authors.begin(), authors.end() );

    vector<string> words( authList.begin(), authList.end() );

    forward_list<string> words2( articles.begin(), articles.end() );


    // array
    array<string,4> arr = {"caokaiyan","heping"};

    array<string,4> copy = arr;

//    for( const auto x : arr )
//        cout << x << endl;
//
//    for( const auto x  : copy )
//        cout << x << endl;
//

    list<string> names;
    vector<const char*> oldstyle;
//    names = oldstyle;

    names.assign( oldstyle.cbegin(), oldstyle.cend() );

    // 比较运算符
    vector<int> v1 = {1,3,5,7,9,12};
    vector<int> v2 = {1,3,9};
    vector<int> v3 = {1,3,5,7};
    vector<int> v4 = {1,3,5,7,9,12};

    cout << (v1 < v2) << endl;

    cout << ( v1 == v4 ) << endl;

    cout << "done!" << endl;
    return EXIT_SUCCESS;
}
