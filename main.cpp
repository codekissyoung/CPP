#include <iomanip>
#include <ios>
#include <iostream>
#include <complex>
#include <vector>

#include <string>
#include <vector>
#include <list>
#include <map>

#include <array>
#include <algorithm>
#include <stdexcept> /* 标准异常库 */

/* 使用到的 c 标准库 */
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cctype>

/* 项目头文件 */
#include "common.h"
#include "stock.h"
#include "median.h"
#include "vector.h"

// 定义一个学生的数据结构
struct Student_info
{/*{{{*/
    string name;
    double midterm;
    double final_term;
    vector<double> homework;
};/*}}}*/

class Person
{/*{{{*/
    public:
        Person();
        ~Person();
        void eat();
        string name;
        int age;
};/*}}}*/

Person::Person()
{/*{{{*/
    cout << "Person()" << endl;
}/*}}}*/

Person::~Person()
{/*{{{*/
    cout << "~Person()" <<endl;
}/*}}}*/

void Person::eat()
{/*{{{*/
    cout << "Person eat" << endl;
}/*}}}*/

class Worker : public Person
{/*{{{*/
    public:
        Worker();
        ~Worker();
        void eat();
        void work();
        double salary;
};/*}}}*/

Worker::Worker()
{/*{{{*/
    cout << "Worker()" << endl;
}/*}}}*/

Worker::~Worker()
{/*{{{*/
    cout << "~Worker()" << endl;
}/*}}}*/

void Worker::eat()
{/*{{{*/
    cout << "worker eat" << endl;
}/*}}}*/

void Worker::work()
{/*{{{*/
    cout << "name : " << name << " age : " << age << " salary : " << salary << endl;
}/*}}}*/

void throw_1()
{/*{{{*/
    cout << "抛出异常" << endl;
    throw 1;
}/*}}}*/

// 将完整的一个字符串 分割成单词，存于 vector<string> 中
vector<string> split( const string& s )
{/*{{{*/
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;
    while ( i != s.size() )
    {
        while( i != s.size() && isspace( s[i] ) )
        {
            ++i;
        }

        string_size j = i;

        while( j != s.size() && isspace( s[j] ) == 0 )
        {
            ++j;
        }

        if( i != j )
        {
            ret.push_back( s.substr( i, j - i ) );
            i = j;
        }
    }
    return ret;
}/*}}}*/

// 计算期末成绩
double grade( double m, double f, double h )
{/*{{{*/
    return 0.2 * m + 0.4 * f + 0.4 * h;
}/*}}}*/

// 计算期末成绩(重载）
double grade( double m, double f, const vector<double>& hw )
{/*{{{*/
    if( hw.size() == 0 )
        throw domain_error( "student has done no homework");
    return grade( m, f, median(hw) );
}/*}}}*/

// 计算一个学生的总成绩
double grade( const Student_info& s )
{/*{{{*/
    return grade( s.midterm, s.final_term, s.homework );
}/*}}}*/

// 判断学生是否不及格
bool fgrade( const Student_info& s )
{/*{{{*/
    return grade( s ) < 60;
}/*}}}*/

// 把及格的学生和不及格的学生分开
vector<Student_info> extract_fails( vector<Student_info>& students )
{/*{{{*/
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();

    while( iter != students.end() )
    {
        if( fgrade(*iter) )
        {
            fail.push_back( *iter ); // 将迭代器指示的元素加入到 fail 中
            iter = students.erase( iter ); // 删除 该迭代器，erase 返回了一个迭代器(指向刚刚删掉的迭代器后面那个元素)，赋值给 iter
        }
        else
        {
            ++iter;
        }
    }
    return fail;
}/*}}}*/

// 从输入流中将家庭作业读入到一个 vector<double> 中
istream& read_hw( istream& in, vector<double>& hw )
{/*{{{*/
    if( in )
    {
        // 清除原先内容
        hw.clear();

        // 读家庭作业成绩
        double x;
        while( in >> x )
        {
            hw.push_back( x );
        }

        // 清除流以使输入动作对下一个学生有效
        in.clear();
    }
    return in;
}/*}}}*/

// 读入一个学生的成绩
istream& read( istream& is, Student_info& s )
{/*{{{*/
    // 读入该学生的名字 期中 期末 成绩
    is >> s.name >> s.midterm >> s.final_term;

    // 读入该学生的平时成绩
    read_hw( is, s.homework );

    return is;
}/*}}}*/

// 用作 sort 函数的第三个参数
bool compare( const Student_info& x, const Student_info& y )
{/*{{{*/
    return x.name < y.name;
}/*}}}*/

