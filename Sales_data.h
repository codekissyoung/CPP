#ifndef CPP_SALES_DATA_H
#define CPP_SALES_DATA_H

#include <iostream>
#include <string>

// ------------------------------------- Sales_data class ------------------------------------- //
class Sales_data
{
    friend Sales_data add( const Sales_data &, const Sales_data & );
    friend std::ostream &print( std::ostream &, const Sales_data & );
    friend std::istream &read( std::istream &, Sales_data & );

public:
    Sales_data() = default;
    explicit Sales_data( const std::string &s ) : bookNo(s) { }
    explicit Sales_data( std::istream &is ) { read( is, *this); }
    Sales_data( const std::string &s, unsigned n, double p ) : bookNo(s), units_sold(n), revenue(p*n) { }

    std::string isbn() const { return bookNo; }

    Sales_data &combine( const Sales_data & );

    double avg_price() const;

private:
    std::string bookNo;         // 书名
    unsigned units_sold = 0;    // 售出数量
    double revenue = 0.0;       // 总收入
};

Sales_data add( const Sales_data &, const Sales_data & );
std::ostream &print( std::ostream &, const Sales_data & );
std::istream &read( std::istream &, Sales_data & );

#endif //CPP_SALES_DATA_H
