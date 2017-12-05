#include <iostream>
#include "stock.h"
using namespace std;

Stock::Stock()
{
    company     = "unknown Company";
    shares      = 10;
    share_val   = 1;
    set_tot();
}

// 管理某个公司的股票 首次购买
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

Stock::~Stock()
{
    cout << "调用析构函数" << endl;
}

// 买入股票
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

// 卖出股票
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

// 更新股价
void Stock::update( double price )
{
    share_val = price;
    set_tot();
}

// 显示大概情况
void Stock::show()
{
    cout << "Company : " << company << "\t"
         << "Shares : " << shares << "\t"
         << "Share Price : " << share_val << "\t"
         << "Total Worth : " << total_val << endl;
}





