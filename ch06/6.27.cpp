#include <iostream>
#include <initializer_list>

using std::cout;
using std::endl;
using std::initializer_list;

int sum(initializer_list<int> il)
{
	int sum = 0;
	for (auto beg = il.begin(); beg != il.end(); ++beg)
		sum += *beg;
	return sum;
}

int main()
{
	int ret = sum({ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 });
	cout << ret << endl;
	return 0;
}