#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
	string connectStr;
	if (cin >> connectStr)
	{
		string currStr;
		while (cin >> currStr)
		{
			connectStr += currStr;
		}
		cout << connectStr << endl;
	}
	else
	{
		cerr << "You don't input strings" << endl;
	}
	

	/*

	string str;
	for (string buff; cin >> buff; str += (str.empty() ? "" : " ") + buff);
	cout << "The concatenated string is " << str << endl;
	
	*/

	return 0;
}