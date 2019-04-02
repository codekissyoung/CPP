#include "median.h"

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <list>

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

// 返回不及格的学生 实现1
vector<Student_info> extract_fails(vector<Student_info> &students)
{
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0;

    while ( i != students.size() )
    {
        if( fgrade(students[i]) )
        {
            fail.push_back(students[i]);
            students.erase(students.begin() + i );
        } else{
            ++i;
        }
    }
    return fail;
}

// 返回不及格的学生 实现2
vector<Student_info> extract_fails1( vector<Student_info> &students )
{
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();

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

// 使用 list 代替 vector 来实现高效的插入与删除操作
list<Student_info> extract_fails( list<Student_info> &students )
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

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