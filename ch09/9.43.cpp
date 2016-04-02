#include <iostream>
#include <string>
#include <cstddef>
#include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::distance;     

void replace(string &s, const string &oldVal, const string &newVal)
{
	for (auto iter = s.begin(); distance(iter, s.end()) >=
		static_cast<ptrdiff_t>(oldVal.size()); ++iter)
	{
		if (*iter == oldVal[0] && string(iter, std::next(iter, oldVal.size()))
			== oldVal)
		{
			iter = s.erase(iter, std::next(iter, oldVal.size()));
			iter = s.insert(iter, newVal.cbegin(), newVal.cend());
		}
	}
}

int main()
{
	string str("the tho and the thru should be replaced");
	replace(str, "tho", "though");
	replace(str, "thru", "through");
	cout << str << endl;
	return 0;
}