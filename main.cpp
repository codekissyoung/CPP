#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "sales_data.h"

int main()
{
    using namespace std;
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
