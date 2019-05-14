#ifndef __FUNC_H__
#define __FUNC_H__

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <map>
#include <algorithm>

typedef std::array<std::string, 4> ARRAY_SEA;
typedef std::string::const_iterator iter;
typedef std::vector<std::string> p_func_str_in_vec_out(const std::string &);

void skip_to_int();

int get_int();

int get_int(int low, int high);

extern const std::string test_url_str;

extern const ARRAY_SEA Snames;

void fill( ARRAY_SEA *pa );

void show( ARRAY_SEA da );

bool not_space( char c );

bool space( char c);

int square( int x );

bool isShorter( const std::string &s1, const std::string &s2 );

void biggies( std::vector<std::string> &words, std::vector<std::string>::size_type sz );

template <typename T>
void my_swap( T &v1, T &v2 )
{
    T temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}

int *find( const std::vector<int> &vec, int value );

// 将一段字符拆分成单词
std::vector<std::string> split( const std::string &s );

// 将一段字符串拆分成单词的 迭代器实现版本
std::vector<std::string> split1( const std::string &str );

// 使用输出迭代器改造，获得更大的适应性
template <typename Out>
void split( const std::string &str, Out out )
{
    auto i = str.begin();

    while( i != str.end() )
    {
        i = std::find_if( i, str.end(), not_space );

        auto j = std::find_if( i, str.end(), space );

        if( i != str.end() )
            *out++ = std::string( i, j );

        i = j;
    }
}

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

// 测试顺序只读访问
template <typename In, typename X>
In my_find( In begin, In end,const X &x )
{
    while( begin != end && *begin != x )
        ++begin;
    return begin;
}

// 测试顺序只写访问
template <typename In, typename Out>
Out my_copy( In begin, In end, Out dest )
{
    while( begin != end )
        *dest++ = *begin++;

    return dest;
}

// 测试顺序读写访问, 将[beg,end)区间的所有等于 x 的元素替换成 y
template <typename For, typename X>
void my_replace( For beg, For end, const X &x, const X &y )
{
    while( beg != end )
    {
        if( *beg == x )
            *beg = y;
        ++beg;
    }
}

// 可逆访问例子
template <typename Bi>
void my_reverse( Bi begin, Bi end )
{
    while( begin != end )
    {
        --end;
        if( begin != end )
            swap( *begin++, *end );
    }
}

// 随机访问迭代器
template <typename Ran, class X>
bool my_binary_search( Ran begin, Ran end, const X &x )
{
    while ( begin < end )
    {
        Ran mid = begin + ( end - begin ) / 2;
        if( *mid > x )
            end = mid;
        else if( *mid < x )
            begin = mid + 1;
        else
            return true;
    }
    return false;
}

// 格式化输出list
template <typename T>
std::ostream &operator<<(std::ostream &os, std::list<T> &list )
{
    auto end = list.end();
    os << "{ ";
    for( auto begin = list.begin(); begin != end;  )
    {
        os << *begin;
        ++begin;
        if( begin != end )
            os << ", ";
    }
    os << " }" << std::endl;
    return os;
}

// 格式化输出 vector
template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> &vec )
{
    auto end = vec.end();
    os << "{ ";
    for( auto begin = vec.begin(); begin != end;  )
    {
        os << *begin;
        ++begin;
        if( begin != end )
            os << ", ";
    }
    os << " }" << std::endl;
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

// 全排列算法
void permutation( int* arr, int s, int e );

#endif
