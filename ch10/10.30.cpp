#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::istream_iterator;
using std::ostream_iterator;
using std::sort;
using std::copy;
using std::vector;

int main()
{
	istream_iterator<int> isiter(cin), eof;
	vector<int> ivec(isiter, eof);
	sort(ivec.begin(), ivec.end());
	ostream_iterator<int> ositer(cout, " ");
	copy(ivec.cbegin(), ivec.cend(), ositer);
	return 0;
}