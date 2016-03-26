#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
	/* compare two strings */
	string str1("The Little Fox"), str2("The Old Fox");
	if (str1 != str2)
		cout << "the two string are not equal" << endl;
	else
		cout << "the two string are equal" << endl;

	/* compare two C-style strings */
	const char ca1[] = "The Little Fox";
	const char ca2[] = "The Old Fox";
	if (strcmp(ca1, ca2) == 0)
		cout << "the two C-style strings are equal" << endl;
	else
		cout << "the two C-style strings are not equal" << endl;

	return 0;

}