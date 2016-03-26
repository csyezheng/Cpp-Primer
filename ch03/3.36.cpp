#include <iostream>
#include <cstddef>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::end;

bool compareTwoArrays(int* const beg, int* const end, int* const lft, int* const rht)
{
	if (end - beg != rht - lft)
		return false;
	
	for (int *begIter = beg, *lftIter = lft; 
		begIter != end, lftIter != rht; ++begIter, ++lftIter)
	{
		if (*begIter != *lftIter)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	/* compare two arrays */
	int arr1[7] = { 1, 2, 4, 2, 5, 8, 9 };
	int arr2[7] = { 1, 2, 4, 3, 4, 2, 5 };
	auto pBeg = begin(arr1), pLft = begin(arr2);
	auto pEnd = end(arr1), pRht = end(arr2);
	if (compareTwoArrays(pBeg, pEnd, pLft, pRht))
		cout << "the two arrays are equal" << endl;
	else
		cout << "the two arrays are not equal" << endl;

	/* compare two vectors */
	vector<int> ivec1 = { 0, 2, 3, 4, 1, 4, 6, 8 };
	vector<int> ivec2 = { 0, 2, 3, 4, 1, 4, 6, 8 };
	if (ivec1 == ivec2)
		cout << "the two vector are equal" << endl;
	else
		cout << "thw two vector are not equal" << endl;
	return 0;
}