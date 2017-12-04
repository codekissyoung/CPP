#include <iostream>
#include <string>
#include <vector>
#include <array>

/* 使用到的 c 标准库 */
#include <cmath>
#include <cstring>

#include "sales_data.h"

using namespace std; // 作用于当前整个文件

// 使用模板
template <typename T>
void Swap( T &a, T &b);

template <typename T>
void Swap( T *a, T *b, int n); // 重载模板

void vardump( const int arr[], int n ); // 打印一个数组

int main()
{
    // 测试使用模板 来自动完成重载过程
    int i = 10;
    int j = 20;
    cout << "i : " << i << " j : " << j << endl;
    Swap( i, j );
    cout << "i : " << i << " j : " << j << endl;

    double di = 20.11;
    double dj = 90.22;
    cout << "di : " << di << " dj : " << dj << endl;
    Swap( di, dj );
    cout << "di : " << di << " dj : " << dj << endl;

    // 重载模板
    int d1[3] = {1,2,3};
    int d2[3] = {6,7,9};

    Swap( d1, d2, sizeof(d1) / sizeof( int ) );
    vardump( d2 , sizeof( d2 ) / sizeof( int ) );

    return 0;

}

template <typename T>
void Swap( T &a, T &b)
{/*{{{*/
    T temp;
    temp = a;
    a = b;
    b = temp;
}/*}}}*/

template <typename T>
void Swap( T* a, T* b, int n)
{/*{{{*/
    T temp;
    for( int i = 0; i < n; i++ )
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}/*}}}*/

// 打印一个数组的值
void vardump( const int arr[], int n )
{/*{{{*/
    for( int i = 0 ; i < n; i++ )
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}/*}}}*/
