#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;

std::istream &readData(std::istream &is)
{
	string str;
	while (is >> str)
		cout << str << endl;
	is.clear();
	return is;
}

int main()
{
	istringstream iss("Hello, World!");
	readData(iss);

	return 0;
}