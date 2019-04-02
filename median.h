#ifndef CPP_MEDIAN_H
#define CPP_MEDIAN_H
#include <vector>
#include <iostream>
struct Student_info{
    std::string name;
    double midterm_score, final_score;
    std::vector<double> homework;
};

double median( std::vector<double> vec );

double grade( double m_score, double f_score, double h_score );
double grade( double m_score, double f_score, const std::vector<double> &hw );
double grade( const Student_info &s );

std::istream &read_hw( std::istream &in, std::vector<double> &hw );
std::istream &read( std::istream &is, Student_info &s );

bool compare( const Student_info &x, const Student_info &y );
#endif
