#ifndef STOCK_H_
#define STOCK_H_
#include <string>
using namespace std;
class Stock
{

    private :
        string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot()
        {
            total_val = shares * share_val;
        }

    public :
        // 两个构造函数 分别对应不同创建对象的情况
        Stock();
        Stock( const string& co, long n, double pr );
        ~Stock();
        void buy( long num, double price );
        void sell( long num, double price );
        void update( double price );
        void show();
        const Stock& topval( const Stock& s ) const;
};
#endif