// 打印一个标题头
void print_head( )
{/*{{{*/
    // 输入标题头
    string name = "codekissyoung";
    string greeting = "Hello, " + name + "!";
    const int pad = 1;
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    for ( int r = 0; r != rows; r++ )
    {
        string::size_type c = 0;
        while( c != cols )
        {
            if( r == pad + 1 && c == pad + 1 )
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                if( r == 0 || r == rows - 1 || c == 0 || c == cols - 1 )
                {
                    cout << '*';
                }
                else
                {
                    cout << ' ';
                }
                ++c;
            }
        }
        cout << endl;
    }
}/*}}}*/

// 找出一个 vector<string> 中最长的字符串长度
string::size_type width( const vector<string>& v )
{/*{{{*/
    string::size_type maxlen = 0;
    for( vector<string>::size_type i = 0; i != v.size(); ++ i )
    {
        maxlen = max( maxlen, v[i].size() );
    }
    return maxlen;
}/*}}}*/

// 给一个 vector 加上 * 边框
vector<string> frame ( const vector<string>& v )
{/*{{{*/
    vector<string> ret;
    string::size_type maxlen = width( v );
    string border( maxlen + 4, '*' );

    // 输出顶部的边框
    ret.push_back( border );
    // 输出内部行
    for( vector<string>::size_type i = 0; i != v.size(); ++ i )
    {
        ret.push_back( "* " + v[i] + string( maxlen - v[i].size(), ' ' ) + " *" );
    }
    // 输出底部边框
    ret.push_back( border );
    return ret;
}/*}}}*/

// 纵向链接
// 等价于库提供的方法: ret.insert( ret.end(), bottom.begin(), bottom.end() );
vector<string> vcat( const vector<string>& top, const vector<string>& bottom )
{/*{{{*/
    vector<string> ret = top;

    for ( vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it )
    {
        ret.push_back( *it );
    }
    return ret;
}/*}}}*/

// 横向链接
vector<string> hcat( const vector<string>& left, const vector<string>& right )
{/*{{{*/
    vector<string> ret;
    string::size_type width1 = width( left ) + 1;
    vector<string>::size_type i = 0, j = 0;
    while( i != left.size() || j != right.size() )
    {
        string s;
        if( i != left.size() )
        {
            s = left[i];
            i++;
        }

        s += string( width1 - s.size(), ' ' );
        if( j != right.size() )
        {
            s += right[j];
            j++;
        }
        ret.push_back( s );
    }
    return ret;
}/*}}}*/

// 不是 url 的字符串
bool not_url_char( char c )
{/*{{{*/
    static const string url_ch = "~;/?:@=&$-_.+!*'(),`";
    return !( isalnum(c) || find( url_ch.begin(), url_ch.end(), c ) != url_ch.end() );
}/*}}}*/

// 判断是不是一个 url 的结尾
string::const_iterator url_end( string::const_iterator b, string::const_iterator e )
{/*{{{*/
    return find_if( b, e, not_url_char );
}/*}}}*/

// 判断是不是一个 url 的开头
string::const_iterator url_beg( string::const_iterator b, string::const_iterator e )
{/*{{{*/
    static const string sep = "://";
    typedef string::const_iterator iter;

    iter i = b;

    while( ( i = search( i, e, sep.begin(), sep.end() )) != e )
    {
        if( i != b && i + sep.size() != e )
        {
            iter beg = i;
            while( beg != b && isalpha( beg[-1] ) )
            {
                --beg;
            }

            if( beg != i && i + sep.size() != e && !not_url_char( i[ sep.size() ] ) )
            {
                return beg;
            }
        }

        if( i != e )
        {
            i += sep.size();
        }
    }
    return e;
}/*}}}*/

// 查找一个字符串中的所有 urls
vector<string> find_urls( const string& s )
{/*{{{*/
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin();
    iter e = s.end();

    while( b != e )
    {
        b = url_beg( b, e );

        if( b != e )
        {
            iter after = url_end( b, e );
            ret.push_back( string( b, after ) );
            b = after;
        }
    }
    return ret;
}/*}}}*/

// 查找输入中每一个单词的所有行
map<string, vector<int> > xref( istream& in, vector<string> find_words( const string&) = split )
{/*{{{*/
    string line;
    int line_number = 0;

    map<string, vector<int> > ret;

    while( getline( in, line ) )
    {
        ++line_number;

        vector<string> words = find_words( line );

        for ( vector<string>::const_iterator it = words.begin() ; it != words.end(); ++it )
        {
            ret[*it].push_back( line_number );
        }
    }
    return ret;
}/*}}}*/

/*
 * 圆形类
 * */
class Circle
{
    private :
        double m_s; // 面积
        double m_r; // 半径

    public : 
        void setR( double r )
        {
            m_r = r;
        }

        double getR()
        {
            return m_r;
        }

        double getArea()
        {
            m_s = 3.14 * m_r * m_r;
            return m_s;
        }
};

enum class Color { red, blue, green };
enum class Traffic_light { green,yellow, red };

