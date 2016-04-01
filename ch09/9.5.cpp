#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

using vecIter = vector<int>::const_iterator;

vecIter findVal(vecIter beg, vecIter end, int val)
{
	auto iter = beg;
	for (/* empty */; iter != end; ++iter)
	{
		if (*iter == val)
			return iter;
	}
	if (iter == end)
	{
		cout << "can't find the value in the vector" << endl;
		return end;
	}
}

int main()
{
	vector<int> ivec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vecIter ret = findVal(ivec.cbegin(), ivec.cend(), 8);
	if (ret != ivec.cend())
		cout << "the number is in the vector" << endl;

	return 0;
}