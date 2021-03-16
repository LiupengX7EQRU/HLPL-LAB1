#include "std_lib_facilities.h"

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

const char let = 'L';
const char quit = 'E';
const char print = ';';
const char number = '8';
const char name = 'a';
const char sqrts = 's'; 
const char pows = 'p';

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case '!':
	case ',':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s = ch;
			cin.unget();
			if (s == "let") return Token(let);	
			if (s == "sqrt") return Token(sqrts);
			if (s == "pow") return Token(pows);
			if (s == "exit") return Token(quit);
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (Variable i: names) {
		if (i.name == s) return i.value;
                 }
                 error("get: undefined name ",s);
}
void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get(); // Get a character
	switch (t.kind) {
	case '(': 
	{	double d = expression(); // Perform calculations in semicolons
		t = ts.get(); // Get a ')' closing character
		if (t.kind != ')') error("')' expected"); // If there wasn't any ')' return an error
		return d;
	}
	case sqrts: // Calculate square root of number or group of numbers
	{
		double d = primary();
		if (d < 0) error("square root of negative number was detected"); // Print error message if negative number was thrown to sqrt
		return sqrt(d);
	}
	case pows:
	{
		t = ts.get();
		if (t.kind == '(') {
			double lval = primary();
			int rval = 0;
			t = ts.get();
			if(t.kind == ',') rval = narrow_cast<int>(primary());
			else error("Second argument is not provided");
			double result = 1;
			for(double i = 0; i < rval; i++) {
				result*=lval;
			}
			t = ts.get();
			if (t.kind != ')') error("')' expected"); // If there wasn't any ')' return an error
			return result;
		}
		else error("'(' expected"); // If there wasn't any ')' return an error
	}
	case '-': // For negative digits
		return - primary(); // Return negative digit
	case number: // If Token is a number
		return t.value; // Return the number
	case name: // If Token is a name of variable
		return get_value(t.name); // Return the value of the variable
	default:
		error("primary expected"); // Return an error if an inappropriate character was provided
	}
}


double term()
{
	double left = primary(); // Get the number or the variable
	while(true) {
		Token t = ts.get(); // Get a new character
		switch(t.kind) {
		case '*': // Multiplication
			left *= primary(); 
			break;
		case '/': // Division
		{	double d = primary(); 
			if (d == 0) error("division by zero"); // Division by zero is prohibited
			left /= d;
			break;
		}
        case '!': // Factorial
            {   
                int x = left;
                for (int i = 1; i < left; i++) { // Get a multiplication of all numbers before x (including x)
                    x*=i;
                }
                if (x == 0) left = 1;
                else left = x;
                break;
            }        
        case '%': // Modulo
            {
                double d = primary();
                if(d == 0) error("division by zero");
                left = fmod(left,d); // Use fmod to divide floating-point numbers with remainder
                break;
            }
		default:
			ts.unget(t); // If nothing was done return character to the stream
			if (left == -0) return 0; // Change -0 to 0 when it was multiplied or divided by negative digit
			return left; // Return new or unchanged value of 'left'
		}

	}
}
double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
	try {
		names.push_back(Variable("k",1000)); // Pre-defined variable 'k'

		calculate(); // Performs calculations
		return 0;
	}
	catch (exception& e) { // Throws an exception
		cerr << "exception: " << e.what() << endl; // Describe the error
		char c;
		while (cin >>c&& c!=';');
		return 1;
	}
	catch (...) { // Throws an exception
		cerr << "exception\n";
		char c;
		while (cin>>c && c!=';');
		return 2;
	}
