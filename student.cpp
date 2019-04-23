#include "student.h"

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>

#include <list>

using namespace std;

double median( vector<double> vec )
{
    auto size = vec.size();
    if( vec.empty() )
        throw domain_error( "median of an empty vector" );
    sort( vec.begin(), vec.end() );
    auto mid = size / 2;
    return ( size % 2 == 0 ) ? ( vec[mid] + vec[ mid - 1 ] ) / 2 : vec[ mid ];
}

// 计算最终成绩
double grade( double m_score, double f_score, double h_score )
{
    return 0.2 * m_score + 0.4 * f_score + 0.4 * h_score;
}
double grade( double m_score, double f_score, const vector<double> &hw )
{
    if( hw.empty() )
        throw domain_error("no homework");
    return grade( m_score, f_score, median( hw ) );
}
double grade( const Student_info &s )
{
    return grade( s.midterm_score, s.final_score, s.homework );
}

// 判定不及格
bool fgrade( const Student_info &s )
{
    return grade( s ) < 60;
}

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

istream &read( istream &is, Student_info &s )
{
    is >> s.name >> s.midterm_score >> s.final_score;
    read_hw( is, s.homework );
    return is;
}



bool comp_name(const Student_info &x, const Student_info &y)
{
    return x.name < y.name;
}

vector<Student_info> extract_fails( vector<Student_info> &students )
{
    vector<Student_info> fail;
    auto iter = students.begin();

    while( iter != students.end() )
    {
        if( fgrade(*iter) )
        {
            fail.push_back(*iter);
            // 进行 erase 操作后，所有位于删除元素后面的元素的迭代器都会失效。
            // 所幸，erase 返回了一个迭代器，它指向我们刚刚删除的元素的后一个元素
            // 所以赋值给 iter 后，迭代器继续生效
            iter = students.erase(iter);
        }
        else
            ++iter;
    }
    return fail;
}

list<Student_info> extract_fails( list<Student_info> &students )
{
    list<Student_info> fail;
    auto iter = students.begin();

    while( iter != students.end() )
    {
        if( fgrade(*iter) )
        {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else
            ++iter;
    }
    return fail;
}

std::ostream &operator<<( std::ostream &o, Student_info &s )
{
    o << s.name << "," << s.final_score << "," << s.midterm_score << ",homework: ";
    for( auto x : s.homework )
    {
        o << x << " ";
    }
    o << endl;
    return o;
}