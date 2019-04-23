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
    vector<Student_info> students;
    Student_info temp;

    while( read( cin, temp ) )
        students.push_back(temp);

    vector<Student_info> fail_students = extract_fails( students );

    for( auto x : students )
        cout << x;

    return EXIT_SUCCESS;
}
