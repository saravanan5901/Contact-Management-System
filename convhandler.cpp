#ifndef convcpp
#define convcpp

//Handles conversions between int and string
#include <string>
#include <sstream>
using namespace std;

int toInt(string str)
{
	stringstream s(str);
	int ival;
	s >> ival;
	return ival;
}

string toString(int i)
{
	ostringstream s;
	s << i;
	string str = s.str();
	return str;
}

#endif
