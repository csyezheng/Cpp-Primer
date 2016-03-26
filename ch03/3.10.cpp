#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main()
{
	string str;
	cin >> str;
	string::size_type i = 0;
	for (; i != str.size(); ++i)
		if (!ispunct(str[i]))
			cout << str[i];
	cout << endl;
}