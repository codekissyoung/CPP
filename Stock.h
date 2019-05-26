#ifndef STOCK_H_
#define STOCK_H_
#include <string>

class Stock
{
private:
    std::string company; // 持有公司名称
    long shares;         // 股票数量
    double share_val;    // 每股价格
    double total_val;    // 持股总价格

    void set_tot(){ total_val = shares * share_val; }

public:
    Stock();
    Stock( std::string co, long n = 0 , double pr = 0.0 );
    ~Stock();

    void buy( long num, double price );  // 买入
    void sell( long num, double price ); // 卖出
    void update( double price );         // 更新股价
    void show() const;                   // 显示

    // 获取总股价更高的那个对象
    const Stock& topval( const Stock& s ) const;
};

#endif
