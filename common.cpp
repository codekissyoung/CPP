#include "common.h"

using namespace std;

Sales_data::Sales_data( std::istream &is )
{
    read( is, *this );
}

double Sales_data::avg_price() const 
{
    if( units_sold )
        return revenue / units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine( const Sales_data &rhs )
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this; // 返回调用该函数的对象
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
    os << "isbn: " << item.isbn() << " sold: " << item.units_sold << " revenue: " << item.revenue << " avg_price: " << item.avg_price();
    return os;
}

Sales_data add( const Sales_data &lhs, const Sales_data &rhs )
{
    // 默认情况下，拷贝对象的数据成员
    Sales_data sum = lhs;
    sum.combine( rhs );
    return sum;
}


// ------------------------------ Screen class -------------------------------- //

inline Screen &Screen::move( pos r, pos c )
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