Traffic_light& operator++( Traffic_light& t )
{
    switch( t )
    {
        case Traffic_light::green:
            t = Traffic_light::yellow;
            
        case Traffic_light::yellow:
            t = Traffic_light::red;

        case Traffic_light::red:
            t = Traffic_light::green;
    }
    return t;
}

using namespace std;

// -------------------------------------- main ------------------------------------------- //
int main( int argc, char *argv[] )
{

    static_assert( sizeof(int) >= 4, "sizeof int 小于4字节");

    Vector my_vector(6);

    my_vector.read();

    cout << my_vector.size() << endl;

    auto sum = my_vector.sum();

    cout << sum << endl;

    try{
        cout << my_vector[my_vector.size()] << endl;
    }catch( out_of_range ){
        printf("数组越界了\n");
    }

    cout << my_vector[1] << endl;

    try{
        Vector orther_vector( -10 );        
    }catch( length_error ){
        printf("length < 0 \n");
    }catch( bad_alloc )
    {
        // 处理内存耗尽问题
    }

    return 0;

    map<string,vector<int> > words_in_line = xref( cin );

    for( map<string, vector<int> >::const_iterator it = words_in_line.begin(); it != words_in_line.end(); ++ it )
    {
        cout << it -> first << " : ";
        for( vector<int>::const_iterator vit = it -> second.begin(); vit != it -> second.end(); ++vit )
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
    print_head();

    // 关联容器
    string str;
    map<string, int> counters;

    while( cin >> str )
    {
        ++counters[str];
    }

    for( map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it )
    {
        cout << it -> first << "\t" << it->second << endl;
    }

    string s;
    getline( cin, s );
    vector<string> one_line = split( s );
    one_line = frame( one_line );
    for( vector<string>::size_type i = 0; i != one_line.size(); ++i )
    {
        cout << one_line[i] << endl;
    }

    // 处理一个文件里面的学生
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while( read( cin, record ) )
    {
        maxlen = max( maxlen, record.name.size() );
        students.push_back( record );
    }

    // 按字母排序
    sort( students.begin(), students.end(), compare );

    // 输出成绩报表
    for( vector<Student_info>::size_type i = 0; i != students.size(); ++i )
    {
        cout << setw( maxlen + 2 ) << students[i].name;
        try
        {
            double final_grade = grade( students[i] );
            streamsize prec = cout.precision();
            cout << setprecision(4) << "  |  " << final_grade << setprecision(prec);
        }
        catch ( domain_error e )
        {
            cout << e.what();
        }
        cout << endl;
    }

    // 处理异常
    try
    {
        throw_1();
    }
    catch( int )
    {
        cout << "在 int 里处理了异常" << endl;
    }
    catch( double )
    {
        cout << "在 double 里处理了异常" << endl;
    }
    catch( ... )
    {
        cout << "无奈了 在这里捕获所有异常" << endl;
    }

    // 实例化一个子类
    Worker *worker = new  Worker();
    worker -> name = "codekissyoung";
    worker -> age = 22;
    worker -> salary = 11000.00;
    worker -> eat();
    worker -> Person :: eat();
    worker -> work();
    delete worker;
    worker = NULL;

    job Teacher = { "codekissyoung", 10000.00, 4 };
    job Worker  = { "caokaiyan", 4000.00, 3 };
    Swap( Teacher, Worker );
    cout << Worker.name << " : " << Worker.salary << " , " << Worker.floor << endl;

    double u = 10.392;
    double v = 30.291;
    Swap( u, v );
    cout << "u : " << u << " v : " << v << endl;

    int things[6] = { 13, 31, 103, 301, 310, 130 };
    struct debts mr_E[3] = {
        { "codekissyoung",   2400.0 },
        { "caokaiyan",       1300.2 },
        { "zhangjian",       2342.09 }
    };
    double* pd[3];

    for( int i = 0; i < 3; i++ )
    {
        pd[i] = &mr_E[i].amount;
    }

    ShowArray( things, 6 );
    ShowArray( pd, 3 );
    cout << "10 + 34.90 = " << mixed( 10, 34.90 ) << endl;

    // 股票demo
    Stock stock_cat = Stock( "NanoSmart", 20, 12.50 );
    stock_cat.show();
    stock_cat.buy( 15, 18.125 );
    stock_cat.show();
    stock_cat.sell( 2, 54.125 );
    stock_cat.show();

    // 默认公司
    Stock default_stock;
    default_stock.show();

    Stock top_stock = default_stock.topval( stock_cat );
    top_stock.show();

    // 对象数组
    Stock mystuff[4] = {
        Stock("美团",200,1),
        Stock("百度",130,3.45),
        Stock("腾讯",120,200.89),
        Stock("阿里",60,6.22)
    };
    Stock* top = &mystuff[0];
    for( int i = 1; i < 4 ; i++ )
    {
        *top = top -> topval( mystuff[i] );
    }
    top -> show();

    return 0;
}

