#include "std_lib_facilities.h"

struct Date
{
    int y;  //year
    int m;  //month
    int d;  //day
};


void init_day(Date& dd, int y, int m, int d)
{
    if (y <1900 || y > 3000) error ("invalid month")
    if (m < 1 || m > 12) error("impossible month");
    if (d < 1 || d > 31) error("impossible day");
    
    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n)
{
    dd.d += n;
    if (dd.d > 31) dd.d %= 31;
}
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y 
              << ',' << d.m 
              << ',' << d.d << ')';
}

int main()
{
    Date today( 1978, 6, 25 );
	Date tomorrow( today );
    add_day(tomorrow, 1);
    cout << today << '\n'
         << tomorrow << '\n';
    //Date bad_day(2004, 13, -5);
    
    return 0;
}


