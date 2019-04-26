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

    vector<Student_info> students;
    Student_info record;

    while ( record.read( cin ) )
        students.push_back( record );

    sort( students.begin(), students.end(), comp_name );

    for( auto x : students )
        cout << x.get_name();

    return EXIT_SUCCESS;
}
