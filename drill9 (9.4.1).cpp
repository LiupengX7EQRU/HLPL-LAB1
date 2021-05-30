#include "std_lib_facilities.h"

struct Date
{
	Date(int y, int m, int d);

	int y;
	int m;
	int d;
};

Date::Date(int yy, int mm, int dd)
{
    if (yy <1900 || yy > 3000) error ("invalid year");
    if (mm < 1 || mm > 12) error("impossible month");
    if (dd < 1 || dd > 31) error("impossible day");
	else
	{
		y = yy; m = mm; d = dd;
	}
		
}


void add_day(Date& dd, int n)
{
    dd.d += n;
    
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


