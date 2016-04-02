#include <iostream>
#include <list>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::deque;

int main()
{
	list<int> ilst = { 0, 32, 421, 12, 42, 132, 23, 45, 22 };
	deque<int> oddDeque, evenDeque;
	for (auto beg = ilst.cbegin(); beg != ilst.cend(); ++beg)
	{
		if ((*beg & 1) != 1)
			evenDeque.push_back(*beg);
		else
			oddDeque.push_back(*beg);
	}
	for (const auto &entry : oddDeque)
		cout << entry << " ";
	cout << endl;
	for (const auto &elem : evenDeque)
		cout << elem << " ";
	cout << endl;
	return 0;
}