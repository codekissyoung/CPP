#include "common.h"

// 常量定义
extern const double PI = 3.1415926535;
extern const double PI_under_180 = 180.0f/PI;
extern const double PI_over_180 = PI/180.0f;

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
Screen &Screen::move( pos r, pos c )
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get( pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

Screen &Screen::set( char c )
{
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set( pos r, pos col, char ch )
{
    contents[ r * width + col ] = ch;
    return *this;
}

// ------------------------------ Window_mgr class -------------------------------- //

