#include "common.h"
#include "func.h"
#include "Stock.h"
#include "Student_info.h"
#include "My_vector.h"
#include "My_stack.h"
#include "My_Queue.h"
#include "My_array.h"
#include "My_pair.h"
#include "StringBad.h"
#include "vec.h"
#include "Sales_item.h"
#include "Str.h"
#include "Screen.h"
#include "Window_mgr.h"
#include "Brass_model.h"

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
#include <valarray>

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <climits>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int main( int argc, char *argv[] )
{
    My_pair<string,int> ratings[4] = {
            My_pair<string,int>("codekissyoung",5),
            My_pair<string,int>("zhangjian",234),
            My_pair<string,int>("fengbo",235),
            My_pair<string,int>("zhj",341)
    };

    ratings[3].first() = "just test";

    for( int i = 0; i < 4; ++i )
    {
        cout << ratings[i].first() << "," << ratings[i].second() << endl;
    }

    return EXIT_SUCCESS;
}
