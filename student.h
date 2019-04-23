#ifndef CPP_STUDENT_H
#define CPP_STUDENT_H

#include <vector>
#include <iostream>
#include <list>

struct Student_info{
    std::string name;
    double midterm_score;
    double final_score;
    std::vector<double> homework;
};

// 获取中值
double median( std::vector<double> vec );

// 计算总成绩
double grade( double, double, double );
double grade( double, double, const std::vector<double> & );

// 算出一个学生的总成绩
double grade( const Student_info & );

// 读取家庭成绩
std::istream &read_hw( std::istream &, std::vector<double> & );

// 读入一个学生的成绩
std::istream &read( std::istream &, Student_info & );

// 比较两个Student_info的大小
bool compare( const Student_info &, const Student_info & );

// 判断该成绩是否合格
bool fgrade( const Student_info & );

// 返回不及格的学生
std::vector<Student_info> extract_fails( std::vector<Student_info> & );
std::list<Student_info> extract_fails( std::list<Student_info> & );

#endif
