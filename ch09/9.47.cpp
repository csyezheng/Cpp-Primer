#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
	string str("ab2c3d7r4e6");
	auto i = str.find_first_of("0123456789");
	cout << str[i] << endl;
	auto locate = str.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
	cout << str[locate] << endl;
	return 0;
}