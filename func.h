#ifndef __FUNC_H__
#define __FUNC_H__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>

const int Seasons = 4;

const std::array<std::string, Seasons> Snames = {
        "Spring",
        "Summer",
        "Fall",
        "Winter"
};

void fill( std::array<double, Seasons> *pa );

void show( std::array<double, Seasons> da );

int square( int x );

// 将一段字符拆分成单词
std::vector<std::string> split( const std::string &s );

// 将一段字符串拆分成单词的 迭代器实现版本
std::vector<std::string> split1( const std::string &str );

// 获取一个 string 向量的最长字符串的 长度
std::string::size_type width( const std::vector<std::string> &v );

// 给string向量加上 * 边框
std::vector<std::string> frame( const std::vector<std::string> &v );

// 纵向链接两个向量
std::vector<std::string> vcat( const std::vector<std::string>& top, const std::vector<std::string> &bottom );

// 横向链接两个向量
std::vector<std::string> hcat( const std::vector<std::string> &left, const std::vector<std::string> &right );

// 判断一个字符串是否是回文
bool is_palindrome( const std::string& s );

// 不是 url 的字符
bool not_url_char( char c );

// 函数模板的使用
template <typename elemType>
void print( const std::vector<elemType> &vec )
{
    std::cout << "{ ";
    for( auto x : vec )
        std::cout << x << ", ";
    std::cout << " }" << std::endl;
}

// 函数模板的使用
template <typename elemType>
void print( const std::list<elemType> &li )
{
    std::cout << "{ ";
    for( auto x : li )
        std::cout << x << ", ";
    std::cout << " }" << std::endl;
}

int *find( const std::vector<int> &vec, int value );

#endif
