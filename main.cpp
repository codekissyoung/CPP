#include <iostream>
#include <string>
#include <vector>
#include <array>

/* 使用到的 c 标准库 */
#include <cmath>
#include <cstring>

#include "sales_data.h"

using namespace std; // 作用于当前整个文件

const int Seasons = 4;
const array<string, Seasons> Snames = {"Spring","Summer","Fall","Winter"};

void say_hello ( const char *str ); // 函数声明
void fill( array<double, Seasons> *pa );
void show( array<double, Seasons> da );

// 使用模板
template <typename T>
void Swap( T &a, T &b);

int main()
{
    Sales_data Book1,Book2; // Sales_data 是结构体 C++ 中使用结构体声明变量 可以省略 struct

    // 使用 new 来分配内存
    int* pn = new int;
    *pn = 10;
    cout << "pn = " << pn << " *pn = " << *pn << endl;
    delete pn; // 释放内存

    int dynamic_arr_size = 0;
    cout << "输入想存储数组的个数: ";
    cin >> dynamic_arr_size;
    double* dynamic_arr = new double[ dynamic_arr_size ]; // 动态数组
    for( int i = 0; i < dynamic_arr_size; i++ )
    {
        cout << "dynamic_arr[ " << i << " ] : ";
        cin >> dynamic_arr[i];
    }
    for( int i = 0; i < dynamic_arr_size; i++ )
    {
        cout << "dynamic_arr[ " << i << " ] : " << dynamic_arr[i] << endl;
    }
    delete []dynamic_arr; // 释放整个动态数组内存

    say_hello("codekisssyoung"); // 函数调用

    // 使用 <vector> 代替数组
    vector<int> vi;
    int n;
    cout << "vector<int> n : ";
    cin >> n;
    cout << " n : " << n << endl;

    // 使用 <array>
    array<double, Seasons> expenses;
    fill( &expenses );
    show( expenses );

    // 测试使用模板
    int i = 10;
    int j = 20;
    cout << "i : " << i << " j : " << j << endl;
    Swap( i, j );
    cout << "i : " << i << " j : " << j << endl;

    return 0;

}

// 函数定义
void say_hello ( const char *str )
{/*{{{*/
    cout << "hello " << str << endl;
}/*}}}*/

// 写入四季节的开销
void fill( array<double, Seasons> *pa )
{/*{{{*/
    for( int i = 0; i < Seasons; i++ )
    {
        cout << "Enter " << Snames[i] << " expenses : ";
        cin >> (*pa)[i];
    }
}/*}}}*/

// 展示四季节的开销
void show( array<double, Seasons> da )
{/*{{{*/
    double total = 0.0;
    cout << "EXPENSES : " << endl;
    for( int i = 0; i < Seasons; i++ )
    {
        cout << Snames[i] << " : $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total Expenses : $" << total << endl;
}/*}}}*/

template <typename T>
void Swap( T &a, T &b)
{/*{{{*/
    T temp;
    temp = a;
    a = b;
    b = temp;
}/*}}}*/

