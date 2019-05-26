#include "common.h"
#include "func.h"
#include "Stock.h"
#include "Student_info.h"
#include "My_vector.h"
#include "My_stack.h"
#include "My_Queue.h"
#include "StringBad.h"
#include "vec.h"
#include "Sales_item.h"
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
#include <climits>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int main( int argc, char *argv[] )
{
    My_Queue que;

    que.enqueue( 89 );
    que.enqueue( 90 );
    que.enqueue( 1000 );

//    while ( !que.isempty() )
//    {
//        Item temp;
//          que.dequeue( temp );
//        cout << temp << endl;
//    }

    return EXIT_SUCCESS;
}
