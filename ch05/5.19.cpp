#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	bool yesOrNot = true;
	do
	{
		cout << "Please enter two strings" << endl;
		string str1, str2;
		cin >> str1 >> str2;
		if (str1.size() <= str2.size())
			cout << str1 << endl;
		else
			cout << str2 << endl;
		cout << "Do you want to use again? y or n " << endl;
		char choose;
		cin >> choose;
		if (choose == 'y' || choose == 'Y')
			yesOrNot = true;
		else
			yesOrNot = false;
	} while (yesOrNot);

	return 0;
}