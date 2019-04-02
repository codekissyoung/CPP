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


        cout << "家庭作业: ";
        vector<double> homework;
        
        read_hw( cin, homework );

        double final_grade = grade( m_score, f_score, homework );

        cout << endl
             << "期中:" << m_score 
             << " 期末:" << f_score 
             << " 家庭:" << median( homework ) 
             << " 总成绩:" << final_grade << endl;
 
        return 0;
    }
    catch( domain_error )
    {
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

