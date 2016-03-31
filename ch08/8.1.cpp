#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

std::istream &readData(std::istream &is)
{
	string str;
	while (is >> str)
		cout << str;
	is.clear();
	return is;
}

int main()
{
	std::istream &is = readData(cin);
	cout << is.rdstate() << endl;
	return 0;
}