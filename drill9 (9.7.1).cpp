#include "std_lib_facilities.h"

enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
    int y, m, d;
public:
    Date(int y, Month m, int d);   
    void add_day(int n);         
    Month month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }
};


Date::Date(int yy, Month mm, int dd)
    :y{yy}, m{mm}, d{dd}
{
    
    if (m < 1 || m > 12) error("impossible month");
    if (d < 1 || d > 31) error("impossible day");
    
}

void Date::add_day(int n)
{
	
	if (d += n > 31)
	{
		d = 1;
		++m;
	}
}
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year() 
              << ',' << d.month() 
              << ',' << d.day() << ')';
}

int main()
{

    Date today( 1978, Month::dec, 31 );
    Date tomorrow( today );
    tomorrow.add_day(1);
    cout << today << '\n'
         << tomorrow << '\n';
    //Date bad_day(2004, 13, -5);
    
    return 0;
}

