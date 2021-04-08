#include "std_lib_facilities.h"

class Date {
    int y, m, d;
public:
    Date(int y, int m, int d);   
    void add_day(int n);         
    int month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }
};


void init_day(Date& dd, int y, int m, int d)
{
    if (y <1900 || y > 3000) error ("invalid year")
    if (m < 1 || m > 12) error("impossible month");
    if (d < 1 || d > 31) error("impossible day");
    
    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n)
{
	
	if (d += n > 31)
	{
		d = 1;
		++m;
	}
}
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y 
              << ',' << d.m 
              << ',' << d.d << ')';
}

int main()
{

    Date today( 1978, 6, 31 );
    Date tomorrow( today );
    tomorrow.add_day(1);
    cout << today << '\n'
         << tomorrow << '\n';
    //Date bad_day(2004, 13, -5);
    
    return 0;
}

