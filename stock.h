#ifndef STOCK_H_
#define STOCK_H_
#include <string>

class Stock
{
    private :

        std::string company; // 持有公司名称
    
        long shares; // 股票数量

        double share_val; // 每股价格

        double total_val; // 持股总价格

        void set_tot()
        {
            total_val = shares * share_val;
        }

    public :

        Stock();

        // 管理某个公司的股票 首次购买
        Stock( const std::string &co, long n, double pr );
        
        ~Stock();

        // 管理某个公司的股票 首次购买
        void acquire( const std::string &co, long n, double pr );

        // 买入股票
        void buy( long num, double price );

        // 卖出股票
        void sell( long num, double price );
        
        // 更新股价
        void update( double price );
        
        // 显示大概情况
        void show();
        
        // 获取总股价更高的那个对象
        const Stock& topval( const Stock& s ) const;
};

#endif
