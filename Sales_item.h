#ifndef CPP_SALES_ITEM_H
#define CPP_SALES_ITEM_H

#include <iostream>
#include <string>
#include <utility>

class Sales_item {

private:
    std::string isbn;           // 书编号
    unsigned    units_sold = 0; // 售出次数
    double      revenue = 0.0;  // 售出总额

public:
    Sales_item() : units_sold(0),revenue(0.0) {}
    explicit Sales_item( const std::string &&book ) : isbn(book),units_sold(0),revenue(0.0) {}
    explicit Sales_item( std::istream &is ){ is >> *this; }

    friend std::istream &operator>>(std::istream &, Sales_item &);
    friend std::ostream &operator<<(std::ostream &, const Sales_item &);
    friend bool operator==(const Sales_item &lhs, const Sales_item &rhs );

    Sales_item &operator+=(const Sales_item &rhs )
    {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }

    double avg_price() const
    {
        if(units_sold)
            return revenue / units_sold;
        else
            return 0.0;
    }

    bool same_isbn(const Sales_item &rhs) const{
        return isbn == rhs.isbn;
    }
};

Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs );
bool operator==(const Sales_item &lhs, const Sales_item &rhs );
bool operator!=(const Sales_item &lhs, const Sales_item &rhs );
std::istream &operator>>(std::istream &, Sales_item &);
std::ostream &operator<<(std::ostream &, const Sales_item &);

#endif
