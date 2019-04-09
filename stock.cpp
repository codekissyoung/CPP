#include "stock.h"

#include <iostream>

using namespace std;

Stock::Stock()
{
    company     = "unknown Company";
    shares      = 0;
    share_val   = 0;
    set_tot();
}

Stock::Stock( const string& co, long n, double pr )
{
    company = co;
    if( n < 0 )
    {
        cout << "Number of shares can not be negative " << company  << " shares set to 0 \n";
        shares = 0;
    }
    else
    {
        shares = n;
    }

    share_val = pr;
    set_tot();
}

void Stock::acquire( const string& co, long n, double pr )
{
    company = co;
    if( n < 0 )
    {
        cout << "Number of shares can not be negative " << company  << " shares set to 0 \n";
        shares = 0;
    }
    else
    {
        shares = n;
    }

    share_val = pr;
    set_tot();
}

Stock::~Stock()
{
   cout << company << "~Stock 析构\n" << endl;
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
    {
        cout << "售出不能为 0 " << endl ;
    }
    else if( num > shares )
    {
        cout << "存量不够" << endl;
    }
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


void Stock::show()
{
    cout << "Company : " << company << "\t"
         << "Shares : " << shares << "\t"
         << "Share Price : " << share_val << "\t"
         << "Total Worth : " << total_val << endl;
}


const Stock &Stock::topval( const Stock &s ) const
{
    if ( s.total_val > total_val )
        return s;
    else
        return *this;
}
