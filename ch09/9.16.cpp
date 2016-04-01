#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::vector;

bool isEqual(const list<int> &ilst, const vector<int> &ivec)
{
	if (ilst.size() != ivec.size())
		return false;

	auto lstBeg = ilst.cbegin();
	auto vecBeg = ivec.cbegin();

	while (lstBeg != ilst.cend() && vecBeg != ivec.cend())
	{
		if (*lstBeg != *vecBeg)
			return false;
		++lstBeg;
		++vecBeg;
	}

	return true;
}

int main()
{
	list<int> lst = { 1, 3, 5, 7, 9 };
	vector<int> vec = { 1, 3, 5, 8, 9 };
	
	if (isEqual(lst, vec))
	{
		cout << "the list and the vector have the same elements " << endl;
	}
	else
	{
		cout << "the list and the vector are difference" << endl;
	}
}