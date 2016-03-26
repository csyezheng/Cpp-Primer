#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main()
{
	int ia[3][4] = {
		{ 0, 1, 2, 3 },
		{ 4, 5, 6, 7 },
		{ 8, 9, 10, 11 }
	};

	/* range for */
	for (auto rows : ia)
		for (auto number : rows)
			cout << number << " ";
	cout << endl;

	/* sub */
	for (auto i = 0; i != 3; ++i)
		for (auto j = 0; j != 4; ++j)
			cout << ia[i][j] << " ";
	cout << endl;

	/* pointer */
	for (auto pRow = begin(ia); pRow != end(ia); ++pRow)
		for (auto pCol = begin(*pRow); pCol != end(*pRow); ++pCol)
			cout << *pCol << " ";
	cout << endl;

	return 0;
}