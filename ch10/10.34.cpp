#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
	std::vector<int> ivec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::for_each(ivec.rbegin(), ivec.rend(),
		[](const int val) { std::cout << val << std::endl; });
	return 0;
}