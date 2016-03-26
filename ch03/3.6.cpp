#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
	string str;
	if (cin >> str)
	{
		for (auto &elem : str)
		{
			elem = 'X';
		}
		cout << str << endl;
	}
	else
	{
		cerr << "You must input a string" << endl;
	}

	return 0;
}