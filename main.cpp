#include <iostream>
#include <string>
#include <vector>

/* 使用到的 c 标准库 */
#include <cmath>
#include <cstring>

#include "sales_data.h"

using namespace std; // 作用于当前整个文件

void say_hello ( const char *str ); // 函数声明

int main()
{
    Sales_data Book1,Book2; // Sales_data 是结构体 C++ 中使用结构体声明变量 可以省略 struct
    double area;
    char   name[20];

    // 没啥卵用的枚举
    enum spectrum { red, orange, yellow, green, blue, violet, indigo, ultraviolet };
    spectrum band;
    band = blue;

    // 使用 new 来分配内存
    int* pn = new int;
    *pn = 10;
    cout << "pn = " << pn << " *pn = " << *pn << endl;

    cout << "输入name : ";
    cin.getline( name, 20 ); // 读取一行 通过换行符来确定结尾 但结果不保存换行符
    cout << name << endl;

    say_hello("codekisssyoung"); // 函数调用
    cout << "输入 area : ";
    cin >> area;
    cout << "sqrt( area ) = " << sqrt( area ) << endl;

    return 0;
}

// 函数定义
void say_hello ( const char *str )
{
    cout << "hello " << str << endl;
}










































