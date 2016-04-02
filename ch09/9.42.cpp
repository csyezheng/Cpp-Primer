#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string str;
	str.reserve(100);
	for (int i = 0; i != 100; ++i)
		str.push_back('c');
	for (const auto &ch : str)
		cout << ch;
	return 0;
}