#include <iostream>
#include <string>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

int main()
{
	list<string> slst;
	string str;
	while (cin >> str)
	{
		slst.push_back(str);
	}
	for (auto beg = slst.cbegin(); beg != slst.cend(); ++beg)
	{
		cout << *beg << " ";
	}
	cout << endl;
	return 0;
}