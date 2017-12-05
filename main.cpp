#include <iostream>
#include <string>
#include <vector>
#include <array>

/* 使用到的 c 标准库 */
#include <cmath>
#include <cstring>

#include "sales_data.h"

using namespace std; // 作用于当前整个文件

struct job
{
    char name[40];
    double salary;
    int floor;
};

struct debts
{
    char name[50];
    double amount;
};

// 模板化原型
template <typename T>
void Swap( T& i, T& j)
{
    T temp;
    temp = i;
    i = j;
    j = temp;
}

// 显式具体化原型
template <> void Swap( job& i, job& j)
{
    double salary_temp;
    int floor_temp;
    salary_temp = i.salary;
    floor_temp  = i.floor;
    i.salary    = j.salary;
    i.floor     = j.floor;
    j.salary    = salary_temp;
    j.floor     = floor_temp;
}

template <typename T>
void ShowArray( T arr[], int n )
{
    cout << "template A : " << endl;
    for( int i = 0; i < n; i++ )
    {
        cout << arr[i] << '\t';
    }
    cout << endl;
}

template <typename T>
void ShowArray( T* arr[], int n )
{
    cout << "template B : " << endl;
    for( int i = 0; i< n; i++ )
    {
        cout << *arr[i] << "\t";
    }
    cout <<endl;
}

// decltype 获取表达式计算后的类型
template <typename T1, typename T2>
auto mixed( T1 x, T2 y ) -> decltype( x + y )
{
    return x + y;
}

int main()
{
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
    return 0;
}

