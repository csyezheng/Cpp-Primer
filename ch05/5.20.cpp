#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;


int main()
{
	bool isRepeated = false;
	string prevStr, followStr;
	while (cin >> followStr)
	{
		if (prevStr == followStr)
		{
			isRepeated = true;
			break;
		}
		else
		{
			prevStr = followStr;
		}
	}
	if (isRepeated)
		cout << prevStr << endl;
	else
		cout << "There are no repeated string" << endl;

	return 0;
}