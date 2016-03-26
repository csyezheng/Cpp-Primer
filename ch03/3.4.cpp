#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	if (str1 == str2)
	{
		cout << "the two string are equal" << endl;
	}
	else
	{
		if (str1 < str2)
			cout << str2 << endl;
		else
			cout << str1 << endl;
	}

	/* ------------------ */
	string str3, str4;
	cin >> str3 >> str4;
	auto len3 = str3.size(), len4 = str4.size();
	if (len3 == len4)
	{
		cout << "the two string have the same length" << endl;
	}
	else
	{
		if (len3 < len4)
			cout << str4 << endl;
		else
			cout << str3 << endl;
	}

	return 0;
}