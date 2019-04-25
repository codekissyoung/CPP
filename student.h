#ifndef CPP_STUDENT_H
#define CPP_STUDENT_H

#include <vector>
#include <iostream>
#include <list>
#include <exception>

struct Student_info{
    std::string name;
    double midterm_score;
    double final_score;
    std::vector<double> homework;
};

// 获取中值
double median( std::vector<double> vec );

// 获取中值 泛化
template <typename T>
T median( std::vector<T> v )
{
    auto size = v.size();
    if( v.empty() )
        throw std::domain_error("median of an empty vector");
    sort( v.begin(), v.end() );

    auto mid = size / 2;
    return ( size % 2 == 0 ) ? ( v[mid] + v[mid-1] ) / 2 : v[mid];
}

// 计算总成绩
double grade( double, double, double );
double grade( double, double, const std::vector<double> & );

// 算出一个学生的总成绩
double grade( const Student_info & );

// 将输入流中家庭作业的成绩读入到vector中
std::istream &read_hw( std::istream &, std::vector<double> & );

// 读入一个学生的成绩
std::istream &read( std::istream &, Student_info & );

// 比较两个Student_info的大小
bool comp_name(const Student_info &, const Student_info &);

// 判断该成绩是否合格
bool fgrade( const Student_info & );

// 返回不及格的学生
std::vector<Student_info> extract_fails( std::vector<Student_info> & );
std::list<Student_info> extract_fails( std::list<Student_info> & );

std::ostream &operator<<( std::ostream &, Student_info & );
#endif
