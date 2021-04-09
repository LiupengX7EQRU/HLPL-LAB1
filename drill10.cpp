#include "std_lib_facilities.h"

//10.1
class Point 
{
public:
	int x;
	int y;
} ;
ostream& operator<<(ostream& os, Point& p)
{
	return os << '(' << p.x << ',' << p.y << ')';
}
int main()
try {
	//10.2 
	cout << "Dear user, we kindly ask you to input 7(x,y) pairs" << '/n';
	vector<Point> original_points;
	int i = 1;
	for (i = 1; i < 8; i++)
	{
		char ch1, ch2, ch3;
		int xx, yy;
		cin >> ch1 >> xx >> ch2 >> yy >> ch3;
		original_points.push_back(Point{ xx, yy });
	}
	// 10.3
	cout << "Print out the original points:" << '/n';
	for (auto e : original_points)
		cout << e << " ";

	//10.4
	string fname = "mydata.txt";
	ofstream opp{ fname };
	if (!opp) error("Cannot open file: ", fname);
	for (Point P : original_points)
		opp << P;
	
	//10.5
	opp.close();
	vector<Point> processed_points;

	ifstream ipp{ fname };
	if (!ipp) error("Cannot open input file: ", fname);
	for (i = 1; i < 8; i++)
	{
		int xx, yy;
		char ch1, ch2, ch3;
		ipp >> ch1 >> xx >> ch2 >> yy >> ch3;
		processed_points.push_back(Point{ xx,yy });
	}
	
	//10.6
	cout << "Print out the data elements:" << '/n';
	for (auto p : processed_points)
		cout << p << " ";

	cout << "Print out the original points:" << '/n';
	for (auto e : original_points)
		cout << e << " ";
	
	//10.7
	if (original_points.size() != processed_points.size())
		cout << "Something's wrong!\n";
{
catch (exception& e) 
{
	cerr << "Error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Something terrible has happened!\n";
	return 2;
}
