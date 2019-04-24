#ifndef __FUNC_H__
#define __FUNC_H__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <map>

typedef std::array<std::string, 4> ARRAY_SEA;
typedef std::string::const_iterator iter;
typedef std::vector<std::string> p_func_str_in_vec_out(const std::string &);

extern const std::string test_url_str;

extern const ARRAY_SEA Snames;

void fill( ARRAY_SEA *pa );

void show( ARRAY_SEA da );

int square( int x );

int *find( const std::vector<int> &vec, int value );

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
bool is_palindrome( const std::string &s );

// 不是 url 的字符
bool not_url_char( char c );

// 是 url 的字符
bool url_char( char c );

iter url_beg( iter b, iter e );

iter url_end( iter b, iter e );

// 查找一个字符串中包含的所有 url
std::vector<std::string> find_urls( const std::string &s );

// 记录输入的单词，以及单词出现的行数
std::map<std::string, std::vector<int>>
xref( std::istream &in, std::vector<std::string> (*)(const std::string &) = split );

// 格式化输出 vector
template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> &vec )
{
    std::string str = "{ ";
    for( auto x : vec )
    {
        str += std::to_string( x );
        str += ", ";
    }
    str.pop_back();
    str.pop_back();
    str += " }";
    os << str << std::endl;

    return os;
}

// 打印一个 string 为键的关联数组
template <typename T>
std::ostream &operator<<( std::ostream &os, std::map<std::string,T> &m )
{
    os << "{" << std::endl;
    for( auto x : m )
        os << "\t" << x.first << " : " << x.second << "," << std::endl;

    os << "}" << std::endl;
    return os;
}

// 函数模板的使用
template <typename T>
void print( const std::list<T> &li )
{
    std::cout << "{ ";
    for( auto x : li )
        std::cout << x << " ";
    std::cout << "}" << std::endl;
}

// 打印数组
template <typename T>
void print( T* arr, int n )
{
    std::cout << "{ ";
    for( int i = 0; i < n; i++ )
    {
        std::cout << arr[i];
        if( i != n -1 )
            std::cout << ", ";
    }
    std::cout << " }" << std::endl;
}

template <typename T>
void swap( T &v1, T &v2 )
{
    T temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}

// 全排列算法
void permutation( int* arr, int s, int e );

#endif
