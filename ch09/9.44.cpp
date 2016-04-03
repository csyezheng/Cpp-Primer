#include <iostream>
#include <algorithm>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::replace;

void replaceStr(string &s, const string &oldVal, const string &newVal)
{
	for (string::size_type i = 0; i + oldVal.size() <= s.size(); /* */)
	{
		if (s[i] == oldVal[0] && s.substr(i, oldVal.size()) == oldVal)
		{
			s.replace(i, oldVal.size(), newVal);
			i = i + newVal.size();
		}
		else
			++i;
	}
}

int main()
{
	string str("the tho and the thru will be replaced");
	replaceStr(str, "tho", "though");
	replaceStr(str, "thru", "through");
	cout << str << endl;
	return 0;
}