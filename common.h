#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <string>
#include <vector>

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

// ------------------------------------- Screen class ------------------------------------- //
class Screen
{
    public:
        typedef std::string::size_type pos;
        Screen() = default;
        Screen( pos ht, pos wd, char c );

        // 读取光标处字符
        inline char get() const { return contents[cursor]; }
        inline char get( pos ht, pos wd ) const;

        // 设置光标所在处的字符
        Screen &set(char);

        inline Screen &set( pos, pos, char );

        Screen &move( pos r, pos c );

        Screen &display( std::ostream &os )
        {
            do_display(os);
            return *this;
        }

        pos get_high() { return high; }

        const Screen &display( std::ostream &os ) const
        {
            do_display(os);
            return *this;
        }

    private:
        pos cursor = 0;
        pos high   = 0;
        pos width  = 0;
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
