#include "median.h"

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;

// 获取中值
double median( vector<double> vec )
{
    auto size = vec.size();

    if( size == 0 )
        throw domain_error( "median of an empty vector " );

    sort( vec.begin(), vec.end() );

    auto mid = size / 2;

    return ( size % 2 == 0 ) ? ( vec[mid] + vec[ mid - 1 ] ) / 2 : vec[ mid ];
}

// 计算总成绩
double grade( double m_score, double f_score, double h_score )
{
    return 0.2 * m_score + 0.4 * f_score + 0.4 * h_score;
}

double grade( double m_score, double f_score, const vector<double> &hw )
{
    if( hw.size() == 0 )
        throw domain_error("no homework");
    return grade( m_score, f_score, median( hw ) );
}

// 读取家庭成绩
istream &read_hw( istream &in, vector<double> &hw )
{
    if( in )
    {
        hw.clear();

        double x;
        while( in >> x )
            hw.push_back(x);

        in.clear();
    }
    return in;
}

// 读入一个学生的成绩
istream &read( istream &is, Student_info &s )
{
    is >> s.name >> s.midterm_score >> s.final_score;
    read_hw( is, s.homework );
    return is;
}

// 算出一个学生的总成绩
double grade( const Student_info &s )
{
    return grade( s.midterm_score, s.final_score, s.homework );
}

// 比较两个Student_info的大小
bool compare( const Student_info &x, const Student_info &y )
{
    return x.name < y.name;
}

// 判断该成绩是否合格
bool fgrade( const Student_info &s )
{
    return grade(s) < 60;
}
