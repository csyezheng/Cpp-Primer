#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

using vecIter = vector<int>::const_iterator;

bool findVal(vecIter beg, vecIter end, int val)
{
	for (auto iter = beg; iter != end; ++iter)
	{
		if (*iter == val)
			return true;
	}
	return false;
}

int main()
{
	vector<int> ivec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	bool ret = findVal(ivec.cbegin(), ivec.cend(), 8);
	if (ret)
		cout << "the number is in the vector" << endl;
	else
		cout << "the number isn't in the vector" << endl;

	return 0;
}