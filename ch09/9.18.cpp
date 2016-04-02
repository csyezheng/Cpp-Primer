#include <iostream>
#include <string>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::deque;

int main()
{
	deque<string> sdeque;
	string str;
	while (cin >> str)
	{
		sdeque.push_back(str);
	}
	for (auto beg = sdeque.cbegin(); beg != sdeque.cend(); ++beg)
	{
		cout << *beg << " ";
	}
	cout << endl;
	
	return 0;
}