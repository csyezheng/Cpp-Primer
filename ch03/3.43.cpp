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
	for (const size_t (&rows)[4] : ia)
		for (const int number : rows)
			cout << number << " ";
	cout << endl;

	/* sub */
	for (size_t i = 0; i != 3; ++i)
		for (size_t j = 0; j != 4; ++j)
			cout << ia[i][j] << " ";
	cout << endl;

	/* pointer */
	for (int (*pRow)[4] = begin(ia); pRow != end(ia); ++pRow)
		for (int *pCol = begin(*pRow); pCol != end(*pRow); ++pCol)
			cout << *pCol << " ";
	cout << endl;

	return 0;
}