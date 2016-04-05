#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> ilst = { 9, 0, 12, 32, 54, 0, 23, 3, 0, 23, 3 };
	auto iter = std::find(ilst.crbegin(), ilst.crend(), 0);
	std::cout << std::distance(iter, ilst.crend()) << std::endl;
	return 0;
}