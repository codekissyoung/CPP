#include "Stock.h"

#include <iostream>

using namespace std;

Stock::Stock() : company{"unknow company"}, shares{0}, share_val{0}, total_val{0}{ }

Stock::Stock( string co, long n, double pr ) : company{ std::move(co) }, shares{n}, share_val{pr}, total_val{0}
{
    if( n < 0 )
    {
        cout << "Number of shares can not be negative " << company  << " shares set to 0 \n";
        shares = 0;
    }

    set_tot();
}

Stock::~Stock()
{
   cout << company << " ~Stock() called" << endl;
}


void Stock::buy( long num, double price )
{
    if( num < 0 )
    {
        cout << "购买不能为 0 " << endl;
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell( long num, double price )
{
    if( num < 0)
        cout << "售出不能为 0 " << endl ;
    else if( num > shares )
        cout << "存量不够" << endl;
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update( double price )
{
    share_val = price;
    set_tot();
}

void Stock::show() const
{
    cout << "公司: " << company << "\t"
         << "持有: " << shares << "\t"
         << "股价: $" << share_val << "\t"
         << "总值: $" << total_val << endl;
}

const Stock &Stock::topval( const Stock &s ) const
{
    if ( s.total_val > total_val )
        return s;
    else
        return *this;
}
