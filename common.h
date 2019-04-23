#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <string>
#include <vector>

// 常量声明，定义在别处，所以需要注明 extern
extern const double PI;

struct Reading{
    int hour;
    double temperature;
    Reading(int h, double t) : hour(h), temperature(t){}
};

void skip_to_int();
int get_int();
int get_int(int low, int high);

// ------------------------------------- Sales_data class ------------------------------------- //
class Sales_data
{
    public:
        Sales_data() = default; // 默认构造函数
        Sales_data( const std::string &s ) : bookNo(s) { }
        Sales_data( const std::string &s, unsigned n, double p ) : bookNo(s), units_sold(n), revenue( p * n ) { }
        Sales_data( std::istream& );

        std::string isbn() const { return bookNo; }

        Sales_data& combine( const Sales_data& );
        double avg_price() const;

        friend Sales_data add( const Sales_data&, const Sales_data& );
        friend std::ostream &print( std::ostream&, const Sales_data& );
        friend std::istream &read( std::istream&, Sales_data& );

    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};

// Sales_data 的非成员函数声明
Sales_data add( const Sales_data&, const Sales_data& );
std::ostream &print( std::ostream&, const Sales_data& );
std::istream &read( std::istream&, Sales_data& );

// ------------------------------------- Screen class ------------------------------------- //
class Screen
{
    public:
        typedef std::string::size_type pos;
        Screen() = default;
        Screen( pos ht, pos wd, char c ): height(ht), width(wd), contents( ht * wd, c ) { }

        // 读取光标处字符
        inline char get() const { return contents[cursor]; }
        inline char get( pos ht, pos wd ) const;

        // 设置光标所在处的字符
        Screen &set(char);
        inline Screen &set(pos, pos, char);

        Screen &move( pos r, pos c );

        Screen &display( std::ostream &os )
        {
            do_display(os);
            return *this;
        }

        const Screen &display( std::ostream &os ) const
        {
            do_display(os);
            return *this;
        }

    private:
        pos cursor = 0;
        pos height = 0;
        pos width = 0;
        std::string contents;

        void do_display( std::ostream &os ) const
        {
            os << contents;
        }
};

// ------------------------------------- Screen class ------------------------------------- //
class Window_mgr
{
    private:
        std::vector<Screen> screens { Screen(24, 80, ' ') };
};

#endif
