#include "Sales_data.h"

#include <iostream>

using namespace std;

double Sales_data::avg_price() const
{
    if( units_sold )
        return revenue / units_sold;
    else
        return 0;
}

Sales_data &Sales_data::combine( const Sales_data &rhs )
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream &read( istream &is, Sales_data &item )
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print( ostream &os, const Sales_data &item )
{
    os << "isbn: " << item.isbn()
       << " sold: " << item.units_sold
       << " revenue: " << item.revenue
       << " avg_price: " << item.avg_price();
    return os;
}

Sales_data add( const Sales_data &lhs, const Sales_data &rhs )
{
    Sales_data sum = lhs;// 默认情况下，拷贝对象的数据成员
    sum.combine( rhs );
    return sum;
}