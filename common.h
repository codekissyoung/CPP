#include <iostream>
#include <string>
using namespace std;

#ifndef SALES_DATA_H
#define SALES_DATA_H

struct Sales_data
{
    string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

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
template <> void Swap<job>( job& i, job& j);

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

#endif
