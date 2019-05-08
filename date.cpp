#include "date.h"

#include <iostream>
#include <exception>

namespace My
{
    using namespace std;

    Date::Date( int y, Month m, int d ) : y( y ), m( m ), d(d)
    {
        if( !is_date( y, m, d ) )
            throw range_error( "range error" );
    }

    Date &default_date()
    {
        static Date d( 2001, Date::jan, 1 );
        return d;
    }

    Date::Date() : y( default_date().year()), m( default_date().month() ), d( default_date().day() )
    {
    
    }

    void Date::add_day( int n )
    {
    
    }

    void Date::add_month( int n )
    {
    
    }

    void Date::add_year( int n )
    {
        if( m == feb && d == 29 && !leapyear( y + n ) )
        {
            m = mar;
            d = 1;
        }
        y += n;
    }

    bool is_date( int y, Date::Month m, int d )
    {
        int days_in_month = 31;

        switch( m )
        {
            case Date::feb:
                days_in_month = leapyear( y ) ? 29 : 28;
                break;
            case Date::apr:
            case Date::jun:
            case Date::sep:
            case Date::nov:
                days_in_month = 30;
                break;
            default:
                break;
        }

        return d >= 0 && d < days_in_month ;
    }

    bool leapyear( int y )
    {
        return true;
    }

    bool operator==( const Date& a, const Date& b )
    {
        return a.year() == b.year() && a.month() == b.month() && a.day() == b.day();
    }

    bool operator!=( const Date& a, const Date& b )
    {
        return !( a == b );
    }

    ostream& operator<<( ostream& os, const Date& d )
    {
        return os << d.year() << d.month() << d.day() << endl;
    }

    istream& operator>>( istream& is, Date& date )
    {
        int y,m,d;
        char ch1,ch2,ch3,ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if( !is )
            return is;
        if( ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != '|' )
        {
            is.clear( ios_base::failbit );
            return is;
        }
        return is;
    }

}
