#include <iostream>
#include <vector>
#include <array>

/* 使用到的 c 标准库 */
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <climits>

#include "common.h"
#include "stock.h"

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
{
    cout << "抛出异常" << endl;
    throw 1;
}

using namespace std; // 作用于当前整个文件
int main( int argc, char *argv[] )
{
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

    // 对下面这个二维数组进行排序
    char str_arr[][30] = {
        "hello",
        "jack",
        "香港",
        "澳门",
        "7呵呵呵",
        "9fuck",
        "hello world"
    };

    int len = sizeof(str_arr) / sizeof( str_arr[0] );
    char temp[30];
    for( int i = 0; i < len; ++ i )
    {
        for( int j = i + 1; j < len; ++j )
        {
            if( strcmp( str_arr[i], str_arr[j] ) > 0 )
            {
                strcpy( temp, str_arr[i] );
                strcpy( str_arr[i], str_arr[j] );
                strcpy( str_arr[j], temp );
            }
        }
    }

    for( int i = 0 ; i < len; i++)
    {
        cout << str_arr[i] << "\t";
    }
    cout << endl;

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

