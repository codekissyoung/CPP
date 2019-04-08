#include "common.h"
#include "func.h"

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <array>

using namespace std;

// 函数指针
const double * (*p_fun)( const double *, int );

// 一个数组，数组的每个元素都是 p1 函数指针
const double * (*p_arr[3])( const double *, int );

// 一个指针，指针指向 pa
const double * (*(*p_pointer)[3])( const double *, int );

void fill( array<double, Seasons> *pa )
{
    for( int i = 0; i < Seasons; i++ )
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa)[i];
    }
}

void show( array<double, Seasons> da )
{
    double  total = 0.0;
    cout << "\nEXPENSES\n";
    for( int i = 0; i < Seasons; i++ )
    {
        cout << Snames[i] << " : $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses: $ " << total << endl;
}


typedef string::const_iterator iter;

bool not_url_char( char c )
{
    static const string url_ch = " ~;/?:@=&$-_.+!*'(),`";
    return find( url_ch.begin(), url_ch.end(), c ) != url_ch.end();
}

iter url_beg( iter b, iter e )
{
    static const string sep = "://";

    iter i = b;

    while( (i = search(i, e, sep.begin(), sep.end())) != e )
    {
        if( i != b && i + sep.size() != e )
        {

        }
    }
    return e;
}

iter url_end( iter b, iter e )
{
    return find_if( b, e, not_url_char );
}

// 正文http://网址 正文
vector<string> find_urls( const string& s )
{
    vector<string> ret;
    iter b = s.begin(), e = s.end();

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
}

bool space( char c )
{
    return isspace( c );
}

bool not_space( char c )
{
    return !isspace( c );
}

bool is_palindrome( const string& s )
{
    return equal( s.begin(), s.end(), s.rbegin() );
}

vector<string> split( const string &s )
{
    typedef string::size_type string_size;

    vector<string> ret;

    string_size i = 0; // 单词的第一个字符 索引
    string_size j = 0; // 单词的最后一个字符索引的 后一位

    while ( i != s.size() )
    {
        // 忽略前段的空白字符
        while ( i != s.size() && isspace(s[i]) )
            ++i;

        j = i;
        while ( j != s.size() && !isspace(s[j]) )
            ++j;

        if( i != j )
        {
            ret.push_back( s.substr( i, j - i ) );
            i = j;
        }
    }

    return ret;
}

vector<string> split1( const string &str )
{
    vector<string> ret;

    iter i = str.begin();
    while( i != str.end() )
    {
        i = find_if( i, str.end(), not_space );

        iter j = find_if(i, str.end(), space);

        if( i != str.end() )
        {
            ret.push_back( string(i, j) );
        }
        i = j;
    }
    return ret;
}

string::size_type width( const vector<string> &v )
{
    string::size_type maxlen = 0;
    for( auto &x : v )
    {
        maxlen = max( maxlen, x.size() );
    }
    return maxlen;
}

vector<string> frame( const vector<string> &v )
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    
    ret.push_back( string( maxlen + 4, '*') );

    for( auto x : v )
        ret.push_back("* " + x + string(maxlen - x.size(),' ') + " *");

    ret.push_back( string( maxlen + 4, '*') );

    return ret;
}

vector<string> vcat( const vector<string>& top, const vector<string> &bottom )
{
    vector<string> ret = top;

    // for( vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it )
    // {
    //     ret.push_back( *it );
    // }

    ret.insert( ret.end(), bottom.begin(), bottom.end() );

    return ret;
}

vector<string> hcat( const vector<string> &left, const vector<string> & right )
{
    vector<string> ret;

    string::size_type width_left = width( left ) + 1;

    vector<string>::size_type i = 0, j = 0;

    while( i != left.size() || j != right.size() )
    {
        string s;

        if( i != left.size() )
            s = left[i++];

        s += string( width_left - s.size(), ' ');

        if( j != right.size() )
            s += right[j++];

        ret.push_back(s);
    }

    return ret;
}

int square( int x )
{
    return x * x;
}

void skip_to_int()
{
    if(cin.fail())
    {
        cin.clear();
        char ch;
        while (cin >> ch){
            cout << "read : " << ch << endl;
            if(isdigit(ch))
            {
                cin.unget();
                return;
            }
        }
    }
}

int get_int()
{
    int n = 0;
    while (true){
        if(cin >> n)
            return n;
        cout << "not a number, try again: ";
        skip_to_int();
    }
}

int get_int(int low, int high )
{
    cout << "enter a number between " << low << " - " << high << " : ";
    while (true)
    {
        int n = get_int();
        if( low <= n && n <= high )
            return n;
        cout << n << " not between " << low << " - " << high << endl;
    }
}