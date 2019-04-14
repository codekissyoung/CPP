#include "common.h"
#include "func.h"
#include "stock.h"
#include "median.h"
#include "vector.h"
#include "container.h"
#include "date.h"
#include "stack.h"

#include <iostream>
#include <array>

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>


using namespace std;

int main( int argc, char *argv[] )
{
    try
    {
        cout << "num: ";
        const int ARR_SIZE = 10;
        int num, arr[ARR_SIZE][ARR_SIZE];
        memset( arr, 0, sizeof(arr) );
        if( scanf("%d", &num) )
        {
            int i = 0, j = 0, k = 0, count = 0;

            arr[i][j] = ++count; // 第一个
            // 我们的原则是：先判断,再移动,而不是移动(++)后发现超出边界了再退回来
            // 所以判断条件是 j + 1 < 边界
            while( count < num * num )
            {
                // 向右移动 直至边界
                while( j + 1 < num - k )
                    arr[i][++j] = ++count;
                // 向下移动 直至边界
                while( i + 1 < num - k )
                    arr[++i][j] = ++count;
                // 向左移动 直至边界
                while( j - 1 > k - 1 )
                    arr[i][--j] = ++count;
                // 向上移动 直至边界, 注意这里的边界是已经填入过数字的行
                while( i - 1 > k )
                    arr[--i][j] = ++count;

                k++; // 从新修改边界
            }
        }

        for( int i = 0; i < ARR_SIZE; i++ )
        {
            for( int j = 0; j < ARR_SIZE; j++ )
                cout << arr[i][j] << "\t";
            cout << endl;
        }
        return 0;
    }
    catch( domain_error &e )
    {
        cout << e.what();
        cout << endl << "no homework grades" << endl;
    }
    catch( runtime_error &e )
    {
        cerr << "runtime error:" << e.what() << endl;
        return 1;
    }
    catch( ... )
    {
        cout << "unknown exception !" << endl;
        return 2;
    }
}

