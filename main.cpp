#include <iostream>
#include <string>
#include <vector>
#include "sales_data.h"

using namespace std;

int main()
{
    struct Sales_data Book1,Book2;
    cout << "输入Book1 : " << endl;
    cin >> Book1.bookNo >> Book1.units_sold >> Book1.revenue;
    cout << "输出Book1 : " << Book1.bookNo << Book1.units_sold << Book1.revenue << endl;
    return 0;
}
