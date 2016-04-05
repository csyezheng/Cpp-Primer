#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
#include <iostream>

int main()
{
	std::vector<int> ivec = { 1, 2, 3, 23, 2, 4, 2, 5, 2, 1 };
	std::list<int> ilst;
	std::copy(ivec.crbegin() + 3, ivec.crbegin() + 8, std::back_inserter(ilst));
	std::for_each(ilst.cbegin(), ilst.cend(),
		[](const int val) { std::cout << val << std::endl; });
	return 0;
}