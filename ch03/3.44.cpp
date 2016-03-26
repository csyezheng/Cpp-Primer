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

	using arr4_type = int[4];

	/* range for */
	for (arr4_type rows : ia)
		for (int number : rows)
			cout << number << " ";
	cout << endl;

	/* sub */
	for (size_t i = 0; i != 3; ++i)
		for (size_t j = 0; j != 4; ++j)
			cout << ia[i][j] << " ";
	cout << endl;

	/* pointer */
	for (arr4_type *pRow = begin(ia); pRow != end(ia); ++pRow)
		for (int *pCol = begin(*pRow); pCol != end(*pRow); ++pCol)
			cout << *pCol << " ";
	cout << endl;

	return 0;
}
