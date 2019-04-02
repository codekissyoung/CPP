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
        cout << "学生姓名 : ";
        string name;
        cin >> name;
        
        cout << "成绩: ";
        double m_score, f_score;
        cin >> m_score >> f_score;

        double x = 0;
        vector<double> homework;
        while( cin >> x )
            homework.push_back( x );

        auto count = homework.size();

        sort( homework.begin(), homework.end() );
        
        auto mid = count / 2;
        double median;
        median = count % 2 == 0 ? ( homework[mid] + homework[mid-1] ) / 2 : homework[mid]; 

        cout << endl
             << "期中:" << m_score 
             << " 期末:" << f_score 
             << " 家庭:" << median
             << " 总成绩:" << 0.2 * m_score + 0.4 * f_score + 0.4 * median << endl;
 
        return 0;
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

