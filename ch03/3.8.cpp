#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
	/* use while iterator */
	string strToX;
	cin >> strToX;
	auto beg = strToX.begin();
	while (beg != strToX.end())
		*beg++ = 'X';
	cout << strToX << endl;

	/* use for iterator */
	string str;
	cin >> str;
	for (decltype(str.size()) i = 0; i != str.size(); ++i)
		str[i] = 'X';
	cout << str << endl;

	return 0;
}