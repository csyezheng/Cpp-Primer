#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
	int arr[10] = { 0, 2, 3, 4, 1, 5, 6 };
	for (auto beg = begin(arr); beg != end(arr); ++beg)
		*beg = 0;
	for (auto &elem : arr)
	{
		cout << elem << " ";
	}
	cout << endl;
	return 0;
}