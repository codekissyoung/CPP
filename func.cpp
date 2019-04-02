#include "common.h"
#include "func.h"

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

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
