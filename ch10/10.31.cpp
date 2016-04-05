#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

int main()
{
	std::istream_iterator<int> is_iter(std::cin), eof;
	std::vector<int> ivec(is_iter, eof);
	std::sort(ivec.begin(), ivec.end());
	std::ostream_iterator<int> os_iter(std::cout, " ");
	std::unique_copy(ivec.begin(), ivec.end(), os_iter);
	return 0;
}