#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (auto end = std::prev(ivec.cend()); true; --end)
	{
		std::cout << *end << std::endl;
		if (end == ivec.cbegin())
			break;
	}
	return 0;
}