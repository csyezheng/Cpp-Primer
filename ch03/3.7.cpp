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
		for (char elem : str)   //use the type of "char" instead of "auto" 
		{
			elem = 'X';   // the string can't be changed
		}
		cout << str << endl;
	}
	else
	{
		cerr << "You must input a string" << endl;
	}

	return 0;
}