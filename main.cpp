#include "common.h"
#include "func.h"
#include "stock.h"
#include "median.h"
#include "vector.h"
#include "container.h"
#include "date.h"

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

#include <cmath>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cctype>
#include <fstream>
#include <cerrno>

using namespace std;

int main(int argc, char *argv[] )
{
    try
    {

        vector<Student_info> students;

        Student_info record;

        while( read(cin, record) )
        {
            students.push_back(record);
        }

        sort(students.begin(), students.end(), compare );


        for( auto x : students )
        {
            cout << x.name << "  ";

            double final_grade = grade( x );

            cout << "总成绩 : " << final_grade << endl;
        }

        return 0;
    }
    catch( domain_error e )
    {
        cout << e.what();
        cout << endl << "no homework grades" << endl;
    }
    catch( runtime_error& e )
    {
        cerr << "runtime error:" << e.what() << endl;
        return 1;
    }
    catch( ... )
    {
        cout << "unknown exception !" << endl;
        return 2;
    }
}

