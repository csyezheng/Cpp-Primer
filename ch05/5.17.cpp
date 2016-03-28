#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool isSubSequence(vector<int> lhs, vector<int> rhs)
{
	for (auto iter1 = lhs.begin(), iter2 = rhs.begin(); iter1 != lhs.end() &&
		iter2 != rhs.end(); ++iter1, ++iter2)
	{
		if (*iter1 != *iter2)
			return false;
	}
	return true;
}

int main()
{
	vector<int> ivec1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> ivec2 = { 0, 1, 4, 3 };
	if (isSubSequence(ivec1, ivec2))
		cout << "a vector is another's subsequence " << endl;
	else
		cout << "a vector is not another's subsequence" << endl;

	return 0;
}