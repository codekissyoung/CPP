#include "Sales_item.h"

#include <iostream>

using namespace std;

Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs )
{
    Sales_item ret( lhs );
    ret += rhs;
    return ret;
}

bool operator==(const Sales_item &lhs, const Sales_item &rhs )
{
    return lhs.same_isbn(rhs) && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_item &lhs, const Sales_item &rhs )
{
    return !( lhs == rhs );
}

istream &operator>>(std::istream &is, Sales_item &s )
{
    double price;
    is >> s.isbn >> s.units_sold >> price;
    if(is)
        s.revenue = s.units_sold * price;
    else
        s = Sales_item();
    return is;
}

ostream &operator<<(std::ostream &os, const Sales_item &s)
{
    os << s.isbn << "\t" << s.units_sold << "\t" << s.avg_price() << "\t" << s.revenue << endl;
    return os;
}