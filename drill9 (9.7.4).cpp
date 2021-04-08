#include "std_lib_facilities.h"

enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date 
{
public:
        Date(int y, Month m, int d);

	void add_day(int n);
	void add_month(int n);
	void add_year(int n);

	Month month() const { return m; }
	int day() const { return d; }
	int year() const { return y; }

private:
	int y, d;
	Month m;
   
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
		int nextM = int(m) + 1;
		if (nextM > 12)
		{
			add_month(1);
		}
		else
			m = Month(nextM);
	}
	
}

void Date::add_month(int n)
{
	int nextM = 0;
	if ((nextM = int(m) + n) > 12)
	{
		m = Month::jan;
		add_year(1);
	}
	else
		m = Month(nextM);
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
    cout << tomorrow << '\n';
    tomorrow.add_month(1);
    cout << tomorrow << '\n';
    
    cout << today << '\n'
         << tomorrow << '\n';
    //Date bad_day(2004, 13, -5);
    
    return 0;
}

