#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "sales_data.h"

using namespace std; // 作用于当前整个文件

void say_hello ( const char *str ); // 函数声明

int main()
{
    say_hello("codekisssyoung"); // 函数调用
    struct Sales_data Book1,Book2;
    /*
    cout << "输入Book1 : " << endl;
    cin >> Book1.bookNo >> Book1.units_sold >> Book1.revenue;
    cout << "输出Book1 : " << Book1.bookNo << Book1.units_sold << Book1.revenue << endl;
    */

    double area;
    double side;
    cout << "输入 area : ";
    cin >> area;
    side = sqrt( area );
    cout << "sqrt( area ) = " << side << endl;
    return 0;
}

// 函数定义
void say_hello ( const char *str )
{
    cout << "hello " << str << endl;
}
