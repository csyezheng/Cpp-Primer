#include <iostream>
#include <cstddef>
#include <string>

using namespace std;

int main()
{
	string prevStr, followStr;
	bool isBARepeated = false;
	while (cin >> followStr)
	{
		if (followStr == prevStr && isupper(followStr[0]))
		{
			isBARepeated = true;
			break;
		}
		else
		{
			prevStr = followStr;
		}
	}
	if (isBARepeated)
		cout << followStr << endl;
	else
		cout << "There are not repeated word the first alpha is upper" << endl;

	return 0;
}